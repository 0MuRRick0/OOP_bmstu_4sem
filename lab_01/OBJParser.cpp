#include "OBJParser.h"

parseStructure initParseStructure(void)
{
    parseStructure st;
    st.faces = NULL;
    st.verticies = NULL;
    return st;
}

ErrorCode freeParseStructure(parseStructure st)
{
    free(st.faces);
    free(st.verticies);
    st.faceCount = 0;
    st.verticieCount = 0;
    return SUCCESS;
}

static ErrorCode initializeColors(mesh &mesh, RGB color) {
    for (int i = 0; i < mesh.tri_count; ++i) {
        setTriangleColor(mesh.tris[i], color);
    }
    return SUCCESS;
}

static ErrorCode copyTrianglesIntoMesh(mesh& dst, const triangle* src, const int count) {
    for (int i = 0; i < count; ++i) {
        dst.tris[i] = src[i];
    }
    return SUCCESS;
}

bool isVerticie(const char* line) {
    const char* p = line;
    while (*p && isspace(*p)) p++;
    return p[0] == 'v' && (p[1] == ' ' || p[1] == '\t');
}

bool isFace(const char* line) {
    const char* p = line;
    while (*p && isspace(*p)) p++;
    return p[0] == 'f' && (p[1] == ' ' || p[1] == '\t');
}

ErrorCode getFaceCount(int& count, FILE* file) {
    count = 0;
    rewind(file);
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (isFace(line)) count++;
    }
    return ferror(file) ? ERROR_FILE_CONTENTS : SUCCESS;
}

ErrorCode getVerticieCount(int& count, FILE* file) {
    count = 0;
    rewind(file);
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (isVerticie(line)) count++;
    }
    return ferror(file) ? ERROR_FILE_CONTENTS : SUCCESS;
}

ErrorCode createVerticieArray(point4d*& verticies, const int count) {
    if (count <= 0)
        return ERROR_INVALID_ARGUMENT;
    verticies = (point4d*)malloc(sizeof(point4d) * count);
    return verticies ? SUCCESS : ERROR_MEMORY_ALLOCATION;
}

ErrorCode createFaceArray(triangle*& faces, const int count) {
    if (count <= 0)
        return ERROR_INVALID_ARGUMENT;
    faces = (triangle*)malloc(sizeof(triangle) * count);
    return faces ? SUCCESS : ERROR_MEMORY_ALLOCATION;
}

ErrorCode parseVertexLine(point4d& vertex, const char* line) {
    ErrorCode error = SUCCESS;

    const char* p = line;

    if (sscanf(p, "v %lf %lf %lf", &vertex.x, &vertex.y, &vertex.z) != 3)
        error = ERROR_PARSE_VERTEX;
    vertex.h = 1.0;

    return error;
}

bool vertexIndexesIsValid(const int v[3], const int maxIndex)
{
    bool isValid = true;
    for (int i = 0; i < 3; i++)
    {
        if (v[i] < 1 || v[i] > maxIndex)
            isValid = false;
    }
    return isValid;
}

ErrorCode parseFaceLine(triangle& face, const char* line, const point4d* verticies, const int count) {
    ErrorCode error = SUCCESS;

    const char* p = line;

    int v[3];
    if (sscanf(p, "f %d %d %d", &v[0], &v[1], &v[2]) != 3)
    {
        error = ERROR_PARSE_FACE;
    }
    else if (!vertexIndexesIsValid(v, count))
    {
        error = ERROR_PARSE_FACE;
    }
    else
    {
        for (int i = 0; i < 3; i++)
            face.p[i] = verticies[v[i] - 1];
    }

    return error;
}

ErrorCode prepareStructure(parseStructure& st, FILE* file)
{
    ErrorCode error = SUCCESS;
    if (error = getFaceCount(st.faceCount, file))
    {
    }
    else if (error = getVerticieCount(st.verticieCount, file))
    {
    }
    else if (error = createVerticieArray(st.verticies, st.verticieCount))
    {
    }
    else if (error = createFaceArray(st.faces, st.faceCount))
    {
    }
    return error;
}


ErrorCode checkFileValid(FILE* file) {
    return file ? SUCCESS : ERROR_FILE_OPEN;
}

ErrorCode fillStructure(parseStructure& st, FILE* file) {
    ErrorCode error = SUCCESS;
    rewind(file);
    char line[256];
    int vi = 0, fi = 0;

    while (!error && fgets(line, sizeof(line), file)) {
        if (isVerticie(line)) {
            error = parseVertexLine(st.verticies[vi++], line);
        }
        else if (isFace(line)) {
            error = parseFaceLine(st.faces[fi++], line, st.verticies, st.verticieCount);
        }
    }

    return error;
}

ErrorCode getData(parseStructure& st, const char* filename)
{
    ErrorCode error = SUCCESS;

    FILE* file = fopen(filename, "r");
    if (error = checkFileValid(file))
    {
    }
    else if (error = prepareStructure(st, file))
    {
    }
    else if (error = fillStructure(st, file))
    {
    }

    return error;
}

ErrorCode copyDataIntoMesh(mesh& mesh, const parseStructure& data) {
    ErrorCode error = SUCCESS;

    if (error = allocateTrianglesForMesh(mesh, data.faceCount))
    {
    }
    else if (error = copyTrianglesIntoMesh(mesh, data.faces, data.faceCount))
    {
        free(mesh.tris);
        mesh.tris = NULL;
    }
    else
    {
        mesh.tri_count = data.faceCount;
    }

    return SUCCESS;
}

ErrorCode loadOBJ(mesh& resultMesh, const readParams readparams) {
    ErrorCode error = SUCCESS;

    parseStructure data = initParseStructure();

    if (error = getData(data, readparams.filepath))
    {
    }
    else if (error = copyDataIntoMesh(resultMesh, data))
    {
    }
    else if (error = initializeColors(resultMesh, readparams.figureColor))
    {
    }
    else if (error = freeParseStructure(data))
    {
    }

    return error;
}

ErrorCode openObjectFile(mesh& mymesh, const readParams readparams) {
    if (!readparams.filepath) {
        return ERROR_FILE_NOT_SELECTED;
    }

    mesh tmpMesh;
    initMesh(tmpMesh);

    ErrorCode error = loadOBJ(tmpMesh, readparams);

    if (!error)
    {
        freeTrianglesInMesh(mymesh);
        mymesh = tmpMesh;
    }

    return error;
}