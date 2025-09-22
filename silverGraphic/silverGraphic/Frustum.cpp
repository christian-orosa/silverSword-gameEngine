#include "Frustum.h"


DECLARE_ENGINE_NAMESPACE

Frustum::Frustum()
{
    for (int i = 0; i < 6; i++)
    {
        normals[i] = Vector3D(0, 0, 0);
        distances[i] = 0.0f;
    }
}

// Se calcula a partir de la matriz view-projection
void Frustum::Update(const Matrix4x4& m)
{
    // Left plane
    normals[LeftPlane].x = m.matrix[3] + m.matrix[0];
    normals[LeftPlane].y = m.matrix[7] + m.matrix[4];
    normals[LeftPlane].z = m.matrix[11] + m.matrix[8];
    distances[LeftPlane] = m.matrix[15] + m.matrix[12];

    // Right plane
    normals[RightPlane].x = m.matrix[3] - m.matrix[0];
    normals[RightPlane].y = m.matrix[7] - m.matrix[4];
    normals[RightPlane].z = m.matrix[11] - m.matrix[8];
    distances[RightPlane] = m.matrix[15] - m.matrix[12];

    // Bottom plane
    normals[BottomPlane].x = m.matrix[3] + m.matrix[1];
    normals[BottomPlane].y = m.matrix[7] + m.matrix[5];
    normals[BottomPlane].z = m.matrix[11] + m.matrix[9];
    distances[BottomPlane] = m.matrix[15] + m.matrix[13];

    // Top plane
    normals[TopPlane].x = m.matrix[3] - m.matrix[1];
    normals[TopPlane].y = m.matrix[7] - m.matrix[5];
    normals[TopPlane].z = m.matrix[11] - m.matrix[9];
    distances[TopPlane] = m.matrix[15] - m.matrix[13];

    // Near plane
    normals[NearPlane].x = m.matrix[3] + m.matrix[2];
    normals[NearPlane].y = m.matrix[7] + m.matrix[6];
    normals[NearPlane].z = m.matrix[11] + m.matrix[10];
    distances[NearPlane] = m.matrix[15] + m.matrix[14];

    // Far plane
    normals[FarPlane].x = m.matrix[3] - m.matrix[2];
    normals[FarPlane].y = m.matrix[7] - m.matrix[6];
    normals[FarPlane].z = m.matrix[11] - m.matrix[10];
    distances[FarPlane] = m.matrix[15] - m.matrix[14];

    // Normalizar planos
    for (int i = 0; i < 6; i++)
    {
        float length = sqrtf(normals[i].x * normals[i].x +
            normals[i].y * normals[i].y +
            normals[i].z * normals[i].z);
        normals[i] = normals[i] * (1.0f / length);
        distances[i] /= length;
    }
}

bool Frustum::PointInFrustum(const Vector3D& point) const
{
    for (int i = 0; i < 6; i++)
    {
        if (normals[i].Dot3(point) + distances[i] < 0)
            return false;
    }
    return true;
}

bool Frustum::SphereInFrustum(const Vector3D& center, float radius) const
{
    for (int i = 0; i < 6; i++)
    {
        if (normals[i].Dot3(center) + distances[i] < -radius)
            return false;
    }
    return true;
}

END_ENGINE_NAMESPACE
