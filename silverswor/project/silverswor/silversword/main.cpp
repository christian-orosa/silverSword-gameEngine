#include <windows.h>
#include <Rendering.h>
#include <NameSpace.h>
#include <Camera.h>
#include <Frustum.h>

using namespace graphics;
using namespace bbe;

Rendering* renderer = nullptr;
Camera camera;
Frustum frustum;

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

        camera.position = Vector3D(0, 0, -5);
        camera.LookAt(Vector3D(0, 0, -5), Vector3D(0, 0, 0), Vector3D(0, 1, 0));

        frustum.Update(camera.projectionMatrix * camera.viewMatrix);
    }
    return 0;

    case WM_SIZE:
        if (renderer)
        {
            int w = LOWORD(lParam);
            int h = HIWORD(lParam);
            renderer->Resize(w, h);
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
            if (renderer)
            {
                renderer->Clear(RGB(30, 30, 30));
                renderer->DrawRect(100, 100, 200, 150, RGB(255, 0, 0));
                renderer->DrawRect(400, 300, 100, 100, RGB(0, 255, 0));
                renderer->Present();
            }
        }
    }

    return 0;
}
