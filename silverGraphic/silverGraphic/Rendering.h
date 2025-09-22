#pragma once
#include <windows.h>
#include "Camera.h"
#include "Frustum.h"
#include "Vector3D.h"

namespace graphics {

    class Rendering
    {
    public:
        Rendering(HWND hwnd, int width, int height);
        ~Rendering();

        void Clear(COLORREF color);
        void Present();

        void Resize(int width, int height);

        // Dibujo de rectángulos (como antes)
        void DrawRect(int x, int y, int w, int h, COLORREF color);

        // Vincular cámara y frustum
        void SetCamera(bbe::Camera* cam);
        void SetFrustum(bbe::Frustum* frust);

    private:
        HWND hwnd;
        HDC hdc;
        HBITMAP backBuffer;
        HDC backBufferDC;
        int width, height;

        bbe::Camera* camera;
        bbe::Frustum* frustum;
    };

}
