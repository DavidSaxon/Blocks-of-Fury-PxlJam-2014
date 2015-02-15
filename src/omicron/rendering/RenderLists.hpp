#ifndef OMICRON_ENTITY_RENDERING_RENDERLISTS_H_
#   define OMICRON_ENTITY_RENDERING_RENDERLISTS_H_

#include <algorithm>
#include <map>
#include <vector>

#include "lib/Utilitron/MacroUtil.hpp"

#include "src/omicron/component/Camera.hpp"
#include "src/omicron/component/renderable/Renderable.hpp"

namespace omi {

//-----------------------------------TYPEDEF------------------------------------

typedef std::map<int, std::vector<Renderable*>> t_RenderableMap;

/**********************************\
| Object for transparency sorting. |
\**********************************/
struct RenderableDepthSorter {

    // the camera to sort depth with
    Camera* camera;

    /** The sorting function */
    bool operator ()(Renderable* a, Renderable* b) {

        // compared based on their distances from the camera
        float distanceA = util::vec::distance(
            a->getTransform()->translation,
            camera->getTransform()->translation
        );

        float distanceB = util::vec::distance(
            b->getTransform()->translation,
            camera->getTransform()->translation
        );

        return distanceA < distanceB;
    }
};

/*************************************************************************\
| A set of lists that contain all objects to be rendered by the renderer. |
\*************************************************************************/
class RenderLists {
private:

    //--------------------------------------------------------------------------
    //                                RESTRICTIONS
    //--------------------------------------------------------------------------

    DISALLOW_COPY_AND_ASSIGN(RenderLists);

public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates a new set of render lists */
    RenderLists();

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~RenderLists();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Renders all of the renderable components contained within the render
    lists
    @param the camera to use for rendering */
    void render(Camera* camera);

    /** Removes all components from the render lists */
    void clear();

    /** Adds a renderable component to the render lists
    @param renderable the renderable to add */
    void addRenderable(Renderable* renderable);

    /** Removes a renderable from the render lists
    @param renderable the renderable to remove */
    void removeRenderable(Renderable* renderable);

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // all renderable components grouped by layer
    t_RenderableMap m_renderables;

    // the depth sorter
    RenderableDepthSorter depthSorter;
};

} // namespace omi

#endif
