#include "Human.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Human::init() {

    // add meshes
    m_components.add(
        omi::ResourceManager::getMesh("test_human", "", NULL));
}

void Human::update() {
}

