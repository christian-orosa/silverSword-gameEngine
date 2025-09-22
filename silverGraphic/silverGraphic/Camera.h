#ifndef _BB_CAMERA_H_
#define _BB_CAMERA_H_

#include "Matrix.h"
#include "Vector3D.h"
#include "Defines.h"
#include "NameSpace.h"
#include "math.h"

DECLARE_ENGINE_NAMESPACE

class Camera
{
public:
    Camera();

    // Posición y orientación
    Vector3D position;
    Vector3D target;
    Vector3D up;
    Vector3D right;
    Vector3D forward;

    // Matrices
    Matrix4x4 viewMatrix;
    Matrix4x4 projectionMatrix;

    // Métodos
    void LookAt(const Vector3D& eye, const Vector3D& center, const Vector3D& upDir);
    void Perspective(float fovY, float aspect, float nearPlane, float farPlane);
    void Orthographic(float left, float right, float bottom, float top, float nearPlane, float farPlane);

private:
    void UpdateViewMatrix();
};

END_ENGINE_NAMESPACE

#endif
