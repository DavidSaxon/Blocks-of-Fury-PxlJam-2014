#include "Music.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Music::Music(const std::string& id,
             const std::string& filePath,
                   float        volume,
                   bool loop) :
    Updatable(id),
    m_volume (volume),
    m_loop   (loop) {

    if (!m_music.openFromFile(filePath)) {

        // TODO: throw an exception??
        std::cout << "music failed to load" << std::endl;
    }
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

Music::~Music() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Music::update() {

    // update any settings
    if (audioSettings.isMusicDisabled()) {

        m_music.setVolume(0);
    }
    else{

        m_music.setVolume(m_volume * audioSettings.getMusicVolume() * 100);
    }
    m_music.setLoop(m_loop);
}

void Music::play() {

    // don't play if music is disabled
    if (audioSettings.isMusicDisabled()) {

        return;
    }

    // set up the music settings
    m_music.setVolume(m_volume * audioSettings.getMusicVolume() * 100);
    m_music.setLoop(m_loop);

    // play the music
    m_music.play();
}

void Music::pause() {

    m_music.pause();
}

void Music::stop() {

    m_music.stop();
}

//-----------------------------------GETTERS------------------------------------

float Music::getVolume() const {

    return m_volume;
}

bool Music::isStopped() const {

    return m_music.getStatus() == 0;
}

bool Music::isLooping() const {

    return m_loop;
}

//-----------------------------------SETTERS------------------------------------

void Music::setVolume(float volume) {

    m_volume = volume;
}

void Music::setLoop(bool loop) {

    m_loop = loop;
}

} // namespace omi