#include "Polygons.h"

triangle* allocateTriangles(int count) {
    if (count <= 0) {
        return NULL;
    }

    triangle* tris = (triangle*)malloc(count * sizeof(triangle));
    if (!tris) {
        tris = NULL;
    }

    return tris;
}

void setTriangleColor(triangle& tri, const RGB color)
{
    tri.color = color;
}

void freeTriangles(triangle* tris) {
    if (tris) {
        free(tris);
    }
}

const RGB& GetTriangleColor(const triangle& tri) {
    return tri.color;
}

void SetTriangleColor(triangle& tri, const RGB& color) {
    tri.color = color;
}

void CopyTriangleColor(triangle& dst, const triangle& src) {
    SetTriangleColor(dst, GetTriangleColor(src));
}

triangle& MultiplyMatrixTriangle(const triangle& input, const mat4x4 matrix)
{
    triangle result;

    for (int i = 0; i < 3; i++)
    {
        MultiplyMatrixVector(input.p[i], result.p[i], matrix);
    }

    result.color = input.color;
    return result;
}

point4d& FindNormal(const triangle& input)
{
    point4d normal, line1, line2; 

    line1 = VectorSub(input.p[1], input.p[0]);
    line2 = VectorSub(input.p[2], input.p[0]);

    normal.x = line1.y * line2.z - line1.z * line2.y;
    normal.y = line1.z * line2.x - line1.x * line2.z;
    normal.z = line1.x * line2.y - line1.y * line2.x;
    
    point4d normalizedVector = NormalizeVector(normal);
    return normalizedVector;
}

inline const point4d& GetPointAt(const triangle& tri, const int index) {
    return tri.p[index];
}

inline point4d SubtractPoints(const point4d& a, const point4d& b) {
    point4d result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    result.h = 0;
    return result;
}

bool IsSeen(const triangle& input, const point4d& camera, const point4d& normal)
{
    bool isVisible = false;

    const point4d& triPoint = GetPointAt(input, 0);

    point4d triPointRelatedToCamera = SubtractPoints(triPoint, camera);

    float dotResult = DotProduct(normal, triPointRelatedToCamera);

    if (dotResult < 0.0) {
        isVisible = true;
    }

    return isVisible;
}

inline double CalculateAverageZ(const triangle& tri) {
    double sum = 0.0;
    for (int i = 0; i < 3; ++i) {
        sum += GetPointAt(tri, i).z;
    }
    return sum / 3.0;
}

int cmp_triangles(const void* input1, const void* input2)
{
    int result = 0;
    const triangle* t1 = (triangle *)(input1);
    const triangle* t2 = (triangle *)(input2);

    double z1 = CalculateAverageZ(*t1);
    double z2 = CalculateAverageZ(*t2);

    if (z1 > z2) {
        result = -1;
    }
    else if (z1 < z2) {
        result = 1;
    }

    return result;
}