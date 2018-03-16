#include "vec3.h"


inline vec3 vec3::operator+(const vec3 &v) {
    return vec3(v.e[0] + e[0], v.e[1] + e[1], v.e[2] + e[2]);
}

inline vec3 vec3::operator-(const vec3 &v) {
    return vec3(v.e[0] - e[0], v.e[1] - e[1], v.e[2] - e[2]);
}

inline vec3 vec3::operator*(const vec3 &v) {
    return vec3(v.e[0] * e[0], v.e[1] * e[1], v.e[2] * e[2]);
}

inline vec3 vec3::operator/(const vec3 &v) {
    return vec3(v.e[0] / e[0], v.e[1] / e[1], v.e[2] / e[2]);
}

inline vec3 vec3::operator*(const float &f) {
    return vec3(e[0] * f, e[1] * f, e[2] * f);
}

inline vec3 vec3::operator/(const float &f) {
    return vec3(e[0] / f, e[1] / f, e[2] / f);
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
