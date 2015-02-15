#ifndef OMICRON_OMICRON_H_
#   define OMICRON_OMICRON_H_

#include "src/omicron/logic/FPSManager.hpp"
#include "src/omicron/settings/AudioSettings.hpp"
#include "src/omicron/settings/DisplaySettings.hpp"
#include "src/omicron/settings/RenderSettings.hpp"
#include "src/omicron/settings/SystemSettings.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                GLOBAL VARIABLES
//------------------------------------------------------------------------------

//-----------------------------------SETTINGS-----------------------------------

// system settings
extern SystemSettings systemSettings;
// the display settings
extern DisplaySettings displaySettings;
// the render settings
extern RenderSettings renderSettings;
// the audio settings
extern AudioSettings audioSettings;

// the fps manager
extern FPSManager fpsManager;

} // namespace omi

#endif
