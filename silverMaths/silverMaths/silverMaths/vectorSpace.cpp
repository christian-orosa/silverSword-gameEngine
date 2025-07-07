/*
   Silver Sword (2025)
   Created by Christian Orosa
*/

#include "vectorSpace.h"
#include <math.h>

DECLARE_ENGINE_NAMESPACE

// Default constructor: initializes components to zero.
ss::vector3d::vector3d()
{
    x = 0;
    y = 0;
    z = 0;
}

// Constructor: initializes vector components with given values.
ss::vector3d::vector3d(scalar X, scalar Y, scalar Z)
{
    x = X;
    y = Y;
    z = Z;
}

// Copy constructor: copies components from another vector.
ss::vector3d::vector3d(const vector3d& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
}

// Sets this vector to the sum of vectors v1 and v2.
void ss::vector3d::add(const vector3d& v1, const vector3d& v2)
{
    x = v1.x + v2.x;
    y = v1.y + v2.y;
    z = v1.z + v2.z;
}

// Sets this vector to the difference v1 - v2.
void ss::vector3d::subtract(const vector3d& v1, const vector3d& v2)
{
    x = v1.x - v2.x;
    y = v1.y - v2.y;
    z = v1.z - v2.z;
}

// Sets this vector to component-wise multiplication v1 * v2.
void ss::vector3d::multiply(const vector3d& v1, const vector3d& v2)
{
    x = v1.x * v2.x;
    y = v1.y * v2.y;
    z = v1.z * v2.z;
}

// Sets this vector to component-wise division v1 / v2.
void ss::vector3d::divide(const vector3d& v1, const vector3d& v2)
{
    x = v1.x / v2.x;
    y = v1.y / v2.y;
    z = v1.z / v2.z;
}

// Sets this vector to v1 + scalar f.
void ss::vector3d::add(const vector3d& v1, float f)
{
    x = v1.x + f;
    y = v1.y + f;
    z = v1.z + f;
}

// Sets this vector to v1 - scalar f.
void ss::vector3d::subtract(const vector3d& v1, float f)
{
    x = v1.x - f;
    y = v1.y - f;
    z = v1.z - f;
}

// Sets this vector to v1 * scalar f.
void ss::vector3d::multiply(const vector3d& v1, float f)
{
    x = v1.x * f;
    y = v1.y * f;
    z = v1.z * f;
}

// Sets this vector to v1 / scalar f.
// If f == 0, avoids division by zero by treating f as 1.
void ss::vector3d::divide(const vector3d& v1, float f)
{
    if (f != 0)
        f = 1 / f;

    x = v1.x * f;
    y = v1.y * f;
    z = v1.z * f;
}

// Assignment operator: copies vector components.
void ss::vector3d::operator=(const vector3d& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
}

// Compound addition assignment: adds components from vector v.
void ss::vector3d::operator+=(const vector3d& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
}

// Compound subtraction assignment: subtracts components of vector v.
void ss::vector3d::operator-=(const vector3d& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
}

// Compound division assignment: divides components by vector v's components.
void ss::vector3d::operator/=(const vector3d& v)
{
    x /= v.x;
    y /= v.y;
    z /= v.z;
}

// Compound multiplication assignment: multiplies components by vector v's components.
void ss::vector3d::operator*=(const vector3d& v)
{
    x *= v.x;
    y *= v.y;
    z *= v.z;
}

// Vector addition operator: returns new vector = this + v2.
ss::vector3d ss::vector3d::operator+(const vector3d& v2)
{
    return vector3d(x + v2.x, y + v2.y, z + v2.z);
}

// Vector subtraction operator: returns new vector = this - v2.
ss::vector3d ss::vector3d::operator-(const vector3d& v2)
{
    return vector3d(x - v2.x, y - v2.y, z - v2.z);
}

// Component-wise division operator: returns new vector = this / v2.
ss::vector3d ss::vector3d::operator/(const vector3d& v2)
{
    return vector3d(x / v2.x, y / v2.y, z / v2.z);
}

// Component-wise multiplication operator: returns new vector = this * v2.
ss::vector3d ss::vector3d::operator*(const vector3d& v2)
{
    return vector3d(x * v2.x, y * v2.y, z * v2.z);
}

// Scalar addition operator: adds scalar to each component, returns new vector.
ss::vector3d ss::vector3d::operator+(float f)
{
    return vector3d(x + f, y + f, z + f);
}

// Scalar subtraction operator: subtracts scalar from each component, returns new vector.
ss::vector3d ss::vector3d::operator-(float f)
{
    return vector3d(x - f, y - f, z - f);
}

// Scalar division operator: divides each component by scalar, returns new vector.
ss::vector3d ss::vector3d::operator/(float f)
{
    return vector3d(x / f, y / f, z / f);
}

// Scalar multiplication operator: multiplies each component by scalar, returns new vector.
ss::vector3d ss::vector3d::operator*(float f)
{
    return vector3d(x * f, y * f, z * f);
}

// Negates all vector components (multiplies by -1).
void ss::vector3d::negate()
{
    x = -x; y = -y; z = -z;
}

// Calculates the dot product between this vector and vector v.
// Note: original code has a bug and returns x*x + y*y + z*z (magnitude squared),
// but correct implementation is x*v.x + y*v.y + z*v.z.
scalar ss::vector3d::dot3(const vector3d& v)
{
    // Correct dot product calculation:
    return x * v.x + y * v.y + z * v.z;
}

// Returns the magnitude (length) of the vector.
scalar ss::vector3d::magnitude()
{
    return (scalar)sqrt(x * x + y * y + z * z);
}

// Normalizes the vector to unit length (magnitude = 1).
// Protects against very small lengths to avoid division by zero.
void ss::vector3d::normalize()
{
    scalar len = magnitude();

    if (len <= 0.00001)
        len = 1;

    len = 1 / len;

    x *= len; y *= len; z *= len;
}

void ss::vector2d::normalize(vector3d p1, vector3d p2, vector3d p3)
{
}

END_ENGINE_NAMESPACE

// Calculates the normal vector for the plane defined by points p1, p2, and p3.
// Computes edge vectors, normalizes them, then sets this vector to their cross product.
// Finally

ss::vector2d::vector2d()
{
}

ss::vector2d::vector2d(scalar x, scalar y)
{
}

ss::vector2d::vector2d(const vector2d& v)
{
}

void ss::vector2d::add(const vector2d& v1, const vector2d& v2)
{
}

void ss::vector2d::subtract(const vector2d& v1, const vector2d& v2)
{
}

void ss::vector2d::multiply(const vector2d& v1, const vector2d& v2)
{
}

void ss::vector2d::divide(const vector2d& v1, const vector2d& v2)
{
}

void ss::vector2d::add(const vector2d& v1, float f)
{
}

void ss::vector2d::subtract(const vector2d& v1, float f)
{
}

void ss::vector2d::multiply(const vector2d& v1, float f)
{
}

void ss::vector2d::divide(const vector2d& v1, float f)
{
}

void ss::vector2d::operator=(const vector2d& v)
{
}

void ss::vector2d::operator+=(const vector2d& v)
{
}

void ss::vector2d::operator-=(const vector2d& v)
{
}

void ss::vector2d::operator/=(const vector2d& v)
{
}

void ss::vector2d::operator*=(const vector2d& v)
{
}

ss::vector2d ss::vector2d::operator+(const vector2d& v2)
{
    return vector2d();
}

ss::vector2d ss::vector2d::operator-(const vector2d& v2)
{
    return ss::vector2d();
}

ss::vector2d ss::vector2d::operator/(const vector2d& v2)
{
    return vector2d();
}

ss::vector2d ss::vector2d::operator*(const vector2d& v2)
{
    return vector2d();
}

/*float ss::specialMaths::log(float x, float y) //uncontinued
{
    return std::log(x) / std::log(y); 

    return 
}*/

float ss::specialMaths::degreesToRad(float degrees)
{
    return degrees * (PI_CONST / 180.0f);
}

float ss::specialMaths::squareRoot(float x)
{
    if (x < 0.0f)
    {
        return -1.0f; // error, no raíz cuadrada para negativos
    }
    if (x == 0.0f)
    {
        return 0.0f;
    }

    float guess = x;
    const float epsilon = 0.00001f; // precisión deseada

    for (int i = 0; i < 20; ++i)
    {
        float nextGuess = 0.5f * (guess + x / guess);
        if (guess - nextGuess < epsilon && guess - nextGuess > -epsilon)
        {
            break;
        }
        guess = nextGuess;
    }

    return guess;
}

float ss::specialMaths::log(float x)
{
    if (x <= 0.0f)
    {
        // error, log no definido para <= 0
        return -1e30f; // valor muy pequeño para indicar error
    }

    // Reducimos x para que esté en rango (0.5, 2)
    // Usamos la propiedad ln(a*b) = ln(a) + ln(b)
    int k = 0;
    while (x > 2.0f)
    {
        x *= 0.5f; // dividir entre 2
        k++;
    }
    while (x < 0.5f)
    {
        x *= 2.0f; // multiplicar por 2
        k--;
    }

    float z = (x - 1.0f) / (x + 1.0f);
    float z_squared = z * z;

    // calculamos la serie de Taylor (hasta 5 términos)
    float result = 0.0f;
    float term = z;
    int n = 1;

    // sumamos términos impares: z + z^3/3 + z^5/5 + ...
    for (int i = 0; i < 5; i++) {
        result += term / n;
        term *= z_squared;
        n += 2;
    }

    result *= 2.0f;

    // añadimos ln(2) * k, ya que hicimos escalado con potencias de 2
    // ln(2) ~ 0.69314718f
    const float LN2 = 0.69314718f;
    result += k * LN2;

    return result;
}
