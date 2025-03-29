#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <QFileDialog.h>
#include "Mesh.h"
#include "actionData.h"

typedef struct parseStructure
{
	point4d *verticies;
	triangle* faces;
	int faceCount;
	int verticieCount;
};

ErrorCode openObjectFile(mesh& mymesh, const readParams readparams);