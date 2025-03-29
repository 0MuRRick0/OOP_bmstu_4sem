#pragma once

#include "userInterface.h"
#include "Errors.h"
#include "Mesh.h"
#include "OBJParser.h"
#include "qfiledialog.h"
#include "render.h"
#include "actionData.h"
#include "MatrixLib.h"
#include "Camera.h"

ErrorCode transformHandler(mesh& mymesh, const transformParams& params);
