#include "Camera.h"
#include "math.h"

DECLARE_ENGINE_NAMESPACE

Camera::Camera()
{
    position = Vector3D(0.0f, 0.0f, 0.0f);
    target = Vector3D(0.0f, 0.0f, -1.0f);
    up = Vector3D(0.0f, 1.0f, 0.0f);

    forward = (target - position);
    forward.Normalize();

    right = forward.CrossProduct(up);
    right.Normalize();

    up = right.CrossProduct(forward); // Recalcula up ortogonal
    UpdateViewMatrix();
}

void Camera::LookAt(const Vector3D& eye, const Vector3D& center, const Vector3D& upDir)
{
    position = eye;
    target = center;
    up = upDir;

    forward = (target - position);
    forward.Normalize();

    right = forward.CrossProduct(up);
    right.Normalize();

    up = right.CrossProduct(forward); // Recalcula up ortogonal
    UpdateViewMatrix();
}

void Camera::UpdateViewMatrix()
{
    viewMatrix.CreateViewMatrix(position, forward, up, right);
}

void Camera::Perspective(float fovY, float aspect, float nearPlane, float farPlane)
{
    projectionMatrix.Zero();

    float f = 1.0f / tanf(fovY * 0.5f * (float)DEG_TO_RAD(1.0f));

    projectionMatrix.matrix[0] = f / aspect;
    projectionMatrix.matrix[5] = f;
    projectionMatrix.matrix[10] = (farPlane + nearPlane) / (nearPlane - farPlane);
    projectionMatrix.matrix[11] = -1.0f;
    projectionMatrix.matrix[14] = (2.0f * farPlane * nearPlane) / (nearPlane - farPlane);
    projectionMatrix.matrix[15] = 0.0f;
}

void Camera::Orthographic(float left, float rightVal, float bottom, float topVal, float nearPlane, float farPlane)
{
    projectionMatrix.Identity();

    projectionMatrix.matrix[0] = 2.0f / (rightVal - left);
    projectionMatrix.matrix[5] = 2.0f / (topVal - bottom);
    projectionMatrix.matrix[10] = -2.0f / (farPlane - nearPlane);

    projectionMatrix.matrix[12] = -(rightVal + left) / (rightVal - left);
    projectionMatrix.matrix[13] = -(topVal + bottom) / (topVal - bottom);
    projectionMatrix.matrix[14] = -(farPlane + nearPlane) / (farPlane - nearPlane);
}

END_ENGINE_NAMESPACE
