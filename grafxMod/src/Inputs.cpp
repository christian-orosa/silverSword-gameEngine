#include "Inputs.h"

DECLARE_ENGINE_NAMESPACE

Inputs::Inputs()
{
    for (int i = 0; i < 256; i++) keys[i] = false;
    moveSpeed = 2.5f;  // unidades por segundo
    rotSpeed = 90.0f; // grados por segundo
}

void Inputs::HandleKeyDown(WPARAM key, Camera& camera)
{
    if (key < 256)
        keys[key] = true;
}

void Inputs::HandleKeyUp(WPARAM key)
{
    if (key < 256)
        keys[key] = false;
}

void Inputs::Update(Camera& camera, float deltaTime)
{
    Vector3D forward = camera.forward;
    Vector3D right = camera.right;
    Vector3D up = camera.up;

    forward.normalize();
    right.normalize();
    up.normalize();

    // Movimiento WASD
    if (keys['W']) camera.position += forward * (moveSpeed * deltaTime);
    if (keys['S']) camera.position -= forward * (moveSpeed * deltaTime);
    if (keys['A']) camera.position -= right * (moveSpeed * deltaTime);
    if (keys['D']) camera.position += right * (moveSpeed * deltaTime);

    // Movimiento vertical (Q/E)
    if (keys['Q']) camera.position -= up * (moveSpeed * deltaTime);
    if (keys['E']) camera.position += up * (moveSpeed * deltaTime);

    // Rotación con flechas
    if (keys[VK_LEFT] || keys[VK_RIGHT]) {
        float angle = (keys[VK_LEFT] ? -rotSpeed : rotSpeed) * deltaTime;

        bbe::Matrix4x4 rotY;
        rotY.Identity();
        rotY.RotateY(angle);

        camera.forward = rotY.VectorMatrixMultiply3x3(camera.forward);
        camera.right = rotY.VectorMatrixMultiply3x3(camera.right);
    }

    if (keys[VK_UP] || keys[VK_DOWN]) {
        float angle = (keys[VK_UP] ? -rotSpeed : rotSpeed) * deltaTime;

        bbe::Matrix4x4 rotX;
        rotX.Identity();
        rotX.RotateX(angle);

        camera.forward = rotX.VectorMatrixMultiply3x3(camera.forward);
        camera.up = rotX.VectorMatrixMultiply3x3(camera.up);
    }

    // Actualizar viewMatrix
    camera.LookAt(camera.position, camera.position + camera.forward, Vector3D(0, 1, 0));
}
END_ENGINE_NAMESPACE