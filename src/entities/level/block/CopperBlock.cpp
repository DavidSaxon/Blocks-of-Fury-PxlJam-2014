#include "CopperBlock.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

CopperBlock::CopperBlock(const util::vec::Vector3& pos, block::Owner owner) :
    Block("block_copper", "weapon_copper", "engine_copper", "trail_copper",
        0.025f, "bullet_copper", pos, owner) {

    m_health = 1.5f;
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

CopperBlock::~CopperBlock() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void CopperBlock::createBullet() {

    addEntity(new CopperBullet(
        bullet::Owner(m_owner), m_weaponT->translation, -35.0f));
    addEntity(new CopperBullet(
        bullet::Owner(m_owner), m_weaponT->translation, 35.0f));
}