#include "EnemyHub.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

EnemyHub::EnemyHub(const util::vec::Vector3& pos) :
    Block("block_hub_enemy", "weapon_steel", "engine_steel", "trail_steel",
          0.03f, "bullet_steel", pos, block::ENEMY) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

EnemyHub::~EnemyHub() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void EnemyHub::createBullet() {

    addEntity(new SteelBullet(
        bullet::Owner(m_owner), m_weaponT->translation));
}
