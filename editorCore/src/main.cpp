/*
   Silver Sword (2025)
   by Christian Orosa
*/

#include <windows.h>
#include "../../../libs/graphics/include/Camera.h"
#include "../../../libs/graphics/include/Frustum.h"
#include "../../../libs/graphics/include/Rendering.h"
#include "../../../libs/maths/include/NameSpace.h"
#include "../../../libs/graphics/include/Inputs.h"

using namespace graphics;
using namespace bbe;

Rendering* renderer = nullptr;
Camera camera;
Frustum frustum;
Inputs input;

LARGE_INTEGER frequency;
LARGE_INTEGER lastTime;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:
    {
        RECT rc;
        GetClientRect(hwnd, &rc);
        int w = rc.right - rc.left;
        int h = rc.bottom - rc.top;
        renderer = new Rendering(hwnd, w, h);

        // Configuración inicial de la cámara
        camera.position = Vector3D(0, 0, -5);
        camera.LookAt(Vector3D(0, 0, -5), Vector3D(0, 0, 0), Vector3D(0, 1, 0));
        camera.Perspective(60.0f, (float)w / (float)h, 0.1f, 100.0f);

        frustum.Update(camera.projectionMatrix * camera.viewMatrix);

        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&lastTime);
    }
    return 0;

    case WM_KEYDOWN:
        input.HandleKeyDown(wParam, camera);
        if (wParam == VK_ESCAPE) PostQuitMessage(0);
        return 0;

    case WM_KEYUP:
        input.HandleKeyUp(wParam);
        return 0;

    case WM_SIZE:
        if (renderer)
        {
            int w = LOWORD(lParam);
            int h = HIWORD(lParam);
            renderer->Resize(w, h);
            camera.Perspective(60.0f, (float)w / (float)h, 0.1f, 100.0f);
            frustum.Update(camera.projectionMatrix * camera.viewMatrix);
        }
        return 0;

    case WM_DESTROY:
        delete renderer;
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = TEXT("MyWindowClass");
    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        wc.lpszClassName,
        TEXT("-SILVERSWORD Engine- by: Christian Orosa"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        NULL, NULL, hInstance, NULL
    );

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (true)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT) break;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            // Delta time
            LARGE_INTEGER currentTime;
            QueryPerformanceCounter(&currentTime);
            float deltaTime = (float)(currentTime.QuadPart - lastTime.QuadPart) / (float)frequency.QuadPart;
            lastTime = currentTime;

            // Input actualiza cámara
            input.Update(camera, deltaTime);

            // Limpia pantalla
            renderer->Clear(RGB(30, 30, 30));

            // Quad 1 (cerca, Z=0)
            Vector3D quad1[4] = {
                Vector3D(-1, -1, 0),
                Vector3D(1, -1, 0),
                Vector3D(1,  1, 0),
                Vector3D(-1,  1, 0)
            };
            renderer->DrawQuad3D(quad1, RGB(255, 0, 0), camera);

            // Quad 2 (más lejos, Z=+3)
            Vector3D quad2[4] = {
                Vector3D(-2, -2, 3),
                Vector3D(2, -2, 3),
                Vector3D(2,  2, 3),
                Vector3D(-2,  2, 3)
            };
            renderer->DrawQuad3D(quad2, RGB(0, 255, 0), camera);

            // Presenta en pantalla
            renderer->Present();
        }
    }

    return 0;
}
