#include "SystemSettings.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

SystemSettings::SystemSettings() :
    m_change(true),
    m_cursorHidden(false),
    m_cursorLocked(false) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

SystemSettings::~SystemSettings() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

bool SystemSettings::check() {

    bool temp = m_change;
    m_change = false;
    return temp;
}

bool SystemSettings::isCursorHidden() const {

    return m_cursorHidden;
}

bool SystemSettings::isCursorLocked() const {

    return m_cursorLocked;
}

const util::vec::Vector2& SystemSettings::getCursorLockedPos() const {

    return m_cursorLockPos;
}

void SystemSettings::setCursorHidden(bool hidden) {

    m_cursorHidden = hidden;
    m_change = true;
}

void SystemSettings::setCursorLocked(bool locked) {

    m_cursorLocked = locked;
    m_change = true;
}

void SystemSettings::setCursorLockPosition(const util::vec::Vector2& pos) {

    m_cursorLockPos = pos;
    m_change = true;
}

} // namespace omi