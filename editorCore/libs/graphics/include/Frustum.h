#ifndef _BB_FRUSTUM_H_
#define _BB_FRUSTUM_H_

#include "Camera.h"


DECLARE_ENGINE_NAMESPACE

class Frustum
{
public:
    enum Planes
    {
        NearPlane = 0,
        FarPlane,
        LeftPlane,
        RightPlane,
        TopPlane,
        BottomPlane
    };

    Frustum();
    void Update(const Matrix4x4& viewProjMatrix); // Actualiza los planos a partir de la matriz view-projection

    bool PointInFrustum(const Vector3D& point) const;
    bool SphereInFrustum(const Vector3D& center, float radius) const;

private:
    Vector3D normals[6]; // Normales de los planos
    float distances[6];  // Distancia de cada plano
};

END_ENGINE_NAMESPACE

#endif
