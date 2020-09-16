//
// Copyright (c) 2008-2020 the Urho3D project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#include "../../Precompiled.h"

#include "../../Graphics/Graphics.h"
#include "../../Graphics/GraphicsImpl.h"
#include "../../Graphics/Material.h"
#include "../../Graphics/RenderSurface.h"
#include "../../IO/Log.h"
#include "../../Resource/ResourceCache.h"
#include "../../Resource/XMLFile.h"


namespace Urho3D
{

static GLenum glWrapModes[] =
{
    GL_REPEAT,
    GL_MIRRORED_REPEAT,
    GL_CLAMP_TO_EDGE,
    GL_CLAMP_TO_EDGE
};

static GLenum GetWrapMode(TextureAddressMode mode)
{
    return glWrapModes[mode];
}

void Texture::SetSRGB(bool enable)
{
    if (graphics_)
        enable &= graphics_->GetSRGBSupport();

    if (enable != sRGB_)
    {
        sRGB_ = enable;
        // If texture had already been created, must recreate it to set the sRGB texture format
        if (object_.name_)
            Create();

        // If texture in use in the framebuffer, mark it dirty
        if (graphics_ && graphics_->GetRenderTarget(0) && graphics_->GetRenderTarget(0)->GetParentTexture() == this)
            graphics_->MarkFBODirty();
    }
}

void Texture::UpdateParameters()
{
    if (!object_.name_ || !graphics_)
        return;

    // Wrapping
    glTexParameteri(target_, GL_TEXTURE_WRAP_S, GetWrapMode(addressModes_[COORD_U]));
    glTexParameteri(target_, GL_TEXTURE_WRAP_T, GetWrapMode(addressModes_[COORD_V]));

    TextureFilterMode filterMode = filterMode_;
    if (filterMode == FILTER_DEFAULT)
        filterMode = graphics_->GetDefaultTextureFilterMode();

    // Filtering
    switch (filterMode)
    {
    case FILTER_NEAREST:
        if (levels_ < 2)
            glTexParameteri(target_, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        else
            glTexParameteri(target_, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
        glTexParameteri(target_, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        break;

    case FILTER_BILINEAR:
        if (levels_ < 2)
            glTexParameteri(target_, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        else
            glTexParameteri(target_, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
        glTexParameteri(target_, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        break;

    case FILTER_ANISOTROPIC:
    case FILTER_TRILINEAR:
        if (levels_ < 2)
            glTexParameteri(target_, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        else
            glTexParameteri(target_, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(target_, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        break;

    case FILTER_NEAREST_ANISOTROPIC:
        if (levels_ < 2)
            glTexParameteri(target_, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        else
            glTexParameteri(target_, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
        glTexParameteri(target_, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        break;

    default:
        break;
    }

    parametersDirty_ = false;
}

bool Texture::GetParametersDirty() const
{
    return parametersDirty_;
}

bool Texture::IsCompressed() const
{
    return format_ == GL_COMPRESSED_RGBA_S3TC_DXT1_EXT || format_ == GL_COMPRESSED_RGBA_S3TC_DXT3_EXT ||
           format_ == GL_COMPRESSED_RGBA_S3TC_DXT5_EXT || format_ == GL_ETC1_RGB8_OES ||
           format_ == COMPRESSED_RGB_PVRTC_4BPPV1_IMG || format_ == COMPRESSED_RGBA_PVRTC_4BPPV1_IMG ||
           format_ == COMPRESSED_RGB_PVRTC_2BPPV1_IMG || format_ == COMPRESSED_RGBA_PVRTC_2BPPV1_IMG;
}

unsigned Texture::GetRowDataSize(int width) const
{
    switch (format_)
    {
    case GL_ALPHA:
    case GL_LUMINANCE:
        return (unsigned)width;

    case GL_LUMINANCE_ALPHA:
        return (unsigned)(width * 2);

    case GL_RGB:
        return (unsigned)(width * 3);

    case GL_RGBA:
        return (unsigned)(width * 4);

    case GL_COMPRESSED_RGBA_S3TC_DXT1_EXT:
        return ((unsigned)(width + 3) >> 2u) * 8;

    case GL_COMPRESSED_RGBA_S3TC_DXT3_EXT:
    case GL_COMPRESSED_RGBA_S3TC_DXT5_EXT:
        return ((unsigned)(width + 3) >> 2u) * 16;

    case GL_ETC1_RGB8_OES:
        return ((unsigned)(width + 3) >> 2u) * 8;

    case COMPRESSED_RGB_PVRTC_4BPPV1_IMG:
    case COMPRESSED_RGBA_PVRTC_4BPPV1_IMG:
        return ((unsigned)(width + 3) >> 2u) * 8;

    case COMPRESSED_RGB_PVRTC_2BPPV1_IMG:
    case COMPRESSED_RGBA_PVRTC_2BPPV1_IMG:
        return ((unsigned)(width + 7) >> 3u) * 8;

    default:
        return 0;
    }
}

unsigned Texture::GetExternalFormat(unsigned format)
{
    return format;
}

unsigned Texture::GetDataType(unsigned format)
{
    if (format == GL_DEPTH_COMPONENT || format == GL_DEPTH_COMPONENT24_OES)
        return GL_UNSIGNED_INT;
    else if (format == GL_DEPTH_COMPONENT16)
        return GL_UNSIGNED_SHORT;
    else
        return GL_UNSIGNED_BYTE;
}

unsigned Texture::GetSRGBFormat(unsigned format)
{
    return format;
}

void Texture::RegenerateLevels()
{
    if (!object_.name_)
        return;

    glGenerateMipmap(target_);

    levelsDirty_ = false;
}

}
