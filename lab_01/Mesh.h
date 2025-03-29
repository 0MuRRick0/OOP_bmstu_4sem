#pragma once

#include "Polygons.h"
#include "MatrixLib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Errors.h"


typedef struct {
    triangle* tris;
    int tri_count;
} mesh;

void initMesh(mesh& m);
bool isEmptyMesh(const mesh& mesh);
mesh returnEmptyMesh(void);

ErrorCode allocateTrianglesForMesh(mesh &m, const int tri_count);
ErrorCode allocateTrianglesAsInMesh(mesh& dst, const mesh& src);
void freeTrianglesInMesh(mesh& m);

