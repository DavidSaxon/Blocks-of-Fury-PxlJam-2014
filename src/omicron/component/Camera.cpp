#include "Camera.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Camera::Camera(const std::string& id,
                     cam::Mode    mode,
                     Transform*   transform)
    :
    Component  (id),
    m_mode     (mode),
    m_transform(transform),
    m_fov      (60.0f),
    m_nearClip (0.001f),
    m_farClip  (1000.0f) {
}

Camera::Camera(const std::string& id,
                      cam::Mode    mode,
                      Transform*   transform,
                      float        fov)
    :
    Component  (id),
    m_mode     (mode),
    m_transform(transform),
    m_fov      (fov),
    m_nearClip (0.001f),
    m_farClip  (1000.0f) {
}

Camera::Camera(const std::string& id,
                      cam::Mode    mode,
                      Transform*   transform,
                      float        nearClip,
                      float        farClip)
    :
    Component  (id),
    m_mode     (mode),
    m_transform(transform),
    m_fov      (60.0f),
    m_nearClip (nearClip),
    m_farClip  (farClip) {
}

Camera::Camera(const std::string& id,
                      cam::Mode    mode,
                      Transform*   transform,
                      float        fov,
                      float        nearClip,
                      float        farClip)
    :
    Component  (id),
    m_mode     (mode),
    m_transform(transform),
    m_fov      (fov),
    m_nearClip (nearClip),
    m_farClip  (farClip) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

Camera::~Camera() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

component::Type Camera::getType() const {

    return component::CAMERA;
}

void Camera::apply() {

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (m_mode == cam::PERSPECTIVE) {

        // set up the projection matrix
        gluPerspective(m_fov,
            displaySettings.getSize().x / displaySettings.getSize().y,
            m_nearClip, m_farClip);
    }
    else {

        // set up the orthographic matrix
        float aspectRatio = 
            displaySettings.getSize().x / displaySettings.getSize().y;
        glOrtho(-aspectRatio, aspectRatio, -1.0f, 1.0f, m_nearClip, m_farClip);
    }

    // set up the model view matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // scale
    util::vec::Vector3 scale(m_transform->computeScale());
    glScalef(scale.x, scale.y, scale.z);
    //rotation
    util::vec::Vector3 rotation(m_transform->computeRotation());
    glRotatef(rotation.x, 1.0f, 0.0f, 0.0f);
    glRotatef(rotation.y, 0.0f, 1.0f, 0.0f);
    glRotatef(rotation.z, 0.0f, 0.0f, 1.0f);
    // translation
    util::vec::Vector3 translation = m_transform->computeTranslation();
    glTranslatef(translation.x, translation.y, translation.z);
}

cam::Mode Camera::getMode() const {

    return m_mode;
}

Transform* Camera::getTransform() {

    return m_transform;
}

float Camera::getFOV() const {

    return m_fov;
}

float Camera::getNearClippingPlane() const {

    return m_nearClip;
}

float Camera::getFarClippingPlane() const {

    return m_farClip;
}

void Camera::setMode(cam::Mode mode) {

    m_mode = mode;
}

void Camera::setTransform(Transform* transform) {

    m_transform = transform;
}

void Camera::setFOV(float fov) {

    m_fov = fov;
}

void Camera::setNearClip(float nearClip) {

    m_nearClip = nearClip;
}

void Camera::setFarClip(float farClip) {

    m_farClip = farClip;
}

} // namespace omi