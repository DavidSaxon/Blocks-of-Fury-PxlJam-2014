#include "Player.hpp"

namespace {

static const float LOOK_SPEED = 0.15f;
static const float MOVE_SPEED = 0.15f;

} // namespace anonymouse

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Player::Player() :
    m_shootButton(false) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

Player::~Player() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Player::init() {

    // create a camera
    m_camT = new omi::Transform("",
        util::vec::Vector3(),
        util::vec::Vector3(),
        util::vec::Vector3(1.0f, 1.0f, 1.0f)
    );
    m_camT->translation.z = -15.0f;
    m_components.add(m_camT);
    m_components.add(
        new omi::Camera("", omi::cam::PERSPECTIVE, m_camT));

    // create collision detector
    m_collisionDetect = new omi::CollisionDetector(
        "", "player", this);
    m_collisionDetect->addBounding(new omi::BoundingCircle(2.0f, m_camT));
    m_components.add(m_collisionDetect);

    // create music
    m_musicStart = new omi::Music(
        "", "res/sound/music/test/test_music_start.ogg",
        1.0f, false
    );
    m_components.add(m_musicStart);
    m_musicMain = new omi::Music(
        "", "res/sound/music/test/test_music_main.ogg",
        1.0f, true
    );
    m_components.add(m_musicMain);

    // get sounds
    m_sound_1 = omi::ResourceManager::getSound("test_sound_1");

    // start playing music
    m_musicStart->play();
}

void Player::update() {

    // transition music
    if (m_musicStart->isStopped() && m_musicMain->isStopped()) {

        m_musicMain->play();
    }

    // shoot
    if (omi::input::mousePressed(sf::Mouse::Left)) {

        if (!m_shootButton) {

            omi::SoundPool::play(m_sound_1, false, 1.0f);
            m_shootButton = true;
        }
    }
    else {

        m_shootButton = false;
    }

    // look
    m_camT->rotation.x -=
        (omi::displaySettings.getCentre().y - omi::input::getMousePos().y) *
        LOOK_SPEED * omi::fpsManager.getTimeScale();
    m_camT->rotation.y -=
        (omi::displaySettings.getCentre().x - omi::input::getMousePos().x) *
        LOOK_SPEED * omi::fpsManager.getTimeScale();

    // move
    float moveSpeed = MOVE_SPEED * omi::fpsManager.getTimeScale();
    if (omi::input::isKeyPressed(sf::Keyboard::W)) {

        m_camT->translation.z +=
            util::math::cosd(m_camT->rotation.y) * moveSpeed;
        m_camT->translation.x -=
            util::math::sind(m_camT->rotation.y) * moveSpeed;
    }
    if (omi::input::isKeyPressed(sf::Keyboard::S)) {

        m_camT->translation.z -=
            util::math::cosd(m_camT->rotation.y) * moveSpeed;
        m_camT->translation.x +=
            util::math::sind(m_camT->rotation.y) * moveSpeed;
    }
    if (omi::input::isKeyPressed(sf::Keyboard::A)) {

        m_camT->translation.z +=
            util::math::sind(m_camT->rotation.y) * moveSpeed;
        m_camT->translation.x +=
            util::math::cosd(m_camT->rotation.y) * moveSpeed;
    }
    if (omi::input::isKeyPressed(sf::Keyboard::D)) {

        m_camT->translation.z -=
            util::math::sind(m_camT->rotation.y) * moveSpeed;
        m_camT->translation.x -=
            util::math::cosd(m_camT->rotation.y) * moveSpeed;
    }
}

