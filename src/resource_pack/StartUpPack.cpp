#include "Packs.hpp"

namespace pack {

void buildStartUpPack() {

    //---------------------------------SPRITES----------------------------------

    // omicron logo text bottom
    omi::ResourceManager::addTextureMaterialSprite(
        "omicron_text_bottom", resource_group::START_UP,
        "test_shader",
        "res/gfx/texture/start_up/omicron/logo_text_bottom.png", 2,
        util::vec::Vector2(2, 2),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );
    // omicron logo text top
    omi::ResourceManager::addTextureMaterialSprite(
        "omicron_text_top", resource_group::START_UP,
        "test_shader",
        "res/gfx/texture/start_up/omicron/logo_text_top.png", 3,
        util::vec::Vector2(2, 2),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );
    // omicron long lens flare
    omi::ResourceManager::addTextureMaterialSprite(
        "omicron_flare_long", resource_group::START_UP,
        "test_shader",
        "res/gfx/texture/start_up/omicron/logo_flare_long.png", 4,
        util::vec::Vector2(2, 2),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );
    // omicron centre lens flare
    omi::ResourceManager::addTextureMaterialSprite(
        "omicron_flare_centre", resource_group::START_UP,
        "test_shader",
        "res/gfx/texture/start_up/omicron/logo_flare_centre.png", 5,
        util::vec::Vector2(2, 2),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );
    // omicron glow
    omi::ResourceManager::addTextureMaterialSprite(
        "omicron_glow", resource_group::START_UP,
        "test_shader",
        "res/gfx/texture/start_up/omicron/logo_glow.png", 1,
        util::vec::Vector2(2, 2),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );
    // omicron powered by text
    omi::ResourceManager::addTextureMaterialSprite(
        "omicron_powered_by", resource_group::START_UP,
        "test_shader",
        "res/gfx/texture/start_up/omicron/logo_powered_by.png", 6,
        util::vec::Vector2(2, 2),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );

    //----------------------------------SOUNDS----------------------------------

    omi::ResourceManager::addSound(
        "omicron_intro", resource_group::START_UP,
        "res/sound/fx/start_up/omicron_intro.ogg", 1
    );
}


} // namespace pack
