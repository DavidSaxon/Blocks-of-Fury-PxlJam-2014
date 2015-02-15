#include "Explosion.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Explosion::Explosion(const util::vec::Vector3& pos, const std::string& name) :
    m_timer(0.0f) {

    float rnd = 0.0f + int((360.0 * rand()) / (RAND_MAX + 1.0));

    m_transform = new omi::Transform(
        "", pos,
        util::vec::Vector3(0.0f, 0.0f, rnd),
        util::vec::Vector3(1.0f, 1.0f, 1.0f)
    );

    m_sprite = omi::ResourceManager::getSprite(
        name, "", m_transform);
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

Explosion::~Explosion() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Explosion::init() {

    m_components.add(m_transform);
    m_components.add(m_sprite);
}

void Explosion::update() {

    m_transform->translation.y -=
        value::DOWN_SPEED * omi::fpsManager.getTimeScale();

    m_timer += 0.02f * omi::fpsManager.getTimeScale();
    if (m_timer > 1.0f) {

        remove();
    }
}

