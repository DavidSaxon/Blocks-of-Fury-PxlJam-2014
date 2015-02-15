#include "Window.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Window::Window() :
    m_cursorVisble(true) {

    // set up flags
    unsigned flags = sf::Style::Default;
    if (displaySettings.getFullscreen()) {

        flags = sf::Style::Fullscreen;
    }

    // set up for openGL
    sf::ContextSettings settings;
    settings.depthBits          = 24;
    settings.stencilBits        = 8;
    settings.antialiasingLevel  = 4;
    settings.majorVersion       = 3;
    settings.minorVersion       = 0;

    if (!displaySettings.getFullscreen()) {

        // create the window using sfml
        m_window = std::unique_ptr<sf::Window>(new sf::Window(
            sf::VideoMode(displaySettings.getSize().x, displaySettings.getSize().y),
            displaySettings.getTitle(), flags, settings
        ));

        // set the position of the window
        m_window->setPosition(sf::Vector2i(
            displaySettings.getPos().x, displaySettings.getPos().y));
    }
    else {

        // create the window using sfml
        m_window = std::unique_ptr<sf::Window>(new sf::Window(
            sf::VideoMode::getDesktopMode(),
            displaySettings.getTitle(), flags, settings
        ));
    }

    // set sync
    m_window->setVerticalSyncEnabled(displaySettings.getVsync());

    // set cursor visibility
    m_window->setMouseCursorVisible(m_cursorVisble);
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

Window::~Window() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Window::update() {

    // check if there has been a change in settings
    if (displaySettings.check()) {

        if (!displaySettings.getFullscreen()) {

            m_window->setSize(sf::Vector2u(
                displaySettings.getSize().x, displaySettings.getSize().y));
            m_window->setPosition(sf::Vector2i(
                displaySettings.getPos().x, displaySettings.getPos().y));
            m_window->setTitle(displaySettings.getTitle());
        }

        // TODO: full screen... tricky problem
    }

    // set cursor visibility
    m_window->setMouseCursorVisible(m_cursorVisble);

    // check events
    sf::Event event;
    while (m_window->pollEvent(event)) {

        // TODO: this should be override able
        // close button is pressed
        if (event.type == sf::Event::Closed) {

            exit(0);
        }
    }

    // redisplay the window
    m_window->display();
}

void Window::setCursorVisble(bool visible) {

    m_cursorVisble = visible;
}

} // namespace omi
