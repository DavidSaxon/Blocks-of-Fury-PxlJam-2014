#include "GoldBlock.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

GoldBlock::GoldBlock(const util::vec::Vector3& pos, block::Owner owner) :
    Block("block_gold", "weapon_gold", "engine_gold", "trail_gold",
        0.035f, "bullet_gold", pos, owner) {

    m_health = 3.0f;
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

GoldBlock::~GoldBlock() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void GoldBlock::createBullet() {

    addEntity(new GoldBullet(
        bullet::Owner(m_owner), m_weaponT->translation, -35.0f));
    addEntity(new GoldBullet(
        bullet::Owner(m_owner), m_weaponT->translation, 0.0f));
    addEntity(new GoldBullet(
        bullet::Owner(m_owner), m_weaponT->translation, 35.0f));
}

