/*
** Lua binding: MathLuaAPI
*/

//
// Copyright (c) 2008-2019 the Urho3D project.
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

#include <toluapp/tolua++.h>
#include "LuaScript/ToluaUtils.h"

#if __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"
#endif

/* Exported function */
TOLUA_API int tolua_MathLuaAPI_open (lua_State* tolua_S);

#include "Math/MathDefs.h"
#include "Math/BoundingBox.h"
#include "Math/Color.h"
#include "Math/Frustum.h"
#include "Math/Matrix3.h"
#include "Math/Matrix3x4.h"
#include "Math/Matrix4.h"
#include "Math/Plane.h"
#include "Math/Polyhedron.h"
#include "Math/Quaternion.h"
#include "Math/Random.h"
#include "Math/Ray.h"
#include "Math/Rect.h"
#include "Math/Sphere.h"
#include "Math/StringHash.h"
#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Math/Vector4.h"
using namespace Urho3D;
#pragma warning(disable:4800)

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Quaternion (lua_State* tolua_S)
{
 Quaternion* self = (Quaternion*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Color (lua_State* tolua_S)
{
 Color* self = (Color*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Vector3 (lua_State* tolua_S)
{
 Vector3* self = (Vector3*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_IntVector3 (lua_State* tolua_S)
{
 IntVector3* self = (IntVector3*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_StringHash (lua_State* tolua_S)
{
 StringHash* self = (StringHash*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_IntRect (lua_State* tolua_S)
{
 IntRect* self = (IntRect*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Sphere (lua_State* tolua_S)
{
 Sphere* self = (Sphere*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Vector4 (lua_State* tolua_S)
{
 Vector4* self = (Vector4*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Matrix3 (lua_State* tolua_S)
{
 Matrix3* self = (Matrix3*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Plane (lua_State* tolua_S)
{
 Plane* self = (Plane*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Polyhedron (lua_State* tolua_S)
{
 Polyhedron* self = (Polyhedron*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Ray (lua_State* tolua_S)
{
 Ray* self = (Ray*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Rect (lua_State* tolua_S)
{
 Rect* self = (Rect*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Frustum (lua_State* tolua_S)
{
 Frustum* self = (Frustum*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Vector2 (lua_State* tolua_S)
{
 Vector2* self = (Vector2*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Matrix3x4 (lua_State* tolua_S)
{
 Matrix3x4* self = (Matrix3x4*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_BoundingBox (lua_State* tolua_S)
{
 BoundingBox* self = (BoundingBox*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Matrix4 (lua_State* tolua_S)
{
 Matrix4* self = (Matrix4*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_IntVector2 (lua_State* tolua_S)
{
 IntVector2* self = (IntVector2*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Quaternion");
 tolua_usertype(tolua_S,"Color");
 tolua_usertype(tolua_S,"BoundingBox");
 tolua_usertype(tolua_S,"Vector4");
 tolua_usertype(tolua_S,"IntVector3");
 tolua_usertype(tolua_S,"IntRect");
 tolua_usertype(tolua_S,"Vector3");
 tolua_usertype(tolua_S,"Rect");
 tolua_usertype(tolua_S,"Matrix3");
 tolua_usertype(tolua_S,"Plane");
 tolua_usertype(tolua_S,"Polyhedron");
 tolua_usertype(tolua_S,"Ray");
 tolua_usertype(tolua_S,"Sphere");
 tolua_usertype(tolua_S,"Frustum");
 tolua_usertype(tolua_S,"Vector2");
 tolua_usertype(tolua_S,"Matrix3x4");
 tolua_usertype(tolua_S,"StringHash");
 tolua_usertype(tolua_S,"Matrix4");
 tolua_usertype(tolua_S,"IntVector2");
}

/* get function: M_PI */
#ifndef TOLUA_DISABLE_tolua_get_M_PI
static int tolua_get_M_PI(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)M_PI);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: M_HALF_PI */
#ifndef TOLUA_DISABLE_tolua_get_M_HALF_PI
static int tolua_get_M_HALF_PI(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)M_HALF_PI);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: M_MIN_INT */
#ifndef TOLUA_DISABLE_tolua_get_M_MIN_INT
static int tolua_get_M_MIN_INT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)M_MIN_INT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: M_MAX_INT */
#ifndef TOLUA_DISABLE_tolua_get_M_MAX_INT
static int tolua_get_M_MAX_INT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)M_MAX_INT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: M_MIN_UNSIGNED */
#ifndef TOLUA_DISABLE_tolua_get_M_MIN_UNSIGNED
static int tolua_get_M_MIN_UNSIGNED(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)M_MIN_UNSIGNED);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: M_MAX_UNSIGNED */
#ifndef TOLUA_DISABLE_tolua_get_M_MAX_UNSIGNED
static int tolua_get_M_MAX_UNSIGNED(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)M_MAX_UNSIGNED);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: M_EPSILON */
#ifndef TOLUA_DISABLE_tolua_get_M_EPSILON
static int tolua_get_M_EPSILON(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)M_EPSILON);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: M_LARGE_EPSILON */
#ifndef TOLUA_DISABLE_tolua_get_M_LARGE_EPSILON
static int tolua_get_M_LARGE_EPSILON(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)M_LARGE_EPSILON);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: M_MIN_NEARCLIP */
#ifndef TOLUA_DISABLE_tolua_get_M_MIN_NEARCLIP
static int tolua_get_M_MIN_NEARCLIP(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)M_MIN_NEARCLIP);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: M_MAX_FOV */
#ifndef TOLUA_DISABLE_tolua_get_M_MAX_FOV
static int tolua_get_M_MAX_FOV(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)M_MAX_FOV);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: M_LARGE_VALUE */
#ifndef TOLUA_DISABLE_tolua_get_M_LARGE_VALUE
static int tolua_get_M_LARGE_VALUE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)M_LARGE_VALUE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: M_INFINITY */
#ifndef TOLUA_DISABLE_tolua_get_M_INFINITY
static int tolua_get_M_INFINITY(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)M_INFINITY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: M_DEGTORAD */
#ifndef TOLUA_DISABLE_tolua_get_M_DEGTORAD
static int tolua_get_M_DEGTORAD(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)M_DEGTORAD);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: M_DEGTORAD_2 */
#ifndef TOLUA_DISABLE_tolua_get_M_DEGTORAD_2
static int tolua_get_M_DEGTORAD_2(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)M_DEGTORAD_2);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: M_RADTODEG */
#ifndef TOLUA_DISABLE_tolua_get_M_RADTODEG
static int tolua_get_M_RADTODEG(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)M_RADTODEG);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* function: Equals */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Equals00
static int tolua_MathLuaAPI_Equals00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float lhs = ((float)  tolua_tonumber(tolua_S,1,0));
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
 {
  bool tolua_ret = (bool)  Equals(lhs,rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Equals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: IsNaN */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IsNaN00
static int tolua_MathLuaAPI_IsNaN00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float value = ((float)  tolua_tonumber(tolua_S,1,0));
 {
  bool tolua_ret = (bool)  IsNaN(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsNaN'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Lerp */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Lerp00
static int tolua_MathLuaAPI_Lerp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float lhs = ((float)  tolua_tonumber(tolua_S,1,0));
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
  float t = ((float)  tolua_tonumber(tolua_S,3,0));
 {
  float tolua_ret = (float)  Lerp(lhs,rhs,t);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Lerp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: InverseLerp */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_InverseLerp00
static int tolua_MathLuaAPI_InverseLerp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float lhs = ((float)  tolua_tonumber(tolua_S,1,0));
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
  float x = ((float)  tolua_tonumber(tolua_S,3,0));
 {
  float tolua_ret = (float)  InverseLerp(lhs,rhs,x);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InverseLerp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Min */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Min00
static int tolua_MathLuaAPI_Min00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float lhs = ((float)  tolua_tonumber(tolua_S,1,0));
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
 {
  float tolua_ret = (float)  Min(lhs,rhs);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Min'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Max */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Max00
static int tolua_MathLuaAPI_Max00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float lhs = ((float)  tolua_tonumber(tolua_S,1,0));
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
 {
  float tolua_ret = (float)  Max(lhs,rhs);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Max'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Abs */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Abs00
static int tolua_MathLuaAPI_Abs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float value = ((float)  tolua_tonumber(tolua_S,1,0));
 {
  float tolua_ret = (float)  Abs(value);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Abs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Sign */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sign00
static int tolua_MathLuaAPI_Sign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float value = ((float)  tolua_tonumber(tolua_S,1,0));
 {
  float tolua_ret = (float)  Sign(value);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Sign'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Clamp */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Clamp00
static int tolua_MathLuaAPI_Clamp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float value = ((float)  tolua_tonumber(tolua_S,1,0));
  float min = ((float)  tolua_tonumber(tolua_S,2,0));
  float max = ((float)  tolua_tonumber(tolua_S,3,0));
 {
  float tolua_ret = (float)  Clamp(value,min,max);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clamp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: SmoothStep */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_SmoothStep00
static int tolua_MathLuaAPI_SmoothStep00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float lhs = ((float)  tolua_tonumber(tolua_S,1,0));
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
  float t = ((float)  tolua_tonumber(tolua_S,3,0));
 {
  float tolua_ret = (float)  SmoothStep(lhs,rhs,t);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SmoothStep'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Sin */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sin00
static int tolua_MathLuaAPI_Sin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float angle = ((float)  tolua_tonumber(tolua_S,1,0));
 {
  float tolua_ret = (float)  Sin(angle);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Sin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Cos */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Cos00
static int tolua_MathLuaAPI_Cos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float angle = ((float)  tolua_tonumber(tolua_S,1,0));
 {
  float tolua_ret = (float)  Cos(angle);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Cos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Tan */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Tan00
static int tolua_MathLuaAPI_Tan00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float angle = ((float)  tolua_tonumber(tolua_S,1,0));
 {
  float tolua_ret = (float)  Tan(angle);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Tan'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Asin */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Asin00
static int tolua_MathLuaAPI_Asin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,1,0));
 {
  float tolua_ret = (float)  Asin(x);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Asin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Acos */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Acos00
static int tolua_MathLuaAPI_Acos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,1,0));
 {
  float tolua_ret = (float)  Acos(x);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Acos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Atan */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Atan00
static int tolua_MathLuaAPI_Atan00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,1,0));
 {
  float tolua_ret = (float)  Atan(x);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Atan'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Atan2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Atan200
static int tolua_MathLuaAPI_Atan200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float y = ((float)  tolua_tonumber(tolua_S,1,0));
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
 {
  float tolua_ret = (float)  Atan2(y,x);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Atan2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Sqrt */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sqrt00
static int tolua_MathLuaAPI_Sqrt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,1,0));
 {
  float tolua_ret = (float)  Sqrt(x);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Sqrt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Pow */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Pow00
static int tolua_MathLuaAPI_Pow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,1,0));
  float y = ((float)  tolua_tonumber(tolua_S,2,0));
 {
  float tolua_ret = (float)  Pow(x,y);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Pow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Ln */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Ln00
static int tolua_MathLuaAPI_Ln00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,1,0));
 {
  float tolua_ret = (float)  Ln(x);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Ln'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Mod */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Mod00
static int tolua_MathLuaAPI_Mod00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,1,0));
  float y = ((float)  tolua_tonumber(tolua_S,2,0));
 {
  float tolua_ret = (float)  Mod(x,y);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Mod'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Fract */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Fract00
static int tolua_MathLuaAPI_Fract00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,1,0));
 {
  float tolua_ret = (float)  Fract(x);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Fract'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Floor */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Floor00
static int tolua_MathLuaAPI_Floor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,1,0));
 {
  float tolua_ret = (float)  Floor(x);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Floor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Round */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Round00
static int tolua_MathLuaAPI_Round00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,1,0));
 {
  float tolua_ret = (float)  Round(x);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Round'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Ceil */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Ceil00
static int tolua_MathLuaAPI_Ceil00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,1,0));
 {
  float tolua_ret = (float)  Ceil(x);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Ceil'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: FloorToInt */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_FloorToInt00
static int tolua_MathLuaAPI_FloorToInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  FloorToInt(x);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FloorToInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: RoundToInt */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_RoundToInt00
static int tolua_MathLuaAPI_RoundToInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  RoundToInt(x);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RoundToInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: CeilToInt */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_CeilToInt00
static int tolua_MathLuaAPI_CeilToInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  CeilToInt(x);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CeilToInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Min */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_MinInt00
static int tolua_MathLuaAPI_MinInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int lhs = ((int)  tolua_tonumber(tolua_S,1,0));
  int rhs = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  Min(lhs,rhs);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MinInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Max */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_MaxInt00
static int tolua_MathLuaAPI_MaxInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int lhs = ((int)  tolua_tonumber(tolua_S,1,0));
  int rhs = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  Max(lhs,rhs);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MaxInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Abs */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_AbsInt00
static int tolua_MathLuaAPI_AbsInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int value = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  Abs(value);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AbsInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Clamp */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_ClampInt00
static int tolua_MathLuaAPI_ClampInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int value = ((int)  tolua_tonumber(tolua_S,1,0));
  int min = ((int)  tolua_tonumber(tolua_S,2,0));
  int max = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  int tolua_ret = (int)  Clamp(value,min,max);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClampInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: IsPowerOfTwo */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IsPowerOfTwo00
static int tolua_MathLuaAPI_IsPowerOfTwo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  unsigned value = ((unsigned)  tolua_tonumber(tolua_S,1,0));
 {
  bool tolua_ret = (bool)  IsPowerOfTwo(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsPowerOfTwo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: NextPowerOfTwo */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_NextPowerOfTwo00
static int tolua_MathLuaAPI_NextPowerOfTwo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  unsigned value = ((unsigned)  tolua_tonumber(tolua_S,1,0));
 {
  unsigned tolua_ret = (unsigned)  NextPowerOfTwo(value);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'NextPowerOfTwo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: CountSetBits */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_CountSetBits00
static int tolua_MathLuaAPI_CountSetBits00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  unsigned value = ((unsigned)  tolua_tonumber(tolua_S,1,0));
 {
  unsigned tolua_ret = (unsigned)  CountSetBits(value);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CountSetBits'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: LogBaseTwo */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_LogBaseTwo00
static int tolua_MathLuaAPI_LogBaseTwo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  unsigned value = ((unsigned)  tolua_tonumber(tolua_S,1,0));
 {
  unsigned tolua_ret = (unsigned)  LogBaseTwo(value);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LogBaseTwo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: SDBMHash */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_SDBMHash00
static int tolua_MathLuaAPI_SDBMHash00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  unsigned hash = ((unsigned)  tolua_tonumber(tolua_S,1,0));
  unsigned char c = ((unsigned char)  tolua_tonumber(tolua_S,2,0));
 {
  unsigned tolua_ret = (unsigned)  SDBMHash(hash,c);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SDBMHash'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Random */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Random00
static int tolua_MathLuaAPI_Random00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  float tolua_ret = (float)  Random();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Random'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Random */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Random01
static int tolua_MathLuaAPI_Random01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float range = ((float)  tolua_tonumber(tolua_S,1,0));
 {
  float tolua_ret = (float)  Random(range);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Random00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: Random */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Random02
static int tolua_MathLuaAPI_Random02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float min = ((float)  tolua_tonumber(tolua_S,1,0));
  float max = ((float)  tolua_tonumber(tolua_S,2,0));
 {
  float tolua_ret = (float)  Random(min,max);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Random01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: Random */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_RandomInt00
static int tolua_MathLuaAPI_RandomInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int range = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  Random(range);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RandomInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Random */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_RandomInt01
static int tolua_MathLuaAPI_RandomInt01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  int min = ((int)  tolua_tonumber(tolua_S,1,0));
  int max = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  Random(min,max);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_RandomInt00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: RandomNormal */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_RandomNormal00
static int tolua_MathLuaAPI_RandomNormal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float meanValue = ((float)  tolua_tonumber(tolua_S,1,0));
  float variance = ((float)  tolua_tonumber(tolua_S,2,0));
 {
  float tolua_ret = (float)  RandomNormal(meanValue,variance);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RandomNormal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_new00
static int tolua_MathLuaAPI_BoundingBox_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  BoundingBox* tolua_ret = (BoundingBox*)  Mtolua_new((BoundingBox)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"BoundingBox");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_new00_local
static int tolua_MathLuaAPI_BoundingBox_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  BoundingBox* tolua_ret = (BoundingBox*)  Mtolua_new((BoundingBox)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"BoundingBox");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_new01
static int tolua_MathLuaAPI_BoundingBox_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const BoundingBox* box = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
 {
  BoundingBox* tolua_ret = (BoundingBox*)  Mtolua_new((BoundingBox)(*box));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"BoundingBox");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_new01_local
static int tolua_MathLuaAPI_BoundingBox_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const BoundingBox* box = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
 {
  BoundingBox* tolua_ret = (BoundingBox*)  Mtolua_new((BoundingBox)(*box));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"BoundingBox");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_new02
static int tolua_MathLuaAPI_BoundingBox_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Rect* rect = ((const Rect*)  tolua_tousertype(tolua_S,2,0));
 {
  BoundingBox* tolua_ret = (BoundingBox*)  Mtolua_new((BoundingBox)(*rect));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"BoundingBox");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_new02_local
static int tolua_MathLuaAPI_BoundingBox_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Rect* rect = ((const Rect*)  tolua_tousertype(tolua_S,2,0));
 {
  BoundingBox* tolua_ret = (BoundingBox*)  Mtolua_new((BoundingBox)(*rect));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"BoundingBox");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_new03
static int tolua_MathLuaAPI_BoundingBox_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* min = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* max = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
 {
  BoundingBox* tolua_ret = (BoundingBox*)  Mtolua_new((BoundingBox)(*min,*max));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"BoundingBox");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_new03_local
static int tolua_MathLuaAPI_BoundingBox_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* min = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* max = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
 {
  BoundingBox* tolua_ret = (BoundingBox*)  Mtolua_new((BoundingBox)(*min,*max));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"BoundingBox");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_new04
static int tolua_MathLuaAPI_BoundingBox_new04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float min = ((float)  tolua_tonumber(tolua_S,2,0));
  float max = ((float)  tolua_tonumber(tolua_S,3,0));
 {
  BoundingBox* tolua_ret = (BoundingBox*)  Mtolua_new((BoundingBox)(min,max));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"BoundingBox");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_new03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_new04_local
static int tolua_MathLuaAPI_BoundingBox_new04_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float min = ((float)  tolua_tonumber(tolua_S,2,0));
  float max = ((float)  tolua_tonumber(tolua_S,3,0));
 {
  BoundingBox* tolua_ret = (BoundingBox*)  Mtolua_new((BoundingBox)(min,max));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"BoundingBox");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_new03_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_new05
static int tolua_MathLuaAPI_BoundingBox_new05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Frustum",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Frustum* frustum = ((const Frustum*)  tolua_tousertype(tolua_S,2,0));
 {
  BoundingBox* tolua_ret = (BoundingBox*)  Mtolua_new((BoundingBox)(*frustum));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"BoundingBox");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_new04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_new05_local
static int tolua_MathLuaAPI_BoundingBox_new05_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Frustum",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Frustum* frustum = ((const Frustum*)  tolua_tousertype(tolua_S,2,0));
 {
  BoundingBox* tolua_ret = (BoundingBox*)  Mtolua_new((BoundingBox)(*frustum));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"BoundingBox");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_new04_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_new06
static int tolua_MathLuaAPI_BoundingBox_new06(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Polyhedron",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Polyhedron* poly = ((const Polyhedron*)  tolua_tousertype(tolua_S,2,0));
 {
  BoundingBox* tolua_ret = (BoundingBox*)  Mtolua_new((BoundingBox)(*poly));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"BoundingBox");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_new05(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_new06_local
static int tolua_MathLuaAPI_BoundingBox_new06_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Polyhedron",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Polyhedron* poly = ((const Polyhedron*)  tolua_tousertype(tolua_S,2,0));
 {
  BoundingBox* tolua_ret = (BoundingBox*)  Mtolua_new((BoundingBox)(*poly));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"BoundingBox");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_new05_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_new07
static int tolua_MathLuaAPI_BoundingBox_new07(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Sphere",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Sphere* sphere = ((const Sphere*)  tolua_tousertype(tolua_S,2,0));
 {
  BoundingBox* tolua_ret = (BoundingBox*)  Mtolua_new((BoundingBox)(*sphere));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"BoundingBox");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_new06(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_new07_local
static int tolua_MathLuaAPI_BoundingBox_new07_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Sphere",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Sphere* sphere = ((const Sphere*)  tolua_tousertype(tolua_S,2,0));
 {
  BoundingBox* tolua_ret = (BoundingBox*)  Mtolua_new((BoundingBox)(*sphere));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"BoundingBox");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_new06_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_delete00
static int tolua_MathLuaAPI_BoundingBox_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  BoundingBox* self = (BoundingBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
 Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox__eq00
static int tolua_MathLuaAPI_BoundingBox__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const BoundingBox* self = (const BoundingBox*)  tolua_tousertype(tolua_S,1,0);
  const BoundingBox* rhs = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->operator==(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_Define00
static int tolua_MathLuaAPI_BoundingBox_Define00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  BoundingBox* self = (BoundingBox*)  tolua_tousertype(tolua_S,1,0);
  const BoundingBox* box = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(*box);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Define'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_Define01
static int tolua_MathLuaAPI_BoundingBox_Define01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  BoundingBox* self = (BoundingBox*)  tolua_tousertype(tolua_S,1,0);
  const Rect* rect = ((const Rect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(*rect);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_Define00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_Define02
static int tolua_MathLuaAPI_BoundingBox_Define02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  BoundingBox* self = (BoundingBox*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* min = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* max = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(*min,*max);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_Define01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_Define03
static int tolua_MathLuaAPI_BoundingBox_Define03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  BoundingBox* self = (BoundingBox*)  tolua_tousertype(tolua_S,1,0);
  float min = ((float)  tolua_tonumber(tolua_S,2,0));
  float max = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(min,max);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_Define02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_Define04
static int tolua_MathLuaAPI_BoundingBox_Define04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  BoundingBox* self = (BoundingBox*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(*point);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_Define03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_Define05
static int tolua_MathLuaAPI_BoundingBox_Define05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Frustum",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  BoundingBox* self = (BoundingBox*)  tolua_tousertype(tolua_S,1,0);
  const Frustum* frustum = ((const Frustum*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(*frustum);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_Define04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_Define06
static int tolua_MathLuaAPI_BoundingBox_Define06(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Polyhedron",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  BoundingBox* self = (BoundingBox*)  tolua_tousertype(tolua_S,1,0);
  const Polyhedron* poly = ((const Polyhedron*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(*poly);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_Define05(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_Define07
static int tolua_MathLuaAPI_BoundingBox_Define07(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Sphere",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  BoundingBox* self = (BoundingBox*)  tolua_tousertype(tolua_S,1,0);
  const Sphere* sphere = ((const Sphere*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(*sphere);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_Define06(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Merge of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_Merge00
static int tolua_MathLuaAPI_BoundingBox_Merge00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  BoundingBox* self = (BoundingBox*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Merge'", NULL);
#endif
 {
  self->Merge(*point);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Merge'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Merge of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_Merge01
static int tolua_MathLuaAPI_BoundingBox_Merge01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  BoundingBox* self = (BoundingBox*)  tolua_tousertype(tolua_S,1,0);
  const BoundingBox* box = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Merge'", NULL);
#endif
 {
  self->Merge(*box);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_Merge00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Merge of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_Merge02
static int tolua_MathLuaAPI_BoundingBox_Merge02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Frustum",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  BoundingBox* self = (BoundingBox*)  tolua_tousertype(tolua_S,1,0);
  const Frustum* frustum = ((const Frustum*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Merge'", NULL);
#endif
 {
  self->Merge(*frustum);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_Merge01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Merge of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_Merge03
static int tolua_MathLuaAPI_BoundingBox_Merge03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Polyhedron",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  BoundingBox* self = (BoundingBox*)  tolua_tousertype(tolua_S,1,0);
  const Polyhedron* poly = ((const Polyhedron*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Merge'", NULL);
#endif
 {
  self->Merge(*poly);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_Merge02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Merge of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_Merge04
static int tolua_MathLuaAPI_BoundingBox_Merge04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Sphere",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  BoundingBox* self = (BoundingBox*)  tolua_tousertype(tolua_S,1,0);
  const Sphere* sphere = ((const Sphere*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Merge'", NULL);
#endif
 {
  self->Merge(*sphere);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_Merge03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clip of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_Clip00
static int tolua_MathLuaAPI_BoundingBox_Clip00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  BoundingBox* self = (BoundingBox*)  tolua_tousertype(tolua_S,1,0);
  const BoundingBox* box = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clip'", NULL);
#endif
 {
  self->Clip(*box);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Transform of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_Transform00
static int tolua_MathLuaAPI_BoundingBox_Transform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  BoundingBox* self = (BoundingBox*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3* transform = ((const Matrix3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Transform'", NULL);
#endif
 {
  self->Transform(*transform);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Transform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Transform of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_Transform01
static int tolua_MathLuaAPI_BoundingBox_Transform01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3x4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  BoundingBox* self = (BoundingBox*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3x4* transform = ((const Matrix3x4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Transform'", NULL);
#endif
 {
  self->Transform(*transform);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_Transform00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_Clear00
static int tolua_MathLuaAPI_BoundingBox_Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BoundingBox",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  BoundingBox* self = (BoundingBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'", NULL);
#endif
 {
  self->Clear();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Defined of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_Defined00
static int tolua_MathLuaAPI_BoundingBox_Defined00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const BoundingBox",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const BoundingBox* self = (const BoundingBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Defined'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Defined();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Defined'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Center of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_Center00
static int tolua_MathLuaAPI_BoundingBox_Center00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const BoundingBox",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const BoundingBox* self = (const BoundingBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Center'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->Center();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Center'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Size of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_Size00
static int tolua_MathLuaAPI_BoundingBox_Size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const BoundingBox",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const BoundingBox* self = (const BoundingBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Size'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->Size();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: HalfSize of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_HalfSize00
static int tolua_MathLuaAPI_BoundingBox_HalfSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const BoundingBox",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const BoundingBox* self = (const BoundingBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HalfSize'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->HalfSize();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HalfSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Transformed of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_Transformed00
static int tolua_MathLuaAPI_BoundingBox_Transformed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const BoundingBox* self = (const BoundingBox*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3* transform = ((const Matrix3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Transformed'", NULL);
#endif
 {
  BoundingBox tolua_ret = (BoundingBox)  self->Transformed(*transform);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((BoundingBox)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"BoundingBox");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(BoundingBox));
  tolua_pushusertype(tolua_S,tolua_obj,"BoundingBox");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Transformed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Transformed of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_Transformed01
static int tolua_MathLuaAPI_BoundingBox_Transformed01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3x4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const BoundingBox* self = (const BoundingBox*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3x4* transform = ((const Matrix3x4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Transformed'", NULL);
#endif
 {
  BoundingBox tolua_ret = (BoundingBox)  self->Transformed(*transform);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((BoundingBox)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"BoundingBox");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(BoundingBox));
  tolua_pushusertype(tolua_S,tolua_obj,"BoundingBox");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_Transformed00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Projected of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_Projected00
static int tolua_MathLuaAPI_BoundingBox_Projected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const BoundingBox* self = (const BoundingBox*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* projection = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Projected'", NULL);
#endif
 {
  Rect tolua_ret = (Rect)  self->Projected(*projection);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Rect)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Rect");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Rect));
  tolua_pushusertype(tolua_S,tolua_obj,"Rect");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Projected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DistanceToPoint of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_DistanceToPoint00
static int tolua_MathLuaAPI_BoundingBox_DistanceToPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const BoundingBox* self = (const BoundingBox*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DistanceToPoint'", NULL);
#endif
 {
  float tolua_ret = (float)  self->DistanceToPoint(*point);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DistanceToPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsInside of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_IsInside00
static int tolua_MathLuaAPI_BoundingBox_IsInside00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const BoundingBox* self = (const BoundingBox*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsInside'", NULL);
#endif
 {
  Intersection tolua_ret = (Intersection)  self->IsInside(*point);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsInside'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsInside of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_IsInside01
static int tolua_MathLuaAPI_BoundingBox_IsInside01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const BoundingBox* self = (const BoundingBox*)  tolua_tousertype(tolua_S,1,0);
  const BoundingBox* box = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsInside'", NULL);
#endif
 {
  Intersection tolua_ret = (Intersection)  self->IsInside(*box);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_IsInside00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsInsideFast of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_IsInsideFast00
static int tolua_MathLuaAPI_BoundingBox_IsInsideFast00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const BoundingBox* self = (const BoundingBox*)  tolua_tousertype(tolua_S,1,0);
  const BoundingBox* box = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsInsideFast'", NULL);
#endif
 {
  Intersection tolua_ret = (Intersection)  self->IsInsideFast(*box);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsInsideFast'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsInside of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_IsInside02
static int tolua_MathLuaAPI_BoundingBox_IsInside02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Sphere",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const BoundingBox* self = (const BoundingBox*)  tolua_tousertype(tolua_S,1,0);
  const Sphere* sphere = ((const Sphere*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsInside'", NULL);
#endif
 {
  Intersection tolua_ret = (Intersection)  self->IsInside(*sphere);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_IsInside01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsInsideFast of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_IsInsideFast01
static int tolua_MathLuaAPI_BoundingBox_IsInsideFast01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const BoundingBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Sphere",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const BoundingBox* self = (const BoundingBox*)  tolua_tousertype(tolua_S,1,0);
  const Sphere* sphere = ((const Sphere*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsInsideFast'", NULL);
#endif
 {
  Intersection tolua_ret = (Intersection)  self->IsInsideFast(*sphere);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_BoundingBox_IsInsideFast00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToString of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_BoundingBox_ToString00
static int tolua_MathLuaAPI_BoundingBox_ToString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const BoundingBox",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const BoundingBox* self = (const BoundingBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToString'", NULL);
#endif
 {
  String tolua_ret = (String)  self->ToString();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: min_ of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_get_BoundingBox_min
static int tolua_get_BoundingBox_min(lua_State* tolua_S)
{
  BoundingBox* self = (BoundingBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'min_'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->min_,"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: min_ of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_set_BoundingBox_min
static int tolua_set_BoundingBox_min(lua_State* tolua_S)
{
  BoundingBox* self = (BoundingBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'min_'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->min_ = *((Vector3*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: max_ of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_get_BoundingBox_max
static int tolua_get_BoundingBox_max(lua_State* tolua_S)
{
  BoundingBox* self = (BoundingBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'max_'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->max_,"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: max_ of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_set_BoundingBox_max
static int tolua_set_BoundingBox_max(lua_State* tolua_S)
{
  BoundingBox* self = (BoundingBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'max_'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->max_ = *((Vector3*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: center of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_get_BoundingBox_center
static int tolua_get_BoundingBox_center(lua_State* tolua_S)
{
  BoundingBox* self = (BoundingBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'center'",NULL);
#endif
 Vector3 tolua_ret = (Vector3)self->Center();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((Vector3)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: size of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_get_BoundingBox_size
static int tolua_get_BoundingBox_size(lua_State* tolua_S)
{
  BoundingBox* self = (BoundingBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'size'",NULL);
#endif
 Vector3 tolua_ret = (Vector3)self->Size();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((Vector3)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: halfSize of class  BoundingBox */
#ifndef TOLUA_DISABLE_tolua_get_BoundingBox_halfSize
static int tolua_get_BoundingBox_halfSize(lua_State* tolua_S)
{
  BoundingBox* self = (BoundingBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'halfSize'",NULL);
#endif
 Vector3 tolua_ret = (Vector3)self->HalfSize();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((Vector3)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_new00
static int tolua_MathLuaAPI_Color_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Color",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Color* tolua_ret = (Color*)  Mtolua_new((Color)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Color");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_new00_local
static int tolua_MathLuaAPI_Color_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Color",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Color* tolua_ret = (Color*)  Mtolua_new((Color)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Color");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_new01
static int tolua_MathLuaAPI_Color_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Color",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Color",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Color* color = ((const Color*)  tolua_tousertype(tolua_S,2,0));
 {
  Color* tolua_ret = (Color*)  Mtolua_new((Color)(*color));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Color");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Color_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_new01_local
static int tolua_MathLuaAPI_Color_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Color",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Color",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Color* color = ((const Color*)  tolua_tousertype(tolua_S,2,0));
 {
  Color* tolua_ret = (Color*)  Mtolua_new((Color)(*color));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Color");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Color_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_new02
static int tolua_MathLuaAPI_Color_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Color",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Color",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Color* color = ((const Color*)  tolua_tousertype(tolua_S,2,0));
  float a = ((float)  tolua_tonumber(tolua_S,3,0));
 {
  Color* tolua_ret = (Color*)  Mtolua_new((Color)(*color,a));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Color");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Color_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_new02_local
static int tolua_MathLuaAPI_Color_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Color",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Color",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Color* color = ((const Color*)  tolua_tousertype(tolua_S,2,0));
  float a = ((float)  tolua_tonumber(tolua_S,3,0));
 {
  Color* tolua_ret = (Color*)  Mtolua_new((Color)(*color,a));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Color");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Color_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_new03
static int tolua_MathLuaAPI_Color_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Color",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
  float g = ((float)  tolua_tonumber(tolua_S,3,0));
  float b = ((float)  tolua_tonumber(tolua_S,4,0));
 {
  Color* tolua_ret = (Color*)  Mtolua_new((Color)(r,g,b));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Color");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Color_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_new03_local
static int tolua_MathLuaAPI_Color_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Color",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
  float g = ((float)  tolua_tonumber(tolua_S,3,0));
  float b = ((float)  tolua_tonumber(tolua_S,4,0));
 {
  Color* tolua_ret = (Color*)  Mtolua_new((Color)(r,g,b));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Color");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Color_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_new04
static int tolua_MathLuaAPI_Color_new04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Color",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
  float g = ((float)  tolua_tonumber(tolua_S,3,0));
  float b = ((float)  tolua_tonumber(tolua_S,4,0));
  float a = ((float)  tolua_tonumber(tolua_S,5,0));
 {
  Color* tolua_ret = (Color*)  Mtolua_new((Color)(r,g,b,a));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Color");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Color_new03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_new04_local
static int tolua_MathLuaAPI_Color_new04_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Color",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
  float g = ((float)  tolua_tonumber(tolua_S,3,0));
  float b = ((float)  tolua_tonumber(tolua_S,4,0));
  float a = ((float)  tolua_tonumber(tolua_S,5,0));
 {
  Color* tolua_ret = (Color*)  Mtolua_new((Color)(r,g,b,a));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Color");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Color_new03_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_delete00
static int tolua_MathLuaAPI_Color_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Color",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
 Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color__eq00
static int tolua_MathLuaAPI_Color__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Color",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Color",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Color* self = (const Color*)  tolua_tousertype(tolua_S,1,0);
  const Color* rhs = ((const Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->operator==(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color__mul00
static int tolua_MathLuaAPI_Color__mul00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Color",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Color* self = (const Color*)  tolua_tousertype(tolua_S,1,0);
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
 {
  Color tolua_ret = (Color)  self->operator*(rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Color)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Color");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Color));
  tolua_pushusertype(tolua_S,tolua_obj,"Color");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color__add00
static int tolua_MathLuaAPI_Color__add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Color",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Color",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
  const Color* rhs = ((const Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
 {
  Color tolua_ret = (Color)  self->operator+(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Color)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Color");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Color));
  tolua_pushusertype(tolua_S,tolua_obj,"Color");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToUInt of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_ToUInt00
static int tolua_MathLuaAPI_Color_ToUInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Color",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Color* self = (const Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToUInt'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->ToUInt();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToUInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToHSL of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_ToHSL00
static int tolua_MathLuaAPI_Color_ToHSL00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Color",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Color* self = (const Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToHSL'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->ToHSL();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToHSL'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToHSV of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_ToHSV00
static int tolua_MathLuaAPI_Color_ToHSV00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Color",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Color* self = (const Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToHSV'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->ToHSV();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToHSV'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FromUInt of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_FromUInt00
static int tolua_MathLuaAPI_Color_FromUInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Color",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
  unsigned color = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FromUInt'", NULL);
#endif
 {
  self->FromUInt(color);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FromUInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FromHSL of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_FromHSL00
static int tolua_MathLuaAPI_Color_FromHSL00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Color",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
  float h = ((float)  tolua_tonumber(tolua_S,2,0));
  float s = ((float)  tolua_tonumber(tolua_S,3,0));
  float l = ((float)  tolua_tonumber(tolua_S,4,0));
  float a = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FromHSL'", NULL);
#endif
 {
  self->FromHSL(h,s,l,a);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FromHSL'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FromHSV of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_FromHSV00
static int tolua_MathLuaAPI_Color_FromHSV00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Color",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
  float h = ((float)  tolua_tonumber(tolua_S,2,0));
  float s = ((float)  tolua_tonumber(tolua_S,3,0));
  float v = ((float)  tolua_tonumber(tolua_S,4,0));
  float a = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FromHSV'", NULL);
#endif
 {
  self->FromHSV(h,s,v,a);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FromHSV'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToVector3 of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_ToVector300
static int tolua_MathLuaAPI_Color_ToVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Color",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Color* self = (const Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToVector3'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->ToVector3();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToVector4 of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_ToVector400
static int tolua_MathLuaAPI_Color_ToVector400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Color",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Color* self = (const Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToVector4'", NULL);
#endif
 {
  Vector4 tolua_ret = (Vector4)  self->ToVector4();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToVector4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SumRGB of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_SumRGB00
static int tolua_MathLuaAPI_Color_SumRGB00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Color",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Color* self = (const Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SumRGB'", NULL);
#endif
 {
  float tolua_ret = (float)  self->SumRGB();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SumRGB'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Average of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_Average00
static int tolua_MathLuaAPI_Color_Average00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Color",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Color* self = (const Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Average'", NULL);
#endif
 {
  float tolua_ret = (float)  self->Average();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Average'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Luma of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_Luma00
static int tolua_MathLuaAPI_Color_Luma00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Color",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Color* self = (const Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Luma'", NULL);
#endif
 {
  float tolua_ret = (float)  self->Luma();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Luma'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Chroma of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_Chroma00
static int tolua_MathLuaAPI_Color_Chroma00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Color",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Color* self = (const Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Chroma'", NULL);
#endif
 {
  float tolua_ret = (float)  self->Chroma();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Chroma'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Hue of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_Hue00
static int tolua_MathLuaAPI_Color_Hue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Color",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Color* self = (const Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Hue'", NULL);
#endif
 {
  float tolua_ret = (float)  self->Hue();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Hue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SaturationHSL of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_SaturationHSL00
static int tolua_MathLuaAPI_Color_SaturationHSL00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Color",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Color* self = (const Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SaturationHSL'", NULL);
#endif
 {
  float tolua_ret = (float)  self->SaturationHSL();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SaturationHSL'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SaturationHSV of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_SaturationHSV00
static int tolua_MathLuaAPI_Color_SaturationHSV00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Color",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Color* self = (const Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SaturationHSV'", NULL);
#endif
 {
  float tolua_ret = (float)  self->SaturationHSV();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SaturationHSV'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Value of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_Value00
static int tolua_MathLuaAPI_Color_Value00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Color",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Color* self = (const Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Value'", NULL);
#endif
 {
  float tolua_ret = (float)  self->Value();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Value'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Lightness of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_Lightness00
static int tolua_MathLuaAPI_Color_Lightness00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Color",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Color* self = (const Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Lightness'", NULL);
#endif
 {
  float tolua_ret = (float)  self->Lightness();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Lightness'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: MaxRGB of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_MaxRGB00
static int tolua_MathLuaAPI_Color_MaxRGB00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Color",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Color* self = (const Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'MaxRGB'", NULL);
#endif
 {
  float tolua_ret = (float)  self->MaxRGB();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MaxRGB'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: MinRGB of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_MinRGB00
static int tolua_MathLuaAPI_Color_MinRGB00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Color",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Color* self = (const Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'MinRGB'", NULL);
#endif
 {
  float tolua_ret = (float)  self->MinRGB();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MinRGB'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Range of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_Range00
static int tolua_MathLuaAPI_Color_Range00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Color",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Color* self = (const Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Range'", NULL);
#endif
 {
  float tolua_ret = (float)  self->Range();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Range'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clip of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_Clip00
static int tolua_MathLuaAPI_Color_Clip00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Color",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
  bool clipAlpha = ((bool)  tolua_toboolean(tolua_S,2,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clip'", NULL);
#endif
 {
  self->Clip(clipAlpha);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Invert of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_Invert00
static int tolua_MathLuaAPI_Color_Invert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Color",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
  bool invertAlpha = ((bool)  tolua_toboolean(tolua_S,2,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Invert'", NULL);
#endif
 {
  self->Invert(invertAlpha);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Invert'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Lerp of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_Lerp00
static int tolua_MathLuaAPI_Color_Lerp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Color",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Color",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Color* self = (const Color*)  tolua_tousertype(tolua_S,1,0);
  const Color* rhs = ((const Color*)  tolua_tousertype(tolua_S,2,0));
  float t = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Lerp'", NULL);
#endif
 {
  Color tolua_ret = (Color)  self->Lerp(*rhs,t);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Color)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Color");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Color));
  tolua_pushusertype(tolua_S,tolua_obj,"Color");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Lerp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Abs of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_Abs00
static int tolua_MathLuaAPI_Color_Abs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Color",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Color* self = (const Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Abs'", NULL);
#endif
 {
  Color tolua_ret = (Color)  self->Abs();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Color)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Color");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Color));
  tolua_pushusertype(tolua_S,tolua_obj,"Color");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Abs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Equals of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_Equals00
static int tolua_MathLuaAPI_Color_Equals00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Color",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Color",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Color* self = (const Color*)  tolua_tousertype(tolua_S,1,0);
  const Color* rhs = ((const Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Equals'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Equals(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Equals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToString of class  Color */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Color_ToString00
static int tolua_MathLuaAPI_Color_ToString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Color",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Color* self = (const Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToString'", NULL);
#endif
 {
  String tolua_ret = (String)  self->ToString();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: r_ of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_r
static int tolua_get_Color_r(lua_State* tolua_S)
{
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'r_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->r_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: r_ of class  Color */
#ifndef TOLUA_DISABLE_tolua_set_Color_r
static int tolua_set_Color_r(lua_State* tolua_S)
{
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'r_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->r_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: g_ of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_g
static int tolua_get_Color_g(lua_State* tolua_S)
{
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'g_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->g_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: g_ of class  Color */
#ifndef TOLUA_DISABLE_tolua_set_Color_g
static int tolua_set_Color_g(lua_State* tolua_S)
{
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'g_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->g_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: b_ of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_b
static int tolua_get_Color_b(lua_State* tolua_S)
{
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'b_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->b_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: b_ of class  Color */
#ifndef TOLUA_DISABLE_tolua_set_Color_b
static int tolua_set_Color_b(lua_State* tolua_S)
{
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'b_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->b_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: a_ of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_a
static int tolua_get_Color_a(lua_State* tolua_S)
{
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'a_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->a_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: a_ of class  Color */
#ifndef TOLUA_DISABLE_tolua_set_Color_a
static int tolua_set_Color_a(lua_State* tolua_S)
{
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'a_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->a_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WHITE of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_WHITE
static int tolua_get_Color_WHITE(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Color::WHITE,"const Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: GRAY of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_GRAY
static int tolua_get_Color_GRAY(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Color::GRAY,"const Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: BLACK of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_BLACK
static int tolua_get_Color_BLACK(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Color::BLACK,"const Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: RED of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_RED
static int tolua_get_Color_RED(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Color::RED,"const Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: GREEN of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_GREEN
static int tolua_get_Color_GREEN(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Color::GREEN,"const Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: BLUE of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_BLUE
static int tolua_get_Color_BLUE(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Color::BLUE,"const Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CYAN of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_CYAN
static int tolua_get_Color_CYAN(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Color::CYAN,"const Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MAGENTA of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_MAGENTA
static int tolua_get_Color_MAGENTA(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Color::MAGENTA,"const Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: YELLOW of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_YELLOW
static int tolua_get_Color_YELLOW(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Color::YELLOW,"const Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: TRANSPARENT_BLACK of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_TRANSPARENT_BLACK
static int tolua_get_Color_TRANSPARENT_BLACK(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Color::TRANSPARENT_BLACK,"const Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: NUM_FRUSTUM_PLANES */
#ifndef TOLUA_DISABLE_tolua_get_NUM_FRUSTUM_PLANES
static int tolua_get_NUM_FRUSTUM_PLANES(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)NUM_FRUSTUM_PLANES);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: NUM_FRUSTUM_VERTICES */
#ifndef TOLUA_DISABLE_tolua_get_NUM_FRUSTUM_VERTICES
static int tolua_get_NUM_FRUSTUM_VERTICES(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)NUM_FRUSTUM_VERTICES);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Frustum */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Frustum_new00
static int tolua_MathLuaAPI_Frustum_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Frustum",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Frustum* tolua_ret = (Frustum*)  Mtolua_new((Frustum)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Frustum");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Frustum */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Frustum_new00_local
static int tolua_MathLuaAPI_Frustum_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Frustum",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Frustum* tolua_ret = (Frustum*)  Mtolua_new((Frustum)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Frustum");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Frustum */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Frustum_new01
static int tolua_MathLuaAPI_Frustum_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Frustum",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Frustum",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Frustum* frustum = ((const Frustum*)  tolua_tousertype(tolua_S,2,0));
 {
  Frustum* tolua_ret = (Frustum*)  Mtolua_new((Frustum)(*frustum));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Frustum");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Frustum_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Frustum */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Frustum_new01_local
static int tolua_MathLuaAPI_Frustum_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Frustum",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Frustum",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Frustum* frustum = ((const Frustum*)  tolua_tousertype(tolua_S,2,0));
 {
  Frustum* tolua_ret = (Frustum*)  Mtolua_new((Frustum)(*frustum));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Frustum");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Frustum_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Frustum */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Frustum_delete00
static int tolua_MathLuaAPI_Frustum_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Frustum",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Frustum* self = (Frustum*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
 Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  Frustum */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Frustum_Define00
static int tolua_MathLuaAPI_Frustum_Define00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Frustum",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Frustum* self = (Frustum*)  tolua_tousertype(tolua_S,1,0);
  float fov = ((float)  tolua_tonumber(tolua_S,2,0));
  float aspectRatio = ((float)  tolua_tonumber(tolua_S,3,0));
  float zoom = ((float)  tolua_tonumber(tolua_S,4,0));
  float nearZ = ((float)  tolua_tonumber(tolua_S,5,0));
  float farZ = ((float)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(fov,aspectRatio,zoom,nearZ,farZ);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Define'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  Frustum */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Frustum_Define01
static int tolua_MathLuaAPI_Frustum_Define01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Frustum",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,7,&tolua_err) || !tolua_isusertype(tolua_S,7,"const Matrix3x4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Frustum* self = (Frustum*)  tolua_tousertype(tolua_S,1,0);
  float fov = ((float)  tolua_tonumber(tolua_S,2,0));
  float aspectRatio = ((float)  tolua_tonumber(tolua_S,3,0));
  float zoom = ((float)  tolua_tonumber(tolua_S,4,0));
  float nearZ = ((float)  tolua_tonumber(tolua_S,5,0));
  float farZ = ((float)  tolua_tonumber(tolua_S,6,0));
  const Matrix3x4* transform = ((const Matrix3x4*)  tolua_tousertype(tolua_S,7,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(fov,aspectRatio,zoom,nearZ,farZ,*transform);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Frustum_Define00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  Frustum */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Frustum_Define02
static int tolua_MathLuaAPI_Frustum_Define02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Frustum",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Frustum* self = (Frustum*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* near = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* far = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(*near,*far);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Frustum_Define01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  Frustum */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Frustum_Define03
static int tolua_MathLuaAPI_Frustum_Define03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Frustum",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Matrix3x4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Frustum* self = (Frustum*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* near = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* far = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Matrix3x4* transform = ((const Matrix3x4*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(*near,*far,*transform);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Frustum_Define02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  Frustum */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Frustum_Define04
static int tolua_MathLuaAPI_Frustum_Define04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Frustum",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Frustum* self = (Frustum*)  tolua_tousertype(tolua_S,1,0);
  const BoundingBox* box = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(*box);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Frustum_Define03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  Frustum */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Frustum_Define05
static int tolua_MathLuaAPI_Frustum_Define05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Frustum",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Matrix3x4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Frustum* self = (Frustum*)  tolua_tousertype(tolua_S,1,0);
  const BoundingBox* box = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
  const Matrix3x4* transform = ((const Matrix3x4*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(*box,*transform);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Frustum_Define04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  Frustum */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Frustum_Define06
static int tolua_MathLuaAPI_Frustum_Define06(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Frustum",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Frustum* self = (Frustum*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* projection = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(*projection);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Frustum_Define05(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: DefineOrtho of class  Frustum */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Frustum_DefineOrtho00
static int tolua_MathLuaAPI_Frustum_DefineOrtho00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Frustum",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Frustum* self = (Frustum*)  tolua_tousertype(tolua_S,1,0);
  float orthoSize = ((float)  tolua_tonumber(tolua_S,2,0));
  float aspectRatio = ((float)  tolua_tonumber(tolua_S,3,0));
  float zoom = ((float)  tolua_tonumber(tolua_S,4,0));
  float nearZ = ((float)  tolua_tonumber(tolua_S,5,0));
  float farZ = ((float)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DefineOrtho'", NULL);
#endif
 {
  self->DefineOrtho(orthoSize,aspectRatio,zoom,nearZ,farZ);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DefineOrtho'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DefineOrtho of class  Frustum */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Frustum_DefineOrtho01
static int tolua_MathLuaAPI_Frustum_DefineOrtho01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Frustum",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,7,&tolua_err) || !tolua_isusertype(tolua_S,7,"const Matrix3x4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Frustum* self = (Frustum*)  tolua_tousertype(tolua_S,1,0);
  float orthoSize = ((float)  tolua_tonumber(tolua_S,2,0));
  float aspectRatio = ((float)  tolua_tonumber(tolua_S,3,0));
  float zoom = ((float)  tolua_tonumber(tolua_S,4,0));
  float nearZ = ((float)  tolua_tonumber(tolua_S,5,0));
  float farZ = ((float)  tolua_tonumber(tolua_S,6,0));
  const Matrix3x4* transform = ((const Matrix3x4*)  tolua_tousertype(tolua_S,7,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DefineOrtho'", NULL);
#endif
 {
  self->DefineOrtho(orthoSize,aspectRatio,zoom,nearZ,farZ,*transform);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Frustum_DefineOrtho00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: DefineSplit of class  Frustum */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Frustum_DefineSplit00
static int tolua_MathLuaAPI_Frustum_DefineSplit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Frustum",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Frustum* self = (Frustum*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* projection = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
  float near = ((float)  tolua_tonumber(tolua_S,3,0));
  float far = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DefineSplit'", NULL);
#endif
 {
  self->DefineSplit(*projection,near,far);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DefineSplit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Transform of class  Frustum */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Frustum_Transform00
static int tolua_MathLuaAPI_Frustum_Transform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Frustum",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Frustum* self = (Frustum*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3* transform = ((const Matrix3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Transform'", NULL);
#endif
 {
  self->Transform(*transform);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Transform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Transform of class  Frustum */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Frustum_Transform01
static int tolua_MathLuaAPI_Frustum_Transform01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Frustum",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3x4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Frustum* self = (Frustum*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3x4* transform = ((const Matrix3x4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Transform'", NULL);
#endif
 {
  self->Transform(*transform);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Frustum_Transform00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsInside of class  Frustum */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Frustum_IsInside00
static int tolua_MathLuaAPI_Frustum_IsInside00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Frustum",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Frustum* self = (const Frustum*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsInside'", NULL);
#endif
 {
  Intersection tolua_ret = (Intersection)  self->IsInside(*point);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsInside'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsInside of class  Frustum */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Frustum_IsInside01
static int tolua_MathLuaAPI_Frustum_IsInside01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Frustum",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Sphere",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Frustum* self = (const Frustum*)  tolua_tousertype(tolua_S,1,0);
  const Sphere* sphere = ((const Sphere*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsInside'", NULL);
#endif
 {
  Intersection tolua_ret = (Intersection)  self->IsInside(*sphere);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Frustum_IsInside00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsInsideFast of class  Frustum */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Frustum_IsInsideFast00
static int tolua_MathLuaAPI_Frustum_IsInsideFast00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Frustum",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Sphere",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Frustum* self = (const Frustum*)  tolua_tousertype(tolua_S,1,0);
  const Sphere* sphere = ((const Sphere*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsInsideFast'", NULL);
#endif
 {
  Intersection tolua_ret = (Intersection)  self->IsInsideFast(*sphere);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsInsideFast'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsInside of class  Frustum */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Frustum_IsInside02
static int tolua_MathLuaAPI_Frustum_IsInside02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Frustum",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Frustum* self = (const Frustum*)  tolua_tousertype(tolua_S,1,0);
  const BoundingBox* box = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsInside'", NULL);
#endif
 {
  Intersection tolua_ret = (Intersection)  self->IsInside(*box);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Frustum_IsInside01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsInsideFast of class  Frustum */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Frustum_IsInsideFast01
static int tolua_MathLuaAPI_Frustum_IsInsideFast01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Frustum",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Frustum* self = (const Frustum*)  tolua_tousertype(tolua_S,1,0);
  const BoundingBox* box = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsInsideFast'", NULL);
#endif
 {
  Intersection tolua_ret = (Intersection)  self->IsInsideFast(*box);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Frustum_IsInsideFast00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Distance of class  Frustum */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Frustum_Distance00
static int tolua_MathLuaAPI_Frustum_Distance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Frustum",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Frustum* self = (const Frustum*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Distance'", NULL);
#endif
 {
  float tolua_ret = (float)  self->Distance(*point);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Distance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Transformed of class  Frustum */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Frustum_Transformed00
static int tolua_MathLuaAPI_Frustum_Transformed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Frustum",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Frustum* self = (const Frustum*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3* transform = ((const Matrix3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Transformed'", NULL);
#endif
 {
  Frustum tolua_ret = (Frustum)  self->Transformed(*transform);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Frustum)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Frustum");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Frustum));
  tolua_pushusertype(tolua_S,tolua_obj,"Frustum");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Transformed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Transformed of class  Frustum */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Frustum_Transformed01
static int tolua_MathLuaAPI_Frustum_Transformed01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Frustum",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3x4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Frustum* self = (const Frustum*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3x4* transform = ((const Matrix3x4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Transformed'", NULL);
#endif
 {
  Frustum tolua_ret = (Frustum)  self->Transformed(*transform);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Frustum)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Frustum");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Frustum));
  tolua_pushusertype(tolua_S,tolua_obj,"Frustum");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Frustum_Transformed00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Projected of class  Frustum */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Frustum_Projected00
static int tolua_MathLuaAPI_Frustum_Projected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Frustum",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Frustum* self = (const Frustum*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* transform = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Projected'", NULL);
#endif
 {
  Rect tolua_ret = (Rect)  self->Projected(*transform);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Rect)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Rect");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Rect));
  tolua_pushusertype(tolua_S,tolua_obj,"Rect");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Projected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: UpdatePlanes of class  Frustum */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Frustum_UpdatePlanes00
static int tolua_MathLuaAPI_Frustum_UpdatePlanes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Frustum",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Frustum* self = (Frustum*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UpdatePlanes'", NULL);
#endif
 {
  self->UpdatePlanes();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UpdatePlanes'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3_new00
static int tolua_MathLuaAPI_Matrix3_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Matrix3",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Matrix3* tolua_ret = (Matrix3*)  Mtolua_new((Matrix3)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix3");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3_new00_local
static int tolua_MathLuaAPI_Matrix3_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Matrix3",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Matrix3* tolua_ret = (Matrix3*)  Mtolua_new((Matrix3)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3_new01
static int tolua_MathLuaAPI_Matrix3_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Matrix3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Matrix3* matrix = ((const Matrix3*)  tolua_tousertype(tolua_S,2,0));
 {
  Matrix3* tolua_ret = (Matrix3*)  Mtolua_new((Matrix3)(*matrix));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix3");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix3_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3_new01_local
static int tolua_MathLuaAPI_Matrix3_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Matrix3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Matrix3* matrix = ((const Matrix3*)  tolua_tousertype(tolua_S,2,0));
 {
  Matrix3* tolua_ret = (Matrix3*)  Mtolua_new((Matrix3)(*matrix));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix3_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3_new02
static int tolua_MathLuaAPI_Matrix3_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Matrix3",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,10,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,11,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float v00 = ((float)  tolua_tonumber(tolua_S,2,0));
  float v01 = ((float)  tolua_tonumber(tolua_S,3,0));
  float v02 = ((float)  tolua_tonumber(tolua_S,4,0));
  float v10 = ((float)  tolua_tonumber(tolua_S,5,0));
  float v11 = ((float)  tolua_tonumber(tolua_S,6,0));
  float v12 = ((float)  tolua_tonumber(tolua_S,7,0));
  float v20 = ((float)  tolua_tonumber(tolua_S,8,0));
  float v21 = ((float)  tolua_tonumber(tolua_S,9,0));
  float v22 = ((float)  tolua_tonumber(tolua_S,10,0));
 {
  Matrix3* tolua_ret = (Matrix3*)  Mtolua_new((Matrix3)(v00,v01,v02,v10,v11,v12,v20,v21,v22));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix3");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix3_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3_new02_local
static int tolua_MathLuaAPI_Matrix3_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Matrix3",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,10,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,11,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float v00 = ((float)  tolua_tonumber(tolua_S,2,0));
  float v01 = ((float)  tolua_tonumber(tolua_S,3,0));
  float v02 = ((float)  tolua_tonumber(tolua_S,4,0));
  float v10 = ((float)  tolua_tonumber(tolua_S,5,0));
  float v11 = ((float)  tolua_tonumber(tolua_S,6,0));
  float v12 = ((float)  tolua_tonumber(tolua_S,7,0));
  float v20 = ((float)  tolua_tonumber(tolua_S,8,0));
  float v21 = ((float)  tolua_tonumber(tolua_S,9,0));
  float v22 = ((float)  tolua_tonumber(tolua_S,10,0));
 {
  Matrix3* tolua_ret = (Matrix3*)  Mtolua_new((Matrix3)(v00,v01,v02,v10,v11,v12,v20,v21,v22));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix3_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3_delete00
static int tolua_MathLuaAPI_Matrix3_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Matrix3",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Matrix3* self = (Matrix3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
 Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3__eq00
static int tolua_MathLuaAPI_Matrix3__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix3* self = (const Matrix3*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3* rhs = ((const Matrix3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->operator==(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3__mul00
static int tolua_MathLuaAPI_Matrix3__mul00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix3* self = (const Matrix3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* rhs = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->operator*(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3__add00
static int tolua_MathLuaAPI_Matrix3__add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix3* self = (const Matrix3*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3* rhs = ((const Matrix3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
 {
  Matrix3 tolua_ret = (Matrix3)  self->operator+(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix3));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3__sub00
static int tolua_MathLuaAPI_Matrix3__sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix3* self = (const Matrix3*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3* rhs = ((const Matrix3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
 {
  Matrix3 tolua_ret = (Matrix3)  self->operator-(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix3));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3__mul01
static int tolua_MathLuaAPI_Matrix3__mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Matrix3* self = (const Matrix3*)  tolua_tousertype(tolua_S,1,0);
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
 {
  Matrix3 tolua_ret = (Matrix3)  self->operator*(rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix3));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix3__mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3__mul02
static int tolua_MathLuaAPI_Matrix3__mul02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Matrix3* self = (const Matrix3*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3* rhs = ((const Matrix3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
 {
  Matrix3 tolua_ret = (Matrix3)  self->operator*(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix3));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix3__mul01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScale of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3_SetScale00
static int tolua_MathLuaAPI_Matrix3_SetScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Matrix3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Matrix3* self = (Matrix3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* scale = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScale'", NULL);
#endif
 {
  self->SetScale(*scale);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScale of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3_SetScale01
static int tolua_MathLuaAPI_Matrix3_SetScale01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Matrix3",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Matrix3* self = (Matrix3*)  tolua_tousertype(tolua_S,1,0);
  float scale = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScale'", NULL);
#endif
 {
  self->SetScale(scale);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix3_SetScale00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Scale of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3_Scale00
static int tolua_MathLuaAPI_Matrix3_Scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix3* self = (const Matrix3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Scale'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->Scale();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Transpose of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3_Transpose00
static int tolua_MathLuaAPI_Matrix3_Transpose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix3* self = (const Matrix3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Transpose'", NULL);
#endif
 {
  Matrix3 tolua_ret = (Matrix3)  self->Transpose();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix3));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Transpose'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Scaled of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3_Scaled00
static int tolua_MathLuaAPI_Matrix3_Scaled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix3* self = (const Matrix3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* scale = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Scaled'", NULL);
#endif
 {
  Matrix3 tolua_ret = (Matrix3)  self->Scaled(*scale);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix3));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Scaled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Equals of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3_Equals00
static int tolua_MathLuaAPI_Matrix3_Equals00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix3* self = (const Matrix3*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3* rhs = ((const Matrix3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Equals'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Equals(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Equals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Inverse of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3_Inverse00
static int tolua_MathLuaAPI_Matrix3_Inverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix3* self = (const Matrix3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Inverse'", NULL);
#endif
 {
  Matrix3 tolua_ret = (Matrix3)  self->Inverse();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix3));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Inverse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToString of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3_ToString00
static int tolua_MathLuaAPI_Matrix3_ToString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix3* self = (const Matrix3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToString'", NULL);
#endif
 {
  String tolua_ret = (String)  self->ToString();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m00_ of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix3_m00
static int tolua_get_Matrix3_m00(lua_State* tolua_S)
{
  Matrix3* self = (Matrix3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm00_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m00_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m00_ of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix3_m00
static int tolua_set_Matrix3_m00(lua_State* tolua_S)
{
  Matrix3* self = (Matrix3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm00_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m00_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m01_ of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix3_m01
static int tolua_get_Matrix3_m01(lua_State* tolua_S)
{
  Matrix3* self = (Matrix3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm01_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m01_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m01_ of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix3_m01
static int tolua_set_Matrix3_m01(lua_State* tolua_S)
{
  Matrix3* self = (Matrix3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm01_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m01_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m02_ of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix3_m02
static int tolua_get_Matrix3_m02(lua_State* tolua_S)
{
  Matrix3* self = (Matrix3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm02_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m02_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m02_ of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix3_m02
static int tolua_set_Matrix3_m02(lua_State* tolua_S)
{
  Matrix3* self = (Matrix3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm02_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m02_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m10_ of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix3_m10
static int tolua_get_Matrix3_m10(lua_State* tolua_S)
{
  Matrix3* self = (Matrix3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm10_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m10_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m10_ of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix3_m10
static int tolua_set_Matrix3_m10(lua_State* tolua_S)
{
  Matrix3* self = (Matrix3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm10_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m10_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m11_ of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix3_m11
static int tolua_get_Matrix3_m11(lua_State* tolua_S)
{
  Matrix3* self = (Matrix3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm11_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m11_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m11_ of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix3_m11
static int tolua_set_Matrix3_m11(lua_State* tolua_S)
{
  Matrix3* self = (Matrix3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm11_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m11_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m12_ of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix3_m12
static int tolua_get_Matrix3_m12(lua_State* tolua_S)
{
  Matrix3* self = (Matrix3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm12_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m12_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m12_ of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix3_m12
static int tolua_set_Matrix3_m12(lua_State* tolua_S)
{
  Matrix3* self = (Matrix3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm12_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m12_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m20_ of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix3_m20
static int tolua_get_Matrix3_m20(lua_State* tolua_S)
{
  Matrix3* self = (Matrix3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm20_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m20_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m20_ of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix3_m20
static int tolua_set_Matrix3_m20(lua_State* tolua_S)
{
  Matrix3* self = (Matrix3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm20_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m20_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m21_ of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix3_m21
static int tolua_get_Matrix3_m21(lua_State* tolua_S)
{
  Matrix3* self = (Matrix3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm21_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m21_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m21_ of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix3_m21
static int tolua_set_Matrix3_m21(lua_State* tolua_S)
{
  Matrix3* self = (Matrix3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm21_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m21_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m22_ of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix3_m22
static int tolua_get_Matrix3_m22(lua_State* tolua_S)
{
  Matrix3* self = (Matrix3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm22_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m22_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m22_ of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix3_m22
static int tolua_set_Matrix3_m22(lua_State* tolua_S)
{
  Matrix3* self = (Matrix3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm22_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m22_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ZERO of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix3_ZERO
static int tolua_get_Matrix3_ZERO(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Matrix3::ZERO,"const Matrix3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: IDENTITY of class  Matrix3 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix3_IDENTITY
static int tolua_get_Matrix3_IDENTITY(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Matrix3::IDENTITY,"const Matrix3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_new00
static int tolua_MathLuaAPI_Matrix3x4_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Matrix3x4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Matrix3x4* tolua_ret = (Matrix3x4*)  Mtolua_new((Matrix3x4)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix3x4");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_new00_local
static int tolua_MathLuaAPI_Matrix3x4_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Matrix3x4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Matrix3x4* tolua_ret = (Matrix3x4*)  Mtolua_new((Matrix3x4)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix3x4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_new01
static int tolua_MathLuaAPI_Matrix3x4_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Matrix3x4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3x4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Matrix3x4* matrix = ((const Matrix3x4*)  tolua_tousertype(tolua_S,2,0));
 {
  Matrix3x4* tolua_ret = (Matrix3x4*)  Mtolua_new((Matrix3x4)(*matrix));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix3x4");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix3x4_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_new01_local
static int tolua_MathLuaAPI_Matrix3x4_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Matrix3x4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3x4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Matrix3x4* matrix = ((const Matrix3x4*)  tolua_tousertype(tolua_S,2,0));
 {
  Matrix3x4* tolua_ret = (Matrix3x4*)  Mtolua_new((Matrix3x4)(*matrix));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix3x4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix3x4_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_new02
static int tolua_MathLuaAPI_Matrix3x4_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Matrix3x4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Matrix3* matrix = ((const Matrix3*)  tolua_tousertype(tolua_S,2,0));
 {
  Matrix3x4* tolua_ret = (Matrix3x4*)  Mtolua_new((Matrix3x4)(*matrix));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix3x4");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix3x4_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_new02_local
static int tolua_MathLuaAPI_Matrix3x4_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Matrix3x4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Matrix3* matrix = ((const Matrix3*)  tolua_tousertype(tolua_S,2,0));
 {
  Matrix3x4* tolua_ret = (Matrix3x4*)  Mtolua_new((Matrix3x4)(*matrix));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix3x4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix3x4_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_new03
static int tolua_MathLuaAPI_Matrix3x4_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Matrix3x4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Matrix4* matrix = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
 {
  Matrix3x4* tolua_ret = (Matrix3x4*)  Mtolua_new((Matrix3x4)(*matrix));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix3x4");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix3x4_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_new03_local
static int tolua_MathLuaAPI_Matrix3x4_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Matrix3x4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Matrix4* matrix = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
 {
  Matrix3x4* tolua_ret = (Matrix3x4*)  Mtolua_new((Matrix3x4)(*matrix));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix3x4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix3x4_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_new04
static int tolua_MathLuaAPI_Matrix3x4_new04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Matrix3x4",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,10,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,11,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,12,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,13,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,14,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float v00 = ((float)  tolua_tonumber(tolua_S,2,0));
  float v01 = ((float)  tolua_tonumber(tolua_S,3,0));
  float v02 = ((float)  tolua_tonumber(tolua_S,4,0));
  float v03 = ((float)  tolua_tonumber(tolua_S,5,0));
  float v10 = ((float)  tolua_tonumber(tolua_S,6,0));
  float v11 = ((float)  tolua_tonumber(tolua_S,7,0));
  float v12 = ((float)  tolua_tonumber(tolua_S,8,0));
  float v13 = ((float)  tolua_tonumber(tolua_S,9,0));
  float v20 = ((float)  tolua_tonumber(tolua_S,10,0));
  float v21 = ((float)  tolua_tonumber(tolua_S,11,0));
  float v22 = ((float)  tolua_tonumber(tolua_S,12,0));
  float v23 = ((float)  tolua_tonumber(tolua_S,13,0));
 {
  Matrix3x4* tolua_ret = (Matrix3x4*)  Mtolua_new((Matrix3x4)(v00,v01,v02,v03,v10,v11,v12,v13,v20,v21,v22,v23));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix3x4");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix3x4_new03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_new04_local
static int tolua_MathLuaAPI_Matrix3x4_new04_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Matrix3x4",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,10,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,11,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,12,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,13,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,14,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float v00 = ((float)  tolua_tonumber(tolua_S,2,0));
  float v01 = ((float)  tolua_tonumber(tolua_S,3,0));
  float v02 = ((float)  tolua_tonumber(tolua_S,4,0));
  float v03 = ((float)  tolua_tonumber(tolua_S,5,0));
  float v10 = ((float)  tolua_tonumber(tolua_S,6,0));
  float v11 = ((float)  tolua_tonumber(tolua_S,7,0));
  float v12 = ((float)  tolua_tonumber(tolua_S,8,0));
  float v13 = ((float)  tolua_tonumber(tolua_S,9,0));
  float v20 = ((float)  tolua_tonumber(tolua_S,10,0));
  float v21 = ((float)  tolua_tonumber(tolua_S,11,0));
  float v22 = ((float)  tolua_tonumber(tolua_S,12,0));
  float v23 = ((float)  tolua_tonumber(tolua_S,13,0));
 {
  Matrix3x4* tolua_ret = (Matrix3x4*)  Mtolua_new((Matrix3x4)(v00,v01,v02,v03,v10,v11,v12,v13,v20,v21,v22,v23));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix3x4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix3x4_new03_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_new05
static int tolua_MathLuaAPI_Matrix3x4_new05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Matrix3x4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* translation = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
  float scale = ((float)  tolua_tonumber(tolua_S,4,0));
 {
  Matrix3x4* tolua_ret = (Matrix3x4*)  Mtolua_new((Matrix3x4)(*translation,*rotation,scale));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix3x4");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix3x4_new04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_new05_local
static int tolua_MathLuaAPI_Matrix3x4_new05_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Matrix3x4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* translation = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
  float scale = ((float)  tolua_tonumber(tolua_S,4,0));
 {
  Matrix3x4* tolua_ret = (Matrix3x4*)  Mtolua_new((Matrix3x4)(*translation,*rotation,scale));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix3x4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix3x4_new04_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_new06
static int tolua_MathLuaAPI_Matrix3x4_new06(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Matrix3x4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* translation = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* scale = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
 {
  Matrix3x4* tolua_ret = (Matrix3x4*)  Mtolua_new((Matrix3x4)(*translation,*rotation,*scale));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix3x4");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix3x4_new05(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_new06_local
static int tolua_MathLuaAPI_Matrix3x4_new06_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Matrix3x4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* translation = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* scale = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
 {
  Matrix3x4* tolua_ret = (Matrix3x4*)  Mtolua_new((Matrix3x4)(*translation,*rotation,*scale));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix3x4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix3x4_new05_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_delete00
static int tolua_MathLuaAPI_Matrix3x4_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Matrix3x4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
 Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4__eq00
static int tolua_MathLuaAPI_Matrix3x4__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3x4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3x4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix3x4* self = (const Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3x4* rhs = ((const Matrix3x4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->operator==(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4__mul00
static int tolua_MathLuaAPI_Matrix3x4__mul00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3x4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix3x4* self = (const Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* rhs = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->operator*(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4__mul01
static int tolua_MathLuaAPI_Matrix3x4__mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3x4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Matrix3x4* self = (const Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* rhs = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->operator*(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix3x4__mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4__add00
static int tolua_MathLuaAPI_Matrix3x4__add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3x4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3x4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix3x4* self = (const Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3x4* rhs = ((const Matrix3x4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
 {
  Matrix3x4 tolua_ret = (Matrix3x4)  self->operator+(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix3x4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3x4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix3x4));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3x4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4__sub00
static int tolua_MathLuaAPI_Matrix3x4__sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3x4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3x4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix3x4* self = (const Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3x4* rhs = ((const Matrix3x4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
 {
  Matrix3x4 tolua_ret = (Matrix3x4)  self->operator-(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix3x4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3x4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix3x4));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3x4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4__mul02
static int tolua_MathLuaAPI_Matrix3x4__mul02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3x4",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Matrix3x4* self = (const Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
 {
  Matrix3x4 tolua_ret = (Matrix3x4)  self->operator*(rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix3x4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3x4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix3x4));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3x4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix3x4__mul01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4__mul03
static int tolua_MathLuaAPI_Matrix3x4__mul03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3x4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3x4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Matrix3x4* self = (const Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3x4* rhs = ((const Matrix3x4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
 {
  Matrix3x4 tolua_ret = (Matrix3x4)  self->operator*(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix3x4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3x4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix3x4));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3x4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix3x4__mul02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4__mul04
static int tolua_MathLuaAPI_Matrix3x4__mul04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3x4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Matrix3x4* self = (const Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* rhs = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
 {
  Matrix4 tolua_ret = (Matrix4)  self->operator*(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix4));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix3x4__mul03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTranslation of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_SetTranslation00
static int tolua_MathLuaAPI_Matrix3x4_SetTranslation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Matrix3x4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* translation = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTranslation'", NULL);
#endif
 {
  self->SetTranslation(*translation);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTranslation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRotation of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_SetRotation00
static int tolua_MathLuaAPI_Matrix3x4_SetRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Matrix3x4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3* rotation = ((const Matrix3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRotation'", NULL);
#endif
 {
  self->SetRotation(*rotation);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScale of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_SetScale00
static int tolua_MathLuaAPI_Matrix3x4_SetScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Matrix3x4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* scale = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScale'", NULL);
#endif
 {
  self->SetScale(*scale);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScale of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_SetScale01
static int tolua_MathLuaAPI_Matrix3x4_SetScale01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Matrix3x4",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
  float scale = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScale'", NULL);
#endif
 {
  self->SetScale(scale);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix3x4_SetScale00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToMatrix3 of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_ToMatrix300
static int tolua_MathLuaAPI_Matrix3x4_ToMatrix300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3x4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix3x4* self = (const Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToMatrix3'", NULL);
#endif
 {
  Matrix3 tolua_ret = (Matrix3)  self->ToMatrix3();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix3));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToMatrix3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToMatrix4 of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_ToMatrix400
static int tolua_MathLuaAPI_Matrix3x4_ToMatrix400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3x4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix3x4* self = (const Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToMatrix4'", NULL);
#endif
 {
  Matrix4 tolua_ret = (Matrix4)  self->ToMatrix4();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix4));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToMatrix4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RotationMatrix of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_RotationMatrix00
static int tolua_MathLuaAPI_Matrix3x4_RotationMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3x4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix3x4* self = (const Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RotationMatrix'", NULL);
#endif
 {
  Matrix3 tolua_ret = (Matrix3)  self->RotationMatrix();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix3));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RotationMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Translation of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_Translation00
static int tolua_MathLuaAPI_Matrix3x4_Translation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3x4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix3x4* self = (const Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Translation'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->Translation();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Translation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Rotation of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_Rotation00
static int tolua_MathLuaAPI_Matrix3x4_Rotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3x4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix3x4* self = (const Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Rotation'", NULL);
#endif
 {
  Quaternion tolua_ret = (Quaternion)  self->Rotation();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Rotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Scale of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_Scale00
static int tolua_MathLuaAPI_Matrix3x4_Scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3x4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix3x4* self = (const Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Scale'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->Scale();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Equals of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_Equals00
static int tolua_MathLuaAPI_Matrix3x4_Equals00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3x4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3x4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix3x4* self = (const Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3x4* rhs = ((const Matrix3x4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Equals'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Equals(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Equals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Decompose of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_Decompose00
static int tolua_MathLuaAPI_Matrix3x4_Decompose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3x4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Quaternion",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix3x4* self = (const Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
  Vector3* translation = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  Quaternion* rotation = ((Quaternion*)  tolua_tousertype(tolua_S,3,0));
  Vector3* scale = ((Vector3*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Decompose'", NULL);
#endif
 {
  self->Decompose(*translation,*rotation,*scale);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Decompose'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Inverse of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_Inverse00
static int tolua_MathLuaAPI_Matrix3x4_Inverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3x4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix3x4* self = (const Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Inverse'", NULL);
#endif
 {
  Matrix3x4 tolua_ret = (Matrix3x4)  self->Inverse();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix3x4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3x4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix3x4));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3x4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Inverse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToString of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix3x4_ToString00
static int tolua_MathLuaAPI_Matrix3x4_ToString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix3x4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix3x4* self = (const Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToString'", NULL);
#endif
 {
  String tolua_ret = (String)  self->ToString();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m00_ of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix3x4_m00
static int tolua_get_Matrix3x4_m00(lua_State* tolua_S)
{
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm00_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m00_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m00_ of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix3x4_m00
static int tolua_set_Matrix3x4_m00(lua_State* tolua_S)
{
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm00_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m00_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m01_ of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix3x4_m01
static int tolua_get_Matrix3x4_m01(lua_State* tolua_S)
{
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm01_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m01_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m01_ of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix3x4_m01
static int tolua_set_Matrix3x4_m01(lua_State* tolua_S)
{
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm01_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m01_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m02_ of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix3x4_m02
static int tolua_get_Matrix3x4_m02(lua_State* tolua_S)
{
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm02_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m02_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m02_ of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix3x4_m02
static int tolua_set_Matrix3x4_m02(lua_State* tolua_S)
{
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm02_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m02_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m03_ of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix3x4_m03
static int tolua_get_Matrix3x4_m03(lua_State* tolua_S)
{
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm03_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m03_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m03_ of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix3x4_m03
static int tolua_set_Matrix3x4_m03(lua_State* tolua_S)
{
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm03_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m03_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m10_ of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix3x4_m10
static int tolua_get_Matrix3x4_m10(lua_State* tolua_S)
{
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm10_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m10_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m10_ of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix3x4_m10
static int tolua_set_Matrix3x4_m10(lua_State* tolua_S)
{
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm10_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m10_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m11_ of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix3x4_m11
static int tolua_get_Matrix3x4_m11(lua_State* tolua_S)
{
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm11_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m11_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m11_ of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix3x4_m11
static int tolua_set_Matrix3x4_m11(lua_State* tolua_S)
{
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm11_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m11_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m12_ of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix3x4_m12
static int tolua_get_Matrix3x4_m12(lua_State* tolua_S)
{
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm12_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m12_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m12_ of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix3x4_m12
static int tolua_set_Matrix3x4_m12(lua_State* tolua_S)
{
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm12_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m12_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m13_ of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix3x4_m13
static int tolua_get_Matrix3x4_m13(lua_State* tolua_S)
{
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm13_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m13_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m13_ of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix3x4_m13
static int tolua_set_Matrix3x4_m13(lua_State* tolua_S)
{
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm13_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m13_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m20_ of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix3x4_m20
static int tolua_get_Matrix3x4_m20(lua_State* tolua_S)
{
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm20_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m20_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m20_ of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix3x4_m20
static int tolua_set_Matrix3x4_m20(lua_State* tolua_S)
{
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm20_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m20_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m21_ of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix3x4_m21
static int tolua_get_Matrix3x4_m21(lua_State* tolua_S)
{
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm21_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m21_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m21_ of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix3x4_m21
static int tolua_set_Matrix3x4_m21(lua_State* tolua_S)
{
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm21_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m21_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m22_ of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix3x4_m22
static int tolua_get_Matrix3x4_m22(lua_State* tolua_S)
{
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm22_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m22_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m22_ of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix3x4_m22
static int tolua_set_Matrix3x4_m22(lua_State* tolua_S)
{
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm22_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m22_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m23_ of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix3x4_m23
static int tolua_get_Matrix3x4_m23(lua_State* tolua_S)
{
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm23_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m23_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m23_ of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix3x4_m23
static int tolua_set_Matrix3x4_m23(lua_State* tolua_S)
{
  Matrix3x4* self = (Matrix3x4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm23_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m23_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ZERO of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix3x4_ZERO
static int tolua_get_Matrix3x4_ZERO(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Matrix3x4::ZERO,"const Matrix3x4");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: IDENTITY of class  Matrix3x4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix3x4_IDENTITY
static int tolua_get_Matrix3x4_IDENTITY(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Matrix3x4::IDENTITY,"const Matrix3x4");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4_new00
static int tolua_MathLuaAPI_Matrix4_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Matrix4* tolua_ret = (Matrix4*)  Mtolua_new((Matrix4)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix4");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4_new00_local
static int tolua_MathLuaAPI_Matrix4_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Matrix4* tolua_ret = (Matrix4*)  Mtolua_new((Matrix4)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4_new01
static int tolua_MathLuaAPI_Matrix4_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Matrix4* matrix = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
 {
  Matrix4* tolua_ret = (Matrix4*)  Mtolua_new((Matrix4)(*matrix));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix4");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix4_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4_new01_local
static int tolua_MathLuaAPI_Matrix4_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Matrix4* matrix = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
 {
  Matrix4* tolua_ret = (Matrix4*)  Mtolua_new((Matrix4)(*matrix));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix4_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4_new02
static int tolua_MathLuaAPI_Matrix4_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Matrix3* matrix = ((const Matrix3*)  tolua_tousertype(tolua_S,2,0));
 {
  Matrix4* tolua_ret = (Matrix4*)  Mtolua_new((Matrix4)(*matrix));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix4");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix4_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4_new02_local
static int tolua_MathLuaAPI_Matrix4_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Matrix3* matrix = ((const Matrix3*)  tolua_tousertype(tolua_S,2,0));
 {
  Matrix4* tolua_ret = (Matrix4*)  Mtolua_new((Matrix4)(*matrix));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix4_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4_new03
static int tolua_MathLuaAPI_Matrix4_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,10,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,11,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,12,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,13,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,14,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,15,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,16,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,17,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,18,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float v00 = ((float)  tolua_tonumber(tolua_S,2,0));
  float v01 = ((float)  tolua_tonumber(tolua_S,3,0));
  float v02 = ((float)  tolua_tonumber(tolua_S,4,0));
  float v03 = ((float)  tolua_tonumber(tolua_S,5,0));
  float v10 = ((float)  tolua_tonumber(tolua_S,6,0));
  float v11 = ((float)  tolua_tonumber(tolua_S,7,0));
  float v12 = ((float)  tolua_tonumber(tolua_S,8,0));
  float v13 = ((float)  tolua_tonumber(tolua_S,9,0));
  float v20 = ((float)  tolua_tonumber(tolua_S,10,0));
  float v21 = ((float)  tolua_tonumber(tolua_S,11,0));
  float v22 = ((float)  tolua_tonumber(tolua_S,12,0));
  float v23 = ((float)  tolua_tonumber(tolua_S,13,0));
  float v30 = ((float)  tolua_tonumber(tolua_S,14,0));
  float v31 = ((float)  tolua_tonumber(tolua_S,15,0));
  float v32 = ((float)  tolua_tonumber(tolua_S,16,0));
  float v33 = ((float)  tolua_tonumber(tolua_S,17,0));
 {
  Matrix4* tolua_ret = (Matrix4*)  Mtolua_new((Matrix4)(v00,v01,v02,v03,v10,v11,v12,v13,v20,v21,v22,v23,v30,v31,v32,v33));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix4");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix4_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4_new03_local
static int tolua_MathLuaAPI_Matrix4_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,10,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,11,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,12,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,13,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,14,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,15,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,16,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,17,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,18,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float v00 = ((float)  tolua_tonumber(tolua_S,2,0));
  float v01 = ((float)  tolua_tonumber(tolua_S,3,0));
  float v02 = ((float)  tolua_tonumber(tolua_S,4,0));
  float v03 = ((float)  tolua_tonumber(tolua_S,5,0));
  float v10 = ((float)  tolua_tonumber(tolua_S,6,0));
  float v11 = ((float)  tolua_tonumber(tolua_S,7,0));
  float v12 = ((float)  tolua_tonumber(tolua_S,8,0));
  float v13 = ((float)  tolua_tonumber(tolua_S,9,0));
  float v20 = ((float)  tolua_tonumber(tolua_S,10,0));
  float v21 = ((float)  tolua_tonumber(tolua_S,11,0));
  float v22 = ((float)  tolua_tonumber(tolua_S,12,0));
  float v23 = ((float)  tolua_tonumber(tolua_S,13,0));
  float v30 = ((float)  tolua_tonumber(tolua_S,14,0));
  float v31 = ((float)  tolua_tonumber(tolua_S,15,0));
  float v32 = ((float)  tolua_tonumber(tolua_S,16,0));
  float v33 = ((float)  tolua_tonumber(tolua_S,17,0));
 {
  Matrix4* tolua_ret = (Matrix4*)  Mtolua_new((Matrix4)(v00,v01,v02,v03,v10,v11,v12,v13,v20,v21,v22,v23,v30,v31,v32,v33));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix4_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4_delete00
static int tolua_MathLuaAPI_Matrix4_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
 Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4__eq00
static int tolua_MathLuaAPI_Matrix4__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* rhs = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->operator==(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4__mul00
static int tolua_MathLuaAPI_Matrix4__mul00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* rhs = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->operator*(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4__mul01
static int tolua_MathLuaAPI_Matrix4__mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* rhs = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
 {
  Vector4 tolua_ret = (Vector4)  self->operator*(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix4__mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4__add00
static int tolua_MathLuaAPI_Matrix4__add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* rhs = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
 {
  Matrix4 tolua_ret = (Matrix4)  self->operator+(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix4));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4__sub00
static int tolua_MathLuaAPI_Matrix4__sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* rhs = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
 {
  Matrix4 tolua_ret = (Matrix4)  self->operator-(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix4));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4__mul02
static int tolua_MathLuaAPI_Matrix4__mul02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
 {
  Matrix4 tolua_ret = (Matrix4)  self->operator*(rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix4));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix4__mul01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4__mul03
static int tolua_MathLuaAPI_Matrix4__mul03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* rhs = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
 {
  Matrix4 tolua_ret = (Matrix4)  self->operator*(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix4));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix4__mul02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4__mul04
static int tolua_MathLuaAPI_Matrix4__mul04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3x4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3x4* rhs = ((const Matrix3x4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
 {
  Matrix4 tolua_ret = (Matrix4)  self->operator*(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix4));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix4__mul03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTranslation of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4_SetTranslation00
static int tolua_MathLuaAPI_Matrix4_SetTranslation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* translation = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTranslation'", NULL);
#endif
 {
  self->SetTranslation(*translation);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTranslation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRotation of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4_SetRotation00
static int tolua_MathLuaAPI_Matrix4_SetRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3* rotation = ((const Matrix3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRotation'", NULL);
#endif
 {
  self->SetRotation(*rotation);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScale of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4_SetScale00
static int tolua_MathLuaAPI_Matrix4_SetScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* scale = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScale'", NULL);
#endif
 {
  self->SetScale(*scale);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScale of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4_SetScale01
static int tolua_MathLuaAPI_Matrix4_SetScale01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float scale = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScale'", NULL);
#endif
 {
  self->SetScale(scale);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Matrix4_SetScale00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToMatrix3 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4_ToMatrix300
static int tolua_MathLuaAPI_Matrix4_ToMatrix300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToMatrix3'", NULL);
#endif
 {
  Matrix3 tolua_ret = (Matrix3)  self->ToMatrix3();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix3));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToMatrix3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RotationMatrix of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4_RotationMatrix00
static int tolua_MathLuaAPI_Matrix4_RotationMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RotationMatrix'", NULL);
#endif
 {
  Matrix3 tolua_ret = (Matrix3)  self->RotationMatrix();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix3));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RotationMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Translation of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4_Translation00
static int tolua_MathLuaAPI_Matrix4_Translation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Translation'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->Translation();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Translation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Rotation of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4_Rotation00
static int tolua_MathLuaAPI_Matrix4_Rotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Rotation'", NULL);
#endif
 {
  Quaternion tolua_ret = (Quaternion)  self->Rotation();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Rotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Scale of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4_Scale00
static int tolua_MathLuaAPI_Matrix4_Scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Scale'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->Scale();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Transpose of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4_Transpose00
static int tolua_MathLuaAPI_Matrix4_Transpose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Transpose'", NULL);
#endif
 {
  Matrix4 tolua_ret = (Matrix4)  self->Transpose();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix4));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Transpose'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Equals of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4_Equals00
static int tolua_MathLuaAPI_Matrix4_Equals00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* rhs = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Equals'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Equals(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Equals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Decompose of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4_Decompose00
static int tolua_MathLuaAPI_Matrix4_Decompose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Quaternion",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
  Vector3* translation = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  Quaternion* rotation = ((Quaternion*)  tolua_tousertype(tolua_S,3,0));
  Vector3* scale = ((Vector3*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Decompose'", NULL);
#endif
 {
  self->Decompose(*translation,*rotation,*scale);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Decompose'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Inverse of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4_Inverse00
static int tolua_MathLuaAPI_Matrix4_Inverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Inverse'", NULL);
#endif
 {
  Matrix4 tolua_ret = (Matrix4)  self->Inverse();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix4));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Inverse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToString of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Matrix4_ToString00
static int tolua_MathLuaAPI_Matrix4_ToString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToString'", NULL);
#endif
 {
  String tolua_ret = (String)  self->ToString();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m00_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m00
static int tolua_get_Matrix4_m00(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm00_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m00_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m00_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m00
static int tolua_set_Matrix4_m00(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm00_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m00_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m01_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m01
static int tolua_get_Matrix4_m01(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm01_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m01_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m01_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m01
static int tolua_set_Matrix4_m01(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm01_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m01_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m02_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m02
static int tolua_get_Matrix4_m02(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm02_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m02_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m02_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m02
static int tolua_set_Matrix4_m02(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm02_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m02_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m03_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m03
static int tolua_get_Matrix4_m03(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm03_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m03_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m03_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m03
static int tolua_set_Matrix4_m03(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm03_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m03_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m10_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m10
static int tolua_get_Matrix4_m10(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm10_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m10_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m10_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m10
static int tolua_set_Matrix4_m10(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm10_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m10_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m11_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m11
static int tolua_get_Matrix4_m11(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm11_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m11_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m11_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m11
static int tolua_set_Matrix4_m11(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm11_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m11_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m12_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m12
static int tolua_get_Matrix4_m12(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm12_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m12_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m12_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m12
static int tolua_set_Matrix4_m12(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm12_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m12_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m13_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m13
static int tolua_get_Matrix4_m13(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm13_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m13_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m13_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m13
static int tolua_set_Matrix4_m13(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm13_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m13_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m20_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m20
static int tolua_get_Matrix4_m20(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm20_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m20_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m20_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m20
static int tolua_set_Matrix4_m20(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm20_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m20_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m21_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m21
static int tolua_get_Matrix4_m21(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm21_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m21_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m21_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m21
static int tolua_set_Matrix4_m21(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm21_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m21_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m22_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m22
static int tolua_get_Matrix4_m22(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm22_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m22_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m22_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m22
static int tolua_set_Matrix4_m22(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm22_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m22_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m23_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m23
static int tolua_get_Matrix4_m23(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm23_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m23_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m23_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m23
static int tolua_set_Matrix4_m23(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm23_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m23_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m30_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m30
static int tolua_get_Matrix4_m30(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm30_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m30_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m30_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m30
static int tolua_set_Matrix4_m30(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm30_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m30_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m31_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m31
static int tolua_get_Matrix4_m31(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm31_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m31_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m31_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m31
static int tolua_set_Matrix4_m31(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm31_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m31_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m32_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m32
static int tolua_get_Matrix4_m32(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm32_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m32_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m32_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m32
static int tolua_set_Matrix4_m32(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm32_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m32_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m33_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m33
static int tolua_get_Matrix4_m33(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm33_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->m33_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m33_ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m33
static int tolua_set_Matrix4_m33(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm33_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m33_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ZERO of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_ZERO
static int tolua_get_Matrix4_ZERO(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Matrix4::ZERO,"const Matrix4");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: IDENTITY of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_IDENTITY
static int tolua_get_Matrix4_IDENTITY(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Matrix4::IDENTITY,"const Matrix4");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Plane */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Plane_new00
static int tolua_MathLuaAPI_Plane_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Plane",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Plane* tolua_ret = (Plane*)  Mtolua_new((Plane)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Plane");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Plane */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Plane_new00_local
static int tolua_MathLuaAPI_Plane_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Plane",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Plane* tolua_ret = (Plane*)  Mtolua_new((Plane)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Plane");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Plane */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Plane_new01
static int tolua_MathLuaAPI_Plane_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Plane",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Plane",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Plane* plane = ((const Plane*)  tolua_tousertype(tolua_S,2,0));
 {
  Plane* tolua_ret = (Plane*)  Mtolua_new((Plane)(*plane));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Plane");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Plane_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Plane */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Plane_new01_local
static int tolua_MathLuaAPI_Plane_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Plane",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Plane",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Plane* plane = ((const Plane*)  tolua_tousertype(tolua_S,2,0));
 {
  Plane* tolua_ret = (Plane*)  Mtolua_new((Plane)(*plane));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Plane");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Plane_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Plane */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Plane_new02
static int tolua_MathLuaAPI_Plane_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Plane",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* v0 = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* v1 = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* v2 = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
 {
  Plane* tolua_ret = (Plane*)  Mtolua_new((Plane)(*v0,*v1,*v2));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Plane");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Plane_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Plane */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Plane_new02_local
static int tolua_MathLuaAPI_Plane_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Plane",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* v0 = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* v1 = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* v2 = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
 {
  Plane* tolua_ret = (Plane*)  Mtolua_new((Plane)(*v0,*v1,*v2));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Plane");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Plane_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Plane */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Plane_new03
static int tolua_MathLuaAPI_Plane_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Plane",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* normal = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
 {
  Plane* tolua_ret = (Plane*)  Mtolua_new((Plane)(*normal,*point));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Plane");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Plane_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Plane */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Plane_new03_local
static int tolua_MathLuaAPI_Plane_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Plane",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* normal = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
 {
  Plane* tolua_ret = (Plane*)  Mtolua_new((Plane)(*normal,*point));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Plane");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Plane_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Plane */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Plane_new04
static int tolua_MathLuaAPI_Plane_new04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Plane",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector4* plane = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
 {
  Plane* tolua_ret = (Plane*)  Mtolua_new((Plane)(*plane));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Plane");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Plane_new03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Plane */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Plane_new04_local
static int tolua_MathLuaAPI_Plane_new04_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Plane",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector4* plane = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
 {
  Plane* tolua_ret = (Plane*)  Mtolua_new((Plane)(*plane));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Plane");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Plane_new03_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Plane */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Plane_delete00
static int tolua_MathLuaAPI_Plane_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Plane",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Plane* self = (Plane*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
 Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  Plane */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Plane_Define00
static int tolua_MathLuaAPI_Plane_Define00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Plane",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Plane* self = (Plane*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v0 = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* v1 = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* v2 = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(*v0,*v1,*v2);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Define'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  Plane */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Plane_Define01
static int tolua_MathLuaAPI_Plane_Define01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Plane",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Plane* self = (Plane*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* normal = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(*normal,*point);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Plane_Define00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  Plane */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Plane_Define02
static int tolua_MathLuaAPI_Plane_Define02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Plane",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Plane* self = (Plane*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* plane = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(*plane);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Plane_Define01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Transform of class  Plane */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Plane_Transform00
static int tolua_MathLuaAPI_Plane_Transform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Plane",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Plane* self = (Plane*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3* transform = ((const Matrix3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Transform'", NULL);
#endif
 {
  self->Transform(*transform);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Transform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Transform of class  Plane */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Plane_Transform01
static int tolua_MathLuaAPI_Plane_Transform01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Plane",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3x4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Plane* self = (Plane*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3x4* transform = ((const Matrix3x4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Transform'", NULL);
#endif
 {
  self->Transform(*transform);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Plane_Transform00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Transform of class  Plane */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Plane_Transform02
static int tolua_MathLuaAPI_Plane_Transform02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Plane",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Plane* self = (Plane*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* transform = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Transform'", NULL);
#endif
 {
  self->Transform(*transform);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Plane_Transform01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Project of class  Plane */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Plane_Project00
static int tolua_MathLuaAPI_Plane_Project00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Plane",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Plane* self = (const Plane*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Project'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->Project(*point);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Project'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Distance of class  Plane */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Plane_Distance00
static int tolua_MathLuaAPI_Plane_Distance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Plane",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Plane* self = (const Plane*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Distance'", NULL);
#endif
 {
  float tolua_ret = (float)  self->Distance(*point);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Distance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Reflect of class  Plane */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Plane_Reflect00
static int tolua_MathLuaAPI_Plane_Reflect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Plane",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Plane* self = (const Plane*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* direction = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Reflect'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->Reflect(*direction);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Reflect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReflectionMatrix of class  Plane */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Plane_ReflectionMatrix00
static int tolua_MathLuaAPI_Plane_ReflectionMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Plane",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Plane* self = (const Plane*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReflectionMatrix'", NULL);
#endif
 {
  Matrix3x4 tolua_ret = (Matrix3x4)  self->ReflectionMatrix();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix3x4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3x4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix3x4));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3x4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReflectionMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Transformed of class  Plane */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Plane_Transformed00
static int tolua_MathLuaAPI_Plane_Transformed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Plane",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Plane* self = (const Plane*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3* transform = ((const Matrix3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Transformed'", NULL);
#endif
 {
  Plane tolua_ret = (Plane)  self->Transformed(*transform);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Plane)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Plane");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Plane));
  tolua_pushusertype(tolua_S,tolua_obj,"Plane");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Transformed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Transformed of class  Plane */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Plane_Transformed01
static int tolua_MathLuaAPI_Plane_Transformed01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Plane",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3x4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Plane* self = (const Plane*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3x4* transform = ((const Matrix3x4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Transformed'", NULL);
#endif
 {
  Plane tolua_ret = (Plane)  self->Transformed(*transform);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Plane)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Plane");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Plane));
  tolua_pushusertype(tolua_S,tolua_obj,"Plane");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Plane_Transformed00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Transformed of class  Plane */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Plane_Transformed02
static int tolua_MathLuaAPI_Plane_Transformed02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Plane",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Plane* self = (const Plane*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* transform = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Transformed'", NULL);
#endif
 {
  Plane tolua_ret = (Plane)  self->Transformed(*transform);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Plane)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Plane");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Plane));
  tolua_pushusertype(tolua_S,tolua_obj,"Plane");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Plane_Transformed01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToVector4 of class  Plane */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Plane_ToVector400
static int tolua_MathLuaAPI_Plane_ToVector400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Plane",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Plane* self = (const Plane*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToVector4'", NULL);
#endif
 {
  Vector4 tolua_ret = (Vector4)  self->ToVector4();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToVector4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: normal_ of class  Plane */
#ifndef TOLUA_DISABLE_tolua_get_Plane_normal
static int tolua_get_Plane_normal(lua_State* tolua_S)
{
  Plane* self = (Plane*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'normal_'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->normal_,"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: normal_ of class  Plane */
#ifndef TOLUA_DISABLE_tolua_set_Plane_normal
static int tolua_set_Plane_normal(lua_State* tolua_S)
{
  Plane* self = (Plane*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'normal_'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->normal_ = *((Vector3*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: absNormal_ of class  Plane */
#ifndef TOLUA_DISABLE_tolua_get_Plane_absNormal
static int tolua_get_Plane_absNormal(lua_State* tolua_S)
{
  Plane* self = (Plane*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'absNormal_'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->absNormal_,"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: absNormal_ of class  Plane */
#ifndef TOLUA_DISABLE_tolua_set_Plane_absNormal
static int tolua_set_Plane_absNormal(lua_State* tolua_S)
{
  Plane* self = (Plane*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'absNormal_'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->absNormal_ = *((Vector3*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: d_ of class  Plane */
#ifndef TOLUA_DISABLE_tolua_get_Plane_d
static int tolua_get_Plane_d(lua_State* tolua_S)
{
  Plane* self = (Plane*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'd_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->d_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: d_ of class  Plane */
#ifndef TOLUA_DISABLE_tolua_set_Plane_d
static int tolua_set_Plane_d(lua_State* tolua_S)
{
  Plane* self = (Plane*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'd_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->d_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: UP of class  Plane */
#ifndef TOLUA_DISABLE_tolua_get_Plane_UP
static int tolua_get_Plane_UP(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Plane::UP,"const Plane");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Polyhedron */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Polyhedron_new00
static int tolua_MathLuaAPI_Polyhedron_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Polyhedron",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Polyhedron* tolua_ret = (Polyhedron*)  Mtolua_new((Polyhedron)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Polyhedron");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Polyhedron */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Polyhedron_new00_local
static int tolua_MathLuaAPI_Polyhedron_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Polyhedron",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Polyhedron* tolua_ret = (Polyhedron*)  Mtolua_new((Polyhedron)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Polyhedron");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Polyhedron */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Polyhedron_new01
static int tolua_MathLuaAPI_Polyhedron_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Polyhedron",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Polyhedron",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Polyhedron* polyhedron = ((const Polyhedron*)  tolua_tousertype(tolua_S,2,0));
 {
  Polyhedron* tolua_ret = (Polyhedron*)  Mtolua_new((Polyhedron)(*polyhedron));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Polyhedron");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Polyhedron_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Polyhedron */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Polyhedron_new01_local
static int tolua_MathLuaAPI_Polyhedron_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Polyhedron",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Polyhedron",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Polyhedron* polyhedron = ((const Polyhedron*)  tolua_tousertype(tolua_S,2,0));
 {
  Polyhedron* tolua_ret = (Polyhedron*)  Mtolua_new((Polyhedron)(*polyhedron));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Polyhedron");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Polyhedron_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Polyhedron */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Polyhedron_new02
static int tolua_MathLuaAPI_Polyhedron_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Polyhedron",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const BoundingBox* box = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
 {
  Polyhedron* tolua_ret = (Polyhedron*)  Mtolua_new((Polyhedron)(*box));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Polyhedron");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Polyhedron_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Polyhedron */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Polyhedron_new02_local
static int tolua_MathLuaAPI_Polyhedron_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Polyhedron",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const BoundingBox* box = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
 {
  Polyhedron* tolua_ret = (Polyhedron*)  Mtolua_new((Polyhedron)(*box));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Polyhedron");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Polyhedron_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Polyhedron */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Polyhedron_new03
static int tolua_MathLuaAPI_Polyhedron_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Polyhedron",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Frustum",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Frustum* frustum = ((const Frustum*)  tolua_tousertype(tolua_S,2,0));
 {
  Polyhedron* tolua_ret = (Polyhedron*)  Mtolua_new((Polyhedron)(*frustum));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Polyhedron");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Polyhedron_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Polyhedron */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Polyhedron_new03_local
static int tolua_MathLuaAPI_Polyhedron_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Polyhedron",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Frustum",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Frustum* frustum = ((const Frustum*)  tolua_tousertype(tolua_S,2,0));
 {
  Polyhedron* tolua_ret = (Polyhedron*)  Mtolua_new((Polyhedron)(*frustum));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Polyhedron");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Polyhedron_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Polyhedron */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Polyhedron_delete00
static int tolua_MathLuaAPI_Polyhedron_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Polyhedron",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Polyhedron* self = (Polyhedron*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
 Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  Polyhedron */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Polyhedron_Define00
static int tolua_MathLuaAPI_Polyhedron_Define00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Polyhedron",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Polyhedron* self = (Polyhedron*)  tolua_tousertype(tolua_S,1,0);
  const BoundingBox* box = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(*box);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Define'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  Polyhedron */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Polyhedron_Define01
static int tolua_MathLuaAPI_Polyhedron_Define01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Polyhedron",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Frustum",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Polyhedron* self = (Polyhedron*)  tolua_tousertype(tolua_S,1,0);
  const Frustum* frustum = ((const Frustum*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(*frustum);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Polyhedron_Define00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddFace of class  Polyhedron */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Polyhedron_AddFace00
static int tolua_MathLuaAPI_Polyhedron_AddFace00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Polyhedron",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Polyhedron* self = (Polyhedron*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v0 = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* v1 = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* v2 = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddFace'", NULL);
#endif
 {
  self->AddFace(*v0,*v1,*v2);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddFace'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddFace of class  Polyhedron */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Polyhedron_AddFace01
static int tolua_MathLuaAPI_Polyhedron_AddFace01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Polyhedron",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Polyhedron* self = (Polyhedron*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v0 = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* v1 = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* v2 = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
  const Vector3* v3 = ((const Vector3*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddFace'", NULL);
#endif
 {
  self->AddFace(*v0,*v1,*v2,*v3);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Polyhedron_AddFace00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clip of class  Polyhedron */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Polyhedron_Clip00
static int tolua_MathLuaAPI_Polyhedron_Clip00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Polyhedron",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Plane",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Polyhedron* self = (Polyhedron*)  tolua_tousertype(tolua_S,1,0);
  const Plane* plane = ((const Plane*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clip'", NULL);
#endif
 {
  self->Clip(*plane);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clip of class  Polyhedron */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Polyhedron_Clip01
static int tolua_MathLuaAPI_Polyhedron_Clip01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Polyhedron",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Polyhedron* self = (Polyhedron*)  tolua_tousertype(tolua_S,1,0);
  const BoundingBox* box = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clip'", NULL);
#endif
 {
  self->Clip(*box);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Polyhedron_Clip00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clip of class  Polyhedron */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Polyhedron_Clip02
static int tolua_MathLuaAPI_Polyhedron_Clip02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Polyhedron",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Frustum",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Polyhedron* self = (Polyhedron*)  tolua_tousertype(tolua_S,1,0);
  const Frustum* box = ((const Frustum*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clip'", NULL);
#endif
 {
  self->Clip(*box);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Polyhedron_Clip01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  Polyhedron */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Polyhedron_Clear00
static int tolua_MathLuaAPI_Polyhedron_Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Polyhedron",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Polyhedron* self = (Polyhedron*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'", NULL);
#endif
 {
  self->Clear();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Transform of class  Polyhedron */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Polyhedron_Transform00
static int tolua_MathLuaAPI_Polyhedron_Transform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Polyhedron",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Polyhedron* self = (Polyhedron*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3* transform = ((const Matrix3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Transform'", NULL);
#endif
 {
  self->Transform(*transform);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Transform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Transform of class  Polyhedron */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Polyhedron_Transform01
static int tolua_MathLuaAPI_Polyhedron_Transform01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Polyhedron",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3x4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Polyhedron* self = (Polyhedron*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3x4* transform = ((const Matrix3x4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Transform'", NULL);
#endif
 {
  self->Transform(*transform);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Polyhedron_Transform00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Transformed of class  Polyhedron */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Polyhedron_Transformed00
static int tolua_MathLuaAPI_Polyhedron_Transformed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Polyhedron",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Polyhedron* self = (const Polyhedron*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3* transform = ((const Matrix3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Transformed'", NULL);
#endif
 {
  Polyhedron tolua_ret = (Polyhedron)  self->Transformed(*transform);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Polyhedron)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Polyhedron");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Polyhedron));
  tolua_pushusertype(tolua_S,tolua_obj,"Polyhedron");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Transformed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Transformed of class  Polyhedron */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Polyhedron_Transformed01
static int tolua_MathLuaAPI_Polyhedron_Transformed01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Polyhedron",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3x4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Polyhedron* self = (const Polyhedron*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3x4* transform = ((const Matrix3x4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Transformed'", NULL);
#endif
 {
  Polyhedron tolua_ret = (Polyhedron)  self->Transformed(*transform);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Polyhedron)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Polyhedron");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Polyhedron));
  tolua_pushusertype(tolua_S,tolua_obj,"Polyhedron");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Polyhedron_Transformed00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Empty of class  Polyhedron */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Polyhedron_Empty00
static int tolua_MathLuaAPI_Polyhedron_Empty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Polyhedron",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Polyhedron* self = (const Polyhedron*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Empty'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Empty();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Empty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: empty of class  Polyhedron */
#ifndef TOLUA_DISABLE_tolua_get_Polyhedron_empty
static int tolua_get_Polyhedron_empty(lua_State* tolua_S)
{
  Polyhedron* self = (Polyhedron*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'empty'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->Empty());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_new00
static int tolua_MathLuaAPI_Quaternion_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quaternion");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_new00_local
static int tolua_MathLuaAPI_Quaternion_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_new01
static int tolua_MathLuaAPI_Quaternion_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Quaternion* quat = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
 {
  Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)(*quat));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quaternion");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Quaternion_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_new01_local
static int tolua_MathLuaAPI_Quaternion_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Quaternion* quat = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
 {
  Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)(*quat));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Quaternion_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_new02
static int tolua_MathLuaAPI_Quaternion_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float w = ((float)  tolua_tonumber(tolua_S,2,0));
  float x = ((float)  tolua_tonumber(tolua_S,3,0));
  float y = ((float)  tolua_tonumber(tolua_S,4,0));
  float z = ((float)  tolua_tonumber(tolua_S,5,0));
 {
  Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)(w,x,y,z));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quaternion");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Quaternion_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_new02_local
static int tolua_MathLuaAPI_Quaternion_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float w = ((float)  tolua_tonumber(tolua_S,2,0));
  float x = ((float)  tolua_tonumber(tolua_S,3,0));
  float y = ((float)  tolua_tonumber(tolua_S,4,0));
  float z = ((float)  tolua_tonumber(tolua_S,5,0));
 {
  Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)(w,x,y,z));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Quaternion_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_new03
static int tolua_MathLuaAPI_Quaternion_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
  const Vector3* axis = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
 {
  Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)(angle,*axis));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quaternion");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Quaternion_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_new03_local
static int tolua_MathLuaAPI_Quaternion_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
  const Vector3* axis = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
 {
  Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)(angle,*axis));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Quaternion_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_new04
static int tolua_MathLuaAPI_Quaternion_new04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
 {
  Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)(angle));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quaternion");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Quaternion_new03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_new04_local
static int tolua_MathLuaAPI_Quaternion_new04_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
 {
  Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)(angle));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Quaternion_new03_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_new05
static int tolua_MathLuaAPI_Quaternion_new05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
 {
  Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)(x,y,z));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quaternion");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Quaternion_new04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_new05_local
static int tolua_MathLuaAPI_Quaternion_new05_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
 {
  Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)(x,y,z));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Quaternion_new04_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_new06
static int tolua_MathLuaAPI_Quaternion_new06(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* start = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* end = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
 {
  Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)(*start,*end));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quaternion");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Quaternion_new05(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_new06_local
static int tolua_MathLuaAPI_Quaternion_new06_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* start = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* end = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
 {
  Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)(*start,*end));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Quaternion_new05_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_new07
static int tolua_MathLuaAPI_Quaternion_new07(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* xAxis = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* yAxis = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* zAxis = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
 {
  Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)(*xAxis,*yAxis,*zAxis));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quaternion");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Quaternion_new06(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_new07_local
static int tolua_MathLuaAPI_Quaternion_new07_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* xAxis = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* yAxis = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* zAxis = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
 {
  Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)(*xAxis,*yAxis,*zAxis));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Quaternion_new06_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_new08
static int tolua_MathLuaAPI_Quaternion_new08(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Matrix3* matrix = ((const Matrix3*)  tolua_tousertype(tolua_S,2,0));
 {
  Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)(*matrix));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quaternion");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Quaternion_new07(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_new08_local
static int tolua_MathLuaAPI_Quaternion_new08_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Matrix3* matrix = ((const Matrix3*)  tolua_tousertype(tolua_S,2,0));
 {
  Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)(*matrix));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Quaternion_new07_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_delete00
static int tolua_MathLuaAPI_Quaternion_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
 Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion__eq00
static int tolua_MathLuaAPI_Quaternion__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* rhs = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->operator==(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion__mul00
static int tolua_MathLuaAPI_Quaternion__mul00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
 {
  Quaternion tolua_ret = (Quaternion)  self->operator*(rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion__sub00
static int tolua_MathLuaAPI_Quaternion__sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
 {
  Quaternion tolua_ret = (Quaternion)  self->operator-();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion__eq01
static int tolua_MathLuaAPI_Quaternion__eq01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* rhs = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->operator==(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Quaternion__eq00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion__mul01
static int tolua_MathLuaAPI_Quaternion__mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
 {
  Quaternion tolua_ret = (Quaternion)  self->operator*(rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Quaternion__mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion__sub01
static int tolua_MathLuaAPI_Quaternion__sub01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
 {
  Quaternion tolua_ret = (Quaternion)  self->operator-();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Quaternion__sub00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion__add00
static int tolua_MathLuaAPI_Quaternion__add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* rhs = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
 {
  Quaternion tolua_ret = (Quaternion)  self->operator+(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion__sub02
static int tolua_MathLuaAPI_Quaternion__sub02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* rhs = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
 {
  Quaternion tolua_ret = (Quaternion)  self->operator-(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Quaternion__sub01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion__mul02
static int tolua_MathLuaAPI_Quaternion__mul02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* rhs = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
 {
  Quaternion tolua_ret = (Quaternion)  self->operator*(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Quaternion__mul01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion__mul03
static int tolua_MathLuaAPI_Quaternion__mul03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* rhs = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->operator*(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Quaternion__mul02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: FromAngleAxis of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_FromAngleAxis00
static int tolua_MathLuaAPI_Quaternion_FromAngleAxis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
  const Vector3* axis = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FromAngleAxis'", NULL);
#endif
 {
  self->FromAngleAxis(angle,*axis);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FromAngleAxis'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FromEulerAngles of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_FromEulerAngles00
static int tolua_MathLuaAPI_Quaternion_FromEulerAngles00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FromEulerAngles'", NULL);
#endif
 {
  self->FromEulerAngles(x,y,z);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FromEulerAngles'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FromRotationTo of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_FromRotationTo00
static int tolua_MathLuaAPI_Quaternion_FromRotationTo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* start = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* end = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FromRotationTo'", NULL);
#endif
 {
  self->FromRotationTo(*start,*end);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FromRotationTo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FromAxes of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_FromAxes00
static int tolua_MathLuaAPI_Quaternion_FromAxes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* xAxis = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* yAxis = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* zAxis = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FromAxes'", NULL);
#endif
 {
  self->FromAxes(*xAxis,*yAxis,*zAxis);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FromAxes'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FromRotationMatrix of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_FromRotationMatrix00
static int tolua_MathLuaAPI_Quaternion_FromRotationMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3* matrix = ((const Matrix3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FromRotationMatrix'", NULL);
#endif
 {
  self->FromRotationMatrix(*matrix);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FromRotationMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FromLookRotation of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_FromLookRotation00
static int tolua_MathLuaAPI_Quaternion_FromLookRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* direction = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* up = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FromLookRotation'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->FromLookRotation(*direction,*up);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FromLookRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Normalize of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_Normalize00
static int tolua_MathLuaAPI_Quaternion_Normalize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Normalize'", NULL);
#endif
 {
  self->Normalize();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Normalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Normalized of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_Normalized00
static int tolua_MathLuaAPI_Quaternion_Normalized00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Normalized'", NULL);
#endif
 {
  Quaternion tolua_ret = (Quaternion)  self->Normalized();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Normalized'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Inverse of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_Inverse00
static int tolua_MathLuaAPI_Quaternion_Inverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Inverse'", NULL);
#endif
 {
  Quaternion tolua_ret = (Quaternion)  self->Inverse();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Inverse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LengthSquared of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_LengthSquared00
static int tolua_MathLuaAPI_Quaternion_LengthSquared00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LengthSquared'", NULL);
#endif
 {
  float tolua_ret = (float)  self->LengthSquared();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LengthSquared'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DotProduct of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_DotProduct00
static int tolua_MathLuaAPI_Quaternion_DotProduct00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* rhs = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DotProduct'", NULL);
#endif
 {
  float tolua_ret = (float)  self->DotProduct(*rhs);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DotProduct'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Equals of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_Equals00
static int tolua_MathLuaAPI_Quaternion_Equals00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* rhs = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Equals'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Equals(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Equals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsNaN of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_IsNaN00
static int tolua_MathLuaAPI_Quaternion_IsNaN00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsNaN'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsNaN();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsNaN'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Conjugate of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_Conjugate00
static int tolua_MathLuaAPI_Quaternion_Conjugate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Conjugate'", NULL);
#endif
 {
  Quaternion tolua_ret = (Quaternion)  self->Conjugate();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Conjugate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: EulerAngles of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_EulerAngles00
static int tolua_MathLuaAPI_Quaternion_EulerAngles00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'EulerAngles'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->EulerAngles();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EulerAngles'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: YawAngle of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_YawAngle00
static int tolua_MathLuaAPI_Quaternion_YawAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'YawAngle'", NULL);
#endif
 {
  float tolua_ret = (float)  self->YawAngle();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'YawAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PitchAngle of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_PitchAngle00
static int tolua_MathLuaAPI_Quaternion_PitchAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PitchAngle'", NULL);
#endif
 {
  float tolua_ret = (float)  self->PitchAngle();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PitchAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RollAngle of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_RollAngle00
static int tolua_MathLuaAPI_Quaternion_RollAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RollAngle'", NULL);
#endif
 {
  float tolua_ret = (float)  self->RollAngle();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RollAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Axis of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_Axis00
static int tolua_MathLuaAPI_Quaternion_Axis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Axis'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->Axis();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Axis'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Angle of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_Angle00
static int tolua_MathLuaAPI_Quaternion_Angle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Angle'", NULL);
#endif
 {
  float tolua_ret = (float)  self->Angle();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Angle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RotationMatrix of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_RotationMatrix00
static int tolua_MathLuaAPI_Quaternion_RotationMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RotationMatrix'", NULL);
#endif
 {
  Matrix3 tolua_ret = (Matrix3)  self->RotationMatrix();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix3));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RotationMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Slerp of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_Slerp00
static int tolua_MathLuaAPI_Quaternion_Slerp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* rhs = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
  float t = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Slerp'", NULL);
#endif
 {
  Quaternion tolua_ret = (Quaternion)  self->Slerp(*rhs,t);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Slerp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Nlerp of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_Nlerp00
static int tolua_MathLuaAPI_Quaternion_Nlerp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* rhs = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
  float t = ((float)  tolua_tonumber(tolua_S,3,0));
  bool shortestPath = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Nlerp'", NULL);
#endif
 {
  Quaternion tolua_ret = (Quaternion)  self->Nlerp(*rhs,t,shortestPath);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Nlerp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToString of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Quaternion_ToString00
static int tolua_MathLuaAPI_Quaternion_ToString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToString'", NULL);
#endif
 {
  String tolua_ret = (String)  self->ToString();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: w_ of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_get_Quaternion_w
static int tolua_get_Quaternion_w(lua_State* tolua_S)
{
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'w_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->w_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: w_ of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_set_Quaternion_w
static int tolua_set_Quaternion_w(lua_State* tolua_S)
{
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'w_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->w_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x_ of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_get_Quaternion_x
static int tolua_get_Quaternion_x(lua_State* tolua_S)
{
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->x_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x_ of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_set_Quaternion_x
static int tolua_set_Quaternion_x(lua_State* tolua_S)
{
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y_ of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_get_Quaternion_y
static int tolua_get_Quaternion_y(lua_State* tolua_S)
{
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->y_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y_ of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_set_Quaternion_y
static int tolua_set_Quaternion_y(lua_State* tolua_S)
{
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: z_ of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_get_Quaternion_z
static int tolua_get_Quaternion_z(lua_State* tolua_S)
{
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->z_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: z_ of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_set_Quaternion_z
static int tolua_set_Quaternion_z(lua_State* tolua_S)
{
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->z_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: IDENTITY of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_get_Quaternion_IDENTITY
static int tolua_get_Quaternion_IDENTITY(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Quaternion::IDENTITY,"const Quaternion");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* function: SetRandomSeed */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_SetRandomSeed00
static int tolua_MathLuaAPI_SetRandomSeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  unsigned seed = ((unsigned)  tolua_tonumber(tolua_S,1,0));
 {
  SetRandomSeed(seed);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRandomSeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetRandomSeed */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_GetRandomSeed00
static int tolua_MathLuaAPI_GetRandomSeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  unsigned tolua_ret = (unsigned)  GetRandomSeed();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRandomSeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Rand */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rand00
static int tolua_MathLuaAPI_Rand00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  Rand();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Rand'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: RandStandardNormal */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_RandStandardNormal00
static int tolua_MathLuaAPI_RandStandardNormal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  float tolua_ret = (float)  RandStandardNormal();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RandStandardNormal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Ray */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Ray_new00
static int tolua_MathLuaAPI_Ray_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Ray",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Ray* tolua_ret = (Ray*)  Mtolua_new((Ray)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ray");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Ray */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Ray_new00_local
static int tolua_MathLuaAPI_Ray_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Ray",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Ray* tolua_ret = (Ray*)  Mtolua_new((Ray)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ray");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Ray */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Ray_new01
static int tolua_MathLuaAPI_Ray_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Ray",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* origin = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* direction = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
 {
  Ray* tolua_ret = (Ray*)  Mtolua_new((Ray)(*origin,*direction));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ray");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Ray_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Ray */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Ray_new01_local
static int tolua_MathLuaAPI_Ray_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Ray",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* origin = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* direction = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
 {
  Ray* tolua_ret = (Ray*)  Mtolua_new((Ray)(*origin,*direction));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ray");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Ray_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Ray */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Ray_new02
static int tolua_MathLuaAPI_Ray_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Ray",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ray",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Ray* ray = ((const Ray*)  tolua_tousertype(tolua_S,2,0));
 {
  Ray* tolua_ret = (Ray*)  Mtolua_new((Ray)(*ray));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ray");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Ray_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Ray */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Ray_new02_local
static int tolua_MathLuaAPI_Ray_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Ray",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ray",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Ray* ray = ((const Ray*)  tolua_tousertype(tolua_S,2,0));
 {
  Ray* tolua_ret = (Ray*)  Mtolua_new((Ray)(*ray));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ray");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Ray_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Ray */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Ray_delete00
static int tolua_MathLuaAPI_Ray_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Ray",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Ray* self = (Ray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
 Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  Ray */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Ray__eq00
static int tolua_MathLuaAPI_Ray__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Ray",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ray",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Ray* self = (const Ray*)  tolua_tousertype(tolua_S,1,0);
  const Ray* rhs = ((const Ray*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->operator==(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  Ray */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Ray_Define00
static int tolua_MathLuaAPI_Ray_Define00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Ray",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Ray* self = (Ray*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* origin = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* direction = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(*origin,*direction);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Define'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Project of class  Ray */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Ray_Project00
static int tolua_MathLuaAPI_Ray_Project00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Ray",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Ray* self = (const Ray*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Project'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->Project(*point);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Project'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Distance of class  Ray */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Ray_Distance00
static int tolua_MathLuaAPI_Ray_Distance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Ray",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Ray* self = (const Ray*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Distance'", NULL);
#endif
 {
  float tolua_ret = (float)  self->Distance(*point);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Distance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClosestPoint of class  Ray */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Ray_ClosestPoint00
static int tolua_MathLuaAPI_Ray_ClosestPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Ray",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ray",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Ray* self = (const Ray*)  tolua_tousertype(tolua_S,1,0);
  const Ray* ray = ((const Ray*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClosestPoint'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->ClosestPoint(*ray);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClosestPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: HitDistance of class  Ray */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Ray_HitDistance00
static int tolua_MathLuaAPI_Ray_HitDistance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Ray",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Plane",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Ray* self = (const Ray*)  tolua_tousertype(tolua_S,1,0);
  const Plane* plane = ((const Plane*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HitDistance'", NULL);
#endif
 {
  float tolua_ret = (float)  self->HitDistance(*plane);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HitDistance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: HitDistance of class  Ray */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Ray_HitDistance01
static int tolua_MathLuaAPI_Ray_HitDistance01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Ray",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Ray* self = (const Ray*)  tolua_tousertype(tolua_S,1,0);
  const BoundingBox* box = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HitDistance'", NULL);
#endif
 {
  float tolua_ret = (float)  self->HitDistance(*box);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Ray_HitDistance00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: HitDistance of class  Ray */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Ray_HitDistance02
static int tolua_MathLuaAPI_Ray_HitDistance02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Ray",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Frustum",0,&tolua_err)) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Ray* self = (const Ray*)  tolua_tousertype(tolua_S,1,0);
  const Frustum* frustum = ((const Frustum*)  tolua_tousertype(tolua_S,2,0));
  bool solidInside = ((bool)  tolua_toboolean(tolua_S,3,true));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HitDistance'", NULL);
#endif
 {
  float tolua_ret = (float)  self->HitDistance(*frustum,solidInside);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Ray_HitDistance01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: HitDistance of class  Ray */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Ray_HitDistance03
static int tolua_MathLuaAPI_Ray_HitDistance03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Ray",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Sphere",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Ray* self = (const Ray*)  tolua_tousertype(tolua_S,1,0);
  const Sphere* sphere = ((const Sphere*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HitDistance'", NULL);
#endif
 {
  float tolua_ret = (float)  self->HitDistance(*sphere);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Ray_HitDistance02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: HitDistance of class  Ray */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Ray_HitDistance04
static int tolua_MathLuaAPI_Ray_HitDistance04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Ray",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Ray* self = (const Ray*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v0 = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* v1 = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* v2 = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HitDistance'", NULL);
#endif
 {
  float tolua_ret = (float)  self->HitDistance(*v0,*v1,*v2);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Ray_HitDistance03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Transformed of class  Ray */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Ray_Transformed00
static int tolua_MathLuaAPI_Ray_Transformed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Ray",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3x4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Ray* self = (const Ray*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3x4* transform = ((const Matrix3x4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Transformed'", NULL);
#endif
 {
  Ray tolua_ret = (Ray)  self->Transformed(*transform);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Ray)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Ray");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Ray));
  tolua_pushusertype(tolua_S,tolua_obj,"Ray");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Transformed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: origin_ of class  Ray */
#ifndef TOLUA_DISABLE_tolua_get_Ray_origin
static int tolua_get_Ray_origin(lua_State* tolua_S)
{
  Ray* self = (Ray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'origin_'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->origin_,"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: origin_ of class  Ray */
#ifndef TOLUA_DISABLE_tolua_set_Ray_origin
static int tolua_set_Ray_origin(lua_State* tolua_S)
{
  Ray* self = (Ray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'origin_'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->origin_ = *((Vector3*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: direction_ of class  Ray */
#ifndef TOLUA_DISABLE_tolua_get_Ray_direction
static int tolua_get_Ray_direction(lua_State* tolua_S)
{
  Ray* self = (Ray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'direction_'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->direction_,"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: direction_ of class  Ray */
#ifndef TOLUA_DISABLE_tolua_set_Ray_direction
static int tolua_set_Ray_direction(lua_State* tolua_S)
{
  Ray* self = (Ray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'direction_'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->direction_ = *((Vector3*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Rect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rect_new00
static int tolua_MathLuaAPI_Rect_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Rect",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Rect* tolua_ret = (Rect*)  Mtolua_new((Rect)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Rect");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Rect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rect_new00_local
static int tolua_MathLuaAPI_Rect_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Rect",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Rect* tolua_ret = (Rect*)  Mtolua_new((Rect)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Rect");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Rect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rect_new01
static int tolua_MathLuaAPI_Rect_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Rect",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Rect* rect = ((const Rect*)  tolua_tousertype(tolua_S,2,0));
 {
  Rect* tolua_ret = (Rect*)  Mtolua_new((Rect)(*rect));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Rect");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Rect_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Rect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rect_new01_local
static int tolua_MathLuaAPI_Rect_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Rect",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Rect* rect = ((const Rect*)  tolua_tousertype(tolua_S,2,0));
 {
  Rect* tolua_ret = (Rect*)  Mtolua_new((Rect)(*rect));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Rect");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Rect_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Rect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rect_new02
static int tolua_MathLuaAPI_Rect_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Rect",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector2* min = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  const Vector2* max = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
 {
  Rect* tolua_ret = (Rect*)  Mtolua_new((Rect)(*min,*max));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Rect");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Rect_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Rect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rect_new02_local
static int tolua_MathLuaAPI_Rect_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Rect",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector2* min = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  const Vector2* max = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
 {
  Rect* tolua_ret = (Rect*)  Mtolua_new((Rect)(*min,*max));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Rect");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Rect_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Rect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rect_new03
static int tolua_MathLuaAPI_Rect_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Rect",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float left = ((float)  tolua_tonumber(tolua_S,2,0));
  float top = ((float)  tolua_tonumber(tolua_S,3,0));
  float right = ((float)  tolua_tonumber(tolua_S,4,0));
  float bottom = ((float)  tolua_tonumber(tolua_S,5,0));
 {
  Rect* tolua_ret = (Rect*)  Mtolua_new((Rect)(left,top,right,bottom));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Rect");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Rect_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Rect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rect_new03_local
static int tolua_MathLuaAPI_Rect_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Rect",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float left = ((float)  tolua_tonumber(tolua_S,2,0));
  float top = ((float)  tolua_tonumber(tolua_S,3,0));
  float right = ((float)  tolua_tonumber(tolua_S,4,0));
  float bottom = ((float)  tolua_tonumber(tolua_S,5,0));
 {
  Rect* tolua_ret = (Rect*)  Mtolua_new((Rect)(left,top,right,bottom));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Rect");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Rect_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Rect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rect_new04
static int tolua_MathLuaAPI_Rect_new04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Rect",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector4* vector = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
 {
  Rect* tolua_ret = (Rect*)  Mtolua_new((Rect)(*vector));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Rect");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Rect_new03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Rect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rect_new04_local
static int tolua_MathLuaAPI_Rect_new04_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Rect",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector4* vector = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
 {
  Rect* tolua_ret = (Rect*)  Mtolua_new((Rect)(*vector));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Rect");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Rect_new03_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Rect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rect_delete00
static int tolua_MathLuaAPI_Rect_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Rect",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Rect* self = (Rect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
 Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  Rect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rect__eq00
static int tolua_MathLuaAPI_Rect__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Rect",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Rect* self = (const Rect*)  tolua_tousertype(tolua_S,1,0);
  const Rect* rhs = ((const Rect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->operator==(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  Rect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rect_Define00
static int tolua_MathLuaAPI_Rect_Define00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Rect",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Rect* self = (Rect*)  tolua_tousertype(tolua_S,1,0);
  const Rect* rect = ((const Rect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(*rect);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Define'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  Rect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rect_Define01
static int tolua_MathLuaAPI_Rect_Define01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Rect",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Rect* self = (Rect*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* min = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  const Vector2* max = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(*min,*max);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Rect_Define00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  Rect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rect_Define02
static int tolua_MathLuaAPI_Rect_Define02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Rect",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Rect* self = (Rect*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* point = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(*point);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Rect_Define01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Merge of class  Rect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rect_Merge00
static int tolua_MathLuaAPI_Rect_Merge00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Rect",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Rect* self = (Rect*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* point = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Merge'", NULL);
#endif
 {
  self->Merge(*point);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Merge'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Merge of class  Rect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rect_Merge01
static int tolua_MathLuaAPI_Rect_Merge01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Rect",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Rect* self = (Rect*)  tolua_tousertype(tolua_S,1,0);
  const Rect* rect = ((const Rect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Merge'", NULL);
#endif
 {
  self->Merge(*rect);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Rect_Merge00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  Rect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rect_Clear00
static int tolua_MathLuaAPI_Rect_Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Rect",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Rect* self = (Rect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'", NULL);
#endif
 {
  self->Clear();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clip of class  Rect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rect_Clip00
static int tolua_MathLuaAPI_Rect_Clip00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Rect",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Rect* self = (Rect*)  tolua_tousertype(tolua_S,1,0);
  const Rect* rect = ((const Rect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clip'", NULL);
#endif
 {
  self->Clip(*rect);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Defined of class  Rect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rect_Defined00
static int tolua_MathLuaAPI_Rect_Defined00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Rect",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Rect* self = (const Rect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Defined'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Defined();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Defined'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Center of class  Rect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rect_Center00
static int tolua_MathLuaAPI_Rect_Center00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Rect",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Rect* self = (const Rect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Center'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->Center();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Center'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Size of class  Rect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rect_Size00
static int tolua_MathLuaAPI_Rect_Size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Rect",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Rect* self = (const Rect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Size'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->Size();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: HalfSize of class  Rect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rect_HalfSize00
static int tolua_MathLuaAPI_Rect_HalfSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Rect",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Rect* self = (const Rect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HalfSize'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->HalfSize();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HalfSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Equals of class  Rect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rect_Equals00
static int tolua_MathLuaAPI_Rect_Equals00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Rect",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Rect* self = (const Rect*)  tolua_tousertype(tolua_S,1,0);
  const Rect* rhs = ((const Rect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Equals'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Equals(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Equals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsInside of class  Rect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rect_IsInside00
static int tolua_MathLuaAPI_Rect_IsInside00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Rect",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Rect* self = (const Rect*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* point = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsInside'", NULL);
#endif
 {
  Intersection tolua_ret = (Intersection)  self->IsInside(*point);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsInside'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsInside of class  Rect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rect_IsInside01
static int tolua_MathLuaAPI_Rect_IsInside01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Rect",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Rect* self = (const Rect*)  tolua_tousertype(tolua_S,1,0);
  const Rect* rect = ((const Rect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsInside'", NULL);
#endif
 {
  Intersection tolua_ret = (Intersection)  self->IsInside(*rect);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Rect_IsInside00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToVector4 of class  Rect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rect_ToVector400
static int tolua_MathLuaAPI_Rect_ToVector400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Rect",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Rect* self = (const Rect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToVector4'", NULL);
#endif
 {
  Vector4 tolua_ret = (Vector4)  self->ToVector4();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToVector4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToString of class  Rect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Rect_ToString00
static int tolua_MathLuaAPI_Rect_ToString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Rect",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Rect* self = (const Rect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToString'", NULL);
#endif
 {
  String tolua_ret = (String)  self->ToString();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: min_ of class  Rect */
#ifndef TOLUA_DISABLE_tolua_get_Rect_min
static int tolua_get_Rect_min(lua_State* tolua_S)
{
  Rect* self = (Rect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'min_'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->min_,"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: min_ of class  Rect */
#ifndef TOLUA_DISABLE_tolua_set_Rect_min
static int tolua_set_Rect_min(lua_State* tolua_S)
{
  Rect* self = (Rect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'min_'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->min_ = *((Vector2*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: max_ of class  Rect */
#ifndef TOLUA_DISABLE_tolua_get_Rect_max
static int tolua_get_Rect_max(lua_State* tolua_S)
{
  Rect* self = (Rect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'max_'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->max_,"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: max_ of class  Rect */
#ifndef TOLUA_DISABLE_tolua_set_Rect_max
static int tolua_set_Rect_max(lua_State* tolua_S)
{
  Rect* self = (Rect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'max_'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->max_ = *((Vector2*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: FULL of class  Rect */
#ifndef TOLUA_DISABLE_tolua_get_Rect_FULL
static int tolua_get_Rect_FULL(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Rect::FULL,"const Rect");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: POSITIVE of class  Rect */
#ifndef TOLUA_DISABLE_tolua_get_Rect_POSITIVE
static int tolua_get_Rect_POSITIVE(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Rect::POSITIVE,"const Rect");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ZERO of class  Rect */
#ifndef TOLUA_DISABLE_tolua_get_Rect_ZERO
static int tolua_get_Rect_ZERO(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Rect::ZERO,"const Rect");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: center of class  Rect */
#ifndef TOLUA_DISABLE_tolua_get_Rect_center
static int tolua_get_Rect_center(lua_State* tolua_S)
{
  Rect* self = (Rect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'center'",NULL);
#endif
 Vector2 tolua_ret = (Vector2)self->Center();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((Vector2)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: size of class  Rect */
#ifndef TOLUA_DISABLE_tolua_get_Rect_size
static int tolua_get_Rect_size(lua_State* tolua_S)
{
  Rect* self = (Rect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'size'",NULL);
#endif
 Vector2 tolua_ret = (Vector2)self->Size();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((Vector2)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: halfSize of class  Rect */
#ifndef TOLUA_DISABLE_tolua_get_Rect_halfSize
static int tolua_get_Rect_halfSize(lua_State* tolua_S)
{
  Rect* self = (Rect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'halfSize'",NULL);
#endif
 Vector2 tolua_ret = (Vector2)self->HalfSize();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((Vector2)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  IntRect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntRect_new00
static int tolua_MathLuaAPI_IntRect_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"IntRect",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  IntRect* tolua_ret = (IntRect*)  Mtolua_new((IntRect)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"IntRect");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  IntRect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntRect_new00_local
static int tolua_MathLuaAPI_IntRect_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"IntRect",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  IntRect* tolua_ret = (IntRect*)  Mtolua_new((IntRect)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"IntRect");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  IntRect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntRect_new01
static int tolua_MathLuaAPI_IntRect_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"IntRect",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  int left = ((int)  tolua_tonumber(tolua_S,2,0));
  int top = ((int)  tolua_tonumber(tolua_S,3,0));
  int right = ((int)  tolua_tonumber(tolua_S,4,0));
  int bottom = ((int)  tolua_tonumber(tolua_S,5,0));
 {
  IntRect* tolua_ret = (IntRect*)  Mtolua_new((IntRect)(left,top,right,bottom));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"IntRect");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_IntRect_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  IntRect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntRect_new01_local
static int tolua_MathLuaAPI_IntRect_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"IntRect",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  int left = ((int)  tolua_tonumber(tolua_S,2,0));
  int top = ((int)  tolua_tonumber(tolua_S,3,0));
  int right = ((int)  tolua_tonumber(tolua_S,4,0));
  int bottom = ((int)  tolua_tonumber(tolua_S,5,0));
 {
  IntRect* tolua_ret = (IntRect*)  Mtolua_new((IntRect)(left,top,right,bottom));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"IntRect");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_IntRect_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  IntRect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntRect_new02
static int tolua_MathLuaAPI_IntRect_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"IntRect",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const IntVector2* min = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
  const IntVector2* max = ((const IntVector2*)  tolua_tousertype(tolua_S,3,0));
 {
  IntRect* tolua_ret = (IntRect*)  Mtolua_new((IntRect)(*min,*max));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"IntRect");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_IntRect_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  IntRect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntRect_new02_local
static int tolua_MathLuaAPI_IntRect_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"IntRect",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const IntVector2* min = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
  const IntVector2* max = ((const IntVector2*)  tolua_tousertype(tolua_S,3,0));
 {
  IntRect* tolua_ret = (IntRect*)  Mtolua_new((IntRect)(*min,*max));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"IntRect");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_IntRect_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  IntRect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntRect_delete00
static int tolua_MathLuaAPI_IntRect_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"IntRect",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  IntRect* self = (IntRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
 Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  IntRect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntRect__eq00
static int tolua_MathLuaAPI_IntRect__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IntRect",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntRect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IntRect* self = (const IntRect*)  tolua_tousertype(tolua_S,1,0);
  const IntRect* rhs = ((const IntRect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->operator==(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Size of class  IntRect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntRect_Size00
static int tolua_MathLuaAPI_IntRect_Size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IntRect",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IntRect* self = (const IntRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Size'", NULL);
#endif
 {
  IntVector2 tolua_ret = (IntVector2)  self->Size();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector2));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Width of class  IntRect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntRect_Width00
static int tolua_MathLuaAPI_IntRect_Width00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IntRect",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IntRect* self = (const IntRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Width'", NULL);
#endif
 {
  int tolua_ret = (int)  self->Width();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Width'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Height of class  IntRect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntRect_Height00
static int tolua_MathLuaAPI_IntRect_Height00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IntRect",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IntRect* self = (const IntRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Height'", NULL);
#endif
 {
  int tolua_ret = (int)  self->Height();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Height'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsInside of class  IntRect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntRect_IsInside00
static int tolua_MathLuaAPI_IntRect_IsInside00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IntRect",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IntRect* self = (const IntRect*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* point = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsInside'", NULL);
#endif
 {
  Intersection tolua_ret = (Intersection)  self->IsInside(*point);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsInside'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clip of class  IntRect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntRect_Clip00
static int tolua_MathLuaAPI_IntRect_Clip00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"IntRect",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntRect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  IntRect* self = (IntRect*)  tolua_tousertype(tolua_S,1,0);
  const IntRect* rect = ((const IntRect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clip'", NULL);
#endif
 {
  self->Clip(*rect);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Merge of class  IntRect */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntRect_Merge00
static int tolua_MathLuaAPI_IntRect_Merge00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"IntRect",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntRect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  IntRect* self = (IntRect*)  tolua_tousertype(tolua_S,1,0);
  const IntRect* rect = ((const IntRect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Merge'", NULL);
#endif
 {
  self->Merge(*rect);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Merge'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: left_ of class  IntRect */
#ifndef TOLUA_DISABLE_tolua_get_IntRect_left
static int tolua_get_IntRect_left(lua_State* tolua_S)
{
  IntRect* self = (IntRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'left_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->left_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: left_ of class  IntRect */
#ifndef TOLUA_DISABLE_tolua_set_IntRect_left
static int tolua_set_IntRect_left(lua_State* tolua_S)
{
  IntRect* self = (IntRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'left_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->left_ = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: top_ of class  IntRect */
#ifndef TOLUA_DISABLE_tolua_get_IntRect_top
static int tolua_get_IntRect_top(lua_State* tolua_S)
{
  IntRect* self = (IntRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'top_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->top_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: top_ of class  IntRect */
#ifndef TOLUA_DISABLE_tolua_set_IntRect_top
static int tolua_set_IntRect_top(lua_State* tolua_S)
{
  IntRect* self = (IntRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'top_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->top_ = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: right_ of class  IntRect */
#ifndef TOLUA_DISABLE_tolua_get_IntRect_right
static int tolua_get_IntRect_right(lua_State* tolua_S)
{
  IntRect* self = (IntRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'right_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->right_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: right_ of class  IntRect */
#ifndef TOLUA_DISABLE_tolua_set_IntRect_right
static int tolua_set_IntRect_right(lua_State* tolua_S)
{
  IntRect* self = (IntRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'right_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->right_ = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: bottom_ of class  IntRect */
#ifndef TOLUA_DISABLE_tolua_get_IntRect_bottom
static int tolua_get_IntRect_bottom(lua_State* tolua_S)
{
  IntRect* self = (IntRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bottom_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->bottom_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: bottom_ of class  IntRect */
#ifndef TOLUA_DISABLE_tolua_set_IntRect_bottom
static int tolua_set_IntRect_bottom(lua_State* tolua_S)
{
  IntRect* self = (IntRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bottom_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->bottom_ = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ZERO of class  IntRect */
#ifndef TOLUA_DISABLE_tolua_get_IntRect_ZERO
static int tolua_get_IntRect_ZERO(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&IntRect::ZERO,"const IntRect");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: size of class  IntRect */
#ifndef TOLUA_DISABLE_tolua_get_IntRect_size
static int tolua_get_IntRect_size(lua_State* tolua_S)
{
  IntRect* self = (IntRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'size'",NULL);
#endif
 IntVector2 tolua_ret = (IntVector2)self->Size();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((IntVector2)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector2));
 tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: width of class  IntRect */
#ifndef TOLUA_DISABLE_tolua_get_IntRect_width
static int tolua_get_IntRect_width(lua_State* tolua_S)
{
  IntRect* self = (IntRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->Width());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: height of class  IntRect */
#ifndef TOLUA_DISABLE_tolua_get_IntRect_height
static int tolua_get_IntRect_height(lua_State* tolua_S)
{
  IntRect* self = (IntRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->Height());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_new00
static int tolua_MathLuaAPI_Sphere_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sphere",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Sphere* tolua_ret = (Sphere*)  Mtolua_new((Sphere)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sphere");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_new00_local
static int tolua_MathLuaAPI_Sphere_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sphere",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Sphere* tolua_ret = (Sphere*)  Mtolua_new((Sphere)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sphere");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_new01
static int tolua_MathLuaAPI_Sphere_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sphere",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Sphere",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Sphere* sphere = ((const Sphere*)  tolua_tousertype(tolua_S,2,0));
 {
  Sphere* tolua_ret = (Sphere*)  Mtolua_new((Sphere)(*sphere));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sphere");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Sphere_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_new01_local
static int tolua_MathLuaAPI_Sphere_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sphere",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Sphere",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Sphere* sphere = ((const Sphere*)  tolua_tousertype(tolua_S,2,0));
 {
  Sphere* tolua_ret = (Sphere*)  Mtolua_new((Sphere)(*sphere));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sphere");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Sphere_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_new02
static int tolua_MathLuaAPI_Sphere_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sphere",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* center = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float radius = ((float)  tolua_tonumber(tolua_S,3,0));
 {
  Sphere* tolua_ret = (Sphere*)  Mtolua_new((Sphere)(*center,radius));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sphere");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Sphere_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_new02_local
static int tolua_MathLuaAPI_Sphere_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sphere",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* center = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float radius = ((float)  tolua_tonumber(tolua_S,3,0));
 {
  Sphere* tolua_ret = (Sphere*)  Mtolua_new((Sphere)(*center,radius));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sphere");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Sphere_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_new03
static int tolua_MathLuaAPI_Sphere_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sphere",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const BoundingBox* box = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
 {
  Sphere* tolua_ret = (Sphere*)  Mtolua_new((Sphere)(*box));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sphere");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Sphere_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_new03_local
static int tolua_MathLuaAPI_Sphere_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sphere",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const BoundingBox* box = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
 {
  Sphere* tolua_ret = (Sphere*)  Mtolua_new((Sphere)(*box));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sphere");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Sphere_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_new04
static int tolua_MathLuaAPI_Sphere_new04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sphere",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Frustum",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Frustum* frustum = ((const Frustum*)  tolua_tousertype(tolua_S,2,0));
 {
  Sphere* tolua_ret = (Sphere*)  Mtolua_new((Sphere)(*frustum));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sphere");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Sphere_new03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_new04_local
static int tolua_MathLuaAPI_Sphere_new04_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sphere",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Frustum",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Frustum* frustum = ((const Frustum*)  tolua_tousertype(tolua_S,2,0));
 {
  Sphere* tolua_ret = (Sphere*)  Mtolua_new((Sphere)(*frustum));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sphere");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Sphere_new03_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_new05
static int tolua_MathLuaAPI_Sphere_new05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sphere",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Polyhedron",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Polyhedron* poly = ((const Polyhedron*)  tolua_tousertype(tolua_S,2,0));
 {
  Sphere* tolua_ret = (Sphere*)  Mtolua_new((Sphere)(*poly));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sphere");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Sphere_new04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_new05_local
static int tolua_MathLuaAPI_Sphere_new05_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sphere",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Polyhedron",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Polyhedron* poly = ((const Polyhedron*)  tolua_tousertype(tolua_S,2,0));
 {
  Sphere* tolua_ret = (Sphere*)  Mtolua_new((Sphere)(*poly));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sphere");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Sphere_new04_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_delete00
static int tolua_MathLuaAPI_Sphere_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sphere",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sphere* self = (Sphere*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
 Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere__eq00
static int tolua_MathLuaAPI_Sphere__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sphere",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Sphere",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sphere* self = (const Sphere*)  tolua_tousertype(tolua_S,1,0);
  const Sphere* rhs = ((const Sphere*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->operator==(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_Define00
static int tolua_MathLuaAPI_Sphere_Define00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sphere",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Sphere",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sphere* self = (Sphere*)  tolua_tousertype(tolua_S,1,0);
  const Sphere* sphere = ((const Sphere*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(*sphere);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Define'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_Define01
static int tolua_MathLuaAPI_Sphere_Define01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sphere",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Sphere* self = (Sphere*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* center = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float radius = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(*center,radius);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Sphere_Define00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_Define02
static int tolua_MathLuaAPI_Sphere_Define02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sphere",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Sphere* self = (Sphere*)  tolua_tousertype(tolua_S,1,0);
  const BoundingBox* box = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(*box);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Sphere_Define01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_Define03
static int tolua_MathLuaAPI_Sphere_Define03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sphere",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Frustum",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Sphere* self = (Sphere*)  tolua_tousertype(tolua_S,1,0);
  const Frustum* frustum = ((const Frustum*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(*frustum);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Sphere_Define02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Define of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_Define04
static int tolua_MathLuaAPI_Sphere_Define04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sphere",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Polyhedron",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Sphere* self = (Sphere*)  tolua_tousertype(tolua_S,1,0);
  const Polyhedron* poly = ((const Polyhedron*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Define'", NULL);
#endif
 {
  self->Define(*poly);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Sphere_Define03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Merge of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_Merge00
static int tolua_MathLuaAPI_Sphere_Merge00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sphere",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sphere* self = (Sphere*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Merge'", NULL);
#endif
 {
  self->Merge(*point);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Merge'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Merge of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_Merge01
static int tolua_MathLuaAPI_Sphere_Merge01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sphere",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Sphere* self = (Sphere*)  tolua_tousertype(tolua_S,1,0);
  const BoundingBox* box = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Merge'", NULL);
#endif
 {
  self->Merge(*box);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Sphere_Merge00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Merge of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_Merge02
static int tolua_MathLuaAPI_Sphere_Merge02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sphere",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Frustum",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Sphere* self = (Sphere*)  tolua_tousertype(tolua_S,1,0);
  const Frustum* frustum = ((const Frustum*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Merge'", NULL);
#endif
 {
  self->Merge(*frustum);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Sphere_Merge01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Merge of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_Merge03
static int tolua_MathLuaAPI_Sphere_Merge03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sphere",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Polyhedron",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Sphere* self = (Sphere*)  tolua_tousertype(tolua_S,1,0);
  const Polyhedron* poly = ((const Polyhedron*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Merge'", NULL);
#endif
 {
  self->Merge(*poly);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Sphere_Merge02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Merge of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_Merge04
static int tolua_MathLuaAPI_Sphere_Merge04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sphere",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Sphere",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Sphere* self = (Sphere*)  tolua_tousertype(tolua_S,1,0);
  const Sphere* sphere = ((const Sphere*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Merge'", NULL);
#endif
 {
  self->Merge(*sphere);
 }
 }
 return 0;
tolua_lerror:
 return tolua_MathLuaAPI_Sphere_Merge03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_Clear00
static int tolua_MathLuaAPI_Sphere_Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sphere",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sphere* self = (Sphere*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'", NULL);
#endif
 {
  self->Clear();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Defined of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_Defined00
static int tolua_MathLuaAPI_Sphere_Defined00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sphere",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sphere* self = (const Sphere*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Defined'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Defined();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Defined'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsInside of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_IsInside00
static int tolua_MathLuaAPI_Sphere_IsInside00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sphere",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sphere* self = (const Sphere*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsInside'", NULL);
#endif
 {
  Intersection tolua_ret = (Intersection)  self->IsInside(*point);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsInside'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsInside of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_IsInside01
static int tolua_MathLuaAPI_Sphere_IsInside01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sphere",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Sphere",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Sphere* self = (const Sphere*)  tolua_tousertype(tolua_S,1,0);
  const Sphere* sphere = ((const Sphere*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsInside'", NULL);
#endif
 {
  Intersection tolua_ret = (Intersection)  self->IsInside(*sphere);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Sphere_IsInside00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsInsideFast of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_IsInsideFast00
static int tolua_MathLuaAPI_Sphere_IsInsideFast00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sphere",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Sphere",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sphere* self = (const Sphere*)  tolua_tousertype(tolua_S,1,0);
  const Sphere* sphere = ((const Sphere*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsInsideFast'", NULL);
#endif
 {
  Intersection tolua_ret = (Intersection)  self->IsInsideFast(*sphere);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsInsideFast'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsInside of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_IsInside02
static int tolua_MathLuaAPI_Sphere_IsInside02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sphere",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Sphere* self = (const Sphere*)  tolua_tousertype(tolua_S,1,0);
  const BoundingBox* box = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsInside'", NULL);
#endif
 {
  Intersection tolua_ret = (Intersection)  self->IsInside(*box);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Sphere_IsInside01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsInsideFast of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_IsInsideFast01
static int tolua_MathLuaAPI_Sphere_IsInsideFast01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sphere",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Sphere* self = (const Sphere*)  tolua_tousertype(tolua_S,1,0);
  const BoundingBox* box = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsInsideFast'", NULL);
#endif
 {
  Intersection tolua_ret = (Intersection)  self->IsInsideFast(*box);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Sphere_IsInsideFast00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Distance of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_Distance00
static int tolua_MathLuaAPI_Sphere_Distance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sphere",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sphere* self = (const Sphere*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Distance'", NULL);
#endif
 {
  float tolua_ret = (float)  self->Distance(*point);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Distance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLocalPoint of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_GetLocalPoint00
static int tolua_MathLuaAPI_Sphere_GetLocalPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sphere",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sphere* self = (const Sphere*)  tolua_tousertype(tolua_S,1,0);
  float theta = ((float)  tolua_tonumber(tolua_S,2,0));
  float phi = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLocalPoint'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetLocalPoint(theta,phi);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLocalPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPoint of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Sphere_GetPoint00
static int tolua_MathLuaAPI_Sphere_GetPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sphere",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sphere* self = (const Sphere*)  tolua_tousertype(tolua_S,1,0);
  float theta = ((float)  tolua_tonumber(tolua_S,2,0));
  float phi = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPoint'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetPoint(theta,phi);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: center_ of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_get_Sphere_center
static int tolua_get_Sphere_center(lua_State* tolua_S)
{
  Sphere* self = (Sphere*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'center_'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->center_,"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: center_ of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_set_Sphere_center
static int tolua_set_Sphere_center(lua_State* tolua_S)
{
  Sphere* self = (Sphere*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'center_'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->center_ = *((Vector3*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: radius_ of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_get_Sphere_radius
static int tolua_get_Sphere_radius(lua_State* tolua_S)
{
  Sphere* self = (Sphere*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'radius_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->radius_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: radius_ of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_set_Sphere_radius
static int tolua_set_Sphere_radius(lua_State* tolua_S)
{
  Sphere* self = (Sphere*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'radius_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->radius_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  StringHash */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_StringHash_new00
static int tolua_MathLuaAPI_StringHash_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"StringHash",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  StringHash* tolua_ret = (StringHash*)  Mtolua_new((StringHash)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"StringHash");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  StringHash */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_StringHash_new00_local
static int tolua_MathLuaAPI_StringHash_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"StringHash",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  StringHash* tolua_ret = (StringHash*)  Mtolua_new((StringHash)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"StringHash");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  StringHash */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_StringHash_new01
static int tolua_MathLuaAPI_StringHash_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"StringHash",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const StringHash",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const StringHash* rhs = ((const StringHash*)  tolua_tousertype(tolua_S,2,0));
 {
  StringHash* tolua_ret = (StringHash*)  Mtolua_new((StringHash)(*rhs));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"StringHash");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_StringHash_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  StringHash */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_StringHash_new01_local
static int tolua_MathLuaAPI_StringHash_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"StringHash",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const StringHash",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const StringHash* rhs = ((const StringHash*)  tolua_tousertype(tolua_S,2,0));
 {
  StringHash* tolua_ret = (StringHash*)  Mtolua_new((StringHash)(*rhs));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"StringHash");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_StringHash_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  StringHash */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_StringHash_new02
static int tolua_MathLuaAPI_StringHash_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"StringHash",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const char* str = ((const char*)  tolua_tostring(tolua_S,2,0));
 {
  StringHash* tolua_ret = (StringHash*)  Mtolua_new((StringHash)(str));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"StringHash");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_StringHash_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  StringHash */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_StringHash_new02_local
static int tolua_MathLuaAPI_StringHash_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"StringHash",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const char* str = ((const char*)  tolua_tostring(tolua_S,2,0));
 {
  StringHash* tolua_ret = (StringHash*)  Mtolua_new((StringHash)(str));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"StringHash");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_StringHash_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  StringHash */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_StringHash_new03
static int tolua_MathLuaAPI_StringHash_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"StringHash",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  unsigned value = ((unsigned)  tolua_tonumber(tolua_S,2,0));
 {
  StringHash* tolua_ret = (StringHash*)  Mtolua_new((StringHash)(value));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"StringHash");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_StringHash_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  StringHash */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_StringHash_new03_local
static int tolua_MathLuaAPI_StringHash_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"StringHash",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  unsigned value = ((unsigned)  tolua_tonumber(tolua_S,2,0));
 {
  StringHash* tolua_ret = (StringHash*)  Mtolua_new((StringHash)(value));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"StringHash");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_StringHash_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  StringHash */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_StringHash_delete00
static int tolua_MathLuaAPI_StringHash_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StringHash",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StringHash* self = (StringHash*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
 Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  StringHash */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_StringHash__add00
static int tolua_MathLuaAPI_StringHash__add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const StringHash",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const StringHash",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const StringHash* self = (const StringHash*)  tolua_tousertype(tolua_S,1,0);
  const StringHash* rhs = ((const StringHash*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
 {
  StringHash tolua_ret = (StringHash)  self->operator+(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((StringHash)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"StringHash");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(StringHash));
  tolua_pushusertype(tolua_S,tolua_obj,"StringHash");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  StringHash */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_StringHash__eq00
static int tolua_MathLuaAPI_StringHash__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const StringHash",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const StringHash",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const StringHash* self = (const StringHash*)  tolua_tousertype(tolua_S,1,0);
  const StringHash* rhs = ((const StringHash*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->operator==(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator< of class  StringHash */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_StringHash__lt00
static int tolua_MathLuaAPI_StringHash__lt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const StringHash",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const StringHash",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const StringHash* self = (const StringHash*)  tolua_tousertype(tolua_S,1,0);
  const StringHash* rhs = ((const StringHash*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator<'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->operator<(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.lt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operatorbool of class  StringHash */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_StringHash__bool00
static int tolua_MathLuaAPI_StringHash__bool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const StringHash",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const StringHash* self = (const StringHash*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operatorbool'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->operator  bool();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.bool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Value of class  StringHash */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_StringHash_Value00
static int tolua_MathLuaAPI_StringHash_Value00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const StringHash",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const StringHash* self = (const StringHash*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Value'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->Value();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Value'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToString of class  StringHash */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_StringHash_ToString00
static int tolua_MathLuaAPI_StringHash_ToString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const StringHash",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const StringHash* self = (const StringHash*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToString'", NULL);
#endif
 {
  String tolua_ret = (String)  self->ToString();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToHash of class  StringHash */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_StringHash_ToHash00
static int tolua_MathLuaAPI_StringHash_ToHash00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const StringHash",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const StringHash* self = (const StringHash*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToHash'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->ToHash();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToHash'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Calculate of class  StringHash */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_StringHash_Calculate00
static int tolua_MathLuaAPI_StringHash_Calculate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"StringHash",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* str = ((const char*)  tolua_tostring(tolua_S,2,0));
  unsigned hash = ((unsigned)  tolua_tonumber(tolua_S,3,0));
 {
  unsigned tolua_ret = (unsigned)  StringHash::Calculate(str,hash);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Calculate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ZERO of class  StringHash */
#ifndef TOLUA_DISABLE_tolua_get_StringHash_ZERO
static int tolua_get_StringHash_ZERO(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&StringHash::ZERO,"const StringHash");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: value of class  StringHash */
#ifndef TOLUA_DISABLE_tolua_get_StringHash_value
static int tolua_get_StringHash_value(lua_State* tolua_S)
{
  StringHash* self = (StringHash*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->Value());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2_new00
static int tolua_MathLuaAPI_Vector2_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Vector2* tolua_ret = (Vector2*)  Mtolua_new((Vector2)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2_new00_local
static int tolua_MathLuaAPI_Vector2_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Vector2* tolua_ret = (Vector2*)  Mtolua_new((Vector2)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2_new01
static int tolua_MathLuaAPI_Vector2_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector2* vector = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
 {
  Vector2* tolua_ret = (Vector2*)  Mtolua_new((Vector2)(*vector));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector2");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector2_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2_new01_local
static int tolua_MathLuaAPI_Vector2_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector2* vector = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
 {
  Vector2* tolua_ret = (Vector2*)  Mtolua_new((Vector2)(*vector));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector2_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2_new02
static int tolua_MathLuaAPI_Vector2_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const IntVector2* vector = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
 {
  Vector2* tolua_ret = (Vector2*)  Mtolua_new((Vector2)(*vector));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector2");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector2_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2_new02_local
static int tolua_MathLuaAPI_Vector2_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const IntVector2* vector = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
 {
  Vector2* tolua_ret = (Vector2*)  Mtolua_new((Vector2)(*vector));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector2_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2_new03
static int tolua_MathLuaAPI_Vector2_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
 {
  Vector2* tolua_ret = (Vector2*)  Mtolua_new((Vector2)(x,y));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector2");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector2_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2_new03_local
static int tolua_MathLuaAPI_Vector2_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
 {
  Vector2* tolua_ret = (Vector2*)  Mtolua_new((Vector2)(x,y));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector2_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2_delete00
static int tolua_MathLuaAPI_Vector2_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Vector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
 Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2__eq00
static int tolua_MathLuaAPI_Vector2__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* rhs = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->operator==(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2__add00
static int tolua_MathLuaAPI_Vector2__add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* rhs = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->operator+(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2__sub00
static int tolua_MathLuaAPI_Vector2__sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->operator-();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2__sub01
static int tolua_MathLuaAPI_Vector2__sub01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* rhs = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->operator-(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector2__sub00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2__mul00
static int tolua_MathLuaAPI_Vector2__mul00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->operator*(rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2__mul01
static int tolua_MathLuaAPI_Vector2__mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* rhs = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->operator*(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector2__mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2__div00
static int tolua_MathLuaAPI_Vector2__div00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->operator/(rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.div'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2__div01
static int tolua_MathLuaAPI_Vector2__div01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* rhs = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->operator/(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector2__div00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Normalize of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2_Normalize00
static int tolua_MathLuaAPI_Vector2_Normalize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Vector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Normalize'", NULL);
#endif
 {
  self->Normalize();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Normalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Length of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2_Length00
static int tolua_MathLuaAPI_Vector2_Length00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Length'", NULL);
#endif
 {
  float tolua_ret = (float)  self->Length();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Length'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LengthSquared of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2_LengthSquared00
static int tolua_MathLuaAPI_Vector2_LengthSquared00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LengthSquared'", NULL);
#endif
 {
  float tolua_ret = (float)  self->LengthSquared();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LengthSquared'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DotProduct of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2_DotProduct00
static int tolua_MathLuaAPI_Vector2_DotProduct00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* rhs = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DotProduct'", NULL);
#endif
 {
  float tolua_ret = (float)  self->DotProduct(*rhs);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DotProduct'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AbsDotProduct of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2_AbsDotProduct00
static int tolua_MathLuaAPI_Vector2_AbsDotProduct00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* rhs = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AbsDotProduct'", NULL);
#endif
 {
  float tolua_ret = (float)  self->AbsDotProduct(*rhs);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AbsDotProduct'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ProjectOntoAxis of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2_ProjectOntoAxis00
static int tolua_MathLuaAPI_Vector2_ProjectOntoAxis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* axis = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ProjectOntoAxis'", NULL);
#endif
 {
  float tolua_ret = (float)  self->ProjectOntoAxis(*axis);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ProjectOntoAxis'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Angle of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2_Angle00
static int tolua_MathLuaAPI_Vector2_Angle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* rhs = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Angle'", NULL);
#endif
 {
  float tolua_ret = (float)  self->Angle(*rhs);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Angle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Abs of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2_Abs00
static int tolua_MathLuaAPI_Vector2_Abs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Abs'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->Abs();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Abs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Lerp of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2_Lerp00
static int tolua_MathLuaAPI_Vector2_Lerp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* rhs = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  float t = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Lerp'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->Lerp(*rhs,t);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Lerp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Equals of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2_Equals00
static int tolua_MathLuaAPI_Vector2_Equals00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* rhs = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Equals'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Equals(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Equals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsNaN of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2_IsNaN00
static int tolua_MathLuaAPI_Vector2_IsNaN00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsNaN'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsNaN();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsNaN'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Normalized of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2_Normalized00
static int tolua_MathLuaAPI_Vector2_Normalized00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Normalized'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->Normalized();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Normalized'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToString of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector2_ToString00
static int tolua_MathLuaAPI_Vector2_ToString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToString'", NULL);
#endif
 {
  String tolua_ret = (String)  self->ToString();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x_ of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_get_Vector2_x
static int tolua_get_Vector2_x(lua_State* tolua_S)
{
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->x_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x_ of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_set_Vector2_x
static int tolua_set_Vector2_x(lua_State* tolua_S)
{
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y_ of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_get_Vector2_y
static int tolua_get_Vector2_y(lua_State* tolua_S)
{
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->y_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y_ of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_set_Vector2_y
static int tolua_set_Vector2_y(lua_State* tolua_S)
{
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ZERO of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_get_Vector2_ZERO
static int tolua_get_Vector2_ZERO(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Vector2::ZERO,"const Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: LEFT of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_get_Vector2_LEFT
static int tolua_get_Vector2_LEFT(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Vector2::LEFT,"const Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: RIGHT of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_get_Vector2_RIGHT
static int tolua_get_Vector2_RIGHT(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Vector2::RIGHT,"const Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: UP of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_get_Vector2_UP
static int tolua_get_Vector2_UP(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Vector2::UP,"const Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DOWN of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_get_Vector2_DOWN
static int tolua_get_Vector2_DOWN(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Vector2::DOWN,"const Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ONE of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_get_Vector2_ONE
static int tolua_get_Vector2_ONE(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Vector2::ONE,"const Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  IntVector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector2_new00
static int tolua_MathLuaAPI_IntVector2_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"IntVector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  IntVector2* tolua_ret = (IntVector2*)  Mtolua_new((IntVector2)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"IntVector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  IntVector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector2_new00_local
static int tolua_MathLuaAPI_IntVector2_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"IntVector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  IntVector2* tolua_ret = (IntVector2*)  Mtolua_new((IntVector2)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  IntVector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector2_new01
static int tolua_MathLuaAPI_IntVector2_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"IntVector2",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  IntVector2* tolua_ret = (IntVector2*)  Mtolua_new((IntVector2)(x,y));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"IntVector2");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_IntVector2_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  IntVector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector2_new01_local
static int tolua_MathLuaAPI_IntVector2_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"IntVector2",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  IntVector2* tolua_ret = (IntVector2*)  Mtolua_new((IntVector2)(x,y));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_IntVector2_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  IntVector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector2_new02
static int tolua_MathLuaAPI_IntVector2_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"IntVector2",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const IntVector2* rhs = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
 {
  IntVector2* tolua_ret = (IntVector2*)  Mtolua_new((IntVector2)(*rhs));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"IntVector2");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_IntVector2_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  IntVector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector2_new02_local
static int tolua_MathLuaAPI_IntVector2_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"IntVector2",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const IntVector2* rhs = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
 {
  IntVector2* tolua_ret = (IntVector2*)  Mtolua_new((IntVector2)(*rhs));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_IntVector2_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  IntVector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector2_delete00
static int tolua_MathLuaAPI_IntVector2_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"IntVector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  IntVector2* self = (IntVector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
 Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  IntVector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector2__eq00
static int tolua_MathLuaAPI_IntVector2__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IntVector2",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IntVector2* self = (const IntVector2*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* rhs = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->operator==(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  IntVector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector2__add00
static int tolua_MathLuaAPI_IntVector2__add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IntVector2",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IntVector2* self = (const IntVector2*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* rhs = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
 {
  IntVector2 tolua_ret = (IntVector2)  self->operator+(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector2));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  IntVector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector2__sub00
static int tolua_MathLuaAPI_IntVector2__sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IntVector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IntVector2* self = (const IntVector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
 {
  IntVector2 tolua_ret = (IntVector2)  self->operator-();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector2));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  IntVector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector2__sub01
static int tolua_MathLuaAPI_IntVector2__sub01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IntVector2",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const IntVector2* self = (const IntVector2*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* rhs = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
 {
  IntVector2 tolua_ret = (IntVector2)  self->operator-(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector2));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_IntVector2__sub00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  IntVector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector2__mul00
static int tolua_MathLuaAPI_IntVector2__mul00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IntVector2",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IntVector2* self = (const IntVector2*)  tolua_tousertype(tolua_S,1,0);
  int rhs = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
 {
  IntVector2 tolua_ret = (IntVector2)  self->operator*(rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector2));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  IntVector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector2__mul01
static int tolua_MathLuaAPI_IntVector2__mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IntVector2",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const IntVector2* self = (const IntVector2*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* rhs = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
 {
  IntVector2 tolua_ret = (IntVector2)  self->operator*(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector2));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_IntVector2__mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  IntVector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector2__div00
static int tolua_MathLuaAPI_IntVector2__div00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IntVector2",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IntVector2* self = (const IntVector2*)  tolua_tousertype(tolua_S,1,0);
  int rhs = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
 {
  IntVector2 tolua_ret = (IntVector2)  self->operator/(rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector2));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.div'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  IntVector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector2__div01
static int tolua_MathLuaAPI_IntVector2__div01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IntVector2",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const IntVector2* self = (const IntVector2*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* rhs = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
 {
  IntVector2 tolua_ret = (IntVector2)  self->operator/(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector2));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_IntVector2__div00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToString of class  IntVector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector2_ToString00
static int tolua_MathLuaAPI_IntVector2_ToString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IntVector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IntVector2* self = (const IntVector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToString'", NULL);
#endif
 {
  String tolua_ret = (String)  self->ToString();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToHash of class  IntVector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector2_ToHash00
static int tolua_MathLuaAPI_IntVector2_ToHash00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IntVector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IntVector2* self = (const IntVector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToHash'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->ToHash();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToHash'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Length of class  IntVector2 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector2_Length00
static int tolua_MathLuaAPI_IntVector2_Length00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IntVector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IntVector2* self = (const IntVector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Length'", NULL);
#endif
 {
  float tolua_ret = (float)  self->Length();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Length'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x_ of class  IntVector2 */
#ifndef TOLUA_DISABLE_tolua_get_IntVector2_x
static int tolua_get_IntVector2_x(lua_State* tolua_S)
{
  IntVector2* self = (IntVector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->x_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x_ of class  IntVector2 */
#ifndef TOLUA_DISABLE_tolua_set_IntVector2_x
static int tolua_set_IntVector2_x(lua_State* tolua_S)
{
  IntVector2* self = (IntVector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x_ = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y_ of class  IntVector2 */
#ifndef TOLUA_DISABLE_tolua_get_IntVector2_y
static int tolua_get_IntVector2_y(lua_State* tolua_S)
{
  IntVector2* self = (IntVector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->y_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y_ of class  IntVector2 */
#ifndef TOLUA_DISABLE_tolua_set_IntVector2_y
static int tolua_set_IntVector2_y(lua_State* tolua_S)
{
  IntVector2* self = (IntVector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y_ = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ZERO of class  IntVector2 */
#ifndef TOLUA_DISABLE_tolua_get_IntVector2_ZERO
static int tolua_get_IntVector2_ZERO(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&IntVector2::ZERO,"const IntVector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: LEFT of class  IntVector2 */
#ifndef TOLUA_DISABLE_tolua_get_IntVector2_LEFT
static int tolua_get_IntVector2_LEFT(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&IntVector2::LEFT,"const IntVector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: RIGHT of class  IntVector2 */
#ifndef TOLUA_DISABLE_tolua_get_IntVector2_RIGHT
static int tolua_get_IntVector2_RIGHT(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&IntVector2::RIGHT,"const IntVector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: UP of class  IntVector2 */
#ifndef TOLUA_DISABLE_tolua_get_IntVector2_UP
static int tolua_get_IntVector2_UP(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&IntVector2::UP,"const IntVector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DOWN of class  IntVector2 */
#ifndef TOLUA_DISABLE_tolua_get_IntVector2_DOWN
static int tolua_get_IntVector2_DOWN(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&IntVector2::DOWN,"const IntVector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ONE of class  IntVector2 */
#ifndef TOLUA_DISABLE_tolua_get_IntVector2_ONE
static int tolua_get_IntVector2_ONE(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&IntVector2::ONE,"const IntVector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* function: VectorLerp */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_VectorLerp00
static int tolua_MathLuaAPI_VectorLerp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector2* lhs = ((const Vector2*)  tolua_tousertype(tolua_S,1,0));
  const Vector2* rhs = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  const Vector2* t = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
 {
  Vector2 tolua_ret = (Vector2)  VectorLerp(*lhs,*rhs,*t);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'VectorLerp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: VectorMin */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_VectorMin00
static int tolua_MathLuaAPI_VectorMin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector2* lhs = ((const Vector2*)  tolua_tousertype(tolua_S,1,0));
  const Vector2* rhs = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
 {
  Vector2 tolua_ret = (Vector2)  VectorMin(*lhs,*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'VectorMin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: VectorMax */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_VectorMax00
static int tolua_MathLuaAPI_VectorMax00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector2* lhs = ((const Vector2*)  tolua_tousertype(tolua_S,1,0));
  const Vector2* rhs = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
 {
  Vector2 tolua_ret = (Vector2)  VectorMax(*lhs,*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'VectorMax'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: VectorFloor */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_VectorFloor00
static int tolua_MathLuaAPI_VectorFloor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector2* vec = ((const Vector2*)  tolua_tousertype(tolua_S,1,0));
 {
  Vector2 tolua_ret = (Vector2)  VectorFloor(*vec);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'VectorFloor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: VectorRound */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_VectorRound00
static int tolua_MathLuaAPI_VectorRound00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector2* vec = ((const Vector2*)  tolua_tousertype(tolua_S,1,0));
 {
  Vector2 tolua_ret = (Vector2)  VectorRound(*vec);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'VectorRound'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: VectorCeil */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_VectorCeil00
static int tolua_MathLuaAPI_VectorCeil00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector2* vec = ((const Vector2*)  tolua_tousertype(tolua_S,1,0));
 {
  Vector2 tolua_ret = (Vector2)  VectorCeil(*vec);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'VectorCeil'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: VectorFloorToInt */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_VectorFloorToInt00
static int tolua_MathLuaAPI_VectorFloorToInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector2* vec = ((const Vector2*)  tolua_tousertype(tolua_S,1,0));
 {
  IntVector2 tolua_ret = (IntVector2)  VectorFloorToInt(*vec);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector2));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'VectorFloorToInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: VectorRoundToInt */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_VectorRoundToInt00
static int tolua_MathLuaAPI_VectorRoundToInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector2* vec = ((const Vector2*)  tolua_tousertype(tolua_S,1,0));
 {
  IntVector2 tolua_ret = (IntVector2)  VectorRoundToInt(*vec);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector2));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'VectorRoundToInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: VectorCeilToInt */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_VectorCeilToInt00
static int tolua_MathLuaAPI_VectorCeilToInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector2* vec = ((const Vector2*)  tolua_tousertype(tolua_S,1,0));
 {
  IntVector2 tolua_ret = (IntVector2)  VectorCeilToInt(*vec);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector2));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'VectorCeilToInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: VectorMin */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_VectorMin01
static int tolua_MathLuaAPI_VectorMin01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const IntVector2",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const IntVector2* lhs = ((const IntVector2*)  tolua_tousertype(tolua_S,1,0));
  const IntVector2* rhs = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
 {
  IntVector2 tolua_ret = (IntVector2)  VectorMin(*lhs,*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector2));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_VectorMin00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: VectorMax */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_VectorMax01
static int tolua_MathLuaAPI_VectorMax01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const IntVector2",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const IntVector2* lhs = ((const IntVector2*)  tolua_tousertype(tolua_S,1,0));
  const IntVector2* rhs = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
 {
  IntVector2 tolua_ret = (IntVector2)  VectorMax(*lhs,*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector2));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_VectorMax00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: StableRandom */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_StableRandom00
static int tolua_MathLuaAPI_StableRandom00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector2* seed = ((const Vector2*)  tolua_tousertype(tolua_S,1,0));
 {
  float tolua_ret = (float)  StableRandom(*seed);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'StableRandom'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: StableRandom */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_StableRandom01
static int tolua_MathLuaAPI_StableRandom01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float seed = ((float)  tolua_tonumber(tolua_S,1,0));
 {
  float tolua_ret = (float)  StableRandom(seed);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_StableRandom00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_new00
static int tolua_MathLuaAPI_Vector3_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Vector3* tolua_ret = (Vector3*)  Mtolua_new((Vector3)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector3");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_new00_local
static int tolua_MathLuaAPI_Vector3_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Vector3* tolua_ret = (Vector3*)  Mtolua_new((Vector3)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_new01
static int tolua_MathLuaAPI_Vector3_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* vector = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
 {
  Vector3* tolua_ret = (Vector3*)  Mtolua_new((Vector3)(*vector));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector3");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector3_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_new01_local
static int tolua_MathLuaAPI_Vector3_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* vector = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
 {
  Vector3* tolua_ret = (Vector3*)  Mtolua_new((Vector3)(*vector));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector3_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_new02
static int tolua_MathLuaAPI_Vector3_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector2* vector = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  float z = ((float)  tolua_tonumber(tolua_S,3,0));
 {
  Vector3* tolua_ret = (Vector3*)  Mtolua_new((Vector3)(*vector,z));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector3");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector3_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_new02_local
static int tolua_MathLuaAPI_Vector3_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector2* vector = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  float z = ((float)  tolua_tonumber(tolua_S,3,0));
 {
  Vector3* tolua_ret = (Vector3*)  Mtolua_new((Vector3)(*vector,z));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector3_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_new03
static int tolua_MathLuaAPI_Vector3_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector2* vector = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
 {
  Vector3* tolua_ret = (Vector3*)  Mtolua_new((Vector3)(*vector));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector3");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector3_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_new03_local
static int tolua_MathLuaAPI_Vector3_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector2* vector = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
 {
  Vector3* tolua_ret = (Vector3*)  Mtolua_new((Vector3)(*vector));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector3_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_new04
static int tolua_MathLuaAPI_Vector3_new04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const IntVector3* vector = ((const IntVector3*)  tolua_tousertype(tolua_S,2,0));
 {
  Vector3* tolua_ret = (Vector3*)  Mtolua_new((Vector3)(*vector));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector3");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector3_new03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_new04_local
static int tolua_MathLuaAPI_Vector3_new04_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const IntVector3* vector = ((const IntVector3*)  tolua_tousertype(tolua_S,2,0));
 {
  Vector3* tolua_ret = (Vector3*)  Mtolua_new((Vector3)(*vector));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector3_new03_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_new05
static int tolua_MathLuaAPI_Vector3_new05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
 {
  Vector3* tolua_ret = (Vector3*)  Mtolua_new((Vector3)(x,y,z));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector3");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector3_new04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_new05_local
static int tolua_MathLuaAPI_Vector3_new05_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
 {
  Vector3* tolua_ret = (Vector3*)  Mtolua_new((Vector3)(x,y,z));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector3_new04_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_new06
static int tolua_MathLuaAPI_Vector3_new06(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
 {
  Vector3* tolua_ret = (Vector3*)  Mtolua_new((Vector3)(x,y));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector3");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector3_new05(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_new06_local
static int tolua_MathLuaAPI_Vector3_new06_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
 {
  Vector3* tolua_ret = (Vector3*)  Mtolua_new((Vector3)(x,y));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector3_new05_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_delete00
static int tolua_MathLuaAPI_Vector3_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Vector3",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
 Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3__eq00
static int tolua_MathLuaAPI_Vector3__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* rhs = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->operator==(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3__add00
static int tolua_MathLuaAPI_Vector3__add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* rhs = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->operator+(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3__sub00
static int tolua_MathLuaAPI_Vector3__sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->operator-();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3__sub01
static int tolua_MathLuaAPI_Vector3__sub01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* rhs = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->operator-(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector3__sub00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3__mul00
static int tolua_MathLuaAPI_Vector3__mul00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->operator*(rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3__mul01
static int tolua_MathLuaAPI_Vector3__mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* rhs = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->operator*(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector3__mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3__div00
static int tolua_MathLuaAPI_Vector3__div00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->operator/(rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.div'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3__div01
static int tolua_MathLuaAPI_Vector3__div01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* rhs = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->operator/(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector3__div00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Normalize of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_Normalize00
static int tolua_MathLuaAPI_Vector3_Normalize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Vector3",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Normalize'", NULL);
#endif
 {
  self->Normalize();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Normalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Length of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_Length00
static int tolua_MathLuaAPI_Vector3_Length00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Length'", NULL);
#endif
 {
  float tolua_ret = (float)  self->Length();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Length'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LengthSquared of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_LengthSquared00
static int tolua_MathLuaAPI_Vector3_LengthSquared00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LengthSquared'", NULL);
#endif
 {
  float tolua_ret = (float)  self->LengthSquared();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LengthSquared'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DotProduct of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_DotProduct00
static int tolua_MathLuaAPI_Vector3_DotProduct00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* rhs = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DotProduct'", NULL);
#endif
 {
  float tolua_ret = (float)  self->DotProduct(*rhs);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DotProduct'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AbsDotProduct of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_AbsDotProduct00
static int tolua_MathLuaAPI_Vector3_AbsDotProduct00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* rhs = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AbsDotProduct'", NULL);
#endif
 {
  float tolua_ret = (float)  self->AbsDotProduct(*rhs);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AbsDotProduct'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ProjectOntoAxis of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_ProjectOntoAxis00
static int tolua_MathLuaAPI_Vector3_ProjectOntoAxis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* axis = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ProjectOntoAxis'", NULL);
#endif
 {
  float tolua_ret = (float)  self->ProjectOntoAxis(*axis);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ProjectOntoAxis'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ProjectOntoPlane of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_ProjectOntoPlane00
static int tolua_MathLuaAPI_Vector3_ProjectOntoPlane00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Vector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* origin = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* normal = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ProjectOntoPlane'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->ProjectOntoPlane(*origin,*normal);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ProjectOntoPlane'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ProjectOntoLine of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_ProjectOntoLine00
static int tolua_MathLuaAPI_Vector3_ProjectOntoLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Vector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* from = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* to = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  bool clamped = ((bool)  tolua_toboolean(tolua_S,4,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ProjectOntoLine'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->ProjectOntoLine(*from,*to,clamped);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ProjectOntoLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DistanceToPoint of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_DistanceToPoint00
static int tolua_MathLuaAPI_Vector3_DistanceToPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DistanceToPoint'", NULL);
#endif
 {
  float tolua_ret = (float)  self->DistanceToPoint(*point);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DistanceToPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DistanceToPlane of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_DistanceToPlane00
static int tolua_MathLuaAPI_Vector3_DistanceToPlane00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* origin = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* normal = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DistanceToPlane'", NULL);
#endif
 {
  float tolua_ret = (float)  self->DistanceToPlane(*origin,*normal);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DistanceToPlane'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Orthogonalize of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_Orthogonalize00
static int tolua_MathLuaAPI_Vector3_Orthogonalize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* axis = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Orthogonalize'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->Orthogonalize(*axis);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Orthogonalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CrossProduct of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_CrossProduct00
static int tolua_MathLuaAPI_Vector3_CrossProduct00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* rhs = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CrossProduct'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->CrossProduct(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CrossProduct'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Abs of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_Abs00
static int tolua_MathLuaAPI_Vector3_Abs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Abs'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->Abs();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Abs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Lerp of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_Lerp00
static int tolua_MathLuaAPI_Vector3_Lerp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* rhs = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float t = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Lerp'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->Lerp(*rhs,t);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Lerp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Equals of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_Equals00
static int tolua_MathLuaAPI_Vector3_Equals00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* rhs = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Equals'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Equals(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Equals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsNaN of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_IsNaN00
static int tolua_MathLuaAPI_Vector3_IsNaN00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsNaN'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsNaN();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsNaN'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Angle of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_Angle00
static int tolua_MathLuaAPI_Vector3_Angle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* rhs = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Angle'", NULL);
#endif
 {
  float tolua_ret = (float)  self->Angle(*rhs);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Angle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Normalized of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_Normalized00
static int tolua_MathLuaAPI_Vector3_Normalized00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Normalized'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->Normalized();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Normalized'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToString of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector3_ToString00
static int tolua_MathLuaAPI_Vector3_ToString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToString'", NULL);
#endif
 {
  String tolua_ret = (String)  self->ToString();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x_ of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_x
static int tolua_get_Vector3_x(lua_State* tolua_S)
{
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->x_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x_ of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_set_Vector3_x
static int tolua_set_Vector3_x(lua_State* tolua_S)
{
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y_ of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_y
static int tolua_get_Vector3_y(lua_State* tolua_S)
{
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->y_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y_ of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_set_Vector3_y
static int tolua_set_Vector3_y(lua_State* tolua_S)
{
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: z_ of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_z
static int tolua_get_Vector3_z(lua_State* tolua_S)
{
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->z_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: z_ of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_set_Vector3_z
static int tolua_set_Vector3_z(lua_State* tolua_S)
{
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->z_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ZERO of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_ZERO
static int tolua_get_Vector3_ZERO(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Vector3::ZERO,"const Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: LEFT of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_LEFT
static int tolua_get_Vector3_LEFT(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Vector3::LEFT,"const Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: RIGHT of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_RIGHT
static int tolua_get_Vector3_RIGHT(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Vector3::RIGHT,"const Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: UP of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_UP
static int tolua_get_Vector3_UP(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Vector3::UP,"const Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DOWN of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_DOWN
static int tolua_get_Vector3_DOWN(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Vector3::DOWN,"const Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: FORWARD of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_FORWARD
static int tolua_get_Vector3_FORWARD(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Vector3::FORWARD,"const Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: BACK of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_BACK
static int tolua_get_Vector3_BACK(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Vector3::BACK,"const Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ONE of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_ONE
static int tolua_get_Vector3_ONE(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Vector3::ONE,"const Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector3_new00
static int tolua_MathLuaAPI_IntVector3_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"IntVector3",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  IntVector3* tolua_ret = (IntVector3*)  Mtolua_new((IntVector3)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"IntVector3");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector3_new00_local
static int tolua_MathLuaAPI_IntVector3_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"IntVector3",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  IntVector3* tolua_ret = (IntVector3*)  Mtolua_new((IntVector3)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector3_new01
static int tolua_MathLuaAPI_IntVector3_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"IntVector3",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int z = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  IntVector3* tolua_ret = (IntVector3*)  Mtolua_new((IntVector3)(x,y,z));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"IntVector3");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_IntVector3_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector3_new01_local
static int tolua_MathLuaAPI_IntVector3_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"IntVector3",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int z = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  IntVector3* tolua_ret = (IntVector3*)  Mtolua_new((IntVector3)(x,y,z));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_IntVector3_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector3_new02
static int tolua_MathLuaAPI_IntVector3_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"IntVector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const IntVector3* rhs = ((const IntVector3*)  tolua_tousertype(tolua_S,2,0));
 {
  IntVector3* tolua_ret = (IntVector3*)  Mtolua_new((IntVector3)(*rhs));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"IntVector3");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_IntVector3_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector3_new02_local
static int tolua_MathLuaAPI_IntVector3_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"IntVector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const IntVector3* rhs = ((const IntVector3*)  tolua_tousertype(tolua_S,2,0));
 {
  IntVector3* tolua_ret = (IntVector3*)  Mtolua_new((IntVector3)(*rhs));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_IntVector3_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector3_delete00
static int tolua_MathLuaAPI_IntVector3_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"IntVector3",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  IntVector3* self = (IntVector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
 Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector3__eq00
static int tolua_MathLuaAPI_IntVector3__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IntVector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IntVector3* self = (const IntVector3*)  tolua_tousertype(tolua_S,1,0);
  const IntVector3* rhs = ((const IntVector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->operator==(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector3__add00
static int tolua_MathLuaAPI_IntVector3__add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IntVector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IntVector3* self = (const IntVector3*)  tolua_tousertype(tolua_S,1,0);
  const IntVector3* rhs = ((const IntVector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
 {
  IntVector3 tolua_ret = (IntVector3)  self->operator+(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector3));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector3__sub00
static int tolua_MathLuaAPI_IntVector3__sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IntVector3",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IntVector3* self = (const IntVector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
 {
  IntVector3 tolua_ret = (IntVector3)  self->operator-();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector3));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector3__sub01
static int tolua_MathLuaAPI_IntVector3__sub01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IntVector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const IntVector3* self = (const IntVector3*)  tolua_tousertype(tolua_S,1,0);
  const IntVector3* rhs = ((const IntVector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
 {
  IntVector3 tolua_ret = (IntVector3)  self->operator-(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector3));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_IntVector3__sub00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector3__mul00
static int tolua_MathLuaAPI_IntVector3__mul00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IntVector3",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IntVector3* self = (const IntVector3*)  tolua_tousertype(tolua_S,1,0);
  int rhs = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
 {
  IntVector3 tolua_ret = (IntVector3)  self->operator*(rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector3));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector3__mul01
static int tolua_MathLuaAPI_IntVector3__mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IntVector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const IntVector3* self = (const IntVector3*)  tolua_tousertype(tolua_S,1,0);
  const IntVector3* rhs = ((const IntVector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
 {
  IntVector3 tolua_ret = (IntVector3)  self->operator*(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector3));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_IntVector3__mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector3__div00
static int tolua_MathLuaAPI_IntVector3__div00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IntVector3",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IntVector3* self = (const IntVector3*)  tolua_tousertype(tolua_S,1,0);
  int rhs = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
 {
  IntVector3 tolua_ret = (IntVector3)  self->operator/(rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector3));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.div'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector3__div01
static int tolua_MathLuaAPI_IntVector3__div01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IntVector3",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const IntVector3* self = (const IntVector3*)  tolua_tousertype(tolua_S,1,0);
  const IntVector3* rhs = ((const IntVector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
 {
  IntVector3 tolua_ret = (IntVector3)  self->operator/(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector3));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_IntVector3__div00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToString of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector3_ToString00
static int tolua_MathLuaAPI_IntVector3_ToString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IntVector3",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IntVector3* self = (const IntVector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToString'", NULL);
#endif
 {
  String tolua_ret = (String)  self->ToString();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToHash of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector3_ToHash00
static int tolua_MathLuaAPI_IntVector3_ToHash00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IntVector3",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IntVector3* self = (const IntVector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToHash'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->ToHash();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToHash'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Length of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_IntVector3_Length00
static int tolua_MathLuaAPI_IntVector3_Length00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IntVector3",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IntVector3* self = (const IntVector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Length'", NULL);
#endif
 {
  float tolua_ret = (float)  self->Length();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Length'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x_ of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_get_IntVector3_x
static int tolua_get_IntVector3_x(lua_State* tolua_S)
{
  IntVector3* self = (IntVector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->x_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x_ of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_set_IntVector3_x
static int tolua_set_IntVector3_x(lua_State* tolua_S)
{
  IntVector3* self = (IntVector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x_ = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y_ of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_get_IntVector3_y
static int tolua_get_IntVector3_y(lua_State* tolua_S)
{
  IntVector3* self = (IntVector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->y_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y_ of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_set_IntVector3_y
static int tolua_set_IntVector3_y(lua_State* tolua_S)
{
  IntVector3* self = (IntVector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y_ = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: z_ of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_get_IntVector3_z
static int tolua_get_IntVector3_z(lua_State* tolua_S)
{
  IntVector3* self = (IntVector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->z_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: z_ of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_set_IntVector3_z
static int tolua_set_IntVector3_z(lua_State* tolua_S)
{
  IntVector3* self = (IntVector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->z_ = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ZERO of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_get_IntVector3_ZERO
static int tolua_get_IntVector3_ZERO(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&IntVector3::ZERO,"const IntVector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: LEFT of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_get_IntVector3_LEFT
static int tolua_get_IntVector3_LEFT(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&IntVector3::LEFT,"const IntVector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: RIGHT of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_get_IntVector3_RIGHT
static int tolua_get_IntVector3_RIGHT(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&IntVector3::RIGHT,"const IntVector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: UP of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_get_IntVector3_UP
static int tolua_get_IntVector3_UP(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&IntVector3::UP,"const IntVector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DOWN of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_get_IntVector3_DOWN
static int tolua_get_IntVector3_DOWN(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&IntVector3::DOWN,"const IntVector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: FORWARD of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_get_IntVector3_FORWARD
static int tolua_get_IntVector3_FORWARD(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&IntVector3::FORWARD,"const IntVector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: BACK of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_get_IntVector3_BACK
static int tolua_get_IntVector3_BACK(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&IntVector3::BACK,"const IntVector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ONE of class  IntVector3 */
#ifndef TOLUA_DISABLE_tolua_get_IntVector3_ONE
static int tolua_get_IntVector3_ONE(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&IntVector3::ONE,"const IntVector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* function: VectorLerp */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_VectorLerp01
static int tolua_MathLuaAPI_VectorLerp01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* lhs = ((const Vector3*)  tolua_tousertype(tolua_S,1,0));
  const Vector3* rhs = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* t = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
 {
  Vector3 tolua_ret = (Vector3)  VectorLerp(*lhs,*rhs,*t);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_VectorLerp00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: VectorMin */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_VectorMin02
static int tolua_MathLuaAPI_VectorMin02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* lhs = ((const Vector3*)  tolua_tousertype(tolua_S,1,0));
  const Vector3* rhs = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
 {
  Vector3 tolua_ret = (Vector3)  VectorMin(*lhs,*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_VectorMin01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: VectorMax */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_VectorMax02
static int tolua_MathLuaAPI_VectorMax02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* lhs = ((const Vector3*)  tolua_tousertype(tolua_S,1,0));
  const Vector3* rhs = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
 {
  Vector3 tolua_ret = (Vector3)  VectorMax(*lhs,*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_VectorMax01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: VectorFloor */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_VectorFloor01
static int tolua_MathLuaAPI_VectorFloor01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* vec = ((const Vector3*)  tolua_tousertype(tolua_S,1,0));
 {
  Vector3 tolua_ret = (Vector3)  VectorFloor(*vec);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_VectorFloor00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: VectorRound */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_VectorRound01
static int tolua_MathLuaAPI_VectorRound01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* vec = ((const Vector3*)  tolua_tousertype(tolua_S,1,0));
 {
  Vector3 tolua_ret = (Vector3)  VectorRound(*vec);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_VectorRound00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: VectorCeil */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_VectorCeil01
static int tolua_MathLuaAPI_VectorCeil01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* vec = ((const Vector3*)  tolua_tousertype(tolua_S,1,0));
 {
  Vector3 tolua_ret = (Vector3)  VectorCeil(*vec);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_VectorCeil00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: VectorFloorToInt */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_VectorFloorToInt01
static int tolua_MathLuaAPI_VectorFloorToInt01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* vec = ((const Vector3*)  tolua_tousertype(tolua_S,1,0));
 {
  IntVector3 tolua_ret = (IntVector3)  VectorFloorToInt(*vec);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector3));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_VectorFloorToInt00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: VectorRoundToInt */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_VectorRoundToInt01
static int tolua_MathLuaAPI_VectorRoundToInt01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* vec = ((const Vector3*)  tolua_tousertype(tolua_S,1,0));
 {
  IntVector3 tolua_ret = (IntVector3)  VectorRoundToInt(*vec);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector3));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_VectorRoundToInt00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: VectorCeilToInt */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_VectorCeilToInt01
static int tolua_MathLuaAPI_VectorCeilToInt01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* vec = ((const Vector3*)  tolua_tousertype(tolua_S,1,0));
 {
  IntVector3 tolua_ret = (IntVector3)  VectorCeilToInt(*vec);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector3));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_VectorCeilToInt00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: VectorMin */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_VectorMin03
static int tolua_MathLuaAPI_VectorMin03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const IntVector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const IntVector3* lhs = ((const IntVector3*)  tolua_tousertype(tolua_S,1,0));
  const IntVector3* rhs = ((const IntVector3*)  tolua_tousertype(tolua_S,2,0));
 {
  IntVector3 tolua_ret = (IntVector3)  VectorMin(*lhs,*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector3));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_VectorMin02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: VectorMax */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_VectorMax03
static int tolua_MathLuaAPI_VectorMax03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const IntVector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const IntVector3* lhs = ((const IntVector3*)  tolua_tousertype(tolua_S,1,0));
  const IntVector3* rhs = ((const IntVector3*)  tolua_tousertype(tolua_S,2,0));
 {
  IntVector3 tolua_ret = (IntVector3)  VectorMax(*lhs,*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector3));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_VectorMax02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: StableRandom */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_StableRandom02
static int tolua_MathLuaAPI_StableRandom02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* seed = ((const Vector3*)  tolua_tousertype(tolua_S,1,0));
 {
  float tolua_ret = (float)  StableRandom(*seed);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_StableRandom01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector4_new00
static int tolua_MathLuaAPI_Vector4_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Vector4* tolua_ret = (Vector4*)  Mtolua_new((Vector4)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector4");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector4_new00_local
static int tolua_MathLuaAPI_Vector4_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Vector4* tolua_ret = (Vector4*)  Mtolua_new((Vector4)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector4_new01
static int tolua_MathLuaAPI_Vector4_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector4* vector = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
 {
  Vector4* tolua_ret = (Vector4*)  Mtolua_new((Vector4)(*vector));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector4");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector4_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector4_new01_local
static int tolua_MathLuaAPI_Vector4_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector4* vector = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
 {
  Vector4* tolua_ret = (Vector4*)  Mtolua_new((Vector4)(*vector));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector4_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector4_new02
static int tolua_MathLuaAPI_Vector4_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* vector = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float w = ((float)  tolua_tonumber(tolua_S,3,0));
 {
  Vector4* tolua_ret = (Vector4*)  Mtolua_new((Vector4)(*vector,w));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector4");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector4_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector4_new02_local
static int tolua_MathLuaAPI_Vector4_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector3* vector = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float w = ((float)  tolua_tonumber(tolua_S,3,0));
 {
  Vector4* tolua_ret = (Vector4*)  Mtolua_new((Vector4)(*vector,w));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector4_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector4_new03
static int tolua_MathLuaAPI_Vector4_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  float w = ((float)  tolua_tonumber(tolua_S,5,0));
 {
  Vector4* tolua_ret = (Vector4*)  Mtolua_new((Vector4)(x,y,z,w));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector4");
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector4_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector4_new03_local
static int tolua_MathLuaAPI_Vector4_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  float w = ((float)  tolua_tonumber(tolua_S,5,0));
 {
  Vector4* tolua_ret = (Vector4*)  Mtolua_new((Vector4)(x,y,z,w));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector4_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector4_delete00
static int tolua_MathLuaAPI_Vector4_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Vector4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
 Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector4__eq00
static int tolua_MathLuaAPI_Vector4__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* rhs = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->operator==(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector4__add00
static int tolua_MathLuaAPI_Vector4__add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* rhs = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
 {
  Vector4 tolua_ret = (Vector4)  self->operator+(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector4__sub00
static int tolua_MathLuaAPI_Vector4__sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
 {
  Vector4 tolua_ret = (Vector4)  self->operator-();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector4__sub01
static int tolua_MathLuaAPI_Vector4__sub01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* rhs = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
 {
  Vector4 tolua_ret = (Vector4)  self->operator-(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector4__sub00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector4__mul00
static int tolua_MathLuaAPI_Vector4__mul00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
 {
  Vector4 tolua_ret = (Vector4)  self->operator*(rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector4__mul01
static int tolua_MathLuaAPI_Vector4__mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* rhs = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
 {
  Vector4 tolua_ret = (Vector4)  self->operator*(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector4__mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector4__div00
static int tolua_MathLuaAPI_Vector4__div00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
 {
  Vector4 tolua_ret = (Vector4)  self->operator/(rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.div'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector4__div01
static int tolua_MathLuaAPI_Vector4__div01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* rhs = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
 {
  Vector4 tolua_ret = (Vector4)  self->operator/(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector4__div00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector4__div02
static int tolua_MathLuaAPI_Vector4__div02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* rhs = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
 {
  Vector4 tolua_ret = (Vector4)  self->operator/(*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_Vector4__div01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: DotProduct of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector4_DotProduct00
static int tolua_MathLuaAPI_Vector4_DotProduct00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* rhs = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DotProduct'", NULL);
#endif
 {
  float tolua_ret = (float)  self->DotProduct(*rhs);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DotProduct'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AbsDotProduct of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector4_AbsDotProduct00
static int tolua_MathLuaAPI_Vector4_AbsDotProduct00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* rhs = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AbsDotProduct'", NULL);
#endif
 {
  float tolua_ret = (float)  self->AbsDotProduct(*rhs);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AbsDotProduct'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ProjectOntoAxis of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector4_ProjectOntoAxis00
static int tolua_MathLuaAPI_Vector4_ProjectOntoAxis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* axis = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ProjectOntoAxis'", NULL);
#endif
 {
  float tolua_ret = (float)  self->ProjectOntoAxis(*axis);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ProjectOntoAxis'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Abs of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector4_Abs00
static int tolua_MathLuaAPI_Vector4_Abs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Abs'", NULL);
#endif
 {
  Vector4 tolua_ret = (Vector4)  self->Abs();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Abs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Lerp of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector4_Lerp00
static int tolua_MathLuaAPI_Vector4_Lerp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* rhs = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
  float t = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Lerp'", NULL);
#endif
 {
  Vector4 tolua_ret = (Vector4)  self->Lerp(*rhs,t);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Lerp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Equals of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector4_Equals00
static int tolua_MathLuaAPI_Vector4_Equals00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* rhs = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Equals'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Equals(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Equals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsNaN of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector4_IsNaN00
static int tolua_MathLuaAPI_Vector4_IsNaN00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsNaN'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsNaN();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsNaN'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToString of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_Vector4_ToString00
static int tolua_MathLuaAPI_Vector4_ToString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToString'", NULL);
#endif
 {
  String tolua_ret = (String)  self->ToString();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x_ of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_x
static int tolua_get_Vector4_x(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->x_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x_ of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_set_Vector4_x
static int tolua_set_Vector4_x(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y_ of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_y
static int tolua_get_Vector4_y(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->y_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y_ of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_set_Vector4_y
static int tolua_set_Vector4_y(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: z_ of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_z
static int tolua_get_Vector4_z(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->z_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: z_ of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_set_Vector4_z
static int tolua_set_Vector4_z(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->z_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: w_ of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_w
static int tolua_get_Vector4_w(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'w_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->w_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: w_ of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_set_Vector4_w
static int tolua_set_Vector4_w(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'w_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->w_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ZERO of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_ZERO
static int tolua_get_Vector4_ZERO(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Vector4::ZERO,"const Vector4");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ONE of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_ONE
static int tolua_get_Vector4_ONE(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&Vector4::ONE,"const Vector4");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* function: VectorLerp */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_VectorLerp02
static int tolua_MathLuaAPI_VectorLerp02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector4* lhs = ((const Vector4*)  tolua_tousertype(tolua_S,1,0));
  const Vector4* rhs = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
  const Vector4* t = ((const Vector4*)  tolua_tousertype(tolua_S,3,0));
 {
  Vector4 tolua_ret = (Vector4)  VectorLerp(*lhs,*rhs,*t);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_VectorLerp01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: VectorMin */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_VectorMin04
static int tolua_MathLuaAPI_VectorMin04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector4* lhs = ((const Vector4*)  tolua_tousertype(tolua_S,1,0));
  const Vector4* rhs = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
 {
  Vector4 tolua_ret = (Vector4)  VectorMin(*lhs,*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_VectorMin03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: VectorMax */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_VectorMax04
static int tolua_MathLuaAPI_VectorMax04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector4* lhs = ((const Vector4*)  tolua_tousertype(tolua_S,1,0));
  const Vector4* rhs = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
 {
  Vector4 tolua_ret = (Vector4)  VectorMax(*lhs,*rhs);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_VectorMax03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: VectorFloor */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_VectorFloor02
static int tolua_MathLuaAPI_VectorFloor02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector4* vec = ((const Vector4*)  tolua_tousertype(tolua_S,1,0));
 {
  Vector4 tolua_ret = (Vector4)  VectorFloor(*vec);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_VectorFloor01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: VectorRound */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_VectorRound02
static int tolua_MathLuaAPI_VectorRound02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector4* vec = ((const Vector4*)  tolua_tousertype(tolua_S,1,0));
 {
  Vector4 tolua_ret = (Vector4)  VectorRound(*vec);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_VectorRound01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: VectorCeil */
#ifndef TOLUA_DISABLE_tolua_MathLuaAPI_VectorCeil02
static int tolua_MathLuaAPI_VectorCeil02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Vector4* vec = ((const Vector4*)  tolua_tousertype(tolua_S,1,0));
 {
  Vector4 tolua_ret = (Vector4)  VectorCeil(*vec);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_MathLuaAPI_VectorCeil01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_MathLuaAPI_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,1);
 tolua_beginmodule(tolua_S,NULL);
 tolua_variable(tolua_S,"M_PI",tolua_get_M_PI,NULL);
 tolua_variable(tolua_S,"M_HALF_PI",tolua_get_M_HALF_PI,NULL);
 tolua_variable(tolua_S,"M_MIN_INT",tolua_get_M_MIN_INT,NULL);
 tolua_variable(tolua_S,"M_MAX_INT",tolua_get_M_MAX_INT,NULL);
 tolua_variable(tolua_S,"M_MIN_UNSIGNED",tolua_get_M_MIN_UNSIGNED,NULL);
 tolua_variable(tolua_S,"M_MAX_UNSIGNED",tolua_get_M_MAX_UNSIGNED,NULL);
 tolua_variable(tolua_S,"M_EPSILON",tolua_get_M_EPSILON,NULL);
 tolua_variable(tolua_S,"M_LARGE_EPSILON",tolua_get_M_LARGE_EPSILON,NULL);
 tolua_variable(tolua_S,"M_MIN_NEARCLIP",tolua_get_M_MIN_NEARCLIP,NULL);
 tolua_variable(tolua_S,"M_MAX_FOV",tolua_get_M_MAX_FOV,NULL);
 tolua_variable(tolua_S,"M_LARGE_VALUE",tolua_get_M_LARGE_VALUE,NULL);
 tolua_variable(tolua_S,"M_INFINITY",tolua_get_M_INFINITY,NULL);
 tolua_variable(tolua_S,"M_DEGTORAD",tolua_get_M_DEGTORAD,NULL);
 tolua_variable(tolua_S,"M_DEGTORAD_2",tolua_get_M_DEGTORAD_2,NULL);
 tolua_variable(tolua_S,"M_RADTODEG",tolua_get_M_RADTODEG,NULL);
 tolua_constant(tolua_S,"OUTSIDE",OUTSIDE);
 tolua_constant(tolua_S,"INTERSECTS",INTERSECTS);
 tolua_constant(tolua_S,"INSIDE",INSIDE);
 tolua_function(tolua_S,"Equals",tolua_MathLuaAPI_Equals00);
 tolua_function(tolua_S,"IsNaN",tolua_MathLuaAPI_IsNaN00);
 tolua_function(tolua_S,"Lerp",tolua_MathLuaAPI_Lerp00);
 tolua_function(tolua_S,"InverseLerp",tolua_MathLuaAPI_InverseLerp00);
 tolua_function(tolua_S,"Min",tolua_MathLuaAPI_Min00);
 tolua_function(tolua_S,"Max",tolua_MathLuaAPI_Max00);
 tolua_function(tolua_S,"Abs",tolua_MathLuaAPI_Abs00);
 tolua_function(tolua_S,"Sign",tolua_MathLuaAPI_Sign00);
 tolua_function(tolua_S,"Clamp",tolua_MathLuaAPI_Clamp00);
 tolua_function(tolua_S,"SmoothStep",tolua_MathLuaAPI_SmoothStep00);
 tolua_function(tolua_S,"Sin",tolua_MathLuaAPI_Sin00);
 tolua_function(tolua_S,"Cos",tolua_MathLuaAPI_Cos00);
 tolua_function(tolua_S,"Tan",tolua_MathLuaAPI_Tan00);
 tolua_function(tolua_S,"Asin",tolua_MathLuaAPI_Asin00);
 tolua_function(tolua_S,"Acos",tolua_MathLuaAPI_Acos00);
 tolua_function(tolua_S,"Atan",tolua_MathLuaAPI_Atan00);
 tolua_function(tolua_S,"Atan2",tolua_MathLuaAPI_Atan200);
 tolua_function(tolua_S,"Sqrt",tolua_MathLuaAPI_Sqrt00);
 tolua_function(tolua_S,"Pow",tolua_MathLuaAPI_Pow00);
 tolua_function(tolua_S,"Ln",tolua_MathLuaAPI_Ln00);
 tolua_function(tolua_S,"Mod",tolua_MathLuaAPI_Mod00);
 tolua_function(tolua_S,"Fract",tolua_MathLuaAPI_Fract00);
 tolua_function(tolua_S,"Floor",tolua_MathLuaAPI_Floor00);
 tolua_function(tolua_S,"Round",tolua_MathLuaAPI_Round00);
 tolua_function(tolua_S,"Ceil",tolua_MathLuaAPI_Ceil00);
 tolua_function(tolua_S,"FloorToInt",tolua_MathLuaAPI_FloorToInt00);
 tolua_function(tolua_S,"RoundToInt",tolua_MathLuaAPI_RoundToInt00);
 tolua_function(tolua_S,"CeilToInt",tolua_MathLuaAPI_CeilToInt00);
 tolua_function(tolua_S,"MinInt",tolua_MathLuaAPI_MinInt00);
 tolua_function(tolua_S,"MaxInt",tolua_MathLuaAPI_MaxInt00);
 tolua_function(tolua_S,"AbsInt",tolua_MathLuaAPI_AbsInt00);
 tolua_function(tolua_S,"ClampInt",tolua_MathLuaAPI_ClampInt00);
 tolua_function(tolua_S,"IsPowerOfTwo",tolua_MathLuaAPI_IsPowerOfTwo00);
 tolua_function(tolua_S,"NextPowerOfTwo",tolua_MathLuaAPI_NextPowerOfTwo00);
 tolua_function(tolua_S,"CountSetBits",tolua_MathLuaAPI_CountSetBits00);
 tolua_function(tolua_S,"LogBaseTwo",tolua_MathLuaAPI_LogBaseTwo00);
 tolua_function(tolua_S,"SDBMHash",tolua_MathLuaAPI_SDBMHash00);
 tolua_function(tolua_S,"Random",tolua_MathLuaAPI_Random00);
 tolua_function(tolua_S,"Random",tolua_MathLuaAPI_Random01);
 tolua_function(tolua_S,"Random",tolua_MathLuaAPI_Random02);
 tolua_function(tolua_S,"RandomInt",tolua_MathLuaAPI_RandomInt00);
 tolua_function(tolua_S,"RandomInt",tolua_MathLuaAPI_RandomInt01);
 tolua_function(tolua_S,"RandomNormal",tolua_MathLuaAPI_RandomNormal00);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"BoundingBox","BoundingBox","",tolua_collect_BoundingBox);
 #else
 tolua_cclass(tolua_S,"BoundingBox","BoundingBox","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"BoundingBox");
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_BoundingBox_new00);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_BoundingBox_new00_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_BoundingBox_new00_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_BoundingBox_new01);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_BoundingBox_new01_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_BoundingBox_new01_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_BoundingBox_new02);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_BoundingBox_new02_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_BoundingBox_new02_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_BoundingBox_new03);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_BoundingBox_new03_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_BoundingBox_new03_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_BoundingBox_new04);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_BoundingBox_new04_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_BoundingBox_new04_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_BoundingBox_new05);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_BoundingBox_new05_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_BoundingBox_new05_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_BoundingBox_new06);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_BoundingBox_new06_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_BoundingBox_new06_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_BoundingBox_new07);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_BoundingBox_new07_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_BoundingBox_new07_local);
  tolua_function(tolua_S,"delete",tolua_MathLuaAPI_BoundingBox_delete00);
  tolua_function(tolua_S,".eq",tolua_MathLuaAPI_BoundingBox__eq00);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_BoundingBox_Define00);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_BoundingBox_Define01);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_BoundingBox_Define02);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_BoundingBox_Define03);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_BoundingBox_Define04);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_BoundingBox_Define05);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_BoundingBox_Define06);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_BoundingBox_Define07);
  tolua_function(tolua_S,"Merge",tolua_MathLuaAPI_BoundingBox_Merge00);
  tolua_function(tolua_S,"Merge",tolua_MathLuaAPI_BoundingBox_Merge01);
  tolua_function(tolua_S,"Merge",tolua_MathLuaAPI_BoundingBox_Merge02);
  tolua_function(tolua_S,"Merge",tolua_MathLuaAPI_BoundingBox_Merge03);
  tolua_function(tolua_S,"Merge",tolua_MathLuaAPI_BoundingBox_Merge04);
  tolua_function(tolua_S,"Clip",tolua_MathLuaAPI_BoundingBox_Clip00);
  tolua_function(tolua_S,"Transform",tolua_MathLuaAPI_BoundingBox_Transform00);
  tolua_function(tolua_S,"Transform",tolua_MathLuaAPI_BoundingBox_Transform01);
  tolua_function(tolua_S,"Clear",tolua_MathLuaAPI_BoundingBox_Clear00);
  tolua_function(tolua_S,"Defined",tolua_MathLuaAPI_BoundingBox_Defined00);
  tolua_function(tolua_S,"Center",tolua_MathLuaAPI_BoundingBox_Center00);
  tolua_function(tolua_S,"Size",tolua_MathLuaAPI_BoundingBox_Size00);
  tolua_function(tolua_S,"HalfSize",tolua_MathLuaAPI_BoundingBox_HalfSize00);
  tolua_function(tolua_S,"Transformed",tolua_MathLuaAPI_BoundingBox_Transformed00);
  tolua_function(tolua_S,"Transformed",tolua_MathLuaAPI_BoundingBox_Transformed01);
  tolua_function(tolua_S,"Projected",tolua_MathLuaAPI_BoundingBox_Projected00);
  tolua_function(tolua_S,"DistanceToPoint",tolua_MathLuaAPI_BoundingBox_DistanceToPoint00);
  tolua_function(tolua_S,"IsInside",tolua_MathLuaAPI_BoundingBox_IsInside00);
  tolua_function(tolua_S,"IsInside",tolua_MathLuaAPI_BoundingBox_IsInside01);
  tolua_function(tolua_S,"IsInsideFast",tolua_MathLuaAPI_BoundingBox_IsInsideFast00);
  tolua_function(tolua_S,"IsInside",tolua_MathLuaAPI_BoundingBox_IsInside02);
  tolua_function(tolua_S,"IsInsideFast",tolua_MathLuaAPI_BoundingBox_IsInsideFast01);
  tolua_function(tolua_S,"ToString",tolua_MathLuaAPI_BoundingBox_ToString00);
  tolua_variable(tolua_S,"min",tolua_get_BoundingBox_min,tolua_set_BoundingBox_min);
  tolua_variable(tolua_S,"max",tolua_get_BoundingBox_max,tolua_set_BoundingBox_max);
  tolua_variable(tolua_S,"center",tolua_get_BoundingBox_center,NULL);
  tolua_variable(tolua_S,"size",tolua_get_BoundingBox_size,NULL);
  tolua_variable(tolua_S,"halfSize",tolua_get_BoundingBox_halfSize,NULL);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Color","Color","",tolua_collect_Color);
 #else
 tolua_cclass(tolua_S,"Color","Color","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Color");
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Color_new00);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Color_new00_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Color_new00_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Color_new01);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Color_new01_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Color_new01_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Color_new02);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Color_new02_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Color_new02_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Color_new03);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Color_new03_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Color_new03_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Color_new04);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Color_new04_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Color_new04_local);
  tolua_function(tolua_S,"delete",tolua_MathLuaAPI_Color_delete00);
  tolua_function(tolua_S,".eq",tolua_MathLuaAPI_Color__eq00);
  tolua_function(tolua_S,".mul",tolua_MathLuaAPI_Color__mul00);
  tolua_function(tolua_S,".add",tolua_MathLuaAPI_Color__add00);
  tolua_function(tolua_S,"ToUInt",tolua_MathLuaAPI_Color_ToUInt00);
  tolua_function(tolua_S,"ToHSL",tolua_MathLuaAPI_Color_ToHSL00);
  tolua_function(tolua_S,"ToHSV",tolua_MathLuaAPI_Color_ToHSV00);
  tolua_function(tolua_S,"FromUInt",tolua_MathLuaAPI_Color_FromUInt00);
  tolua_function(tolua_S,"FromHSL",tolua_MathLuaAPI_Color_FromHSL00);
  tolua_function(tolua_S,"FromHSV",tolua_MathLuaAPI_Color_FromHSV00);
  tolua_function(tolua_S,"ToVector3",tolua_MathLuaAPI_Color_ToVector300);
  tolua_function(tolua_S,"ToVector4",tolua_MathLuaAPI_Color_ToVector400);
  tolua_function(tolua_S,"SumRGB",tolua_MathLuaAPI_Color_SumRGB00);
  tolua_function(tolua_S,"Average",tolua_MathLuaAPI_Color_Average00);
  tolua_function(tolua_S,"Luma",tolua_MathLuaAPI_Color_Luma00);
  tolua_function(tolua_S,"Chroma",tolua_MathLuaAPI_Color_Chroma00);
  tolua_function(tolua_S,"Hue",tolua_MathLuaAPI_Color_Hue00);
  tolua_function(tolua_S,"SaturationHSL",tolua_MathLuaAPI_Color_SaturationHSL00);
  tolua_function(tolua_S,"SaturationHSV",tolua_MathLuaAPI_Color_SaturationHSV00);
  tolua_function(tolua_S,"Value",tolua_MathLuaAPI_Color_Value00);
  tolua_function(tolua_S,"Lightness",tolua_MathLuaAPI_Color_Lightness00);
  tolua_function(tolua_S,"MaxRGB",tolua_MathLuaAPI_Color_MaxRGB00);
  tolua_function(tolua_S,"MinRGB",tolua_MathLuaAPI_Color_MinRGB00);
  tolua_function(tolua_S,"Range",tolua_MathLuaAPI_Color_Range00);
  tolua_function(tolua_S,"Clip",tolua_MathLuaAPI_Color_Clip00);
  tolua_function(tolua_S,"Invert",tolua_MathLuaAPI_Color_Invert00);
  tolua_function(tolua_S,"Lerp",tolua_MathLuaAPI_Color_Lerp00);
  tolua_function(tolua_S,"Abs",tolua_MathLuaAPI_Color_Abs00);
  tolua_function(tolua_S,"Equals",tolua_MathLuaAPI_Color_Equals00);
  tolua_function(tolua_S,"ToString",tolua_MathLuaAPI_Color_ToString00);
  tolua_variable(tolua_S,"r",tolua_get_Color_r,tolua_set_Color_r);
  tolua_variable(tolua_S,"g",tolua_get_Color_g,tolua_set_Color_g);
  tolua_variable(tolua_S,"b",tolua_get_Color_b,tolua_set_Color_b);
  tolua_variable(tolua_S,"a",tolua_get_Color_a,tolua_set_Color_a);
  tolua_variable(tolua_S,"WHITE",tolua_get_Color_WHITE,NULL);
  tolua_variable(tolua_S,"GRAY",tolua_get_Color_GRAY,NULL);
  tolua_variable(tolua_S,"BLACK",tolua_get_Color_BLACK,NULL);
  tolua_variable(tolua_S,"RED",tolua_get_Color_RED,NULL);
  tolua_variable(tolua_S,"GREEN",tolua_get_Color_GREEN,NULL);
  tolua_variable(tolua_S,"BLUE",tolua_get_Color_BLUE,NULL);
  tolua_variable(tolua_S,"CYAN",tolua_get_Color_CYAN,NULL);
  tolua_variable(tolua_S,"MAGENTA",tolua_get_Color_MAGENTA,NULL);
  tolua_variable(tolua_S,"YELLOW",tolua_get_Color_YELLOW,NULL);
  tolua_variable(tolua_S,"TRANSPARENT_BLACK",tolua_get_Color_TRANSPARENT_BLACK,NULL);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"PLANE_NEAR",PLANE_NEAR);
 tolua_constant(tolua_S,"PLANE_LEFT",PLANE_LEFT);
 tolua_constant(tolua_S,"PLANE_RIGHT",PLANE_RIGHT);
 tolua_constant(tolua_S,"PLANE_UP",PLANE_UP);
 tolua_constant(tolua_S,"PLANE_DOWN",PLANE_DOWN);
 tolua_constant(tolua_S,"PLANE_FAR",PLANE_FAR);
 tolua_variable(tolua_S,"NUM_FRUSTUM_PLANES",tolua_get_NUM_FRUSTUM_PLANES,NULL);
 tolua_variable(tolua_S,"NUM_FRUSTUM_VERTICES",tolua_get_NUM_FRUSTUM_VERTICES,NULL);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Frustum","Frustum","",tolua_collect_Frustum);
 #else
 tolua_cclass(tolua_S,"Frustum","Frustum","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Frustum");
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Frustum_new00);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Frustum_new00_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Frustum_new00_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Frustum_new01);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Frustum_new01_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Frustum_new01_local);
  tolua_function(tolua_S,"delete",tolua_MathLuaAPI_Frustum_delete00);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_Frustum_Define00);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_Frustum_Define01);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_Frustum_Define02);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_Frustum_Define03);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_Frustum_Define04);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_Frustum_Define05);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_Frustum_Define06);
  tolua_function(tolua_S,"DefineOrtho",tolua_MathLuaAPI_Frustum_DefineOrtho00);
  tolua_function(tolua_S,"DefineOrtho",tolua_MathLuaAPI_Frustum_DefineOrtho01);
  tolua_function(tolua_S,"DefineSplit",tolua_MathLuaAPI_Frustum_DefineSplit00);
  tolua_function(tolua_S,"Transform",tolua_MathLuaAPI_Frustum_Transform00);
  tolua_function(tolua_S,"Transform",tolua_MathLuaAPI_Frustum_Transform01);
  tolua_function(tolua_S,"IsInside",tolua_MathLuaAPI_Frustum_IsInside00);
  tolua_function(tolua_S,"IsInside",tolua_MathLuaAPI_Frustum_IsInside01);
  tolua_function(tolua_S,"IsInsideFast",tolua_MathLuaAPI_Frustum_IsInsideFast00);
  tolua_function(tolua_S,"IsInside",tolua_MathLuaAPI_Frustum_IsInside02);
  tolua_function(tolua_S,"IsInsideFast",tolua_MathLuaAPI_Frustum_IsInsideFast01);
  tolua_function(tolua_S,"Distance",tolua_MathLuaAPI_Frustum_Distance00);
  tolua_function(tolua_S,"Transformed",tolua_MathLuaAPI_Frustum_Transformed00);
  tolua_function(tolua_S,"Transformed",tolua_MathLuaAPI_Frustum_Transformed01);
  tolua_function(tolua_S,"Projected",tolua_MathLuaAPI_Frustum_Projected00);
  tolua_function(tolua_S,"UpdatePlanes",tolua_MathLuaAPI_Frustum_UpdatePlanes00);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Matrix3","Matrix3","",tolua_collect_Matrix3);
 #else
 tolua_cclass(tolua_S,"Matrix3","Matrix3","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Matrix3");
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Matrix3_new00);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Matrix3_new00_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Matrix3_new00_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Matrix3_new01);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Matrix3_new01_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Matrix3_new01_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Matrix3_new02);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Matrix3_new02_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Matrix3_new02_local);
  tolua_function(tolua_S,"delete",tolua_MathLuaAPI_Matrix3_delete00);
  tolua_function(tolua_S,".eq",tolua_MathLuaAPI_Matrix3__eq00);
  tolua_function(tolua_S,".mul",tolua_MathLuaAPI_Matrix3__mul00);
  tolua_function(tolua_S,".add",tolua_MathLuaAPI_Matrix3__add00);
  tolua_function(tolua_S,".sub",tolua_MathLuaAPI_Matrix3__sub00);
  tolua_function(tolua_S,".mul",tolua_MathLuaAPI_Matrix3__mul01);
  tolua_function(tolua_S,".mul",tolua_MathLuaAPI_Matrix3__mul02);
  tolua_function(tolua_S,"SetScale",tolua_MathLuaAPI_Matrix3_SetScale00);
  tolua_function(tolua_S,"SetScale",tolua_MathLuaAPI_Matrix3_SetScale01);
  tolua_function(tolua_S,"Scale",tolua_MathLuaAPI_Matrix3_Scale00);
  tolua_function(tolua_S,"Transpose",tolua_MathLuaAPI_Matrix3_Transpose00);
  tolua_function(tolua_S,"Scaled",tolua_MathLuaAPI_Matrix3_Scaled00);
  tolua_function(tolua_S,"Equals",tolua_MathLuaAPI_Matrix3_Equals00);
  tolua_function(tolua_S,"Inverse",tolua_MathLuaAPI_Matrix3_Inverse00);
  tolua_function(tolua_S,"ToString",tolua_MathLuaAPI_Matrix3_ToString00);
  tolua_variable(tolua_S,"m00",tolua_get_Matrix3_m00,tolua_set_Matrix3_m00);
  tolua_variable(tolua_S,"m01",tolua_get_Matrix3_m01,tolua_set_Matrix3_m01);
  tolua_variable(tolua_S,"m02",tolua_get_Matrix3_m02,tolua_set_Matrix3_m02);
  tolua_variable(tolua_S,"m10",tolua_get_Matrix3_m10,tolua_set_Matrix3_m10);
  tolua_variable(tolua_S,"m11",tolua_get_Matrix3_m11,tolua_set_Matrix3_m11);
  tolua_variable(tolua_S,"m12",tolua_get_Matrix3_m12,tolua_set_Matrix3_m12);
  tolua_variable(tolua_S,"m20",tolua_get_Matrix3_m20,tolua_set_Matrix3_m20);
  tolua_variable(tolua_S,"m21",tolua_get_Matrix3_m21,tolua_set_Matrix3_m21);
  tolua_variable(tolua_S,"m22",tolua_get_Matrix3_m22,tolua_set_Matrix3_m22);
  tolua_variable(tolua_S,"ZERO",tolua_get_Matrix3_ZERO,NULL);
  tolua_variable(tolua_S,"IDENTITY",tolua_get_Matrix3_IDENTITY,NULL);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Matrix3x4","Matrix3x4","",tolua_collect_Matrix3x4);
 #else
 tolua_cclass(tolua_S,"Matrix3x4","Matrix3x4","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Matrix3x4");
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Matrix3x4_new00);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Matrix3x4_new00_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Matrix3x4_new00_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Matrix3x4_new01);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Matrix3x4_new01_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Matrix3x4_new01_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Matrix3x4_new02);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Matrix3x4_new02_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Matrix3x4_new02_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Matrix3x4_new03);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Matrix3x4_new03_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Matrix3x4_new03_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Matrix3x4_new04);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Matrix3x4_new04_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Matrix3x4_new04_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Matrix3x4_new05);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Matrix3x4_new05_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Matrix3x4_new05_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Matrix3x4_new06);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Matrix3x4_new06_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Matrix3x4_new06_local);
  tolua_function(tolua_S,"delete",tolua_MathLuaAPI_Matrix3x4_delete00);
  tolua_function(tolua_S,".eq",tolua_MathLuaAPI_Matrix3x4__eq00);
  tolua_function(tolua_S,".mul",tolua_MathLuaAPI_Matrix3x4__mul00);
  tolua_function(tolua_S,".mul",tolua_MathLuaAPI_Matrix3x4__mul01);
  tolua_function(tolua_S,".add",tolua_MathLuaAPI_Matrix3x4__add00);
  tolua_function(tolua_S,".sub",tolua_MathLuaAPI_Matrix3x4__sub00);
  tolua_function(tolua_S,".mul",tolua_MathLuaAPI_Matrix3x4__mul02);
  tolua_function(tolua_S,".mul",tolua_MathLuaAPI_Matrix3x4__mul03);
  tolua_function(tolua_S,".mul",tolua_MathLuaAPI_Matrix3x4__mul04);
  tolua_function(tolua_S,"SetTranslation",tolua_MathLuaAPI_Matrix3x4_SetTranslation00);
  tolua_function(tolua_S,"SetRotation",tolua_MathLuaAPI_Matrix3x4_SetRotation00);
  tolua_function(tolua_S,"SetScale",tolua_MathLuaAPI_Matrix3x4_SetScale00);
  tolua_function(tolua_S,"SetScale",tolua_MathLuaAPI_Matrix3x4_SetScale01);
  tolua_function(tolua_S,"ToMatrix3",tolua_MathLuaAPI_Matrix3x4_ToMatrix300);
  tolua_function(tolua_S,"ToMatrix4",tolua_MathLuaAPI_Matrix3x4_ToMatrix400);
  tolua_function(tolua_S,"RotationMatrix",tolua_MathLuaAPI_Matrix3x4_RotationMatrix00);
  tolua_function(tolua_S,"Translation",tolua_MathLuaAPI_Matrix3x4_Translation00);
  tolua_function(tolua_S,"Rotation",tolua_MathLuaAPI_Matrix3x4_Rotation00);
  tolua_function(tolua_S,"Scale",tolua_MathLuaAPI_Matrix3x4_Scale00);
  tolua_function(tolua_S,"Equals",tolua_MathLuaAPI_Matrix3x4_Equals00);
  tolua_function(tolua_S,"Decompose",tolua_MathLuaAPI_Matrix3x4_Decompose00);
  tolua_function(tolua_S,"Inverse",tolua_MathLuaAPI_Matrix3x4_Inverse00);
  tolua_function(tolua_S,"ToString",tolua_MathLuaAPI_Matrix3x4_ToString00);
  tolua_variable(tolua_S,"m00",tolua_get_Matrix3x4_m00,tolua_set_Matrix3x4_m00);
  tolua_variable(tolua_S,"m01",tolua_get_Matrix3x4_m01,tolua_set_Matrix3x4_m01);
  tolua_variable(tolua_S,"m02",tolua_get_Matrix3x4_m02,tolua_set_Matrix3x4_m02);
  tolua_variable(tolua_S,"m03",tolua_get_Matrix3x4_m03,tolua_set_Matrix3x4_m03);
  tolua_variable(tolua_S,"m10",tolua_get_Matrix3x4_m10,tolua_set_Matrix3x4_m10);
  tolua_variable(tolua_S,"m11",tolua_get_Matrix3x4_m11,tolua_set_Matrix3x4_m11);
  tolua_variable(tolua_S,"m12",tolua_get_Matrix3x4_m12,tolua_set_Matrix3x4_m12);
  tolua_variable(tolua_S,"m13",tolua_get_Matrix3x4_m13,tolua_set_Matrix3x4_m13);
  tolua_variable(tolua_S,"m20",tolua_get_Matrix3x4_m20,tolua_set_Matrix3x4_m20);
  tolua_variable(tolua_S,"m21",tolua_get_Matrix3x4_m21,tolua_set_Matrix3x4_m21);
  tolua_variable(tolua_S,"m22",tolua_get_Matrix3x4_m22,tolua_set_Matrix3x4_m22);
  tolua_variable(tolua_S,"m23",tolua_get_Matrix3x4_m23,tolua_set_Matrix3x4_m23);
  tolua_variable(tolua_S,"ZERO",tolua_get_Matrix3x4_ZERO,NULL);
  tolua_variable(tolua_S,"IDENTITY",tolua_get_Matrix3x4_IDENTITY,NULL);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Matrix4","Matrix4","",tolua_collect_Matrix4);
 #else
 tolua_cclass(tolua_S,"Matrix4","Matrix4","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Matrix4");
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Matrix4_new00);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Matrix4_new00_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Matrix4_new00_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Matrix4_new01);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Matrix4_new01_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Matrix4_new01_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Matrix4_new02);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Matrix4_new02_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Matrix4_new02_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Matrix4_new03);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Matrix4_new03_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Matrix4_new03_local);
  tolua_function(tolua_S,"delete",tolua_MathLuaAPI_Matrix4_delete00);
  tolua_function(tolua_S,".eq",tolua_MathLuaAPI_Matrix4__eq00);
  tolua_function(tolua_S,".mul",tolua_MathLuaAPI_Matrix4__mul00);
  tolua_function(tolua_S,".mul",tolua_MathLuaAPI_Matrix4__mul01);
  tolua_function(tolua_S,".add",tolua_MathLuaAPI_Matrix4__add00);
  tolua_function(tolua_S,".sub",tolua_MathLuaAPI_Matrix4__sub00);
  tolua_function(tolua_S,".mul",tolua_MathLuaAPI_Matrix4__mul02);
  tolua_function(tolua_S,".mul",tolua_MathLuaAPI_Matrix4__mul03);
  tolua_function(tolua_S,".mul",tolua_MathLuaAPI_Matrix4__mul04);
  tolua_function(tolua_S,"SetTranslation",tolua_MathLuaAPI_Matrix4_SetTranslation00);
  tolua_function(tolua_S,"SetRotation",tolua_MathLuaAPI_Matrix4_SetRotation00);
  tolua_function(tolua_S,"SetScale",tolua_MathLuaAPI_Matrix4_SetScale00);
  tolua_function(tolua_S,"SetScale",tolua_MathLuaAPI_Matrix4_SetScale01);
  tolua_function(tolua_S,"ToMatrix3",tolua_MathLuaAPI_Matrix4_ToMatrix300);
  tolua_function(tolua_S,"RotationMatrix",tolua_MathLuaAPI_Matrix4_RotationMatrix00);
  tolua_function(tolua_S,"Translation",tolua_MathLuaAPI_Matrix4_Translation00);
  tolua_function(tolua_S,"Rotation",tolua_MathLuaAPI_Matrix4_Rotation00);
  tolua_function(tolua_S,"Scale",tolua_MathLuaAPI_Matrix4_Scale00);
  tolua_function(tolua_S,"Transpose",tolua_MathLuaAPI_Matrix4_Transpose00);
  tolua_function(tolua_S,"Equals",tolua_MathLuaAPI_Matrix4_Equals00);
  tolua_function(tolua_S,"Decompose",tolua_MathLuaAPI_Matrix4_Decompose00);
  tolua_function(tolua_S,"Inverse",tolua_MathLuaAPI_Matrix4_Inverse00);
  tolua_function(tolua_S,"ToString",tolua_MathLuaAPI_Matrix4_ToString00);
  tolua_variable(tolua_S,"m00",tolua_get_Matrix4_m00,tolua_set_Matrix4_m00);
  tolua_variable(tolua_S,"m01",tolua_get_Matrix4_m01,tolua_set_Matrix4_m01);
  tolua_variable(tolua_S,"m02",tolua_get_Matrix4_m02,tolua_set_Matrix4_m02);
  tolua_variable(tolua_S,"m03",tolua_get_Matrix4_m03,tolua_set_Matrix4_m03);
  tolua_variable(tolua_S,"m10",tolua_get_Matrix4_m10,tolua_set_Matrix4_m10);
  tolua_variable(tolua_S,"m11",tolua_get_Matrix4_m11,tolua_set_Matrix4_m11);
  tolua_variable(tolua_S,"m12",tolua_get_Matrix4_m12,tolua_set_Matrix4_m12);
  tolua_variable(tolua_S,"m13",tolua_get_Matrix4_m13,tolua_set_Matrix4_m13);
  tolua_variable(tolua_S,"m20",tolua_get_Matrix4_m20,tolua_set_Matrix4_m20);
  tolua_variable(tolua_S,"m21",tolua_get_Matrix4_m21,tolua_set_Matrix4_m21);
  tolua_variable(tolua_S,"m22",tolua_get_Matrix4_m22,tolua_set_Matrix4_m22);
  tolua_variable(tolua_S,"m23",tolua_get_Matrix4_m23,tolua_set_Matrix4_m23);
  tolua_variable(tolua_S,"m30",tolua_get_Matrix4_m30,tolua_set_Matrix4_m30);
  tolua_variable(tolua_S,"m31",tolua_get_Matrix4_m31,tolua_set_Matrix4_m31);
  tolua_variable(tolua_S,"m32",tolua_get_Matrix4_m32,tolua_set_Matrix4_m32);
  tolua_variable(tolua_S,"m33",tolua_get_Matrix4_m33,tolua_set_Matrix4_m33);
  tolua_variable(tolua_S,"ZERO",tolua_get_Matrix4_ZERO,NULL);
  tolua_variable(tolua_S,"IDENTITY",tolua_get_Matrix4_IDENTITY,NULL);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Plane","Plane","",tolua_collect_Plane);
 #else
 tolua_cclass(tolua_S,"Plane","Plane","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Plane");
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Plane_new00);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Plane_new00_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Plane_new00_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Plane_new01);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Plane_new01_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Plane_new01_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Plane_new02);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Plane_new02_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Plane_new02_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Plane_new03);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Plane_new03_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Plane_new03_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Plane_new04);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Plane_new04_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Plane_new04_local);
  tolua_function(tolua_S,"delete",tolua_MathLuaAPI_Plane_delete00);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_Plane_Define00);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_Plane_Define01);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_Plane_Define02);
  tolua_function(tolua_S,"Transform",tolua_MathLuaAPI_Plane_Transform00);
  tolua_function(tolua_S,"Transform",tolua_MathLuaAPI_Plane_Transform01);
  tolua_function(tolua_S,"Transform",tolua_MathLuaAPI_Plane_Transform02);
  tolua_function(tolua_S,"Project",tolua_MathLuaAPI_Plane_Project00);
  tolua_function(tolua_S,"Distance",tolua_MathLuaAPI_Plane_Distance00);
  tolua_function(tolua_S,"Reflect",tolua_MathLuaAPI_Plane_Reflect00);
  tolua_function(tolua_S,"ReflectionMatrix",tolua_MathLuaAPI_Plane_ReflectionMatrix00);
  tolua_function(tolua_S,"Transformed",tolua_MathLuaAPI_Plane_Transformed00);
  tolua_function(tolua_S,"Transformed",tolua_MathLuaAPI_Plane_Transformed01);
  tolua_function(tolua_S,"Transformed",tolua_MathLuaAPI_Plane_Transformed02);
  tolua_function(tolua_S,"ToVector4",tolua_MathLuaAPI_Plane_ToVector400);
  tolua_variable(tolua_S,"normal",tolua_get_Plane_normal,tolua_set_Plane_normal);
  tolua_variable(tolua_S,"absNormal",tolua_get_Plane_absNormal,tolua_set_Plane_absNormal);
  tolua_variable(tolua_S,"d",tolua_get_Plane_d,tolua_set_Plane_d);
  tolua_variable(tolua_S,"UP",tolua_get_Plane_UP,NULL);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Polyhedron","Polyhedron","",tolua_collect_Polyhedron);
 #else
 tolua_cclass(tolua_S,"Polyhedron","Polyhedron","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Polyhedron");
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Polyhedron_new00);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Polyhedron_new00_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Polyhedron_new00_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Polyhedron_new01);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Polyhedron_new01_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Polyhedron_new01_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Polyhedron_new02);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Polyhedron_new02_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Polyhedron_new02_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Polyhedron_new03);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Polyhedron_new03_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Polyhedron_new03_local);
  tolua_function(tolua_S,"delete",tolua_MathLuaAPI_Polyhedron_delete00);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_Polyhedron_Define00);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_Polyhedron_Define01);
  tolua_function(tolua_S,"AddFace",tolua_MathLuaAPI_Polyhedron_AddFace00);
  tolua_function(tolua_S,"AddFace",tolua_MathLuaAPI_Polyhedron_AddFace01);
  tolua_function(tolua_S,"Clip",tolua_MathLuaAPI_Polyhedron_Clip00);
  tolua_function(tolua_S,"Clip",tolua_MathLuaAPI_Polyhedron_Clip01);
  tolua_function(tolua_S,"Clip",tolua_MathLuaAPI_Polyhedron_Clip02);
  tolua_function(tolua_S,"Clear",tolua_MathLuaAPI_Polyhedron_Clear00);
  tolua_function(tolua_S,"Transform",tolua_MathLuaAPI_Polyhedron_Transform00);
  tolua_function(tolua_S,"Transform",tolua_MathLuaAPI_Polyhedron_Transform01);
  tolua_function(tolua_S,"Transformed",tolua_MathLuaAPI_Polyhedron_Transformed00);
  tolua_function(tolua_S,"Transformed",tolua_MathLuaAPI_Polyhedron_Transformed01);
  tolua_function(tolua_S,"Empty",tolua_MathLuaAPI_Polyhedron_Empty00);
  tolua_variable(tolua_S,"empty",tolua_get_Polyhedron_empty,NULL);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Quaternion","Quaternion","",tolua_collect_Quaternion);
 #else
 tolua_cclass(tolua_S,"Quaternion","Quaternion","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Quaternion");
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Quaternion_new00);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Quaternion_new00_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Quaternion_new00_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Quaternion_new01);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Quaternion_new01_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Quaternion_new01_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Quaternion_new02);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Quaternion_new02_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Quaternion_new02_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Quaternion_new03);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Quaternion_new03_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Quaternion_new03_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Quaternion_new04);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Quaternion_new04_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Quaternion_new04_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Quaternion_new05);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Quaternion_new05_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Quaternion_new05_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Quaternion_new06);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Quaternion_new06_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Quaternion_new06_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Quaternion_new07);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Quaternion_new07_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Quaternion_new07_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Quaternion_new08);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Quaternion_new08_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Quaternion_new08_local);
  tolua_function(tolua_S,"delete",tolua_MathLuaAPI_Quaternion_delete00);
  tolua_function(tolua_S,".eq",tolua_MathLuaAPI_Quaternion__eq00);
  tolua_function(tolua_S,".mul",tolua_MathLuaAPI_Quaternion__mul00);
  tolua_function(tolua_S,".sub",tolua_MathLuaAPI_Quaternion__sub00);
  tolua_function(tolua_S,".eq",tolua_MathLuaAPI_Quaternion__eq01);
  tolua_function(tolua_S,".mul",tolua_MathLuaAPI_Quaternion__mul01);
  tolua_function(tolua_S,".sub",tolua_MathLuaAPI_Quaternion__sub01);
  tolua_function(tolua_S,".add",tolua_MathLuaAPI_Quaternion__add00);
  tolua_function(tolua_S,".sub",tolua_MathLuaAPI_Quaternion__sub02);
  tolua_function(tolua_S,".mul",tolua_MathLuaAPI_Quaternion__mul02);
  tolua_function(tolua_S,".mul",tolua_MathLuaAPI_Quaternion__mul03);
  tolua_function(tolua_S,"FromAngleAxis",tolua_MathLuaAPI_Quaternion_FromAngleAxis00);
  tolua_function(tolua_S,"FromEulerAngles",tolua_MathLuaAPI_Quaternion_FromEulerAngles00);
  tolua_function(tolua_S,"FromRotationTo",tolua_MathLuaAPI_Quaternion_FromRotationTo00);
  tolua_function(tolua_S,"FromAxes",tolua_MathLuaAPI_Quaternion_FromAxes00);
  tolua_function(tolua_S,"FromRotationMatrix",tolua_MathLuaAPI_Quaternion_FromRotationMatrix00);
  tolua_function(tolua_S,"FromLookRotation",tolua_MathLuaAPI_Quaternion_FromLookRotation00);
  tolua_function(tolua_S,"Normalize",tolua_MathLuaAPI_Quaternion_Normalize00);
  tolua_function(tolua_S,"Normalized",tolua_MathLuaAPI_Quaternion_Normalized00);
  tolua_function(tolua_S,"Inverse",tolua_MathLuaAPI_Quaternion_Inverse00);
  tolua_function(tolua_S,"LengthSquared",tolua_MathLuaAPI_Quaternion_LengthSquared00);
  tolua_function(tolua_S,"DotProduct",tolua_MathLuaAPI_Quaternion_DotProduct00);
  tolua_function(tolua_S,"Equals",tolua_MathLuaAPI_Quaternion_Equals00);
  tolua_function(tolua_S,"IsNaN",tolua_MathLuaAPI_Quaternion_IsNaN00);
  tolua_function(tolua_S,"Conjugate",tolua_MathLuaAPI_Quaternion_Conjugate00);
  tolua_function(tolua_S,"EulerAngles",tolua_MathLuaAPI_Quaternion_EulerAngles00);
  tolua_function(tolua_S,"YawAngle",tolua_MathLuaAPI_Quaternion_YawAngle00);
  tolua_function(tolua_S,"PitchAngle",tolua_MathLuaAPI_Quaternion_PitchAngle00);
  tolua_function(tolua_S,"RollAngle",tolua_MathLuaAPI_Quaternion_RollAngle00);
  tolua_function(tolua_S,"Axis",tolua_MathLuaAPI_Quaternion_Axis00);
  tolua_function(tolua_S,"Angle",tolua_MathLuaAPI_Quaternion_Angle00);
  tolua_function(tolua_S,"RotationMatrix",tolua_MathLuaAPI_Quaternion_RotationMatrix00);
  tolua_function(tolua_S,"Slerp",tolua_MathLuaAPI_Quaternion_Slerp00);
  tolua_function(tolua_S,"Nlerp",tolua_MathLuaAPI_Quaternion_Nlerp00);
  tolua_function(tolua_S,"ToString",tolua_MathLuaAPI_Quaternion_ToString00);
  tolua_variable(tolua_S,"w",tolua_get_Quaternion_w,tolua_set_Quaternion_w);
  tolua_variable(tolua_S,"x",tolua_get_Quaternion_x,tolua_set_Quaternion_x);
  tolua_variable(tolua_S,"y",tolua_get_Quaternion_y,tolua_set_Quaternion_y);
  tolua_variable(tolua_S,"z",tolua_get_Quaternion_z,tolua_set_Quaternion_z);
  tolua_variable(tolua_S,"IDENTITY",tolua_get_Quaternion_IDENTITY,NULL);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"SetRandomSeed",tolua_MathLuaAPI_SetRandomSeed00);
 tolua_function(tolua_S,"GetRandomSeed",tolua_MathLuaAPI_GetRandomSeed00);
 tolua_function(tolua_S,"Rand",tolua_MathLuaAPI_Rand00);
 tolua_function(tolua_S,"RandStandardNormal",tolua_MathLuaAPI_RandStandardNormal00);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Ray","Ray","",tolua_collect_Ray);
 #else
 tolua_cclass(tolua_S,"Ray","Ray","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Ray");
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Ray_new00);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Ray_new00_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Ray_new00_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Ray_new01);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Ray_new01_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Ray_new01_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Ray_new02);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Ray_new02_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Ray_new02_local);
  tolua_function(tolua_S,"delete",tolua_MathLuaAPI_Ray_delete00);
  tolua_function(tolua_S,".eq",tolua_MathLuaAPI_Ray__eq00);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_Ray_Define00);
  tolua_function(tolua_S,"Project",tolua_MathLuaAPI_Ray_Project00);
  tolua_function(tolua_S,"Distance",tolua_MathLuaAPI_Ray_Distance00);
  tolua_function(tolua_S,"ClosestPoint",tolua_MathLuaAPI_Ray_ClosestPoint00);
  tolua_function(tolua_S,"HitDistance",tolua_MathLuaAPI_Ray_HitDistance00);
  tolua_function(tolua_S,"HitDistance",tolua_MathLuaAPI_Ray_HitDistance01);
  tolua_function(tolua_S,"HitDistance",tolua_MathLuaAPI_Ray_HitDistance02);
  tolua_function(tolua_S,"HitDistance",tolua_MathLuaAPI_Ray_HitDistance03);
  tolua_function(tolua_S,"HitDistance",tolua_MathLuaAPI_Ray_HitDistance04);
  tolua_function(tolua_S,"Transformed",tolua_MathLuaAPI_Ray_Transformed00);
  tolua_variable(tolua_S,"origin",tolua_get_Ray_origin,tolua_set_Ray_origin);
  tolua_variable(tolua_S,"direction",tolua_get_Ray_direction,tolua_set_Ray_direction);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Rect","Rect","",tolua_collect_Rect);
 #else
 tolua_cclass(tolua_S,"Rect","Rect","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Rect");
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Rect_new00);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Rect_new00_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Rect_new00_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Rect_new01);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Rect_new01_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Rect_new01_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Rect_new02);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Rect_new02_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Rect_new02_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Rect_new03);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Rect_new03_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Rect_new03_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Rect_new04);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Rect_new04_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Rect_new04_local);
  tolua_function(tolua_S,"delete",tolua_MathLuaAPI_Rect_delete00);
  tolua_function(tolua_S,".eq",tolua_MathLuaAPI_Rect__eq00);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_Rect_Define00);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_Rect_Define01);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_Rect_Define02);
  tolua_function(tolua_S,"Merge",tolua_MathLuaAPI_Rect_Merge00);
  tolua_function(tolua_S,"Merge",tolua_MathLuaAPI_Rect_Merge01);
  tolua_function(tolua_S,"Clear",tolua_MathLuaAPI_Rect_Clear00);
  tolua_function(tolua_S,"Clip",tolua_MathLuaAPI_Rect_Clip00);
  tolua_function(tolua_S,"Defined",tolua_MathLuaAPI_Rect_Defined00);
  tolua_function(tolua_S,"Center",tolua_MathLuaAPI_Rect_Center00);
  tolua_function(tolua_S,"Size",tolua_MathLuaAPI_Rect_Size00);
  tolua_function(tolua_S,"HalfSize",tolua_MathLuaAPI_Rect_HalfSize00);
  tolua_function(tolua_S,"Equals",tolua_MathLuaAPI_Rect_Equals00);
  tolua_function(tolua_S,"IsInside",tolua_MathLuaAPI_Rect_IsInside00);
  tolua_function(tolua_S,"IsInside",tolua_MathLuaAPI_Rect_IsInside01);
  tolua_function(tolua_S,"ToVector4",tolua_MathLuaAPI_Rect_ToVector400);
  tolua_function(tolua_S,"ToString",tolua_MathLuaAPI_Rect_ToString00);
  tolua_variable(tolua_S,"min",tolua_get_Rect_min,tolua_set_Rect_min);
  tolua_variable(tolua_S,"max",tolua_get_Rect_max,tolua_set_Rect_max);
  tolua_variable(tolua_S,"FULL",tolua_get_Rect_FULL,NULL);
  tolua_variable(tolua_S,"POSITIVE",tolua_get_Rect_POSITIVE,NULL);
  tolua_variable(tolua_S,"ZERO",tolua_get_Rect_ZERO,NULL);
  tolua_variable(tolua_S,"center",tolua_get_Rect_center,NULL);
  tolua_variable(tolua_S,"size",tolua_get_Rect_size,NULL);
  tolua_variable(tolua_S,"halfSize",tolua_get_Rect_halfSize,NULL);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"IntRect","IntRect","",tolua_collect_IntRect);
 #else
 tolua_cclass(tolua_S,"IntRect","IntRect","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"IntRect");
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_IntRect_new00);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_IntRect_new00_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_IntRect_new00_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_IntRect_new01);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_IntRect_new01_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_IntRect_new01_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_IntRect_new02);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_IntRect_new02_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_IntRect_new02_local);
  tolua_function(tolua_S,"delete",tolua_MathLuaAPI_IntRect_delete00);
  tolua_function(tolua_S,".eq",tolua_MathLuaAPI_IntRect__eq00);
  tolua_function(tolua_S,"Size",tolua_MathLuaAPI_IntRect_Size00);
  tolua_function(tolua_S,"Width",tolua_MathLuaAPI_IntRect_Width00);
  tolua_function(tolua_S,"Height",tolua_MathLuaAPI_IntRect_Height00);
  tolua_function(tolua_S,"IsInside",tolua_MathLuaAPI_IntRect_IsInside00);
  tolua_function(tolua_S,"Clip",tolua_MathLuaAPI_IntRect_Clip00);
  tolua_function(tolua_S,"Merge",tolua_MathLuaAPI_IntRect_Merge00);
  tolua_variable(tolua_S,"left",tolua_get_IntRect_left,tolua_set_IntRect_left);
  tolua_variable(tolua_S,"top",tolua_get_IntRect_top,tolua_set_IntRect_top);
  tolua_variable(tolua_S,"right",tolua_get_IntRect_right,tolua_set_IntRect_right);
  tolua_variable(tolua_S,"bottom",tolua_get_IntRect_bottom,tolua_set_IntRect_bottom);
  tolua_variable(tolua_S,"ZERO",tolua_get_IntRect_ZERO,NULL);
  tolua_variable(tolua_S,"size",tolua_get_IntRect_size,NULL);
  tolua_variable(tolua_S,"width",tolua_get_IntRect_width,NULL);
  tolua_variable(tolua_S,"height",tolua_get_IntRect_height,NULL);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Sphere","Sphere","",tolua_collect_Sphere);
 #else
 tolua_cclass(tolua_S,"Sphere","Sphere","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Sphere");
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Sphere_new00);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Sphere_new00_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Sphere_new00_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Sphere_new01);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Sphere_new01_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Sphere_new01_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Sphere_new02);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Sphere_new02_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Sphere_new02_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Sphere_new03);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Sphere_new03_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Sphere_new03_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Sphere_new04);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Sphere_new04_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Sphere_new04_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Sphere_new05);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Sphere_new05_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Sphere_new05_local);
  tolua_function(tolua_S,"delete",tolua_MathLuaAPI_Sphere_delete00);
  tolua_function(tolua_S,".eq",tolua_MathLuaAPI_Sphere__eq00);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_Sphere_Define00);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_Sphere_Define01);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_Sphere_Define02);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_Sphere_Define03);
  tolua_function(tolua_S,"Define",tolua_MathLuaAPI_Sphere_Define04);
  tolua_function(tolua_S,"Merge",tolua_MathLuaAPI_Sphere_Merge00);
  tolua_function(tolua_S,"Merge",tolua_MathLuaAPI_Sphere_Merge01);
  tolua_function(tolua_S,"Merge",tolua_MathLuaAPI_Sphere_Merge02);
  tolua_function(tolua_S,"Merge",tolua_MathLuaAPI_Sphere_Merge03);
  tolua_function(tolua_S,"Merge",tolua_MathLuaAPI_Sphere_Merge04);
  tolua_function(tolua_S,"Clear",tolua_MathLuaAPI_Sphere_Clear00);
  tolua_function(tolua_S,"Defined",tolua_MathLuaAPI_Sphere_Defined00);
  tolua_function(tolua_S,"IsInside",tolua_MathLuaAPI_Sphere_IsInside00);
  tolua_function(tolua_S,"IsInside",tolua_MathLuaAPI_Sphere_IsInside01);
  tolua_function(tolua_S,"IsInsideFast",tolua_MathLuaAPI_Sphere_IsInsideFast00);
  tolua_function(tolua_S,"IsInside",tolua_MathLuaAPI_Sphere_IsInside02);
  tolua_function(tolua_S,"IsInsideFast",tolua_MathLuaAPI_Sphere_IsInsideFast01);
  tolua_function(tolua_S,"Distance",tolua_MathLuaAPI_Sphere_Distance00);
  tolua_function(tolua_S,"GetLocalPoint",tolua_MathLuaAPI_Sphere_GetLocalPoint00);
  tolua_function(tolua_S,"GetPoint",tolua_MathLuaAPI_Sphere_GetPoint00);
  tolua_variable(tolua_S,"center",tolua_get_Sphere_center,tolua_set_Sphere_center);
  tolua_variable(tolua_S,"radius",tolua_get_Sphere_radius,tolua_set_Sphere_radius);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"StringHash","StringHash","",tolua_collect_StringHash);
 #else
 tolua_cclass(tolua_S,"StringHash","StringHash","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"StringHash");
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_StringHash_new00);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_StringHash_new00_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_StringHash_new00_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_StringHash_new01);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_StringHash_new01_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_StringHash_new01_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_StringHash_new02);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_StringHash_new02_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_StringHash_new02_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_StringHash_new03);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_StringHash_new03_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_StringHash_new03_local);
  tolua_function(tolua_S,"delete",tolua_MathLuaAPI_StringHash_delete00);
  tolua_function(tolua_S,".add",tolua_MathLuaAPI_StringHash__add00);
  tolua_function(tolua_S,".eq",tolua_MathLuaAPI_StringHash__eq00);
  tolua_function(tolua_S,".lt",tolua_MathLuaAPI_StringHash__lt00);
  tolua_function(tolua_S,".bool",tolua_MathLuaAPI_StringHash__bool00);
  tolua_function(tolua_S,"Value",tolua_MathLuaAPI_StringHash_Value00);
  tolua_function(tolua_S,"ToString",tolua_MathLuaAPI_StringHash_ToString00);
  tolua_function(tolua_S,"ToHash",tolua_MathLuaAPI_StringHash_ToHash00);
  tolua_function(tolua_S,"Calculate",tolua_MathLuaAPI_StringHash_Calculate00);
  tolua_variable(tolua_S,"ZERO",tolua_get_StringHash_ZERO,NULL);
  tolua_variable(tolua_S,"value",tolua_get_StringHash_value,NULL);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Vector2","Vector2","",tolua_collect_Vector2);
 #else
 tolua_cclass(tolua_S,"Vector2","Vector2","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Vector2");
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Vector2_new00);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Vector2_new00_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Vector2_new00_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Vector2_new01);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Vector2_new01_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Vector2_new01_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Vector2_new02);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Vector2_new02_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Vector2_new02_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Vector2_new03);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Vector2_new03_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Vector2_new03_local);
  tolua_function(tolua_S,"delete",tolua_MathLuaAPI_Vector2_delete00);
  tolua_function(tolua_S,".eq",tolua_MathLuaAPI_Vector2__eq00);
  tolua_function(tolua_S,".add",tolua_MathLuaAPI_Vector2__add00);
  tolua_function(tolua_S,".sub",tolua_MathLuaAPI_Vector2__sub00);
  tolua_function(tolua_S,".sub",tolua_MathLuaAPI_Vector2__sub01);
  tolua_function(tolua_S,".mul",tolua_MathLuaAPI_Vector2__mul00);
  tolua_function(tolua_S,".mul",tolua_MathLuaAPI_Vector2__mul01);
  tolua_function(tolua_S,".div",tolua_MathLuaAPI_Vector2__div00);
  tolua_function(tolua_S,".div",tolua_MathLuaAPI_Vector2__div01);
  tolua_function(tolua_S,"Normalize",tolua_MathLuaAPI_Vector2_Normalize00);
  tolua_function(tolua_S,"Length",tolua_MathLuaAPI_Vector2_Length00);
  tolua_function(tolua_S,"LengthSquared",tolua_MathLuaAPI_Vector2_LengthSquared00);
  tolua_function(tolua_S,"DotProduct",tolua_MathLuaAPI_Vector2_DotProduct00);
  tolua_function(tolua_S,"AbsDotProduct",tolua_MathLuaAPI_Vector2_AbsDotProduct00);
  tolua_function(tolua_S,"ProjectOntoAxis",tolua_MathLuaAPI_Vector2_ProjectOntoAxis00);
  tolua_function(tolua_S,"Angle",tolua_MathLuaAPI_Vector2_Angle00);
  tolua_function(tolua_S,"Abs",tolua_MathLuaAPI_Vector2_Abs00);
  tolua_function(tolua_S,"Lerp",tolua_MathLuaAPI_Vector2_Lerp00);
  tolua_function(tolua_S,"Equals",tolua_MathLuaAPI_Vector2_Equals00);
  tolua_function(tolua_S,"IsNaN",tolua_MathLuaAPI_Vector2_IsNaN00);
  tolua_function(tolua_S,"Normalized",tolua_MathLuaAPI_Vector2_Normalized00);
  tolua_function(tolua_S,"ToString",tolua_MathLuaAPI_Vector2_ToString00);
  tolua_variable(tolua_S,"x",tolua_get_Vector2_x,tolua_set_Vector2_x);
  tolua_variable(tolua_S,"y",tolua_get_Vector2_y,tolua_set_Vector2_y);
  tolua_variable(tolua_S,"ZERO",tolua_get_Vector2_ZERO,NULL);
  tolua_variable(tolua_S,"LEFT",tolua_get_Vector2_LEFT,NULL);
  tolua_variable(tolua_S,"RIGHT",tolua_get_Vector2_RIGHT,NULL);
  tolua_variable(tolua_S,"UP",tolua_get_Vector2_UP,NULL);
  tolua_variable(tolua_S,"DOWN",tolua_get_Vector2_DOWN,NULL);
  tolua_variable(tolua_S,"ONE",tolua_get_Vector2_ONE,NULL);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"IntVector2","IntVector2","",tolua_collect_IntVector2);
 #else
 tolua_cclass(tolua_S,"IntVector2","IntVector2","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"IntVector2");
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_IntVector2_new00);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_IntVector2_new00_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_IntVector2_new00_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_IntVector2_new01);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_IntVector2_new01_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_IntVector2_new01_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_IntVector2_new02);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_IntVector2_new02_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_IntVector2_new02_local);
  tolua_function(tolua_S,"delete",tolua_MathLuaAPI_IntVector2_delete00);
  tolua_function(tolua_S,".eq",tolua_MathLuaAPI_IntVector2__eq00);
  tolua_function(tolua_S,".add",tolua_MathLuaAPI_IntVector2__add00);
  tolua_function(tolua_S,".sub",tolua_MathLuaAPI_IntVector2__sub00);
  tolua_function(tolua_S,".sub",tolua_MathLuaAPI_IntVector2__sub01);
  tolua_function(tolua_S,".mul",tolua_MathLuaAPI_IntVector2__mul00);
  tolua_function(tolua_S,".mul",tolua_MathLuaAPI_IntVector2__mul01);
  tolua_function(tolua_S,".div",tolua_MathLuaAPI_IntVector2__div00);
  tolua_function(tolua_S,".div",tolua_MathLuaAPI_IntVector2__div01);
  tolua_function(tolua_S,"ToString",tolua_MathLuaAPI_IntVector2_ToString00);
  tolua_function(tolua_S,"ToHash",tolua_MathLuaAPI_IntVector2_ToHash00);
  tolua_function(tolua_S,"Length",tolua_MathLuaAPI_IntVector2_Length00);
  tolua_variable(tolua_S,"x",tolua_get_IntVector2_x,tolua_set_IntVector2_x);
  tolua_variable(tolua_S,"y",tolua_get_IntVector2_y,tolua_set_IntVector2_y);
  tolua_variable(tolua_S,"ZERO",tolua_get_IntVector2_ZERO,NULL);
  tolua_variable(tolua_S,"LEFT",tolua_get_IntVector2_LEFT,NULL);
  tolua_variable(tolua_S,"RIGHT",tolua_get_IntVector2_RIGHT,NULL);
  tolua_variable(tolua_S,"UP",tolua_get_IntVector2_UP,NULL);
  tolua_variable(tolua_S,"DOWN",tolua_get_IntVector2_DOWN,NULL);
  tolua_variable(tolua_S,"ONE",tolua_get_IntVector2_ONE,NULL);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"VectorLerp",tolua_MathLuaAPI_VectorLerp00);
 tolua_function(tolua_S,"VectorMin",tolua_MathLuaAPI_VectorMin00);
 tolua_function(tolua_S,"VectorMax",tolua_MathLuaAPI_VectorMax00);
 tolua_function(tolua_S,"VectorFloor",tolua_MathLuaAPI_VectorFloor00);
 tolua_function(tolua_S,"VectorRound",tolua_MathLuaAPI_VectorRound00);
 tolua_function(tolua_S,"VectorCeil",tolua_MathLuaAPI_VectorCeil00);
 tolua_function(tolua_S,"VectorFloorToInt",tolua_MathLuaAPI_VectorFloorToInt00);
 tolua_function(tolua_S,"VectorRoundToInt",tolua_MathLuaAPI_VectorRoundToInt00);
 tolua_function(tolua_S,"VectorCeilToInt",tolua_MathLuaAPI_VectorCeilToInt00);
 tolua_function(tolua_S,"VectorMin",tolua_MathLuaAPI_VectorMin01);
 tolua_function(tolua_S,"VectorMax",tolua_MathLuaAPI_VectorMax01);
 tolua_function(tolua_S,"StableRandom",tolua_MathLuaAPI_StableRandom00);
 tolua_function(tolua_S,"StableRandom",tolua_MathLuaAPI_StableRandom01);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Vector3","Vector3","",tolua_collect_Vector3);
 #else
 tolua_cclass(tolua_S,"Vector3","Vector3","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Vector3");
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Vector3_new00);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Vector3_new00_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Vector3_new00_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Vector3_new01);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Vector3_new01_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Vector3_new01_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Vector3_new02);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Vector3_new02_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Vector3_new02_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Vector3_new03);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Vector3_new03_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Vector3_new03_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Vector3_new04);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Vector3_new04_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Vector3_new04_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Vector3_new05);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Vector3_new05_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Vector3_new05_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Vector3_new06);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Vector3_new06_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Vector3_new06_local);
  tolua_function(tolua_S,"delete",tolua_MathLuaAPI_Vector3_delete00);
  tolua_function(tolua_S,".eq",tolua_MathLuaAPI_Vector3__eq00);
  tolua_function(tolua_S,".add",tolua_MathLuaAPI_Vector3__add00);
  tolua_function(tolua_S,".sub",tolua_MathLuaAPI_Vector3__sub00);
  tolua_function(tolua_S,".sub",tolua_MathLuaAPI_Vector3__sub01);
  tolua_function(tolua_S,".mul",tolua_MathLuaAPI_Vector3__mul00);
  tolua_function(tolua_S,".mul",tolua_MathLuaAPI_Vector3__mul01);
  tolua_function(tolua_S,".div",tolua_MathLuaAPI_Vector3__div00);
  tolua_function(tolua_S,".div",tolua_MathLuaAPI_Vector3__div01);
  tolua_function(tolua_S,"Normalize",tolua_MathLuaAPI_Vector3_Normalize00);
  tolua_function(tolua_S,"Length",tolua_MathLuaAPI_Vector3_Length00);
  tolua_function(tolua_S,"LengthSquared",tolua_MathLuaAPI_Vector3_LengthSquared00);
  tolua_function(tolua_S,"DotProduct",tolua_MathLuaAPI_Vector3_DotProduct00);
  tolua_function(tolua_S,"AbsDotProduct",tolua_MathLuaAPI_Vector3_AbsDotProduct00);
  tolua_function(tolua_S,"ProjectOntoAxis",tolua_MathLuaAPI_Vector3_ProjectOntoAxis00);
  tolua_function(tolua_S,"ProjectOntoPlane",tolua_MathLuaAPI_Vector3_ProjectOntoPlane00);
  tolua_function(tolua_S,"ProjectOntoLine",tolua_MathLuaAPI_Vector3_ProjectOntoLine00);
  tolua_function(tolua_S,"DistanceToPoint",tolua_MathLuaAPI_Vector3_DistanceToPoint00);
  tolua_function(tolua_S,"DistanceToPlane",tolua_MathLuaAPI_Vector3_DistanceToPlane00);
  tolua_function(tolua_S,"Orthogonalize",tolua_MathLuaAPI_Vector3_Orthogonalize00);
  tolua_function(tolua_S,"CrossProduct",tolua_MathLuaAPI_Vector3_CrossProduct00);
  tolua_function(tolua_S,"Abs",tolua_MathLuaAPI_Vector3_Abs00);
  tolua_function(tolua_S,"Lerp",tolua_MathLuaAPI_Vector3_Lerp00);
  tolua_function(tolua_S,"Equals",tolua_MathLuaAPI_Vector3_Equals00);
  tolua_function(tolua_S,"IsNaN",tolua_MathLuaAPI_Vector3_IsNaN00);
  tolua_function(tolua_S,"Angle",tolua_MathLuaAPI_Vector3_Angle00);
  tolua_function(tolua_S,"Normalized",tolua_MathLuaAPI_Vector3_Normalized00);
  tolua_function(tolua_S,"ToString",tolua_MathLuaAPI_Vector3_ToString00);
  tolua_variable(tolua_S,"x",tolua_get_Vector3_x,tolua_set_Vector3_x);
  tolua_variable(tolua_S,"y",tolua_get_Vector3_y,tolua_set_Vector3_y);
  tolua_variable(tolua_S,"z",tolua_get_Vector3_z,tolua_set_Vector3_z);
  tolua_variable(tolua_S,"ZERO",tolua_get_Vector3_ZERO,NULL);
  tolua_variable(tolua_S,"LEFT",tolua_get_Vector3_LEFT,NULL);
  tolua_variable(tolua_S,"RIGHT",tolua_get_Vector3_RIGHT,NULL);
  tolua_variable(tolua_S,"UP",tolua_get_Vector3_UP,NULL);
  tolua_variable(tolua_S,"DOWN",tolua_get_Vector3_DOWN,NULL);
  tolua_variable(tolua_S,"FORWARD",tolua_get_Vector3_FORWARD,NULL);
  tolua_variable(tolua_S,"BACK",tolua_get_Vector3_BACK,NULL);
  tolua_variable(tolua_S,"ONE",tolua_get_Vector3_ONE,NULL);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"IntVector3","IntVector3","",tolua_collect_IntVector3);
 #else
 tolua_cclass(tolua_S,"IntVector3","IntVector3","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"IntVector3");
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_IntVector3_new00);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_IntVector3_new00_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_IntVector3_new00_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_IntVector3_new01);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_IntVector3_new01_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_IntVector3_new01_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_IntVector3_new02);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_IntVector3_new02_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_IntVector3_new02_local);
  tolua_function(tolua_S,"delete",tolua_MathLuaAPI_IntVector3_delete00);
  tolua_function(tolua_S,".eq",tolua_MathLuaAPI_IntVector3__eq00);
  tolua_function(tolua_S,".add",tolua_MathLuaAPI_IntVector3__add00);
  tolua_function(tolua_S,".sub",tolua_MathLuaAPI_IntVector3__sub00);
  tolua_function(tolua_S,".sub",tolua_MathLuaAPI_IntVector3__sub01);
  tolua_function(tolua_S,".mul",tolua_MathLuaAPI_IntVector3__mul00);
  tolua_function(tolua_S,".mul",tolua_MathLuaAPI_IntVector3__mul01);
  tolua_function(tolua_S,".div",tolua_MathLuaAPI_IntVector3__div00);
  tolua_function(tolua_S,".div",tolua_MathLuaAPI_IntVector3__div01);
  tolua_function(tolua_S,"ToString",tolua_MathLuaAPI_IntVector3_ToString00);
  tolua_function(tolua_S,"ToHash",tolua_MathLuaAPI_IntVector3_ToHash00);
  tolua_function(tolua_S,"Length",tolua_MathLuaAPI_IntVector3_Length00);
  tolua_variable(tolua_S,"x",tolua_get_IntVector3_x,tolua_set_IntVector3_x);
  tolua_variable(tolua_S,"y",tolua_get_IntVector3_y,tolua_set_IntVector3_y);
  tolua_variable(tolua_S,"z",tolua_get_IntVector3_z,tolua_set_IntVector3_z);
  tolua_variable(tolua_S,"ZERO",tolua_get_IntVector3_ZERO,NULL);
  tolua_variable(tolua_S,"LEFT",tolua_get_IntVector3_LEFT,NULL);
  tolua_variable(tolua_S,"RIGHT",tolua_get_IntVector3_RIGHT,NULL);
  tolua_variable(tolua_S,"UP",tolua_get_IntVector3_UP,NULL);
  tolua_variable(tolua_S,"DOWN",tolua_get_IntVector3_DOWN,NULL);
  tolua_variable(tolua_S,"FORWARD",tolua_get_IntVector3_FORWARD,NULL);
  tolua_variable(tolua_S,"BACK",tolua_get_IntVector3_BACK,NULL);
  tolua_variable(tolua_S,"ONE",tolua_get_IntVector3_ONE,NULL);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"VectorLerp",tolua_MathLuaAPI_VectorLerp01);
 tolua_function(tolua_S,"VectorMin",tolua_MathLuaAPI_VectorMin02);
 tolua_function(tolua_S,"VectorMax",tolua_MathLuaAPI_VectorMax02);
 tolua_function(tolua_S,"VectorFloor",tolua_MathLuaAPI_VectorFloor01);
 tolua_function(tolua_S,"VectorRound",tolua_MathLuaAPI_VectorRound01);
 tolua_function(tolua_S,"VectorCeil",tolua_MathLuaAPI_VectorCeil01);
 tolua_function(tolua_S,"VectorFloorToInt",tolua_MathLuaAPI_VectorFloorToInt01);
 tolua_function(tolua_S,"VectorRoundToInt",tolua_MathLuaAPI_VectorRoundToInt01);
 tolua_function(tolua_S,"VectorCeilToInt",tolua_MathLuaAPI_VectorCeilToInt01);
 tolua_function(tolua_S,"VectorMin",tolua_MathLuaAPI_VectorMin03);
 tolua_function(tolua_S,"VectorMax",tolua_MathLuaAPI_VectorMax03);
 tolua_function(tolua_S,"StableRandom",tolua_MathLuaAPI_StableRandom02);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Vector4","Vector4","",tolua_collect_Vector4);
 #else
 tolua_cclass(tolua_S,"Vector4","Vector4","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Vector4");
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Vector4_new00);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Vector4_new00_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Vector4_new00_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Vector4_new01);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Vector4_new01_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Vector4_new01_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Vector4_new02);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Vector4_new02_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Vector4_new02_local);
  tolua_function(tolua_S,"new",tolua_MathLuaAPI_Vector4_new03);
  tolua_function(tolua_S,"new_local",tolua_MathLuaAPI_Vector4_new03_local);
  tolua_function(tolua_S,".call",tolua_MathLuaAPI_Vector4_new03_local);
  tolua_function(tolua_S,"delete",tolua_MathLuaAPI_Vector4_delete00);
  tolua_function(tolua_S,".eq",tolua_MathLuaAPI_Vector4__eq00);
  tolua_function(tolua_S,".add",tolua_MathLuaAPI_Vector4__add00);
  tolua_function(tolua_S,".sub",tolua_MathLuaAPI_Vector4__sub00);
  tolua_function(tolua_S,".sub",tolua_MathLuaAPI_Vector4__sub01);
  tolua_function(tolua_S,".mul",tolua_MathLuaAPI_Vector4__mul00);
  tolua_function(tolua_S,".mul",tolua_MathLuaAPI_Vector4__mul01);
  tolua_function(tolua_S,".div",tolua_MathLuaAPI_Vector4__div00);
  tolua_function(tolua_S,".div",tolua_MathLuaAPI_Vector4__div01);
  tolua_function(tolua_S,".div",tolua_MathLuaAPI_Vector4__div02);
  tolua_function(tolua_S,"DotProduct",tolua_MathLuaAPI_Vector4_DotProduct00);
  tolua_function(tolua_S,"AbsDotProduct",tolua_MathLuaAPI_Vector4_AbsDotProduct00);
  tolua_function(tolua_S,"ProjectOntoAxis",tolua_MathLuaAPI_Vector4_ProjectOntoAxis00);
  tolua_function(tolua_S,"Abs",tolua_MathLuaAPI_Vector4_Abs00);
  tolua_function(tolua_S,"Lerp",tolua_MathLuaAPI_Vector4_Lerp00);
  tolua_function(tolua_S,"Equals",tolua_MathLuaAPI_Vector4_Equals00);
  tolua_function(tolua_S,"IsNaN",tolua_MathLuaAPI_Vector4_IsNaN00);
  tolua_function(tolua_S,"ToString",tolua_MathLuaAPI_Vector4_ToString00);
  tolua_variable(tolua_S,"x",tolua_get_Vector4_x,tolua_set_Vector4_x);
  tolua_variable(tolua_S,"y",tolua_get_Vector4_y,tolua_set_Vector4_y);
  tolua_variable(tolua_S,"z",tolua_get_Vector4_z,tolua_set_Vector4_z);
  tolua_variable(tolua_S,"w",tolua_get_Vector4_w,tolua_set_Vector4_w);
  tolua_variable(tolua_S,"ZERO",tolua_get_Vector4_ZERO,NULL);
  tolua_variable(tolua_S,"ONE",tolua_get_Vector4_ONE,NULL);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"VectorLerp",tolua_MathLuaAPI_VectorLerp02);
 tolua_function(tolua_S,"VectorMin",tolua_MathLuaAPI_VectorMin04);
 tolua_function(tolua_S,"VectorMax",tolua_MathLuaAPI_VectorMax04);
 tolua_function(tolua_S,"VectorFloor",tolua_MathLuaAPI_VectorFloor02);
 tolua_function(tolua_S,"VectorRound",tolua_MathLuaAPI_VectorRound02);
 tolua_function(tolua_S,"VectorCeil",tolua_MathLuaAPI_VectorCeil02);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_MathLuaAPI (lua_State* tolua_S) {
 return tolua_MathLuaAPI_open(tolua_S);
}
#endif

#if __clang__
#pragma clang diagnostic pop
#endif