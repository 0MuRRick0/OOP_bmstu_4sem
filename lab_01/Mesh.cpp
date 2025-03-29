#include "Mesh.h"

void initMesh(mesh& m) {
    m.tris = NULL;
    m.tri_count = 0;
}

mesh returnEmptyMesh(void)
{
    mesh mesh;
    initMesh(mesh);
    return mesh;
}

bool isEmptyMesh(const mesh& mesh)
{
    bool empty = false;
    if (mesh.tris == NULL || mesh.tri_count == NULL)
        empty = true;
    return empty;
}

ErrorCode allocateTrianglesAsInMesh(mesh& dst, const mesh& src)
{
    ErrorCode error = SUCCESS;
    
    error = allocateTrianglesForMesh(dst, src.tri_count);

    return error;
}

ErrorCode allocateTrianglesForMesh(mesh& m, const int tri_count) {
    ErrorCode err = SUCCESS;

    if (tri_count <= 0) {
        err = ERROR_INVALID_ARGUMENT;
    }
    else {
        if (m.tris) {
            freeTriangles(m.tris);
            m.tris = NULL;
        }

        m.tris = allocateTriangles(tri_count);
        if (!m.tris) {
            err = ERROR_MEMORY_ALLOCATION;
        }
    }

    return err;
}

void freeTrianglesInMesh(mesh& m) {
    freeTriangles(m.tris);
    m.tris = NULL;
    m.tri_count = 0;
}