#include "LevelScene.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

LevelScene::LevelScene() :
    m_enemyTimer(1.0f),
    m_diff(0.6f),
    m_start(false) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

LevelScene::~LevelScene() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void LevelScene::init() {

    // apply settings
    omi::renderSettings.setAmbientStrength(1.0f);
    omi::renderSettings.setAmbientColour(util::vec::Vector3(1.0f, 1.0f, 1.0f));

    // set up collision groups
    omi::CollisionDetect::checkGroup("player_block", "player_block");
    omi::CollisionDetect::checkGroup("player_block", "none_block");
    omi::CollisionDetect::checkGroup("player_block", "enemy_block");
    omi::CollisionDetect::checkGroup("player_block", "enemy_bullet");
    omi::CollisionDetect::checkGroup("enemy_block", "player_bullet");

    // add entities
    addEntity(new Terrain());
    addEntity(new PlayerShip());

}

bool LevelScene::update() {

    // exit if the escape key has been pressed
    if (omi::input::isKeyPressed(sf::Keyboard::Escape)) {

        exit(0);
    }

    if (!m_start) {

        if (omi::input::isKeyPressed(sf::Keyboard::Space)) {

            m_start = true;
        }
        
        return false;
    }

    // increase difficulty
    m_diff += 0.0003f * omi::fpsManager.getTimeScale();

    m_enemyTimer += (0.005f * ((rand() % 1000) / 1000.0f) *
        omi::fpsManager.getTimeScale()) + (m_diff * 0.00001f);

    if (m_enemyTimer >= 1.0f) {

        float xPos = ((((rand() % 1000) / 1000.0f) * 2.0f) - 1.0f);
        xPos *= 29.0f;
        addEntity(
            new EnemyShip(util::vec::Vector3(xPos, 22.0f, 0.0f), m_diff));
        m_enemyTimer = 0.0f;
    }

    return false;
}

omi::Scene* LevelScene::nextScene() const {

    return new LevelScene();
}