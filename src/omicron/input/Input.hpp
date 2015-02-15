#ifndef OMICRON_INPUT_INPUT_H_
#   define OMICRON_INPUT_INPUT_H_

#include <SFML/Window.hpp>

#include "lib/Utilitron/Vector.hpp"

namespace omi {

/*********************************\
| functions handling input events |
\*********************************/
namespace input {

//------------------------------------------------------------------------------
//                                  ENUMERATORS
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//                                   PROTOTYPES
//------------------------------------------------------------------------------

/** @return the mouse position */
util::vec::Vector2 getMousePos();

// TODO: make omi mouse buttons
/** @return if the given mouse button is being pressed */
bool mousePressed(sf::Mouse::Button button);

// TODO: make omicron key enum
/** Check if the given is being pressed
#NOTE: this does not take into consideration upper and lower case
@param key the key to check for
@return if the key is being pressed*/
bool isKeyPressed(sf::Keyboard::Key key);

} // namespace input

} // namespace omi

#endif