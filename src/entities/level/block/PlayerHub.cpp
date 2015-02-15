#include "PlayerHub.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

PlayerHub::PlayerHub(const util::vec::Vector3& pos) :
    Block("block_hub_player", "weapon_steel", "engine_steel", "trail_steel",
          0.03f, "bullet_steel", pos, block::PLAYER) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

PlayerHub::~PlayerHub() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void PlayerHub::createBullet() {

    addEntity(new SteelBullet(
        bullet::Owner(m_owner), m_weaponT->translation));
}