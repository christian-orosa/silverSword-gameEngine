#pragma once
#include <windows.h>
#include "Camera.h"
#include "Frustum.h"
#include "../include/Rendering.h"

namespace graphics {

    class Rendering
    {
    public:
        Rendering(HWND hwnd, int width, int height);
        ~Rendering();

        void Clear(COLORREF color);
        void Present();
        void Resize(int width, int height);

        // Dibujo de rectángulos 2D
        void DrawRect(int x, int y, int w, int h, COLORREF color);


        struct Vector4D 
        {
            float x, y, z, w;
        };

        static Vector4D Mul4x4Vec4(const bbe::Matrix4x4& m, const Vector4D& v);

        // Dibujo de un quad en 3D
        void DrawQuad3D(const bbe::Vector3D verts[4], COLORREF color, const bbe::Camera& cam);

    private:
        HWND hwnd;
        HDC hdc;
        HBITMAP backBuffer;
        HDC backBufferDC;
        int width, height;
    };

}
