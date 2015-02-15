#ifndef OMICRON_RESOURCE_PACK_BUILD_H_
#   define OMICRON_RESOURCE_PACK_BUILD_H_

#include "src/omicron/resource/ResourceManager.hpp"
#include "src/override/ResourceGroups.hpp"

/************************************************************************\
| Contains all resources packs that can be built to add resources to the |
| resource manager.                                                      |
\************************************************************************/
namespace pack {

//------------------------------------------------------------------------------
//                                  ENUMERATORS
//------------------------------------------------------------------------------

// The rendering layers of different resources
enum Layers {

    BOTTOM = 0,
    TERRAIN,
    ENGINE_TRAIL,
    BULLET,
    SHIP_ENGINE,
    SHIP_WEAPON,
    SHIP_BLOCK,
    BULLET_EXPLOSION,
    TOP,
    GUI,
    COIN
};

//------------------------------------------------------------------------------
//                                   PROTOTYPES
//------------------------------------------------------------------------------

//--------------------------------RESOURCE PACKS--------------------------------

void buildAllPack();

void buildStartUpPack();

void buildTestPack();

void buildLevelPack();

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

/** Builds all resource packs */
inline void build() {

    buildAllPack();
    buildStartUpPack();
    buildTestPack();
    buildLevelPack();
}

} // namespace pack

#endif
