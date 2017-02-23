/*****************************************************************************/
/*!
@file   Math.h
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   2/23/2017
@brief  sample math interface. Contains a Vector3 class to be used for demo
purposes with the components.
*/
/*****************************************************************************/
#ifndef MATH_H
#define MATH_H

#include <iostream>  

namespace Math
{
    class Vector3
    {
    public:
        Vector3();
        ~Vector3();

        Vector3(float x, float y, float z);
        Vector3(const Vector3& rhs);

        Vector3  operator+    (const Vector3& rhs) const;
        Vector3  operator-    (const Vector3& rhs) const;
        Vector3  operator*    (const Vector3& rhs) const;
        void     operator*    (const float scalar);
        Vector3& operator+=   (const Vector3& rhs);
        Vector3& operator-=   (const Vector3& rhs);
        Vector3& operator/=   (const float value);

        Vector3& Normalize();
        Vector3  CrossProduct (const Vector3& rhs);
        float    DotProduct   (const Vector3& rhs);
        float    Length() const;

        friend std::ostream& operator<<(std::ostream & os, Vector3& vec3);

        void SetVector(float x, float y, float z);
        void SetX(float x);
        void SetY(float y);
        void SetZ(float z);

        float GetX() const;
        float GetY() const;
        float GetZ() const;

    private:
        float _x;
        float _y;
        float _z;
    };
}
#endif