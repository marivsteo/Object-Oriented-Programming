#include "QtGUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
	Tests tests{};
	tests.testGetByNameOrCategory();

	QApplication a(argc, argv);
	Controller controller{};
	controller.loadRepo("input.txt");

	QtGUI w{ controller };
	w.show();
	return a.exec();
}
