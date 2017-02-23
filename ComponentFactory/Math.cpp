/*****************************************************************************/
/*!
@file   Math.cpp
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   2/23/2017
*/
/*****************************************************************************/
#include "Math.h"
#include <cmath>   /* sqrtf */
#include <iomanip> /* setw */

namespace Math
{
    Vector3::Vector3()
    {

    }

    Vector3::~Vector3()
    {

    }

    Vector3::Vector3(float x, float y, float z) : _x(x), _y(y), _z(z)
    {

    }

    Vector3::Vector3(const Vector3& rhs) : _x(rhs._x), _y(rhs._y), _z(rhs._z)
    {

    }

    Vector3 Vector3::operator+(const Vector3& rhs) const
    {
        return Vector3((_x + rhs._x), (_y + rhs._y), (_z + rhs._z));
    }

    Vector3 Vector3::operator-(const Vector3& rhs) const
    {
        return Vector3((_x - rhs._x), (_y - rhs._y), (_z - rhs._z));
    }

    Vector3 Vector3::operator*(const Vector3& rhs) const
    {
        return Vector3((_x * rhs._x), (_y * rhs._y), (_z * rhs._z));
    }

    void Vector3::operator*(const float scalar)
    {
        _x *= scalar;
        _y *= scalar;
        _z *= scalar;
    }

    Vector3& Vector3::operator+= (const Vector3& rhs)
    {
        _x += rhs._x;
        _y += rhs._y;
        _z += rhs._z;
        return *this;
    }

    Vector3& Vector3::operator-= (const Vector3& rhs)
    {
        _x -= rhs._x;
        _y -= rhs._y;
        _z -= rhs._z;
        return *this;
    }

    Vector3& Vector3::operator/= (const float value)
    {
        _x /= value;
        _y /= value;
        _z /= value;
        return *this;
    }

    float Vector3::DotProduct(const Vector3& rhs)
    {
        return ((_x * rhs._x) + (_y * rhs._y) + (_z * rhs._z));
    }

    Vector3 Vector3::CrossProduct(const Vector3& rhs)
    {
        Vector3 retVal;
        retVal._x = (_y * rhs._z) - (_z * rhs._y);
        retVal._y = (_z * rhs._x) - (_x * rhs._z);
        retVal._z = (_x * rhs._y) - (_y * rhs._x);
        return retVal;
    }

    float Vector3::Length() const
    {
        return sqrtf((_x*_x) + (_y*_y) + (_z*_z));
    }

    Vector3& Vector3::Normalize()
    {
        *this /= Length();
        return *this;
    }

    void Vector3::SetVector(float x, float y, float z)
    {
        _x = x;
        _y = y;
        _z = z;
    }

    void Vector3::SetX(float x) { _x = x; }
    void Vector3::SetY(float y) { _y = y; }
    void Vector3::SetZ(float z) { _z = z; }

    float Vector3::GetX() const { return _x; }
    float Vector3::GetY() const { return _y; }
    float Vector3::GetZ() const { return _z; }

    std::ostream& operator<<(std::ostream & os, Vector3& vec3)
    {
        os << " X: "  << std::setw(5) << vec3._x
           << " Y: "  << std::setw(5) << vec3._y
           << " Z: "  << std::setw(5) << vec3._z;
        return os;
    }
}