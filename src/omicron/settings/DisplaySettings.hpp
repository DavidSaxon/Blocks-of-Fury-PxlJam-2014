#ifndef OMICRON_SETTINGS_DISPLAYSETTINGS_H_
#   define OMICRON_SETTINGS_DISPLAYSETTINGS_H_

#include <GL/glew.h>
#include <SFML/OpenGL.hpp>

#include "lib/Utilitron/MacroUtil.hpp"
#include "lib/Utilitron/Vector.hpp"

namespace omi {

/******************************************************************************\
| An object that contains all settings relating to the display window that are |
| controlled by Omicron.                                                       |
\******************************************************************************/
class DisplaySettings {
private:

    //--------------------------------------------------------------------------
    //                                RESTRICTIONS
    //--------------------------------------------------------------------------

    DISALLOW_COPY_AND_ASSIGN(DisplaySettings);

public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates new window settings initialised with the default values */
    DisplaySettings();

    //--------------------------------------------------------------------------
    //                                 DESTRCUTOR
    //--------------------------------------------------------------------------

    ~DisplaySettings();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Hidden
    Checks if a change has been made to the settings */
    bool check();

    //---------------------------------GETTERS----------------------------------

    /** @return the title of the window */
    const std::string& getTitle() const;

    /** @return the size of the window */
    const util::vec::Vector2& getSize() const;
    
    /** @return the position of the window */
    const util::vec::Vector2& getPos() const;

    /** @return the centre of the window */
    const util::vec::Vector2 getCentre() const;

    /** @return if the window is in fullscreen */
    bool getFullscreen() const;

    /** @return if vsync is enabled */
    bool getVsync() const;

    //---------------------------------SETTERS----------------------------------

    /** @param title the new title of the window */
    void setTitle(const std::string& title);

    /** @param size the new size of the window */
    void setSize(const util::vec::Vector2& size);

    /** @param pos the new position of the window */
    void setPos(const util::vec::Vector2& pos);

    /** @param fullscreen the new fullscreen mode of the window */
    void setFullscreen(bool fullscreen);

    /** @param vsync whether vsnyc should be enabled or not */
    void setVsync(bool vsnyc);

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // if a setting has changed
    bool m_change;

    // the title of the window
    std::string m_title;
    // the size of the window
    util::vec::Vector2 m_size;
    // the position of the window
    util::vec::Vector2 m_pos;
    // the centre of the window
    util::vec::Vector2 m_centre;
    // is true if the window is in fullscreen
    bool m_fullscreen;
    // is true to enable vertical sync
    bool m_vsync;
};


} // namespace omi

#endif
