-- Urho2D sprite example.
-- This sample demonstrates:
--     - Creating a 2D scene with sprite
--     - Displaying the scene using the Renderer subsystem
--     - Handling keyboard to move and zoom 2D camera
--     - Usage of Lua Closure to update scene

require "LuaScripts/Utilities/Sample"

function Start()
    -- Execute the common startup for samples
    SampleStart()

    -- Create the scene content
    CreateScene()

    -- Setup the viewport for displaying the scene
    SetupViewport()
end

function CreateScene()
    scene_ = Scene()

    -- Create the Octree component to the scene. This is required before adding any drawable components, or else nothing will
    -- show up. The default octree volume will be from (-1000, -1000, -1000) to (1000, 1000, 1000) in world coordinates it
    -- is also legal to place objects outside the volume but their visibility can then not be checked in a hierarchically
    -- optimizing manner
    scene_:CreateComponent("Octree")

    -- Create a scene node for the camera, which we will move around
    -- The camera will use default settings (1000 far clip distance, 45 degrees FOV, set aspect ratio automatically)
    cameraNode = scene_:CreateChild("Camera")
    -- Set an initial position for the camera scene node above the plane
    cameraNode.position = Vector3(0.0, 0.0, -10.0)
    local camera = cameraNode:CreateComponent("Camera")
    camera.orthographic = true
    camera.orthoSize = graphics.height * PIXEL_SIZE

    -- local spriteAnimationSet = cache:GetResource("AnimationSet2D", "Urho2D/imp/imp.scml")
    -- if spriteAnimationSet == nil then
    --     return
    -- end
    -- local spriteAnimationNode = scene_:CreateChild("SpriteAnimation")
    -- local spriteAnimatedSprite = spriteAnimationNode:CreateComponent("AnimatedSprite2D")
    -- spriteAnimatedSprite.animationSet = spriteAnimationSet
    -- spriteAnimatedSprite:SetAnimation(spriteAnimationSet:GetAnimation(1), LM_FORCE_LOOPED)

    -- local spriteSheet = cache:GetResource("SpriteSheet2D", "ERA/buildings.plist")
    -- if spriteSheet == nil then
    --     return
    -- end
    -- local spriteNode = scene_:CreateChild("StaticSprite2D")
    -- spriteNode:SetScale(3.0)
    -- local staticSprite = spriteNode:CreateComponent("StaticSprite2D")
    -- staticSprite.sprite = spriteSheet:GetSprite("Dino_cave/Dino-cave-01")

    local sprite = cache:GetResource("Sprite2D", "Urho2D/imp/imp_all.png")
    if sprite == nil then
        return
    end
    local spriteNode = scene_:CreateChild("spriteNode")
    spriteNode:SetScale(3.0)
    local staticSprite = spriteNode:CreateComponent("StaticSprite2D")
    staticSprite.sprite = sprite
end

function SetupViewport()
    -- Set up a viewport to the Renderer subsystem so that the 3D scene can be seen. We need to define the scene and the camera
    -- at minimum. Additionally we could configure the viewport screen size and the rendering path (eg. forward / deferred) to
    -- use, but now we just use full screen and default render path configured in the engine command line options
    local viewport = Viewport:new(scene_, cameraNode:GetComponent("Camera"))
    renderer:SetViewport(0, viewport)
end
