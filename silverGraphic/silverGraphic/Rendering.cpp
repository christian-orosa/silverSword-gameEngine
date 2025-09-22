#include "Rendering.h"
#include <windows.h>

namespace graphics {

    Rendering::Rendering(HWND hwnd, int width, int height)
        : hwnd(hwnd), width(width), height(height), camera(nullptr), frustum(nullptr)
    {
        hdc = GetDC(hwnd);
        backBufferDC = CreateCompatibleDC(hdc);
        backBuffer = CreateCompatibleBitmap(hdc, width, height);
        SelectObject(backBufferDC, backBuffer);
    }

    Rendering::~Rendering()
    {
        DeleteObject(backBuffer);
        DeleteDC(backBufferDC);
        ReleaseDC(hwnd, hdc);
    }

    void Rendering::Clear(COLORREF color)
    {
        HBRUSH brush = CreateSolidBrush(color);
        RECT rect = { 0, 0, width, height };
        FillRect(backBufferDC, &rect, brush);
        DeleteObject(brush);
    }

    void Rendering::Present()
    {
        BitBlt(hdc, 0, 0, width, height, backBufferDC, 0, 0, SRCCOPY);
    }

    void Rendering::Resize(int width, int height)
    {
        this->width = width;
        this->height = height;

        DeleteObject(backBuffer);
        backBuffer = CreateCompatibleBitmap(hdc, width, height);
        SelectObject(backBufferDC, backBuffer);
    }

    void Rendering::DrawRect(int x, int y, int w, int h, COLORREF color)
    {
        // Si hay frustum, podríamos hacer un frustum culling básico aquí
        if (frustum && camera)
        {
            bbe::Vector3D rectPos((float)x, (float)y, 0.0f);
            if (!frustum->PointInFrustum(rectPos))
            {
                return; // Fuera del frustum, no dibujar
            }
        }

        HBRUSH brush = CreateSolidBrush(color);
        RECT rect = { x, y, x + w, y + h };
        FillRect(backBufferDC, &rect, brush);
        DeleteObject(brush);
    }

    void Rendering::SetCamera(bbe::Camera* cam)
    {
        camera = cam;
    }

    void Rendering::SetFrustum(bbe::Frustum* frust)
    {
        frustum = frust;
    }

}
