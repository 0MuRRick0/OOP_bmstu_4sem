#pragma once

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <qshortcut.h>
#include <QKeySequence>
#include <QFileDialog.h>
#include <QMessageBox>
#include "MatrixLib.h"
#include "Mesh.h"
#include "userInterface.h"
#include "Errors.h"
#include "Actions.h"

void drawScene(const mesh& mymesh, projParams& params);
void setupConnections(Ui::Form& ui);