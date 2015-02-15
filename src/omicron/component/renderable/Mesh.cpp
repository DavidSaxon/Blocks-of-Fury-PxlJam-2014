#include "Mesh.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Mesh::Mesh(const std::string& id,
                 int          layer,
                 Transform*   transform,
                 Geometry*    geometry,
                 Material     material) :
    Renderable (id, layer, transform, material),
    m_geometry (geometry) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

Mesh::~Mesh() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Mesh::render() {

    // update the material
    m_material.update();

    // only render if the mesh is visible
    if (!visible || !m_material.isVisible()) {

        return;
    }

    glPushMatrix();

    // apply the transform to matrices
    applyTransformations();

    // set the shader
    setShader();

    //TODO: use VBOS
    // geometry
    glBegin(GL_TRIANGLES);
    for (unsigned i = 0; i < m_geometry->vertices.size(); ++i) {


        // draw normals if the geometry contains them
        if (m_geometry->normals.size() > 0) {

            glNormal3f(m_geometry->normals[i].x,
                       m_geometry->normals[i].y,
                       m_geometry->normals[i].z);
        }

        // TODO: check if texture exists too
        // draw the texture coordinates if the exists
        if (m_geometry->uv.size() > 0) {

            glTexCoord2f(m_geometry->uv[i].x, m_geometry->uv[i].y);
        }

        // render vertices
        glVertex3f(m_geometry->vertices[i].x,
                   m_geometry->vertices[i].y,
                   m_geometry->vertices[i].z);
    }
    glEnd();

    unsetShader();

    glPopMatrix();
}

} // namespace omi
