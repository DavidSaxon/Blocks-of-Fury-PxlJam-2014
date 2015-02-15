#include "SteelBlock.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

SteelBlock::SteelBlock(const util::vec::Vector3& pos, block::Owner owner) :
    Block("block_steel", "weapon_steel", "engine_steel", "trail_steel",
        0.03f, "bullet_steel", pos, owner) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

SteelBlock::~SteelBlock() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void SteelBlock::createBullet() {

    addEntity(new SteelBullet(
        bullet::Owner(m_owner), m_weaponT->translation));
}