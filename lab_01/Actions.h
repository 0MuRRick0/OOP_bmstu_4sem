#pragma once

#include "userInterface.h"
#include "Errors.h"
#include "Mesh.h"
#include "OBJParser.h"
#include "qfiledialog.h"
#include "render.h"
#include "actionData.h"
#include "Handler.h"

ErrorCode ReadAction(RGB figureColor);
ErrorCode FreeAction(void);
ErrorCode ProjectAction(Ui::Form ui);
ErrorCode TransformAction(Ui::Form ui, transform transform);
ErrorCode MoveCamera(axis axis, double step);