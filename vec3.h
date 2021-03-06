#ifndef VEC3H
#define VEC3H

#include <math.h>
#include <stdlib.h>
#include <iostream>

class vec3 {
    public:
        vec3() {}
        vec3(float e0, float e1, float e2) {
            e[0] = e0;
            e[1] = e1;
            e[2] = e2;
        }

        inline float x() { return e[0]; }
        inline float y() { return e[1]; }
        inline float z() { return e[2]; }

        inline float r() { return e[0]; }
        inline float g() { return e[1]; }
        inline float b() { return e[2]; }

        // returns value of self
        inline const vec3& operator+() const { return *this; }
        inline vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
        inline float operator[](int i) const { return e[i]; }
        inline float& operator[](int i) { return e[i]; };

        inline vec3& operator+=(const vec3 &v2);
        inline vec3& operator-=(const vec3 &v2);
        inline vec3& operator*=(const vec3 &v2);
        inline vec3& operator/=(const vec3 &v2);
        inline vec3& operator*=(const float t);
        inline vec3& operator/=(const float t);

        inline float length() const { return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]); }
        inline float squared_length() const { return (e[0]*e[0] + e[1]*e[1] + e[2]*e[2]); }
        inline void make_unit_vector();

        float e[3];
};


inline vec3 operator+(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

inline vec3 operator-(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

inline vec3 operator*(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

inline vec3 operator/(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}

inline vec3 operator*(const vec3 &v, float f) {
    return vec3(v.e[0] * f, v.e[1] * f, v.e[2] * f);
}

inline vec3 operator*(float f, const vec3 &v) {
    return vec3(v.e[0] * f, v.e[1] * f, v.e[2] * f);
}

inline vec3 operator/(const vec3 &v, float f) {
    return vec3(v.e[0] / f, v.e[1] / f, v.e[2] / f);
}

inline float dot(const vec3 &v1, const vec3 &v2) {
    return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2]; 
}

inline vec3 cross(const vec3 &v1, const vec3 &v2) {
    return vec3(
                (v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1]),
                (-(v1.e[0] * v2.e[2] - v1.e[2] * v2.e[0])),
                (v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0])
    ); 
}

inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}

//

inline vec3& vec3::operator+=(const vec3 &v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];

    return *this;
}

inline vec3& vec3::operator-=(const vec3 &v) {
    e[0] -= v.e[0];
    e[1] -= v.e[1];
    e[2] -= v.e[2];

    return *this;
}

inline vec3& vec3::operator*=(const vec3 &v) {
    e[0] *= v.e[0];
    e[1] *= v.e[1];
    e[2] *= v.e[2];

    return *this;
}

inline vec3& vec3::operator/=(const vec3 &v) {
    e[0] /= v.e[0];
    e[1] /= v.e[1];
    e[2] /= v.e[2];

    return *this;
}

inline vec3& vec3::operator/=(const float f) {
    e[0] /= f;
    e[1] /= f;
    e[2] /= f;

    return *this;
}

inline vec3& vec3::operator*=(const float f) {
    e[0] *= f;
    e[1] *= f;
    e[2] *= f;

    return *this;
}

#endif