#include "Cave.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Cave::Cave(bool exit) :
    m_exit(exit),
    m_fading(false) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

Cave::~Cave() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Cave::init() {

    if (!m_exit) {

        m_transform = new omi::Transform("",
            util::vec::Vector3(0.0f, 130.0f, 0.0f),
            util::vec::Vector3(0.0f, 0.0f, 0.0f),
            util::vec::Vector3(1.0f, 1.0f, 1.0f)
        );
    }
    else {

        m_transform = new omi::Transform("",
            util::vec::Vector3(0.0f, 130.0f, 0.0f),
            util::vec::Vector3(0.0f, 0.0f, 180.0f),
            util::vec::Vector3(1.0f, 1.0f, 1.0f)
        );
    }
    m_components.add(m_transform);
    m_components.add(omi::ResourceManager::getSprite(
        "cave_opening", "", m_transform));
}

void Cave::update() {

    // move down
    m_transform->translation.y -= value::DOWN_SPEED * 2.0f *
        omi::fpsManager.getTimeScale();

    if (m_transform->translation.y <= 0.0f && !m_fading) {

        m_fading = true;
    }

    if (m_fading) {

        if (m_exit) {

            if (omi::renderSettings.getAmbientStrength() < 1.0f) {

                omi::renderSettings.setAmbientStrength(
                    omi::renderSettings.getAmbientStrength() +
                    (0.01f * omi::fpsManager.getTimeScale()));
            }
            if (omi::renderSettings.getAmbientStrength() >= 1.0f) {

                omi::renderSettings.setAmbientStrength(1.0f);
            }
        }
        else {

            if (omi::renderSettings.getAmbientStrength() > 0.25f) {

                omi::renderSettings.setAmbientStrength(
                    omi::renderSettings.getAmbientStrength() -
                    (0.01f * omi::fpsManager.getTimeScale()));
            }
            if (omi::renderSettings.getAmbientStrength() <= 0.25f) {

                omi::renderSettings.setAmbientStrength(0.25f);
            }
        }
    }

    if (m_transform->translation.y <= -65.0f) {

        remove();
    }
}

