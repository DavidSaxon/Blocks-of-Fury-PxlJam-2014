#ifndef OMICRON_SETTINGS_RENDERSETTINGS_H_
#   define OMICRON_SETTINGS_RENDERSETTINGS_H_

#include <GL/glew.h>
#include <SFML/OpenGL.hpp>

#include "lib/Utilitron/MacroUtil.hpp"
#include "lib/Utilitron/Vector.hpp"

namespace omi {

/*************************************************************\
| An object that contains all settings relating to rendering. |
\*************************************************************/
class RenderSettings {
private:

    //--------------------------------------------------------------------------
    //                                RESTRICTIONS
    //--------------------------------------------------------------------------

    DISALLOW_COPY_AND_ASSIGN(RenderSettings);

public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates new render settings initialised with default values */
    RenderSettings();

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~RenderSettings();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Hidden
    Checks if a change has been made to the settings */
    bool check();

    //---------------------------------GETTERS----------------------------------

    /** @return if depth testing is enabled */
    bool getDepthTest() const;

    /** @param depthTest whether depth testing should be enabled */
    void setDepthTest(bool depthTest);

    /** @return if back face culling is enabled */
    bool getBackFaceCulling() const;

    /** @return the strength of the ambient light */
    float getAmbientStrength() const;

    /** @return the colour of the ambient light */
    const util::vec::Vector3& getAmbientColour() const;

    //---------------------------------SETTERS----------------------------------

    /** @param backFaceCulling whether back face culling should be enabled */
    void setBackFaceCulling(bool backFaceCulling);

    /** @return the clear colour */
    const util::vec::Vector4& getClearColour() const;

    /** @param clearColour the new clear colour */
    void setClearColour(const util::vec::Vector4& clearColour);

    /** @param strength the new strength of ambient light */
    void setAmbientStrength(float strength);

    /** @param colour the new colour of ambient light */
    void setAmbientColour(const util::vec::Vector3& colour);

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // if a setting has changed
    bool m_change;

    // if depth testing is enabled
    bool m_depthTest;
    // if back face culling should be enabled
    bool m_backFaceCulling;
    // the clear colour
    util::vec::Vector4 m_clearColour;

    // the strength of ambient light
    float m_ambientStrength;
    // the colour of ambient light
    util::vec::Vector3 m_ambientColour;
};

} // namespace omi

#endif
