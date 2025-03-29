#pragma once
#include <math.h>
#include <stdlib.h>


#define PI               3.141592653
#define DBL_EPSILON      2.2204460492503131e-016

typedef struct point4d
{
    double x, y, z;
    double h;
} point4d;

typedef struct mat4x4
{
    double m[4][4];
} mat4x4;

// Matrix operations
void MultiplyMatrixVector(const point4d& i, point4d& o, const mat4x4& m);
void MultiplyMatrix(const mat4x4& mat1, const mat4x4& mat2, mat4x4& output);
mat4x4& MatrixQuickInverse(const mat4x4& m);

// Vector operations
point4d VectorAdd(const point4d& input1, const point4d& input2);
point4d VectorSub(const point4d& input1, const point4d& input2);
point4d VectorDiv(const point4d& input1, const double dividend);
point4d VectorMul(const point4d& input1, const double multiplier);

double DotProduct(const point4d& input1, const point4d& input2);
point4d NormalizeVector(const point4d& vector);

// Library matricies
mat4x4& CreateRotationMatrixX(const double rad_angle);
mat4x4& CreateRotationMatrixY(const double rad_angle);
mat4x4& CreateRotationMatrixZ(const double rad_angle);
mat4x4& CreateProjectionMatrix(const int width, const int height);
mat4x4& CreateSingleMatrix(void);
mat4x4& CreateTranslationMatrix(const double dx, const double dy, const double dz);
mat4x4& CreateScalingMatrix(const double scale);
mat4x4& CreateRotationMatrix(const double rad_x, const double rad_y, const double rad_z);
mat4x4& CreateCenterMatrix(const int width, const int height);

// Projection matrix
mat4x4& CreateProjectionMatrix(int WIDTH, int HEIGHT);
mat4x4& CreatePointAtMatrix(const point4d& pos, const point4d forward, const point4d& up);