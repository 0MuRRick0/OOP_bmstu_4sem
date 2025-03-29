#include "transformHandler.h"

ErrorCode transformHandler(mesh& mymesh, const transformParams& params)
{
	ErrorCode error = SUCCESS;

	if (isEmptyMesh(mymesh))
		error = ERROR_FILE_NOT_SELECTED;
	else
	{
		switch (params.transform)
		{
		case SCALE:
			error = scaleObject(mymesh, params.scaleParams);
			break;
		case ROTATE:
			error = rotateObject(mymesh, params.rotParams);
			break;
		case TRANSLATE:
			error = translateObject(mymesh, params.translationParams);
			break;
		default:
			error = ERROR_INVALID_ARGUMENT;
			break;
		}
	}


	return error;
}