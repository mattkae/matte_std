// mathlib.h
// 
// Created by Matt Kosarek
// 
// A file containing some common math functionality that I find
// useful in my projects. I don't like that I don't know what's happening
// in glm, so I wrote most of this myself. All mistakes are my own.
//

#pragma once
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define ABS(x) (x < 0 ? -x : x)
#define SIGN(x) (x < 0 ? -1 : 1)
#define PI 3.141592653589793238463

struct Vector2 {
    float x = 0;
    float y = 0;

    Vector2 operator+(Vector2 other);
    Vector2& operator+=(Vector2 other);
    Vector2 operator-(Vector2 other);
    Vector2 operator*(float s);
    Vector2 operator/(float s);
    float dot(Vector2 other);
    float length();
    Vector2 normalize();
    Vector2 negate();
    Vector2 getPerp();
    Vector2 rotate(float angle);
    float determinant(Vector2 other);
    
    void printDebug(const char* name);
};

struct Vector3 {
    float x = 0.f;
    float y = 0.f;
    float z = 0.f;

    Vector3();
    Vector3(float value);
    Vector3(float x, float y, float z);

    float length();
    float dot(const Vector3& other);
    Vector3 scale(float scalar);
    Vector3 add(const Vector3& other);
    Vector3 subtract(const Vector3& other);
    Vector3 negate();
    Vector3 cross(const Vector3& other);
    Vector3 normalize();

    Vector3 operator+(const Vector3& v2);
    Vector3 operator-(const Vector3& v2);
    Vector3 operator-();
    Vector3 operator*(float value);
    Vector3 operator*(const Vector3& v2);
    float operator[](int index);
    
    void printDebug(const char* name);
};

struct Vector4 {
    float x = 0.f;
    float y = 0.f;
    float z = 0.f;
    float w = 1.f;

    Vector4();
    Vector4(float value);
    Vector4(float inX = 0.f, float inY = 0.f, float inZ = 0.f, float inW = 1.f);
    Vector4 fromColor(float r, float g, float b, float a);
	Vector4 toNormalizedColor();

    float length();
    Vector4 normalize();
    float dot(const Vector4& other);
    Vector4 scale(float scalar);
    Vector4 add(const Vector4& other);
    Vector4 subtract(const Vector4& other);
    Vector4 negate();
    Vector4 cross(const Vector4& other);

    Vector4 operator+(const Vector4& v2);
    Vector4 operator-(const Vector4& v2);
    Vector4 operator-();
    Vector4 operator*(float value);
    Vector4 operator*(const Vector4& v2);
    float operator[](int index);

    void printDebug(const char* name);
};

struct Mat4x4 {
    float m[16] = {
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };

    Mat4x4 copy();
    Mat4x4 scale(Vector3 v);
    Mat4x4 translate(Vector3 v);
	Mat4x4 translateByVec2(Vector2 v);
    Mat4x4 rotate2D(float angle);
    Mat4x4 getXRotationMatrix(float angleRadians);
    Mat4x4 getYRotationMatrix(float angleRadians);
    Mat4x4 getZRotationMatrix(float angleRadians);
    Mat4x4 rotate(float xRadians, float yRadians, float zRadians);
    Vector2 multByVec2(Vector2 v);
    Vector2 operator*(Vector2 v);
    Mat4x4 multMat4x4(const Mat4x4& other);
    Mat4x4 operator*(const Mat4x4& other);
    Mat4x4 getOrthographicMatrix(float left, float right, float bottom, float top);
    Mat4x4 inverse();
	Mat4x4 getPerspectiveProjection(float near, float far, float fieldOfViewRadians, float aspectRatio);
	void print();
};

struct Quaternion {
    float x = 0;
    float y = 0;
    float z = 0;
    float w = 0;

    float operator [](int index);
	Quaternion operator*(const Quaternion& other) const;
	Quaternion operator*(const float& scale) const;
	Quaternion operator+(const Quaternion& other) const;
	Quaternion operator-(const Quaternion& other) const;
	Quaternion interpolate(const Quaternion& other, const float factor);
	Mat4x4 toMatrix() const;
	Quaternion normalize() const;
	float length() const;
	float dot(const Quaternion& other) const;
};
