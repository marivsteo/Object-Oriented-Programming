#include "asg12GUI.h"
#include <QtWidgets/QApplication>

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QRadioButton>
#include <QApplication>
#include <QObject>
#include <vector>
#include <string>

#include "Controller.h"
#include "Exceptions.h"
#include "Movie.h"
#include "GUI.h"

int QtGUI(int argc, char* argv[])
{
	QApplication a(argc, argv);
	std::vector<Movie> repository;
	Controller ctrl{ repository };

	GUI main_widget{ ctrl, 0 };

	main_widget.initGUI();
	main_widget.connectSignals();

	main_widget.show();

	return a.exec();
}

int main(int argc, char* argv[])
{
	return QtGUI(argc, argv);
}