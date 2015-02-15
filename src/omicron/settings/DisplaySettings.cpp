#include "DisplaySettings.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

DisplaySettings::DisplaySettings() :
    m_change    (true),
    m_title     ("Omicron"),
    m_size      (640, 480),
    m_pos       (0, 0),
    m_centre    (320, 240),
    m_fullscreen(false),
    m_vsync     (false) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

DisplaySettings::~DisplaySettings() {
}

//------------------------------------------------------------------------------
//                             PUBLIC MEMBER FUNCIONS
//------------------------------------------------------------------------------

bool DisplaySettings::check() {

    bool temp = m_change;
    m_change = false;
    return temp;
}

//-----------------------------------GETTERS------------------------------------

const std::string& DisplaySettings::getTitle() const {

    return m_title;
}

const util::vec::Vector2& DisplaySettings::getSize() const {

    return m_size;
}

const util::vec::Vector2& DisplaySettings::getPos() const {

    return m_pos;
}

const util::vec::Vector2 DisplaySettings::getCentre() const {

    return m_centre;
}

bool DisplaySettings::getFullscreen() const {

    return m_fullscreen;
}

bool DisplaySettings::getVsync() const {

    return m_vsync;
}

//-----------------------------------SETTERS------------------------------------

void DisplaySettings::setTitle(const std::string& title) {

    m_title = title;
    m_change = true;
}

void DisplaySettings::setSize(const util::vec::Vector2& size) {

    m_size = size;
    // update the centre pos
    m_centre.x = m_size.x / 2.0f;
    m_centre.y = m_size.y / 2.0f;
    m_change = true;
}

void DisplaySettings::setPos(const util::vec::Vector2& pos) {

    m_pos = pos;
    m_change = true;
}

void DisplaySettings::setFullscreen(bool fullscreen) {

    m_fullscreen = fullscreen;
    m_change = true;
}

void DisplaySettings::setVsync(bool vsnyc) {

    m_vsync = vsnyc;
}

} // namespace omi
