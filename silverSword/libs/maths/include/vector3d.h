/*
   Silver Sword (2025)
   Created by Christian Orosa
*/

#ifndef _SS_VECTOR3D_H_
#define _SS_VECTOR3D_H_


#include "namespace.h"
#include "defines.h"


DECLARE_ENGINE_NAMESPACE

class vector3d
{
public:
    // Default constructor: initializes vector components to zero.
    vector3d();

    // Constructor with individual scalar components.
    vector3d(scalar x, scalar y, scalar z);

    // Copy constructor.
    vector3d(const vector3d& v);

    // Set this vector to the sum of v1 and v2.
    void add(const vector3d& v1, const vector3d& v2);

    // Set this vector to the difference of v1 minus v2.
    void subtract(const vector3d& v1, const vector3d& v2);

    // Set this vector to the component-wise multiplication of v1 and v2.
    void multiply(const vector3d& v1, const vector3d& v2);

    // Set this vector to the component-wise division of v1 by v2.
    void divide(const vector3d& v1, const vector3d& v2);

    // Set this vector to v1 plus scalar f added to each component.
    void add(const vector3d& v1, float f);

    // Set this vector to v1 minus scalar f subtracted from each component.
    void subtract(const vector3d& v1, float f);

    // Set this vector to v1 multiplied by scalar f.
    void multiply(const vector3d& v1, float f);

    // Set this vector to v1 divided by scalar f.
    void divide(const vector3d& v1, float f);

    // Assignment operator: copies vector components.
    void operator=(const vector3d& v);

    // Compound addition assignment: adds components of v.
    void operator+=(const vector3d& v);

    // Compound subtraction assignment: subtracts components of v.
    void operator-=(const vector3d& v);

    // Compound division assignment: divides by components of v.
    void operator/=(const vector3d& v);

    // Compound multiplication assignment: multiplies by components of v.
    void operator*=(const vector3d& v);

    // Vector addition: returns new vector result.
    vector3d operator+(const vector3d& v2);

    // Vector subtraction: returns new vector result.
    vector3d operator-(const vector3d& v2);

    // Component-wise division: returns new vector result.
    vector3d operator/(const vector3d& v2);

    // Component-wise multiplication: returns new vector result.
    vector3d operator*(const vector3d& v2);

    // Add scalar to each component, returns new vector.
    vector3d operator+(float f);

    // Subtract scalar from each component, returns new vector.
    vector3d operator-(float f);

    // Divide each component by scalar, returns new vector.
    vector3d operator/(float f);

    // Multiply each component by scalar, returns new vector.
    vector3d operator*(float f);

    // Negates each component of the vector.
    void negate();

    // Computes the dot product with vector v.
    scalar dot3(const vector3d& v);

    // Returns the magnitude (length) of the vector.
    scalar magnitude();

    // Normalizes this vector to unit length.
    void normalize();

    // Computes normal vector from three points (p1, p2, p3).
    void normalize(vector3d p1, vector3d p2, vector3d p3);

    // Computes the cross product of this vector and v, returning the result.
    vector3d crossproduct(const vector3d& v);

    // Vector components.
    scalar x, y, z;
};

END_ENGINE_NAMESPACE

#endif
