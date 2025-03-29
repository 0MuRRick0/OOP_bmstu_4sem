#include "MatrixLib.h"


void MultiplyMatrix(const mat4x4& mat1, const mat4x4& mat2, mat4x4& output)
{
    mat4x4 temp = {}; 
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                temp.m[i][j] += mat1.m[i][k] * mat2.m[k][j];
            }
        }
    }
    output = temp;
}

void MultiplyMatrixPoint(const point4d& i, point4d& o, const mat4x4& m)
{
    o.x = i.x * m.m[0][0] + i.y * m.m[1][0] + i.z * m.m[2][0] + m.m[3][0];
    o.y = i.x * m.m[0][1] + i.y * m.m[1][1] + i.z * m.m[2][1] + m.m[3][1];
    o.z = i.x * m.m[0][2] + i.y * m.m[1][2] + i.z * m.m[2][2] + m.m[3][2];
    o.h = i.x * m.m[0][3] + i.y * m.m[1][3] + i.z * m.m[2][3] + m.m[3][3];
}

void MultiplyMatrixVector
(const point4d& i, point4d& o, const mat4x4& m) {
    o.x = i.x * m.m[0][0] + i.y * m.m[1][0] + i.z * m.m[2][0] + m.m[3][0];
    o.y = i.x * m.m[0][1] + i.y * m.m[1][1] + i.z * m.m[2][1] + m.m[3][1];
    o.z = i.x * m.m[0][2] + i.y * m.m[1][2] + i.z * m.m[2][2] + m.m[3][2];
    o.h = i.x * m.m[0][3] + i.y * m.m[1][3] + i.z * m.m[2][3] + m.m[3][3];
    if (fabs(o.h) > 0) {
        o.x /= o.h; o.y /= o.h; o.z /= o.h; o.h = 1;
    }
}


point4d VectorAdd(const point4d& input1, const point4d& input2)
{
    return { input1.x + input2.x, input1.y + input2.y, input1.z + input2.z };
}

point4d VectorSub(const point4d& input1, const point4d& input2)
{
    return { input1.x - input2.x, input1.y - input2.y, input1.z - input2.z };
}

point4d VectorDiv(const point4d& input1, const double dividend)
{
    return { input1.x / dividend, input1.y / dividend, input1.z / dividend };
}

point4d VectorMul(const point4d& input1, const double multiplier)
{
    return { input1.x * multiplier, input1.y * multiplier, input1.z * multiplier };
}

double DotProduct(const point4d& input1, const point4d& input2)
{
    return { input1.x * input2.x + input1.y * input2.y + input1.z * input2.z };
}

point4d CrossProduct(const point4d& input1, const point4d& input2)
{
    point4d result;
    result.x = input1.y * input2.z - input1.z * input2.y;
    result.y = input1.z * input2.x - input1.x * input2.z;
    result.z = input1.x * input2.y - input1.y * input2.x;
    result.h = 0;
    return result;
}

point4d NormalizeVector(const point4d& vector)
{
    point4d normalized_vector;

    const double length = sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));

    return VectorDiv(vector, length);
}

mat4x4& CreateRotationMatrixX(const double rad_angle) {
    mat4x4 MRotX = {0};
    MRotX.m[0][0] = 1.0;
    MRotX.m[1][1] = cos(rad_angle);
    MRotX.m[1][2] = -sin(rad_angle);
    MRotX.m[2][1] = sin(rad_angle);
    MRotX.m[2][2] = cos(rad_angle);
    MRotX.m[3][3] = 1.0;
    return MRotX;
}

mat4x4& CreateRotationMatrixY(const double rad_angle) {
    mat4x4 MRotY = { 0 };
    MRotY.m[0][0] = cos(rad_angle);
    MRotY.m[0][2] = sin(rad_angle);
    MRotY.m[1][1] = 1.0;
    MRotY.m[2][0] = -sin(rad_angle);
    MRotY.m[2][2] = cos(rad_angle);
    MRotY.m[3][3] = 1.0;
    return MRotY;
}

mat4x4& CreateRotationMatrixZ(const double rad_angle) {
    mat4x4 MRotZ = { 0 };
    MRotZ.m[0][0] = cos(rad_angle);
    MRotZ.m[0][1] = -sin(rad_angle);
    MRotZ.m[1][0] = sin(rad_angle);
    MRotZ.m[1][1] = cos(rad_angle);
    MRotZ.m[2][2] = 1.0;
    MRotZ.m[3][3] = 1.0;
    return MRotZ;
}

mat4x4& CreateProjectionMatrix(const int width, const int height) {
    mat4x4 matProj = { 0 };
    const float fNear = 0.1f;
    const float fFar = 1000.0;
    const float fAspectRatio = static_cast<float>(width) / height;
    const float fFov = 60.0;
    const float fFovRad = 1.0 / tanf(fFov * 0.5f * (PI / 180.0));

    matProj.m[0][0] = fFovRad * fAspectRatio;
    matProj.m[1][1] = fFovRad;
    matProj.m[2][2] = fFar / (fFar - fNear);
    matProj.m[3][2] = (-fFar * fNear) / (fFar - fNear);
    matProj.m[2][3] = 1.0;
    matProj.m[3][3] = 0.0;
    return matProj;
}

mat4x4& CreateSingleMatrix(void) {
    mat4x4 matSingle = { 0 };
    for (int i = 0; i < 4; i++) {
        matSingle.m[i][i] = 1.0;
    }
    return matSingle;
}

int CmpPointByZ(const point4d& v1, const point4d& v2) {
    int result = 0;
    double components1[4] = { v1.x, v1.y, v1.z, v1.h };
    double components2[4] = { v2.x, v2.y, v2.z, v2.h };

    for (int i = 0; i < 4 && result == 0; ++i) {
        double diff = components1[i] - components2[i];
        if (fabs(diff) > DBL_EPSILON) {
            if (diff < 0) {
                result = -1;
            }
            else {
                result = 1;
            }
        }
    }

    return result;
}

mat4x4& CreateTranslationMatrix(const double dx, const double dy, const double dz) {
    mat4x4 TranslationMatrix = { 0 };
    TranslationMatrix.m[0][0] = 1.0;
    TranslationMatrix.m[1][1] = 1.0;
    TranslationMatrix.m[2][2] = 1.0;
    TranslationMatrix.m[3][3] = 1.0;
    TranslationMatrix.m[3][0] = dx;
    TranslationMatrix.m[3][1] = dy;
    TranslationMatrix.m[3][2] = dz;
    return TranslationMatrix;
}

mat4x4& CreateScalingMatrix(const double scale) {
    mat4x4 ScalingMatrix = { 0 };

    ScalingMatrix.m[0][0] = scale;
    ScalingMatrix.m[1][1] = scale;
    ScalingMatrix.m[2][2] = scale;
    ScalingMatrix.m[3][3] = 1.0;
    return ScalingMatrix;
}

mat4x4& CreateRotationMatrix(const double rad_x, const double rad_y, const double rad_z) {
    mat4x4 Result = { 0 };

    mat4x4 mRotXY;
    mat4x4 mRotX = CreateRotationMatrixX(rad_x);
    mat4x4 mRotY = CreateRotationMatrixY(rad_y);
    mat4x4 mRotZ = CreateRotationMatrixZ(rad_z);

    MultiplyMatrix(mRotX, mRotY, mRotXY);
    MultiplyMatrix(mRotXY, mRotZ, Result);

    return Result;
}

mat4x4& CreateCenterMatrix(const int width, const int height) {
    mat4x4 Result = { 0 };

    Result.m[0][0] = width / 2.0;
    Result.m[1][1] = -height / 2.0;
    Result.m[3][0] = width / 2.0;
    Result.m[3][1] = height / 2.0;
    Result.m[3][3] = 1.0;
    return Result;
}

mat4x4& CreatePointAtMatrix(const point4d& pos, const point4d forward, const point4d& up) {
    mat4x4 matrix = { 0 };

    point4d newForward = VectorSub(forward, pos);
    newForward = NormalizeVector(newForward);

    const point4d a = VectorMul(newForward, DotProduct(up, newForward));
    point4d newUp = VectorSub(up, a);
    newUp = NormalizeVector(newUp);

    point4d newRight = CrossProduct(newUp, newForward);

    matrix.m[0][0] = newRight.x;	matrix.m[0][1] = newRight.y;	matrix.m[0][2] = newRight.z;	matrix.m[0][3] = 0.0;
    matrix.m[1][0] = newUp.x;		matrix.m[1][1] = newUp.y;		matrix.m[1][2] = newUp.z;		matrix.m[1][3] = 0.0;
    matrix.m[2][0] = newForward.x;	matrix.m[2][1] = newForward.y;	matrix.m[2][2] = newForward.z;	matrix.m[2][3] = 0.0;
    matrix.m[3][0] = pos.x;			matrix.m[3][1] = pos.y;			matrix.m[3][2] = pos.z;			matrix.m[3][3] = 1.0;
    return matrix;
}

mat4x4& MatrixQuickInverse(const mat4x4& m) {
    mat4x4 matrix = { 0 };

    matrix.m[0][0] = m.m[0][0]; matrix.m[0][1] = m.m[1][0]; matrix.m[0][2] = m.m[2][0]; matrix.m[0][3] = 0.0;
    matrix.m[1][0] = m.m[0][1]; matrix.m[1][1] = m.m[1][1]; matrix.m[1][2] = m.m[2][1]; matrix.m[1][3] = 0.0;
    matrix.m[2][0] = m.m[0][2]; matrix.m[2][1] = m.m[1][2]; matrix.m[2][2] = m.m[2][2]; matrix.m[2][3] = 0.0;
    matrix.m[3][0] = -(m.m[3][0] * matrix.m[0][0] + m.m[3][1] * matrix.m[1][0] + m.m[3][2] * matrix.m[2][0]);
    matrix.m[3][1] = -(m.m[3][0] * matrix.m[0][1] + m.m[3][1] * matrix.m[1][1] + m.m[3][2] * matrix.m[2][1]);
    matrix.m[3][2] = -(m.m[3][0] * matrix.m[0][2] + m.m[3][1] * matrix.m[1][2] + m.m[3][2] * matrix.m[2][2]);
    matrix.m[3][3] = 1.0;
    return matrix;
}