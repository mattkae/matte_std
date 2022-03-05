// mathlib.cpp
//
// Created by Matt Kosarek
// 
// A file containing some common math functionality that I find
// useful in my projects. I don't like that I don't know what's happening
// in glm, so I wrote most of this myself. All mistakes are my own.
//

#include "mathlib.h"
#include <cstdlib>

// ***************************************
// Vector2
Vector2::Vector2() { }

Vector2::Vector2(float inX, float inY) {
    x = inX;
    y = inY;
}

Vector2 getRandomNormalVector2() {
    Vector2 retval = {
		static_cast<float>(rand()) / static_cast<float>(RAND_MAX),
		static_cast<float>(rand()) / static_cast<float>(RAND_MAX) 
	};

	return retval.normalize();
}

Vector2 Vector2::operator+(Vector2 other) {
    return { x + other.x, y + other.y };
}

Vector2& Vector2::operator+=(Vector2 other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector2 Vector2::operator-(Vector2 other) {
    return { x - other.x, y - other.y };
}

Vector2 Vector2::operator*(float s) {
    return { x * s, y * s };
}

Vector2 Vector2::operator/(float s) {
    return { x / s, y / s };
}

float Vector2::dot(Vector2 other) {
    return x * other.x + y * other.y;
}

float Vector2::length() {
    return sqrtf(x * x + y * y);
}

Vector2 Vector2::normalize() {
    float len = length();
    float inverseLength = len == 0 ? 1.0 : 1.0 / len;

    return { x * inverseLength, y * inverseLength };
}

Vector2 Vector2::negate() {
    return { -x, -y };
}

Vector2 Vector2::getPerp() {
    return { y, -x };
}

Vector2 Vector2::rotate(float angle) {
    return {
        x * cosf(angle) - y * sinf(angle),
        x * sinf(angle) + y * cosf(angle)
    };
}

Vector2 Vector2::rotateAround(float angle, const Vector2& other) {
    Vector2 point = { x - other.x, y - other.y };
    point = {
        point.x * cosf(angle) - point.y * sinf(angle),
        point.x * sinf(angle) + point.y * cosf(angle)
    };
    point = point + other;
    return point;
}

void Vector2::printDebug(const char* name) {
    printf("%s=Vector2(%f, %f)\n", name, x, y);
}


// ***************************************
// Vector3
Vector3::Vector3() { };

Vector3::Vector3(float value) {
    x = value;
    y = value;
    z = value;
}

Vector3::Vector3(float inX, float inY, float inZ) {
    x = inX;
    y = inY;
    z = inZ;
}

float Vector3::length() {
    return sqrtf(x * x + y * y + z * z);
}

float Vector3::dot(const Vector3& other) {
	return x * other.x + y * other.y + z * other.z;
}

Vector3 Vector3::scale(float scalar) {
	return {
		x * scalar,
		y * scalar,
		z * scalar
	};
}

Vector3 Vector3::add(const Vector3& other) {
	return {
	    x + other.x,
		y + other.y,
		z + other.z
	};
}

Vector3 Vector3::subtract(const Vector3& other) {
	return {
		x - other.x,
		y - other.y,
		z - other.z
	};
}

Vector3 Vector3::negate() {
	return {
		-x,
		-y,
		-z
	};
}

Vector3 Vector3::cross(const Vector3& other) {
	return {
		y * other.z - z * other.y,
		z * other.x - x * other.z,
		x * other.y - y * other.x
	};
}

Vector3 Vector3::normalize() {
    float len = 1.f / length();
	return {
		x * len,
		y * len,
		z * len
	};
}

Vector3 Vector3::operator+(const Vector3& v2) {
	return add(v2);
}

Vector3& Vector3::operator+=(Vector3 other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vector3 Vector3::operator-(const Vector3& v2) {
	return subtract(v2);
}

Vector3 Vector3::operator-() {
	return negate();
}

Vector3 Vector3::operator*(float value) {
	return scale(value);
}

Vector3 Vector3::operator/(const Vector3& v2) {
    return {
        x / v2.x,
        y / v2.y,
        z / v2.z        
    };
}

Vector3 Vector3::operator*(const Vector3& v2) {
	return {
	    x * v2.x,
	    y * v2.y,
	    z * v2.z
	};
}

float Vector3::operator [](int index) {
	switch (index) {
	case 0:
		return x;
	case 1:
		return y;
	case 2:
		return z;
	default:
		return 0;
	}
}

void Vector2::operator=(const Vector4& other) {
	x = other.x;
	y = other.y;
}

void Vector3::printDebug(const char* name) {
    printf("%s=Vector3(%f, %f, %f)\n", name, x, y, z);
}


// ***************************************
// Vector4
Vector4::Vector4() { }

Vector4::Vector4(float value) {
    x = value;
    y = value;
    z = value;
    w = value;
}

Vector4::Vector4(float inX, float inY, float inZ, float inW) {
    x = inX;
    y = inY;
    z = inZ;
    w = inW;
}

Vector4::Vector4(Vector2& v) {
	x = v.x;
	y = v.y;
	z = 0;
	w = 1;
}

Vector4::Vector4(Vector3& v) {
	x = v.x;
	y = v.y;
	z = v.z;
	w = 1;
}

Vector4 Vector4::fromColor(float r, float g, float b, float a) {
    float scale = 1.f / 255.f;
    return { r * scale, g * scale, b * scale, a * scale };
}

Vector4 Vector4::toNormalizedColor() {
    return fromColor(x, y, z, w);
}

float Vector4::length() {
    return sqrtf(x * x + y * y + z * z + w * w);
}

Vector4 Vector4::normalize() {
    float len = length();
    float inverseLength = len == 0 ? 1.0 : 1.0 / len;

    return { x * inverseLength, y * inverseLength, z * inverseLength, w * inverseLength };
}

float Vector4::dot(const Vector4& other) {
    return x * other.x + y * other.y + z * other.z + w * other.w;
}

Vector4 Vector4::scale(float scalar) {
    return {
	    x * scalar,
	    y * scalar,
	    z * scalar,
	    w * scalar
	};
}

Vector4 Vector4::add(const Vector4& other) {
    return {
	    x + other.x,
		y + other.y,
		z + other.z,
		w + other.w
	};
}

Vector4 Vector4::subtract(const Vector4& other) {
    return {
	    x - other.x,
		y - other.y,
		z - other.z,
		w - other.w
	};
}

Vector4 Vector4::negate() {
    return { -x, -y, -z, -w };
}

Vector4 Vector4::cross(const Vector4& other) {
    return {
	    y * other.z - z * other.y,
		z * other.x - x * other.z,
		x * other.y - y * other.x,
		1.f
	};
}

Vector4 lerp(Vector4 start, Vector4 end, float t) {
    return (end - start) * t + start;
}

void Vector4::operator=(const Vector2& v2) {
	x = v2.x;
	y = v2.y;
	z = 0;
	w = 1;
}

void Vector4::operator=(const Vector3& v2) {
	x = v2.x;
	y = v2.y;
	z = v2.z;
	w = 1;	
}

Vector4 Vector4::operator+(const Vector4& v2) {
    return add(v2);
}

Vector4 Vector4::operator-(const Vector4& v2) {
    return subtract(v2);
}

Vector4 Vector4::operator-() {
    return negate();
}

Vector4 Vector4::operator*(float value) {
    return scale(value);
}

Vector4 Vector4::operator*(const Vector4& v2) {
    return {
	    x * v2.x,
	    y * v2.y,
	    z * v2.z,
	    w * v2.w
	};
}

float Vector4::operator[](int index) {
    switch (index) {
	case 0:
		return x;
	case 1:
		return y;
	case 2:
		return z;
    case 3:
        return w;
	default:
		return 0;
	}
}

void Vector4::printDebug(const char* name) {
    printf("%s=Vector4(%f, %f, %f, %f)\n", name, x, y, z, w);
}


// ***************************************
// Mat4x4
Mat4x4 Mat4x4::copy() {
    Mat4x4 result;
    memcpy(result.m, m, sizeof(float) * 16);
    return result;
}

Mat4x4 Mat4x4::scale(Vector3 v) {
    Mat4x4 result = copy();
    result.m[0] = result.m[0] * v.x;
    result.m[5] = result.m[5] *v.y;
    result.m[10] = result.m[10] * v.z;
    return result;
}

Mat4x4 Mat4x4::translate(Vector3 v) {
    Mat4x4 result = copy();
    result.m[12] += v.x;
    result.m[13] += v.y;
    result.m[14] += v.z;
    return result;
}

Mat4x4 Mat4x4::translateByVec2(Vector2 v) {
    Mat4x4 result = copy();
    result.m[12] += v.x;
    result.m[13] += v.y;
    return result;
}

Mat4x4 Mat4x4::rotate2D(float angle) {
    Mat4x4 result = copy();
    result.m[0] = cos(angle);
    result.m[1] = -sin(angle);
    result.m[4] = sin(angle);
    result.m[5] = cos(angle);
    return result;
}

Mat4x4 Mat4x4::getXRotationMatrix(float angleRadians) {
    return {
        { 1, 0, 0, 0,
          0, cos(angleRadians), -sin(angleRadians), 0,
          0, sin(angleRadians), cos(angleRadians), 0,
          0, 0, 0, 1 }
    };
}

Mat4x4 Mat4x4::getYRotationMatrix(float angleRadians) {
    return {
        { cos(angleRadians), 0, sin(angleRadians), 0,
          0, 1, 0, 0,
          -sin(angleRadians), 0, cos(angleRadians), 0,
          0, 0, 0, 1 }
    };
}

Mat4x4 Mat4x4::getZRotationMatrix(float angleRadians) {
    return {
        { cos(angleRadians), -sin(angleRadians), 0, 0,
          sin(angleRadians), cos(angleRadians), 0, 0,
          0, 0, 1, 0,
          0, 0, 0, 1 }
    };
}

Mat4x4 Mat4x4::rotate(float xRadians, float yRadians, float zRadians) {
    Mat4x4 result = copy();
        
    Mat4x4 rotationMatrix;
    if (xRadians != 0) {
        rotationMatrix = getXRotationMatrix(xRadians);
        result = result * rotationMatrix;
    }

    if (yRadians != 0) {
        rotationMatrix = getYRotationMatrix(yRadians);
        result = result * rotationMatrix;
    }

    if (zRadians != 0) {
        rotationMatrix = getZRotationMatrix(zRadians);
        result = result * rotationMatrix;
    }

    return result;
}

Vector2 Mat4x4::multByVec2(Vector2 v) {
    Vector4 vec4 = { v.x, v.y, 0.0, 1.0 };
    return {
        vec4.x * m[0] + vec4.y * m[4] + vec4.z * m[8] + vec4.w * m[12],
        vec4.x * m[1] + vec4.y * m[5] + vec4.z * m[9] + vec4.w * m[13]
    };
}

Vector2 Mat4x4::operator*(Vector2 v) {
    return multByVec2(v);
}

Mat4x4 Mat4x4::multMat4x4(const Mat4x4& other) {
    Mat4x4 result;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            int row = i * 4;
            result.m[row + j] = m[row + 0] * other.m[0 + j] + m[row + 1] * other.m[4 + j] + m[row + 2] * other.m[8 + j] + m[row + 3] * other.m[12 + j];
        }
    }

    return result;
}

Mat4x4 Mat4x4::operator*(const Mat4x4& other) {
    return multMat4x4(other);
}

Mat4x4 Mat4x4::getOrthographicMatrix(float left, float right, float bottom, float top) {
    Mat4x4 result;
    result.m[0] = 2.0 / (right - left);
    result.m[5] = 2.0 / (top - bottom);
    result.m[10] = 1.0;
    result.m[12] = -(right + left) / (right - left);
    result.m[13] = -(top + bottom) / (top - bottom);
    return result;
}

Mat4x4 Mat4x4::inverse() {
    Mat4x4 inv;

    inv.m[0] = m[5] * m[10] * m[15] - m[5] * m[11] * m[14] - m[9] * m[6] * m[15] + m[9] * m[7] * m[14] + m[13] * m[6] * m[11] - m[13] * m[7] * m[10];
    inv.m[4] = -m[4] * m[10] * m[15] + m[4] * m[11] * m[14] + m[8] * m[6] * m[15] - m[8] * m[7] * m[14] - m[12] * m[6] * m[11] + m[12] * m[7] * m[10];
    inv.m[8] = m[4] * m[9] * m[15] - m[4] * m[11] * m[13] - m[8] * m[5] * m[15] + m[8] * m[7] * m[13] + m[12] * m[5] * m[11] - m[12] * m[7] * m[9];
    inv.m[12] = -m[4] * m[9] * m[14] + m[4] * m[10] * m[13] + m[8] * m[5] * m[14] - m[8] * m[6] * m[13] - m[12] * m[5] * m[10] + m[12] * m[6] * m[9];
    inv.m[1] = -m[1] * m[10] * m[15] + m[1] * m[11] * m[14] + m[9] * m[2] * m[15] - m[9] * m[3] * m[14] - m[13] * m[2] * m[11] + m[13] * m[3] * m[10];
    inv.m[5] = m[0] * m[10] * m[15] - m[0] * m[11] * m[14] - m[8] * m[2] * m[15] + m[8] * m[3] * m[14] + m[12] * m[2] * m[11] - m[12] * m[3] * m[10];
    inv.m[9] = -m[0] * m[9] * m[15] + m[0] * m[11] * m[13] + m[8] * m[1] * m[15] - m[8] * m[3] * m[13] - m[12] * m[1] * m[11] + m[12] * m[3] * m[9];
    inv.m[13] = m[0] * m[9] * m[14] - m[0] * m[10] * m[13] - m[8] * m[1] * m[14] + m[8] * m[2] * m[13] + m[12] * m[1] * m[10] - m[12] * m[2] * m[9];
    inv.m[2] = m[1] * m[6] * m[15] - m[1] * m[7] * m[14] - m[5] * m[2] * m[15] + m[5] * m[3] * m[14] + m[13] * m[2] * m[7] - m[13] * m[3] * m[6];
    inv.m[6] = -m[0] * m[6] * m[15] + m[0] * m[7] * m[14] + m[4] * m[2] * m[15] - m[4] * m[3] * m[14] - m[12] * m[2] * m[7] + m[12] * m[3] * m[6];
    inv.m[10] = m[0] * m[5] * m[15] - m[0] * m[7] * m[13] - m[4] * m[1] * m[15] + m[4] * m[3] * m[13] + m[12] * m[1] * m[7] - m[12] * m[3] * m[5];
    inv.m[14] = -m[0] * m[5] * m[14] + m[0] * m[6] * m[13] + m[4] * m[1] * m[14] - m[4] * m[2] * m[13] - m[12] * m[1] * m[6] + m[12] * m[2] * m[5];
    inv.m[3] = -m[1] * m[6] * m[11] + m[1] * m[7] * m[10] + m[5] * m[2] * m[11] - m[5] * m[3] * m[10] - m[9] * m[2] * m[7] + m[9] * m[3] * m[6];
    inv.m[7] = m[0] * m[6] * m[11] - m[0] * m[7] * m[10] - m[4] * m[2] * m[11] + m[4] * m[3] * m[10] + m[8] * m[2] * m[7] - m[8] * m[3] * m[6];
    inv.m[11] = -m[0] * m[5] * m[11] + m[0] * m[7] * m[9] + m[4] * m[1] * m[11] - m[4] * m[3] * m[9] - m[8] * m[1] * m[7] + m[8] * m[3] * m[5];
    inv.m[15] = m[0] * m[5] * m[10] - m[0] * m[6] * m[9] - m[4] * m[1] * m[10] + m[4] * m[2] * m[9] + m[8] * m[1] * m[6] - m[8] * m[2] * m[5];

    float det = m[0] * inv.m[0] + m[1] * inv.m[4] + m[2] * inv.m[8] + m[3] * inv.m[12];

    if (det == 0)
        return Mat4x4();

    det = 1.f / det;

    for (int i = 0; i < 16; i++)
        inv.m[i] = inv.m[i] * det;

    return inv;
}

Mat4x4 Mat4x4::getPerspectiveProjection(float near, float far, float fieldOfViewRadians, float aspectRatio) {
    float halfFieldOfView = fieldOfViewRadians * 0.5f;
    float top = tan(halfFieldOfView) * near;
    float bottom = -top;
    float right = top * aspectRatio;
    float left = -right;

    return {
        { (2 * near) / (right - left), 0, 0, 0,
          0, (2 * near) / (top - bottom), 0, 0,
          (right + left) / (right - left), (top + bottom) / (top - bottom), -(far + near) / (far - near), -1,
          0, 0, (-2 * far * near) / (far - near), 0 }
    };
}

void Mat4x4::print() {
    printf("[ ");
    for (int idx = 0; idx < 16; idx++) {
        printf("%f, ", m[idx]);
    }
    printf(" ]\n");
}

// ***************************************
// Quaternion
Quaternion::Quaternion() { };

Quaternion::Quaternion(float inW, float inX, float inY, float inZ) {
    w = inW;
    x = inX;
    y = inY;
    z = inZ;
}

float Quaternion::operator [](int index) {
	switch (index) {
	case 0:
		return x;
	case 1:
		return y;
	case 2:
		return z;
	case 3:
		return w;
	default:
		return 0;
	}
}

Quaternion Quaternion::operator*(const Quaternion& other) const {
	return {
		w * other.w - x * other.x - y * other.y - z * other.z,  // w
        w * other.x + x * other.w + y * other.z - z * other.y,  // i
        w * other.y - x * other.z + y * other.w + z * other.x,  // j
        w * other.z + x * other.y - y * other.x + z * other.w   // k
	};
}

Quaternion Quaternion::operator*(const float& scale) const {
	return {
		w * scale,
		x * scale,
		y * scale,
		z * scale
	};
}

Quaternion Quaternion::operator+(const Quaternion& other) const {
	return {
		w + other.w,
		x + other.x,
		y + other.y,
		z + other.z
	};
}

Quaternion Quaternion::operator-(const Quaternion& other) const {
	return {
		w - other.w,
		x - other.x,
		y - other.y,
		z - other.z
	};
}

const float DOT_THRESHOLD = 0.9999f; 

// Using a slerp here, mostly taken from here: http://number-none.com/product/Understanding%20Slerp,%20Then%20Not%20Using%20It/.
// As JBlow says, it's expensive as heck. I will address this if it becomes a problem.
Quaternion Quaternion::interpolate(const Quaternion& other, const float factor) {
	Quaternion newOther = other;
	float dotProduct = dot(other);

	if (dotProduct < 0) {
		newOther = other * -1;
		dotProduct *= -1;
	}

	if (dotProduct > DOT_THRESHOLD) {
		return (*this + ((newOther - *this) * factor)).normalize();
	}

	float thetaZero = acos(dotProduct); // angle between input vectors
	float theta = thetaZero * factor;

	Quaternion v2 = (newOther - (*this * dotProduct)).normalize();

	return (*this * cos(theta)) + (v2 * sin(theta));
}

float Quaternion::length() const {
	return sqrtf(x * x + y * y + z * z + w * w);
}

Quaternion Quaternion::normalize() const {
	float l = length();
	return {
		w / l,
		x / l,
		y / l,
		z / l,
	};
}

/*Mat4x4 Quaternion::toMatrix() const {
	return {
		{
			1 - 2 * (y * y - z * z), 
			2 * (x * y - z * w),
            2 * (x * z + w * y),
            0,

            2 * (x * y + w * z),
            1 - 2 * (x * x - z * z),
            2 * (y * z - w * x),
            0,

            2 * (x * z - w * y),
            2 * (y * z + w * x),
            1 - 2 * (x * x - y * y),
			0,

			0,
			0,
			0,
			1
		}
	};
}*/

Mat4x4 Quaternion::toMatrix() const {
	return {
		{
			1 - 2 * (y * y +  z * z), 
			2 * (x * y + z * w),
			2 * (x * z - y * w),
			0,
			2 * (x * y - w * z),
			1 - 2 * (x * x + z * z),
			2 * (y * z + w * x),
			0,
			2 * (x * z + w * y),
			2 * (y * z - w * x),
			1 - 2 * (x * x + y * y),
			0,
			0,
			0,
			0,
			1
		}
	};
}

float Quaternion::dot(const Quaternion& other) const {
	return w * other.w + x * other.x + y * other.y + z * other.z;
}

Quaternion quaternionFromRotation(Vector3 axis, float angleRadians) {
    float halfAngleRadians = angleRadians / 2.f;
    float cosHalfAngRad = cosf(halfAngleRadians);
    float sinHalfAngRad = sinf(halfAngleRadians);

    return {
        cosHalfAngRad,
        axis.x * sinHalfAngRad,
        axis.y * sinHalfAngRad,
        axis.z * sinHalfAngRad
    };
}

Quaternion quaternionFromEulerAngle(float yaw, float pitch, float roll) {
    float cy = cosf(yaw * 0.5f);
    float sy = sinf(yaw * 0.5f);
    float cp = cosf(pitch * 0.5f);
    float sp = sinf(pitch * 0.5f);
    float cr = cosf(roll * 0.5f);
    float sr = sinf(roll * 0.5f);

    return {
        cr * cp * cy + sr * sp * sy,
        sr * cp * cy - cr * sp * sy,
        cr * sp * cy + sr * cp * sy,
        cr * cp * sy - sr * sp * cy
    };
}

void Quaternion::printDebug(const char* name) {
    printf("%s=Quaternion(%f, %f, %f, %f)\n", name, x, y, z, w);
}
