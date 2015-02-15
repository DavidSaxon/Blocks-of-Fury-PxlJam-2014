#include "Skybox.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Skybox::init() {

    // add meshes
    // m_components.add(
    //     omi::ResourceManager::getMesh("test_skybox", "", NULL));
    m_components.add(
        omi::ResourceManager::getMesh("test_floor_1", "", NULL));
}

void Skybox::update() {
}
