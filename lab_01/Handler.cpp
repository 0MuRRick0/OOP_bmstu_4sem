#include "Handler.h"


ErrorCode actionHandler(actionData& action)
{
	ErrorCode error = SUCCESS;
	static mesh mymesh = returnEmptyMesh();
	static point4d camera = initStartCamera();
	switch (action.action)
	{
	case READ:
		error = openObjectFile(mymesh, action.readparams);
		break;
	case TRANSFORM:
		error = transformHandler(mymesh, action.transformation);
		break;
	case MOVE_CAMERA:
		error = moveCamera(camera, action.camMove);
		break;
	case PROJECT:
		error = projectOnScreen(action.projection, mymesh, camera);
		break;
	case FREE:
		freeTrianglesInMesh(mymesh);
		break;
			
	default:
		break;
	}

	return error;
}

