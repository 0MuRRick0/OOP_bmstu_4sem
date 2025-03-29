#pragma once

#include "MatrixLib.h"

typedef struct RGB
{
    int r, g, b;
} RGB;

typedef struct triangle
{
    point4d p[3];
    RGB color;
} triangle;

triangle* allocateTriangles(int count);
void freeTriangles(triangle* tris);

void CopyTriangleColor(triangle& dst, const triangle& src);
void setTriangleColor(triangle& tri, const RGB color);

triangle& MultiplyMatrixTriangle(const triangle& input, const mat4x4 matrix);

point4d& FindNormal(const triangle& input);

bool IsSeen(const triangle& input, const point4d& camera, const point4d& normal);

int cmp_triangles(const void* input1, const void* input2);
