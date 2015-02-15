#include "Renderer.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Renderer::Renderer() :
    m_camera(NULL) {

    // initialise
    init();
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

Renderer::~Renderer() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Renderer::render() {

    // update any settings that have changed
    applySettings();

    // clear the window
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    // render the render lists
    m_renderLists->render(m_camera);

    // swap the buffers
    // TODO:?
}

void Renderer::clear() {

    m_camera = NULL;
    m_renderLists->clear();
}

void Renderer::setCamera(Camera* camera) {

    m_camera = camera;
}

void Renderer::removeCamera(Camera* camera) {

    if (m_camera == camera) {

        m_camera = NULL;
    }
}

void Renderer::addRenderable(Renderable* renderable) {

    m_renderLists->addRenderable(renderable);
}

void Renderer::removeRenderable(Renderable* renderable) {

    m_renderLists->removeRenderable(renderable);
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Renderer::applySettings() {

    if (renderSettings.check()) {

        // depth test
        renderSettings.getDepthTest() ?
            glEnable(GL_DEPTH_TEST) : glDisable(GL_DEPTH_TEST);
        // back face culling
        renderSettings.getBackFaceCulling() ?
            glEnable(GL_CULL_FACE) : glDisable(GL_CULL_FACE);

        glClearColor(
            renderSettings.getClearColour().r,
            renderSettings.getClearColour().g,
            renderSettings.getClearColour().b,
            renderSettings.getClearColour().a);
    }
}

void Renderer::init() {

    // apply the render settings
    applySettings();

    // apply non changeable settings
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glCullFace(GL_BACK);
    glClearDepth(1.0f);
    glEnable(GL_TEXTURE_2D);

    // initialise DevIL
    ilInit();

    // create the render lists
    m_renderLists = std::unique_ptr<RenderLists>(new RenderLists());
}

} // namespace omi
