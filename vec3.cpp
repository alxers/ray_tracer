#include <vec3.h>

class vec3 {

    inline vec3 operator+(const vec3 &v1, const vec3 &v2) {
        return (v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
    }

    inline vec3 operator-(const vec3 &v1, const vec3 &v2) {
        return (v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
    }
};