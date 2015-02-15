#include "Animation.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTORS
//------------------------------------------------------------------------------

Animation::Animation() :
    m_frame        (0),
    m_lastFrameTime(-1),
    m_accumTime    (0),
    m_repeat       (false) {

    m_visible = true;
}

Animation::Animation(
        const t_TextureList& textures, unsigned frameRate, bool repeat)
    :
    m_textures     (textures),
    m_frameRate    (frameRate),
    m_frameLength  (1000 / frameRate),
    m_frame        (0),
    m_repeat       (repeat),
    m_ended        (false),
    m_lastFrameTime(-1),
    m_accumTime    (0) {

    m_visible = true;
}

Animation::Animation(Animation& other) :
    m_textures     (other.m_textures),
    m_frameRate    (other.m_frameRate),
    m_frameLength  (other.m_frameLength),
    m_frame        (0),
    m_repeat       (other.m_repeat),
    m_ended        (false),
    m_lastFrameTime(-1),
    m_accumTime    (0) {

    m_visible = true;
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

Animation::~Animation() {
}

//------------------------------------------------------------------------------
//                                   OPERATORS
//------------------------------------------------------------------------------

const Animation& Animation::operator=(const Animation& other) {

    m_textures      = other.m_textures;
    m_frameRate     = other.m_frameRate;
    m_frameLength   = other.m_frameLength;
    m_frame         = 0;
    m_repeat        = other.m_repeat;
    m_ended         = false;
    m_lastFrameTime = -1;
    m_accumTime     = 0;
    m_visible       = other.m_visible;
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Animation::update() {

    // don't display anything since the texture has ended
    if (m_ended) {

        m_visible = false;
        return;
    }

    // get time for the first time
    if (m_lastFrameTime < 0) {

        m_lastFrameTime = util::time::getCurrentTime();
    }

    // update the frame if one or more has passed
    util::int64 currentTime = util::time::getCurrentTime();
    if (currentTime - m_lastFrameTime >= m_frameLength) {

        // update the amount of frames we need to
        m_frame += (currentTime - m_lastFrameTime) / m_frameLength;

        // loop or end the texture
        if (m_repeat) {

            m_frame = m_frame % m_textures.size();
        }
        else if (m_frame >= m_textures.size()) {

            m_ended = true;
            m_visible = false;
            return;
        }

        // update the time of the last frame
        m_lastFrameTime = currentTime +
            ((currentTime - m_lastFrameTime) % m_frameLength);
    }

    // set the current texture
    m_id = m_textures[m_frame];
}

tex::Type Animation::getType() const {

    return tex::ANIMATION;
}

} // namsepace omi
