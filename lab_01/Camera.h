#pragma once

#include "MatrixLib.h"
#include "Errors.h"
#include "actionData.h"

point4d initStartCamera(void);
ErrorCode moveCamera(point4d& camera, const cameraMovementParams params);
