#include "Packs.hpp"

namespace pack {

void buildTestPack() {

    //----------------------------------MESHES----------------------------------


    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "test_skybox", resource_group::TEST,
        "test_shader",
        "res/gfx/texture/test/skybox.png",
        "res/gfx/geometry/test/skybox.obj",
        0
    );
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "test_floor_1", resource_group::TEST,
        "default_shader",
        "res/gfx/texture/test/floor_1.png",
        "res/gfx/geometry/test/floor_1.obj",
        1
    );
    omi::ResourceManager::addMaterialGeometryMesh(
        "test_monkey", resource_group::TEST,
        "default_shader",
        util::vec::Vector4(1.0f, 0.0f, 0.0f, 1.0f),
        "res/gfx/geometry/test/monkey.obj",
        2
    );
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "test_human", resource_group::TEST,
        "default_shader",
        "res/gfx/texture/test/human.png",
        "res/gfx/geometry/test/human.obj",
        2
    );

    //----------------------------------SOUNDS----------------------------------

    omi::ResourceManager::addSound(
        "test_sound_1", resource_group::TEST,
        "res/sound/fx/test/test_sound_2.ogg", 3
    );
}

} // namespace pack
