#include "Input.hpp"

namespace omi {

namespace input {

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

util::vec::Vector2 getMousePos() {

    sf::Vector2i pos = sf::Mouse::getPosition();
    return util::vec::Vector2(
            static_cast<float>( pos.x ),
            static_cast<float>( pos.y )
    );
}

bool mousePressed(sf::Mouse::Button button) {

    return sf::Mouse::isButtonPressed(button);
}

} // namespace input

} // namespace omi
