#include "Camera.h"

point4d initStartCamera(void)
{
	point4d camera;
	camera.x = 0;
	camera.y = 0;
	camera.z = -10;
	camera.h = 0;

	return camera;
}

ErrorCode moveCamera(point4d& camera, const cameraMovementParams params)
{
	switch (params.axis)
	{
	case X:
		camera.x += params.value;
		break;
	case Y:
		camera.y += params.value;
		break;
	case Z:
		camera.z += params.value;
		break;
	default:
		break;
	}

	return SUCCESS;
}