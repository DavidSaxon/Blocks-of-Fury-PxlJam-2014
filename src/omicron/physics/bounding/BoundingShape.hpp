#ifndef OMICRON_PHSYICS_BOUNDING_BOUNDINGSHAPE_H_
#   define OMICRON_PHSYICS_BOUNDING_BOUNDINGSHAPE_H_

#include "lib/Utilitron/Vector.hpp"

#include "src/omicron/component/Transform.hpp"

namespace omi {

namespace bounding {

    //! the bounding shape types
    enum Type {

        CIRCLE,
        RECTANGLE
        // TODO: more types
    };
}

/******************************************************************************\
| Abstract base class that defines a shape that used determining the bounds of |
| an object.                                                                   |
\******************************************************************************/
class BoundingShape {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTORS
    //--------------------------------------------------------------------------

    BoundingShape(bounding::Type type, Transform* transform) :
        m_type     (type),
        m_transform(transform) {
    }

    BoundingShape(bounding::Type type,
            Transform* transform, const util::vec::Vector3& offset) :
        m_type     (type),
        m_transform(transform),
        m_offset   (offset) {
    }

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    virtual ~BoundingShape() {
    }

    //--------------------------------------------------------------------------
    //                               PUBLIC METHODS
    //--------------------------------------------------------------------------

    //---------------------------------GETTERS----------------------------------

    /** @return the type of this */
    bounding::Type getType() const {

        return m_type;
    }

    /** @return the transform defining the location of the bounding */
    Transform* getTransform() {

        return m_transform;
    }

    /** @return the offset of the position of the bounding shape */
    const util::vec::Vector3& getOffset() const {

        return m_offset;
    }

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the type of bounding this is
    bounding::Type m_type;
    // the transform defining the position of this bounding
    Transform* m_transform;
    // the offset of this bounding from the position of the transform
    util::vec::Vector3 m_offset;
};

} // namespace omi

#endif
