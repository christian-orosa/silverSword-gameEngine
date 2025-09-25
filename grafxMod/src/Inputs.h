#pragma once
#include <windows.h>
#include "Camera.h"
#include "Vector3D.h"
#include "NameSpace.h"



DECLARE_ENGINE_NAMESPACE

class Inputs
{
public:
    Inputs();

    void HandleKeyDown(WPARAM key, Camera& camera);
    void HandleKeyUp(WPARAM key);

    void Update(Camera& camera, float deltaTime);

private:
    bool keys[256]; // estado de teclas
    float moveSpeed;
    float rotSpeed;
};

END_ENGINE_NAMESPACE
