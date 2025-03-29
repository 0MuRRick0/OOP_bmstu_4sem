#include "Actions.h"
ErrorCode ReadAction(RGB figureColor)
{
	ErrorCode error = SUCCESS;

	QString filePath = QFileDialog::getOpenFileName(nullptr, "Open OBJ File", "", "OBJ Files (*.obj)");

	std::string filePathStd = filePath.toStdString();
	size_t length = filePathStd.size() + 1;

	char* filePathCStr = (char*)malloc(length);
	if (!filePathCStr) {
		error = ERROR_MEMORY_ALLOCATION;
	}

	std::strncpy(filePathCStr, filePathStd.c_str(), length);

	actionData action;
	action.action = READ;
	action.readparams.filepath = filePathCStr;
	action.readparams.figureColor = figureColor;

	error = actionHandler(action);

	free(filePathCStr);

	return error;
}

ErrorCode FreeAction(void)
{
	ErrorCode error = SUCCESS;

	actionData action;
	action.action = FREE;

	error = actionHandler(action);

	return error;
}

ErrorCode ProjectAction(Ui::Form ui)
{
	actionData action;

	action.action = PROJECT;
	action.projection.ui = ui;
	action.projection.height = ui.pixmap_label->height();
	action.projection.width = ui.pixmap_label->width();
	action.projection.backgroundColor = Qt::white;
	const ErrorCode result = actionHandler(action);

	return result;
}

ErrorCode TranslateAction(Ui::Form ui, actionData& action)
{
	ErrorCode error = SUCCESS;
	action.transformation.transform = TRANSLATE;
	TranslationParams& params = action.transformation.translationParams;

	bool allOk = true;
	bool ok;
	point4d tempOffset;

	tempOffset.x = ui.offsetX->text().toDouble(&ok);
	allOk = allOk && ok;

	tempOffset.y = ui.offsetY->text().toDouble(&ok);
	allOk = allOk && ok;

	tempOffset.z = ui.offsetZ->text().toDouble(&ok);
	allOk = allOk && ok;

	if (allOk) {
		params.offset = tempOffset;
		error = actionHandler(action);
	}
	else {
		error = ERROR_INVALID_INPUT;
	}

	return error;
}

ErrorCode RotateAction(Ui::Form ui, actionData& action)
{
	ErrorCode error = SUCCESS;
	action.transformation.transform = ROTATE;
	RotParams& params = action.transformation.rotParams;

	bool allOk = true;
	bool ok;

	// ѕолучаем координаты центра вращени€ напр€мую в структуру RotParams
	params.centerX = ui.rotCenterX->text().toDouble(&ok);
	allOk = allOk && ok;

	params.centerY = ui.rotCenterY->text().toDouble(&ok);
	allOk = allOk && ok;

	params.centerZ = ui.rotCenterZ->text().toDouble(&ok);
	allOk = allOk && ok;

	// ѕолучаем углы вращени€
	double tempRotX = ui.rotX->text().toDouble(&ok);
	allOk = allOk && ok;

	double tempRotY = ui.rotY->text().toDouble(&ok);
	allOk = allOk && ok;

	double tempRotZ = ui.rotZ->text().toDouble(&ok);
	allOk = allOk && ok;

	if (allOk) {
		params.rotX = qDegreesToRadians(tempRotX);
		params.rotY = qDegreesToRadians(tempRotY);
		params.rotZ = qDegreesToRadians(tempRotZ);

		error = actionHandler(action);
	}
	else {
		error = ERROR_INVALID_INPUT;
	}

	return error;
}

ErrorCode ScaleAction(Ui::Form ui, actionData& action)
{
	ErrorCode error = SUCCESS;
	action.transformation.transform = SCALE;

	ScaleParams& params = action.transformation.scaleParams;
	
	bool ok = true;
	double scale = ui.scale->text().toDouble(&ok);

	if (!ok)
		error = ERROR_INVALID_INPUT;
	else
	{
		if (scale < 0.05 || scale > 20)
			error = ERROR_INVALID_INPUT;
		else
		{
			params.scale = scale;
			error = actionHandler(action);
		}
	}

	return error;	
}

ErrorCode TransformAction(Ui::Form ui, transform transform)
{
	ErrorCode error = SUCCESS;

	actionData action;
	action.action = TRANSFORM;
	
	switch (transform)
	{
	case SCALE:
		error = ScaleAction(ui, action);
		break;
	case TRANSLATE:
		error = TranslateAction(ui, action);
		break;
	case ROTATE:
		error = RotateAction(ui, action);
		break;
	default:
		error = ERROR_INVALID_ARGUMENT;
	}

	return error;
}

ErrorCode MoveCamera(axis axis, double step)
{
	ErrorCode error = SUCCESS;

	actionData action;
	action.action = MOVE_CAMERA;

	action.camMove.axis = axis; 
	action.camMove.value = step;

	error = actionHandler(action);
	
	return error;
}
