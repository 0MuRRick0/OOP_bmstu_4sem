#include "qt6.h"
#include "userInterface.h"
#include <qapplication.h>
#include <qwidget.h>



int main(int argc, char* argv[]) {
	QApplication app(argc, argv);

	QWidget window;
	Ui::Form ui;
	ui.setupUi(&window);
	setupConnections(ui);

	window.show();
	return app.exec();
}