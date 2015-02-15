#include "SilverBlock.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

SilverBlock::SilverBlock(const util::vec::Vector3& pos, block::Owner owner) :
    Block("block_silver", "weapon_silver", "engine_silver", "trail_silver",
        0.05f, "bullet_silver", pos, owner) {

    m_health = 2.5f;
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

SilverBlock::~SilverBlock() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void SilverBlock::createBullet() {

    addEntity(new SilverBullet(
        bullet::Owner(m_owner), m_weaponT->translation));
}
