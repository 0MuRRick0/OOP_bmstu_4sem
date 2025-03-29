#pragma once
#include "userInterface.h"
#include "Mesh.h"
#include "Polygons.h"
#include "MatrixLib.h"


enum actions
{
    READ,
    TRANSFORM,
    MOVE_CAMERA,
    PROJECT,
    FREE
};
typedef enum actions actions;


enum transforms
{
    SCALE,
    ROTATE,
    TRANSLATE
};
typedef enum transforms transform;

typedef struct RotParams
{
    double centerX;
    double centerY;
    double centerZ;
    double rotX;
    double rotY;
    double rotZ;
} RotParams;


typedef struct ScaleParams
{
    double scale;
} ScaleParams;

typedef struct TranslationParams
{
    point4d offset;
} TranslationParams;

typedef struct transformParams
{
    transforms transform;
    ScaleParams scaleParams;
    RotParams rotParams;
    TranslationParams translationParams;
} transformParams;


typedef struct projParams
{
    Ui::Form ui;
    QColor backgroundColor;
    int width;
    int height;
} projParams;

typedef struct readParams
{
    char* filepath;
    RGB figureColor;
} readParams;

enum axis
{
    X,
    Y,
    Z
};

struct cameraMovementParams
{
    enum axis axis;
    double value;
};

struct actionData
{
    actions action;
    union
    {
        readParams readparams;
        transformParams transformation;
        cameraMovementParams camMove;
    };

    projParams projection;
};