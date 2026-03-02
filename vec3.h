#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <cmath>

class vec3
{   
public:
    // e is an array which holds our vector elements
    double e[3];

    // Construtor function. If there is no argument creates a zero vector.
    vec3() : e{0,0,0} {}
    vec3(double e0, double e1, double e2) : e{e0,e1,e2} {}

    // Getter functions for the elements
    double x() const {return e[0];}
    double y() const {return e[1];}
    double z() const {return e[2];}

    // Negative of the vector.
    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

    // Vector access like an array.
    double operator[](int i) const { return e[i]; }
    double& operator[](int i) { return e[i]; }

    // Vector Addition
    vec3& operator+=(const vec3& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    // Scalar Multiplication
    vec3& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    // Scalar Divison (We use the scalar multiplication for this code.).
    vec3& operator/=(double t) {
        return *this *= 1/t;
    }

    double length() const {
        return std::sqrt(length_squared());
    }

    double length_squared() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }
};

using point3 = vec3;

// Output to a stream
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

// Vector addition
inline vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

// Vector substraction
inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

// Vector multiplication
inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

//  Scalar multiplication
inline vec3 operator*(double t, const vec3& v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

// Scalar multiplication (reversed)
inline vec3 operator*(const vec3& v, double t) {
    return t * v;
}

// Scalar division
inline vec3 operator/(const vec3& v, double t) {
    return (1/t) * v;
}

// Dot product
inline double dot(const vec3& u, const vec3& v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

// Cross product
inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

// Unit vector normalization
inline vec3 unit_vector(const vec3& v) {
    return v / v.length();
}

#endif