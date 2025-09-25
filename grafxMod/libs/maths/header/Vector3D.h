/*
   Silver Sword (2025)
   Created by Christian Orosa
*/

#ifndef _SS_VECTORSPACE_H_
#define _SS_VECTORSPACE_H_

//#include<cmath> //uncontinued
#include "Namespace.h"
#include "Defines.h"


DECLARE_ENGINE_NAMESPACE

class Vector3D
{
public:
    // Default constructor: initializes vector components to zero.
    Vector3D();

    // Constructor with individual scalar components.
    Vector3D(scalar x, scalar y, scalar z);

    // Copy constructor.
    Vector3D(const Vector3D& v);

    // Set this vector to the sum of v1 and v2.
    void add(const Vector3D& v1, const Vector3D& v2);

    // Set this vector to the difference of v1 minus v2.
    void subtract(const Vector3D& v1, const Vector3D& v2);

    // Set this vector to the component-wise multiplication of v1 and v2.
    void multiply(const Vector3D& v1, const Vector3D& v2);

    // Set this vector to the component-wise division of v1 by v2.
    void divide(const Vector3D& v1, const Vector3D& v2);

    // Set this vector to v1 plus scalar f added to each component.
    void add(const Vector3D& v1, float f);

    // Set this vector to v1 minus scalar f subtracted from each component.
    void subtract(const Vector3D& v1, float f);

    // Set this vector to v1 multiplied by scalar f.
    void multiply(const Vector3D& v1, float f);

    // Set this vector to v1 divided by scalar f.
    void divide(const Vector3D& v1, float f);

    // Assignment operator: copies vector components.
    void operator=(const Vector3D& v);

    // Compound addition assignment: adds components of v.
    void operator+=(const Vector3D& v);

    // Compound subtraction assignment: subtracts components of v.
    void operator-=(const Vector3D& v);

    // Compound division assignment: divides by components of v.
    void operator/=(const Vector3D& v);

    // Compound multiplication assignment: multiplies by components of v.
    void operator*=(const Vector3D& v);

    // Vector addition: returns new vector result.
    Vector3D operator+(const Vector3D& v2);

    // Vector subtraction: returns new vector result.
    Vector3D operator-(const Vector3D& v2);

    // Component-wise division: returns new vector result.
    Vector3D operator/(const Vector3D& v2);

    // Component-wise multiplication: returns new vector result.
    Vector3D operator*(const Vector3D& v2);

    // Add scalar to each component, returns new vector.
    Vector3D operator+(float f);

    // Subtract scalar from each component, returns new vector.
    Vector3D operator-(float f);

    // Divide each component by scalar, returns new vector.
    Vector3D operator/(float f);

    // Multiply each component by scalar, returns new vector.
    Vector3D operator*(float f);

    // Negates each component of the vector.
    void negate();

    // Computes the dot product with vector v.
    scalar dot3(const Vector3D& v) const;

    // Returns the magnitude (length) of the vector.
    scalar magnitude();

    // Normalizes this vector to unit length.
    void normalize();

    // Computes normal vector from three points (p1, p2, p3).
    void normalize(Vector3D p1, Vector3D p2, Vector3D p3);

    // Computes the cross product of this vector and v, returning the result.
    Vector3D crossproduct(const Vector3D& v);




    // Vector components.
    scalar x, y, z;
};


class vector2d
{
public:
    // Default constructor: initializes vector components to zero.
    vector2d();

    // Constructor with individual scalar components.
    vector2d(scalar x, scalar y);

    // Copy constructor.
    vector2d(const vector2d& v);

    // Set this vector to the sum of v1 and v2.
    void add(const vector2d& v1, const vector2d& v2);

    // Set this vector to the difference of v1 minus v2.
    void subtract(const vector2d& v1, const vector2d& v2);

    // Set this vector to the component-wise multiplication of v1 and v2.
    void multiply(const vector2d& v1, const vector2d& v2);

    // Set this vector to the component-wise division of v1 by v2.
    void divide(const vector2d& v1, const vector2d& v2);

    // Set this vector to v1 plus scalar f added to each component.
    void add(const vector2d& v1, float f);

    // Set this vector to v1 minus scalar f subtracted from each component.
    void subtract(const vector2d& v1, float f);

    // Set this vector to v1 multiplied by scalar f.
    void multiply(const vector2d& v1, float f);

    // Set this vector to v1 divided by scalar f.
    void divide(const vector2d& v1, float f);

    // Assignment operator: copies vector components.
    void operator=(const vector2d& v);

    // Compound addition assignment: adds components of v.
    void operator+=(const vector2d& v);

    // Compound subtraction assignment: subtracts components of v.
    void operator-=(const vector2d& v);

    // Compound division assignment: divides by components of v.
    void operator/=(const vector2d& v);

    // Compound multiplication assignment: multiplies by components of v.
    void operator*=(const vector2d& v);

    // Vector addition: returns new vector result.
    vector2d operator+(const vector2d& v2);

    // Vector subtraction: returns new vector result.
    vector2d operator-(const vector2d& v2);

    // Component-wise division: returns new vector result.
    vector2d operator/(const vector2d& v2);

    // Component-wise multiplication: returns new vector result.
    vector2d operator*(const vector2d& v2);

    // Add scalar to each component, returns new vector.
    vector2d operator+(float f);

    // Subtract scalar from each component, returns new vector.
    vector2d operator-(float f);

    // Divide each component by scalar, returns new vector.
    vector2d operator/(float f);

    // Multiply each component by scalar, returns new vector.
    vector2d operator*(float f);

    // Negates each component of the vector.
    void negate();

    // Returns the magnitude (length) of the vector.
    scalar magnitude();

    // Normalizes this vector to unit length.
    void normalize();

    // Computes normal vector from three points (p1, p2, p3).
    void normalize(Vector3D p1, Vector3D p2, Vector3D p3);

    // Vector components.
    scalar x, y;
};

class specialMaths
{
public:


    // Rotaciones básicas
    // ROTACIONES (en grados, aplicadas a un Vector3D)
    Vector3D rotateX(const Vector3D& v, float angleDeg);
    Vector3D rotateY(const Vector3D& v, float angleDeg);
    Vector3D rotateZ(const Vector3D& v, float angleDeg);


    //TRIGONOMETRY (sin, cos, tan, asin, acos, atan, atan2, Deg2Rad)
    float degreesToRad(float degrees);
    //POWERS AND SQUAREROOTS (power, squareRoot and exponent)
    float squareRoot(float x);
    /*INTERPOLATIONS(Lerp, LerpAngle, LerpUnClamped, InverseLerp, MoveTowards,
                     MoveTowardsAngle, smoothDamp, SmoothDampAngle, smoothStep*/

                     //LIMITING AND REPEATING VALUES (Max, Min, Repeat, PingPong, Clamp, Clamp01, Ceil, Floor)

                     //LOGARITHMIC (Log, Log10)
                     //float log(float x, float y);//uncontinued
    float log(float x);
};

END_ENGINE_NAMESPACE

#endif
