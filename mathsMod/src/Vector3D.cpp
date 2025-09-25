/*
   Silver Sword (2025)
   Created by Christian Orosa
*/

#include "Vector3D.h"
#include <math.h>

DECLARE_ENGINE_NAMESPACE

// Default constructor: initializes components to zero.
Vector3D::Vector3D()
{
    x = 0;
    y = 0;
    z = 0;
}

// Constructor: initializes vector components with given values.
Vector3D::Vector3D(scalar X, scalar Y, scalar Z)
{
    x = X;
    y = Y;
    z = Z;
}

// Copy constructor: copies components from another vector.
Vector3D::Vector3D(const Vector3D& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
}

// Sets this vector to the sum of vectors v1 and v2.
void Vector3D::add(const Vector3D& v1, const Vector3D& v2)
{
    x = v1.x + v2.x;
    y = v1.y + v2.y;
    z = v1.z + v2.z;
}

// Sets this vector to the difference v1 - v2.
void Vector3D::subtract(const Vector3D& v1, const Vector3D& v2)
{
    x = v1.x - v2.x;
    y = v1.y - v2.y;
    z = v1.z - v2.z;
}

// Sets this vector to component-wise multiplication v1 * v2.
void Vector3D::multiply(const Vector3D& v1, const Vector3D& v2)
{
    x = v1.x * v2.x;
    y = v1.y * v2.y;
    z = v1.z * v2.z;
}

// Sets this vector to component-wise division v1 / v2.
void Vector3D::divide(const Vector3D& v1, const Vector3D& v2)
{
    x = v1.x / v2.x;
    y = v1.y / v2.y;
    z = v1.z / v2.z;
}

// Sets this vector to v1 + scalar f.
void Vector3D::add(const Vector3D& v1, float f)
{
    x = v1.x + f;
    y = v1.y + f;
    z = v1.z + f;
}

// Sets this vector to v1 - scalar f.
void Vector3D::subtract(const Vector3D& v1, float f)
{
    x = v1.x - f;
    y = v1.y - f;
    z = v1.z - f;
}

// Sets this vector to v1 * scalar f.
void Vector3D::multiply(const Vector3D& v1, float f)
{
    x = v1.x * f;
    y = v1.y * f;
    z = v1.z * f;
}

// Sets this vector to v1 / scalar f.
// If f == 0, avoids division by zero by treating f as 1.
void Vector3D::divide(const Vector3D& v1, float f)
{
    if (f != 0)
        f = 1 / f;

    x = v1.x * f;
    y = v1.y * f;
    z = v1.z * f;
}

// Assignment operator: copies vector components.
void Vector3D::operator=(const Vector3D& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
}

// Compound addition assignment: adds components from vector v.
void Vector3D::operator+=(const Vector3D& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
}

// Compound subtraction assignment: subtracts components of vector v.
void Vector3D::operator-=(const Vector3D& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
}

// Compound division assignment: divides components by vector v's components.
void Vector3D::operator/=(const Vector3D& v)
{
    x /= v.x;
    y /= v.y;
    z /= v.z;
}

// Compound multiplication assignment: multiplies components by vector v's components.
void Vector3D::operator*=(const Vector3D& v)
{
    x *= v.x;
    y *= v.y;
    z *= v.z;
}

// Vector addition operator: returns new vector = this + v2.
Vector3D Vector3D::operator+(const Vector3D& v2)
{
    return Vector3D(x + v2.x, y + v2.y, z + v2.z);
}

// Vector subtraction operator: returns new vector = this - v2.
Vector3D Vector3D::operator-(const Vector3D& v2)
{
    return Vector3D(x - v2.x, y - v2.y, z - v2.z);
}

// Component-wise division operator: returns new vector = this / v2.
Vector3D Vector3D::operator/(const Vector3D& v2)
{
    return Vector3D(x / v2.x, y / v2.y, z / v2.z);
}

// Component-wise multiplication operator: returns new vector = this * v2.
Vector3D Vector3D::operator*(const Vector3D& v2)
{
    return Vector3D(x * v2.x, y * v2.y, z * v2.z);
}

// Scalar addition operator: adds scalar to each component, returns new vector.
Vector3D Vector3D::operator+(float f)
{
    return Vector3D(x + f, y + f, z + f);
}

// Scalar subtraction operator: subtracts scalar from each component, returns new vector.
Vector3D Vector3D::operator-(float f)
{
    return Vector3D(x - f, y - f, z - f);
}

// Scalar division operator: divides each component by scalar, returns new vector.
Vector3D Vector3D::operator/(float f)
{
    return Vector3D(x / f, y / f, z / f);
}

// Scalar multiplication operator: multiplies each component by scalar, returns new vector.
Vector3D Vector3D::operator*(float f)
{
    return Vector3D(x * f, y * f, z * f);
}

// Negates all vector components (multiplies by -1).
void Vector3D::negate()
{
    x = -x; y = -y; z = -z;
}

// Calculates the dot product between this vector and vector v.
// Note: original code has a bug and returns x*x + y*y + z*z (magnitude squared),
// but correct implementation is x*v.x + y*v.y + z*v.z.
scalar Vector3D::dot3(const Vector3D& v) const
{
    // Correct dot product calculation:
    return x * v.x + y * v.y + z * v.z;
}

// Returns the magnitude (length) of the vector.
scalar Vector3D::magnitude()
{
    return (scalar)sqrt(x * x + y * y + z * z);
}

// Normalizes the vector to unit length (magnitude = 1).
// Protects against very small lengths to avoid division by zero.
void Vector3D::normalize()
{
    scalar len = magnitude();

    if (len <= 0.00001)
        len = 1;

    len = 1 / len;

    x *= len; y *= len; z *= len;
}

void vector2d::normalize(Vector3D p1, Vector3D p2, Vector3D p3)
{
}

Vector3D Vector3D::crossproduct(const Vector3D& v)
{
    return Vector3D();
}



// Calculates the normal vector for the plane defined by points p1, p2, and p3.
// Computes edge vectors, normalizes them, then sets this vector to their cross product.
// Finally

vector2d::vector2d()
{
    x = 0;
    y = 0;
}

vector2d::vector2d(scalar x, scalar y)
{
}

vector2d::vector2d(const vector2d& v)
{
}

void vector2d::add(const vector2d& v1, const vector2d& v2)
{
}

void vector2d::subtract(const vector2d& v1, const vector2d& v2)
{
}

void vector2d::multiply(const vector2d& v1, const vector2d& v2)
{
}

void vector2d::divide(const vector2d& v1, const vector2d& v2)
{
}

void vector2d::add(const vector2d& v1, float f)
{
}

void vector2d::subtract(const vector2d& v1, float f)
{
}

void vector2d::multiply(const vector2d& v1, float f)
{
}

void vector2d::divide(const vector2d& v1, float f)
{
}

void vector2d::operator=(const vector2d& v)
{
}

void vector2d::operator+=(const vector2d& v)
{
}

void vector2d::operator-=(const vector2d& v)
{
}

void vector2d::operator/=(const vector2d& v)
{
}

void vector2d::operator*=(const vector2d& v)
{
}

vector2d vector2d::operator+(const vector2d& v2)
{
    return vector2d();
}

vector2d vector2d::operator-(const vector2d& v2)
{
    return vector2d();
}

vector2d vector2d::operator/(const vector2d& v2)
{
    return vector2d();
}

vector2d vector2d::operator*(const vector2d& v2)
{
    return vector2d();
}

/*float specialMaths::log(float x, float y) //uncontinued
{
    return std::log(x) / std::log(y);

    return
}*/




Vector3D specialMaths::rotateX(const Vector3D& v, float angleDeg)
{
    float rad = degreesToRad(angleDeg);
    float cosa = cosf(rad);
    float sina = sinf(rad);

    return Vector3D(
        v.x,
        v.y * cosa - v.z * sina,
        v.y * sina + v.z * cosa
    );
}

Vector3D specialMaths::rotateY(const Vector3D& v, float angleDeg)
{
    float rad = degreesToRad(angleDeg);
    float cosa = cosf(rad);
    float sina = sinf(rad);

    return Vector3D(
        v.x * cosa + v.z * sina,
        v.y,
        -v.x * sina + v.z * cosa
    );
}

Vector3D specialMaths::rotateZ(const Vector3D& v, float angleDeg)
{
    float rad = degreesToRad(angleDeg);
    float cosa = cosf(rad);
    float sina = sinf(rad);

    return Vector3D(
        v.x * cosa - v.y * sina,
        v.x * sina + v.y * cosa,
        v.z
    );
}


float specialMaths::degreesToRad(float degrees)
{
    return degrees * (PI_CONST / 180.0f);
}

float specialMaths::squareRoot(float x)
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

float specialMaths::log(float x)
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
END_ENGINE_NAMESPACE