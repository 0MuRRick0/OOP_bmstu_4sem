#ifndef RENDER_H
#define RENDER_H

#include <QPainter>
#include <QPixmap>
#include <QPolygon>
#include <QColor>
#include <QLineEdit>
#include <QSlider>
#include <QLabel>
#include "actionData.h"
#include "MatrixLib.h"
#include "Polygons.h"
#include "Mesh.h"
#include "userInterface.h"
#include "qt6.h"


ErrorCode rotateObject(mesh& mymesh, const RotParams& rotParams);
ErrorCode scaleObject(mesh& mymesh, const ScaleParams& params);
ErrorCode translateObject(mesh& mymesh, const TranslationParams& params);
ErrorCode projectOnScreen(projParams params, const mesh& mymesh, const point4d& camera);
#endif