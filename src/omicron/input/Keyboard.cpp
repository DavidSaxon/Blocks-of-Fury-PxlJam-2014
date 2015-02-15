#include "Input.hpp"

namespace omi {

namespace input {

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

bool isKeyPressed(sf::Keyboard::Key key) {

    return sf::Keyboard::isKeyPressed(key);
}

} // namespace input

} // namespace omi
