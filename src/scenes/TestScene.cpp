#include "TestScene.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

TestScene::TestScene() {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

TestScene::~TestScene() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void TestScene::init() {

    // apply settings
    omi::systemSettings.setCursorLocked(true);
    omi::systemSettings.setCursorLockPosition(omi::displaySettings.getCentre());

    omi::renderSettings.setAmbientStrength(0.3f);
    omi::renderSettings.setAmbientColour(util::vec::Vector3(0.3f, 0.3f, 1.0f));

    // add entities
    addEntity(new Player());
    addEntity(new Skybox());
    addEntity(new Human());
}

bool TestScene::update() {

    // exit if the escape key has been pressed
    if (omi::input::isKeyPressed(sf::Keyboard::Escape)) {

        return true;
    }

    return false;
}

omi::Scene* TestScene::nextScene() const {

    // revert settings
    omi::systemSettings.setCursorLocked(false);

    return 0;
}
