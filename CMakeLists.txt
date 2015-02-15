cmake_minimum_required(VERSION 2.6)
project(blocks_of_fury)

set(SRCS

    src/omicron/Omicron.cpp
    src/omicron/audio/SoundPool.cpp
    src/omicron/component/Camera.cpp
    src/omicron/component/physics/CollisionDetector.cpp
    src/omicron/component/renderable/Mesh.cpp
    src/omicron/component/renderable/Sprite.cpp
    src/omicron/component/updatable/audio/Music.cpp
    src/omicron/display/Window.cpp
    src/omicron/entity/ComponentTable.cpp
    src/omicron/input/Keyboard.cpp
    src/omicron/input/Mouse.cpp
    src/omicron/logic/FPSManager.cpp
    src/omicron/logic/LogicManager.cpp
    src/omicron/physics/collision_detect/CollisionDetect.cpp
    src/omicron/rendering/Renderer.cpp
    src/omicron/rendering/RenderLists.cpp
    src/omicron/rendering/shading/Animation.cpp
    src/omicron/rendering/shading/Material.cpp
    src/omicron/rendering/shading/Shader.cpp
    src/omicron/rendering/shading/Texture.cpp
    src/omicron/resource/loader/GeometryLoader.cpp
    src/omicron/resource/loader/ShaderLoader.cpp
    src/omicron/resource/loader/TextureLoader.cpp
    src/omicron/resource/type/GeometryResource.cpp
    src/omicron/resource/type/MaterialResource.cpp
    src/omicron/resource/type/MeshResource.cpp
    src/omicron/resource/type/ShaderResource.cpp
    src/omicron/resource/type/SpriteResource.cpp
    src/omicron/resource/type/SoundResource.cpp
    src/omicron/resource/type/TextureResource.cpp
    src/omicron/resource/ResourceManager.cpp
    src/omicron/scene/Scene.cpp
    src/omicron/settings/AudioSettings.cpp
    src/omicron/settings/DisplaySettings.cpp
    src/omicron/settings/RenderSettings.cpp
    src/omicron/settings/SystemSettings.cpp
    src/omicron/system/System.cpp
    src/override/StartUp.cpp

    src/resource_pack/AllPack.cpp
    src/resource_pack/LevelPack.cpp
    src/resource_pack/StartUpPack.cpp
    src/resource_pack/TestPack.cpp

    src/scenes/LevelScene.cpp
    src/scenes/StartUpScene.cpp
    src/scenes/TestScene.cpp

    src/entities/start_up/OmicronLogo.cpp
    src/entities/test/Human.cpp
    src/entities/test/Monkey.cpp
    src/entities/test/Player.cpp
    src/entities/test/Skybox.cpp
    src/entities/level/Cave.cpp
    src/entities/level/EnemyShip.cpp
    src/entities/level/Explosion.cpp
    src/entities/level/PlayerShip.cpp
    src/entities/level/Terrain.cpp
    src/entities/level/block/Block.cpp
    src/entities/level/block/CopperBlock.cpp
    src/entities/level/block/EnemyHub.cpp
    src/entities/level/block/GoldBlock.cpp
    src/entities/level/block/PlayerHub.cpp
    src/entities/level/block/RustyBlock.cpp
    src/entities/level/block/SilverBlock.cpp
    src/entities/level/block/SteelBlock.cpp
    src/entities/level/block/TitaniumBlock.cpp
    src/entities/level/bullet/Bullet.cpp
    src/entities/level/bullet/CopperBullet.cpp
    src/entities/level/bullet/GoldBullet.cpp
    src/entities/level/bullet/RustyBullet.cpp
    src/entities/level/bullet/SilverBullet.cpp
    src/entities/level/bullet/SteelBullet.cpp
    src/entities/level/bullet/TitaniumBullet.cpp
)

set(BASEPATH "${CMAKE_SOURCE_DIR}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++0x -DGL_GLEXT_PROTOTYPES")

include_directories("${BASEPATH}" ${INCLUDE_DIRECTORIES})

link_directories(${LINK_DIRECTORIES})

add_executable(blocks_of_fury ${SRCS})

target_link_libraries(blocks_of_fury

    -lGL
    -lGLU
    -lGLEW
    -lm
    -lIL
    -lsfml-graphics
    -lsfml-window
    -lsfml-audio
    -lsfml-system
)
