#include "Rendering.h"

namespace graphics {

    Rendering::Rendering(HWND hwnd, int width, int height)
        : hwnd(hwnd), width(width), height(height)
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
        HBRUSH brush = CreateSolidBrush(color);
        RECT rect = { x, y, x + w, y + h };
        FillRect(backBufferDC, &rect, brush);
        DeleteObject(brush);
    }

    graphics::Rendering::Vector4D Rendering::Mul4x4Vec4(const bbe::Matrix4x4& m, const Vector4D& v)
    {
        Vector4D out;
        out.x = v.x * m.matrix[0] + v.y * m.matrix[4] + v.z * m.matrix[8] + v.w * m.matrix[12];
        out.y = v.x * m.matrix[1] + v.y * m.matrix[5] + v.z * m.matrix[9] + v.w * m.matrix[13];
        out.z = v.x * m.matrix[2] + v.y * m.matrix[6] + v.z * m.matrix[10] + v.w * m.matrix[14];
        out.w = v.x * m.matrix[3] + v.y * m.matrix[7] + v.z * m.matrix[11] + v.w * m.matrix[15];
        return out;
    }

    void Rendering::DrawQuad3D(const bbe::Vector3D verts[4], COLORREF color, const bbe::Camera& cam)
    {
        POINT poly[4];

        for (int i = 0; i < 4; i++)
        {
            // Mundo  Vista
            Vector4D v = { verts[i].x, verts[i].y, verts[i].z, 1.0f };
            v = Mul4x4Vec4(cam.viewMatrix, v);

            // Vista  Clip
            v = Mul4x4Vec4(cam.projectionMatrix, v);

            // Perspectiva
            if (fabsf(v.w) < 1e-6f) v.w = 1e-6f;
            float ndcX = v.x / v.w;
            float ndcY = v.y / v.w;

            // NDC  Pantalla
            int sx = (int)((ndcX + 1.0f) * 0.5f * width);
            int sy = (int)((1.0f - ndcY) * 0.5f * height);

            poly[i].x = sx;
            poly[i].y = sy;
        }

        HBRUSH brush = CreateSolidBrush(color);
        HBRUSH old = (HBRUSH)SelectObject(backBufferDC, brush);
        Polygon(backBufferDC, poly, 4);
        SelectObject(backBufferDC, old);
        DeleteObject(brush);
    }



}
