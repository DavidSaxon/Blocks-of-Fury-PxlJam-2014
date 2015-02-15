#include "RustyBlock.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

RustyBlock::RustyBlock(const util::vec::Vector3& pos, block::Owner owner) :
    Block("block_rusty", "weapon_rusty", "engine_rusty", "trail_rusty",
        0.035f, "bullet_rusty", pos, owner) {

    m_health = 0.75f;
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

RustyBlock::~RustyBlock() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void RustyBlock::createBullet() {

    addEntity(new RustyBullet(
        bullet::Owner(m_owner), m_weaponT->translation));
}
