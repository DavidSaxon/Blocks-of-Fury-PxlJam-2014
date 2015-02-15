#include "TitaniumBlock.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

TitaniumBlock::TitaniumBlock(const util::vec::Vector3& pos, block::Owner owner) :
    Block("block_titanium", "weapon_titanium", "engine_titanium",
        "trail_titanium", 0.015f, "bullet_titanium", pos, owner) {

        m_health = 2.0f;
}
//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

TitaniumBlock::~TitaniumBlock() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void TitaniumBlock::createBullet() {

    addEntity(new TitaniumBullet(
        bullet::Owner(m_owner), m_weaponT->translation));
}
