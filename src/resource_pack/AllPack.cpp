#include "Packs.hpp"

namespace pack {

void buildAllPack() {

    //---------------------------------SHADERS----------------------------------

    // default shader
    omi::ResourceManager::addShader(
        "default_shader",
        resource_group::ALL,
        "res/gfx/shader/omicron/default_vertex.glsl",
        "res/gfx/shader/omicron/default_fragment.glsl"
    );

    // testing shader
    omi::ResourceManager::addShader(
        "test_shader",
        resource_group::ALL,
        "res/gfx/shader/omicron/test_vertex.glsl",
        "res/gfx/shader/omicron/test_fragment.glsl"
    );
}

} // namespace pack