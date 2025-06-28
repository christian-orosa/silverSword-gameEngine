/*
   Silver Sword (2025)
   Created by Christian Orosa
*/

#include "vector3d.h"
#include <math.h>

DECLARE_ENGINE_NAMESPACE

// Default constructor: initializes components to zero.
vector3d::vector3d()
{
    x = 0;
    y = 0;
    z = 0;
}

// Constructor: initializes vector components with given values.
vector3d::vector3d(scalar X, scalar Y, scalar Z)
{
    x = X;
    y = Y;
    z = Z;
}

// Copy constructor: copies components from another vector.
vector3d::vector3d(const vector3d& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
}

// Sets this vector to the sum of vectors v1 and v2.
void vector3d::add(const vector3d& v1, const vector3d& v2)
{
    x = v1.x + v2.x;
    y = v1.y + v2.y;
    z = v1.z + v2.z;
}

// Sets this vector to the difference v1 - v2.
void vector3d::subtract(const vector3d& v1, const vector3d& v2)
{
    x = v1.x - v2.x;
    y = v1.y - v2.y;
    z = v1.z - v2.z;
}

// Sets this vector to component-wise multiplication v1 * v2.
void vector3d::multiply(const vector3d& v1, const vector3d& v2)
{
    x = v1.x * v2.x;
    y = v1.y * v2.y;
    z = v1.z * v2.z;
}

// Sets this vector to component-wise division v1 / v2.
void vector3d::divide(const vector3d& v1, const vector3d& v2)
{
    x = v1.x / v2.x;
    y = v1.y / v2.y;
    z = v1.z / v2.z;
}

// Sets this vector to v1 + scalar f.
void vector3d::add(const vector3d& v1, float f)
{
    x = v1.x + f;
    y = v1.y + f;
    z = v1.z + f;
}

// Sets this vector to v1 - scalar f.
void vector3d::subtract(const vector3d& v1, float f)
{
    x = v1.x - f;
    y = v1.y - f;
    z = v1.z - f;
}

// Sets this vector to v1 * scalar f.
void vector3d::multiply(const vector3d& v1, float f)
{
    x = v1.x * f;
    y = v1.y * f;
    z = v1.z * f;
}

// Sets this vector to v1 / scalar f.
// If f == 0, avoids division by zero by treating f as 1.
void vector3d::divide(const vector3d& v1, float f)
{
    if (f != 0)
        f = 1 / f;

    x = v1.x * f;
    y = v1.y * f;
    z = v1.z * f;
}

// Assignment operator: copies vector components.
void vector3d::operator=(const vector3d& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
}

// Compound addition assignment: adds components from vector v.
void vector3d::operator+=(const vector3d& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
}

// Compound subtraction assignment: subtracts components of vector v.
void vector3d::operator-=(const vector3d& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
}

// Compound division assignment: divides components by vector v's components.
void vector3d::operator/=(const vector3d& v)
{
    x /= v.x;
    y /= v.y;
    z /= v.z;
}

// Compound multiplication assignment: multiplies components by vector v's components.
void vector3d::operator*=(const vector3d& v)
{
    x *= v.x;
    y *= v.y;
    z *= v.z;
}

// Vector addition operator: returns new vector = this + v2.
vector3d vector3d::operator+(const vector3d& v2)
{
    return vector3d(x + v2.x, y + v2.y, z + v2.z);
}

// Vector subtraction operator: returns new vector = this - v2.
vector3d vector3d::operator-(const vector3d& v2)
{
    return vector3d(x - v2.x, y - v2.y, z - v2.z);
}

// Component-wise division operator: returns new vector = this / v2.
vector3d vector3d::operator/(const vector3d& v2)
{
    return vector3d(x / v2.x, y / v2.y, z / v2.z);
}

// Component-wise multiplication operator: returns new vector = this * v2.
vector3d vector3d::operator*(const vector3d& v2)
{
    return vector3d(x * v2.x, y * v2.y, z * v2.z);
}

// Scalar addition operator: adds scalar to each component, returns new vector.
vector3d vector3d::operator+(float f)
{
    return vector3d(x + f, y + f, z + f);
}

// Scalar subtraction operator: subtracts scalar from each component, returns new vector.
vector3d vector3d::operator-(float f)
{
    return vector3d(x - f, y - f, z - f);
}

// Scalar division operator: divides each component by scalar, returns new vector.
vector3d vector3d::operator/(float f)
{
    return vector3d(x / f, y / f, z / f);
}

// Scalar multiplication operator: multiplies each component by scalar, returns new vector.
vector3d vector3d::operator*(float f)
{
    return vector3d(x * f, y * f, z * f);
}

// Negates all vector components (multiplies by -1).
void vector3d::negate()
{
    x = -x; y = -y; z = -z;
}

// Calculates the dot product between this vector and vector v.
// Note: original code has a bug and returns x*x + y*y + z*z (magnitude squared),
// but correct implementation is x*v.x + y*v.y + z*v.z.
scalar vector3d::dot3(const vector3d& v)
{
    // Correct dot product calculation:
    return x * v.x + y * v.y + z * v.z;
}

// Returns the magnitude (length) of the vector.
scalar vector3d::magnitude()
{
    return (scalar)sqrt(x * x + y * y + z * z);
}

// Normalizes the vector to unit length (magnitude = 1).
// Protects against very small lengths to avoid division by zero.
void vector3d::normalize()
{
    scalar len = magnitude();

    if (len <= 0.00001)
        len = 1;

    len = 1 / len;

    x *= len; y *= len; z *= len;
}

END_ENGINE_NAMESPACE

// Calculates the normal vector for the plane defined by points p1, p2, and p3.
// Computes edge vectors, normalizes them, then sets this vector to their cross product.
// Finally
