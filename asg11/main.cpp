#include "asg11.h"
#include <QtWidgets/QApplication>
#include "CSVMovieRepo.h"
#include <AdminCSVController.h>
#include <GUI.h>

int main(int argc, char *argv[])
{
	MovieRepository* admin_repo;
	//AdminController* c;
	QApplication a(argc, argv);

	admin_repo = new CSVMovieRepo{ "admin.csv" };
	AdminCSVController c { *admin_repo };

	FirstGUI w{ c };
	w.show();

	return a.exec();
}
