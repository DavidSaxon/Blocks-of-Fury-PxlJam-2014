#ifndef BOF_LEVEL_PLAYERSHIP_H_
#    define BOF_LEVEL_PLAYERSHIP_H_

#include <vector>

#include "src/omicron/entity/Entity.hpp"
#include "src/omicron/input/Input.hpp"

#include "src/entities/level/block/PlayerHub.hpp"
#include "src/entities/level/block/SteelBlock.hpp"

class PlayerShip : public omi::Entity {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    PlayerShip();

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~PlayerShip();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the transform of the camera
    omi::Transform* m_camT;
    // the transform of the ship
    omi::Transform* m_shipT;

    // the hub of the ship
    PlayerHub* m_hub;
    // the list of all blocks in the ship
    std::vector<Block*> m_blocks;

    // music
    omi::Music* m_introMusic;
    omi::Music* m_music;

    bool m_first;

    omi::Transform* m_guiT;
    omi::Sprite* m_guiSprite;
    omi::Sprite* m_coinSprite;

    float m_coinTimer;

    bool m_start;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    void processBlockGrab();

    void rebuild();

    void rebuildRec(Block* block);

    void processInput();

    void collisions();

    void movement();

    void initComponents();

    void buildShip();
};

#endif
