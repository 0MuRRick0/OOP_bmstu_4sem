#include "render.h"

static RGB adjustLuminance(const RGB& color, const point4d& light, const point4d& normal) {
    RGB result;
    const int maxIntensity = 255;
    const int minIntensity = 0;
    const double lum = DotProduct(normal, light);
    

    int tempR = (int)(color.r * lum);
    int tempG = (int)(color.g * lum);
    int tempB = (int)(color.b * lum);

    if (tempR > maxIntensity) {
        tempR = maxIntensity;
    }
    if (tempR < minIntensity) {
        tempR = minIntensity;
    }

    if (tempG > maxIntensity) {
        tempG = maxIntensity;
    }
    if (tempG < minIntensity) {
        tempG = minIntensity;
    }

    if (tempB > maxIntensity) {
        tempB = maxIntensity;
    }
    if (tempB < minIntensity) {
        tempB = minIntensity;
    }

    result.r = tempR;
    result.g = tempG;
    result.b = tempB;

    return result;
}


mat4x4 createRotationAroundCenterMatrix(const RotParams& params) {
    mat4x4 rotationMatrix = CreateSingleMatrix();

    mat4x4 translate1 = CreateTranslationMatrix(-params.centerX, -params.centerY, -params.centerZ);
    MultiplyMatrix(rotationMatrix, translate1, rotationMatrix);

    mat4x4 rotate = CreateRotationMatrix(params.rotX, params.rotY, params.rotZ);
    MultiplyMatrix(rotationMatrix, rotate, rotationMatrix);

    mat4x4 translate2 = CreateTranslationMatrix(params.centerX, params.centerY, params.centerZ);
    MultiplyMatrix(rotationMatrix, translate2, rotationMatrix);

    return rotationMatrix;
}

static mat4x4 createCameraTransformMatrix(const point4d& camera) {
    point4d vUp = { 0, 1, 0 };
    point4d vTarget = { 0, 0, 1 };

    mat4x4 matCamera = CreatePointAtMatrix(camera, vTarget, vUp);
    return MatrixQuickInverse(matCamera);
}


mat4x4& createScreenMatrix(const point4d& camera, const projParams& params) {
    mat4x4 projectionMatrix = CreateSingleMatrix();

    mat4x4 cameraMatrix = createCameraTransformMatrix(camera);
    MultiplyMatrix(projectionMatrix, cameraMatrix, projectionMatrix);

    mat4x4 projection = CreateProjectionMatrix(params.width, params.height);
    MultiplyMatrix(projectionMatrix, projection, projectionMatrix);

    mat4x4 center = CreateCenterMatrix(params.width, params.height);
    MultiplyMatrix(projectionMatrix, center, projectionMatrix);

    return projectionMatrix;
}

void MultiplyMatrixMesh(mesh& meshOut, const mesh& meshIn, const mat4x4& matrix) 
{
    for (int i = 0; i < meshIn.tri_count; ++i) 
    {
        meshOut.tris[i] = MultiplyMatrixTriangle(meshIn.tris[i], matrix);
        CopyTriangleColor(meshIn.tris[i], meshOut.tris[i]);
    }
    meshOut.tri_count = meshIn.tri_count;
}

ErrorCode applyMatrixObject(mesh &mymesh, const mat4x4 &matrix)
{
    ErrorCode error = SUCCESS;

    mesh resultMesh;
    initMesh(resultMesh);
    error = allocateTrianglesAsInMesh(resultMesh, mymesh);
    if (!error)
    {
        MultiplyMatrixMesh(resultMesh, mymesh, matrix);
        freeTrianglesInMesh(mymesh);
        mymesh = resultMesh;
    }

    return error;
}

ErrorCode rotateObject(mesh& mymesh, const RotParams& rotParams)
{
    ErrorCode error = SUCCESS;

    mat4x4 rotationMatrix = createRotationAroundCenterMatrix(rotParams);
    error = applyMatrixObject(mymesh, rotationMatrix);

    return error;
}

ErrorCode scaleObject(mesh& mymesh, const ScaleParams& params)
{
    ErrorCode error = SUCCESS;

    mat4x4 scalingMatrix = CreateScalingMatrix(params.scale);
    error = applyMatrixObject(mymesh, scalingMatrix);

    return error;
}

static mat4x4 CreateTranslationMatrixPoint4d(point4d offset)
{
    return CreateTranslationMatrix(offset.x, offset.y, -offset.z);
}

ErrorCode translateObject(mesh& mymesh, const TranslationParams& params)
{
    ErrorCode error = SUCCESS;
    
    const mat4x4 translatationMatrix = CreateTranslationMatrixPoint4d(params.offset);
    error = applyMatrixObject(mymesh, translatationMatrix);
    
    return error;
}

mesh &transformToScreen(const mesh& mymesh, const point4d& camera, const projParams& params)
{
    ErrorCode error = SUCCESS;
    mesh transformedMesh;
    initMesh(transformedMesh);
    error = allocateTrianglesForMesh(transformedMesh, mymesh.tri_count);
    if (error)
    {
        freeTrianglesInMesh(transformedMesh);
    }
    else
    {
        mat4x4 screenMatrix = createScreenMatrix(camera, params);
        MultiplyMatrixMesh(transformedMesh, mymesh, screenMatrix);
        transformedMesh.tri_count = mymesh.tri_count;
    }

    return transformedMesh;
}

ErrorCode calculateSeenMesh(mesh& seenMesh, const mesh& mymesh, const point4d& camera)
{
    ErrorCode error = SUCCESS;
    point4d light = { 0, 0, -1, 0 };


    initMesh(seenMesh);
    error = allocateTrianglesForMesh(seenMesh, mymesh.tri_count);
    if (!error)
    {
        for (int i = 0; i < mymesh.tri_count; i++)
        {
            triangle tri = mymesh.tris[i];
            point4d normal = FindNormal(tri);
            if (IsSeen(tri, camera, normal))
            {
                int& index = seenMesh.tri_count;
                seenMesh.tris[index++] = tri;
                const RGB newColor = adjustLuminance(tri.color, light, normal);
                setTriangleColor(seenMesh.tris[index - 1], newColor);
            }
        }
    }

    qsort(seenMesh.tris, seenMesh.tri_count, sizeof(triangle), cmp_triangles);
    return error;
}

ErrorCode projectOnScreen(projParams params, const mesh& mymesh, const point4d& camera)
{
    ErrorCode error = SUCCESS;
    if (isEmptyMesh(mymesh))
        error = ERROR_FILE_NOT_SELECTED;
    else
    {
        mesh meshSeen;
        error = calculateSeenMesh(meshSeen, mymesh, camera);
        if (!error)
        {
            mesh screenMesh = transformToScreen(meshSeen, camera, params);

            drawScene(screenMesh, params);

        }
    }
    
    return error;
}