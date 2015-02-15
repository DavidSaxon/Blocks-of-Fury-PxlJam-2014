#include "Monkey.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Monkey::init() {

    // add meshes
    m_components.add(
        omi::ResourceManager::getMesh("test_monkey", "", NULL));
}

void Monkey::update() {
}

