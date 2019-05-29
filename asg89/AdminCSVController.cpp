#include <utility>
#include <sstream>
#include <Windows.h>
#include <shellapi.h>
#include "AdminCSVController.h"


void AdminCSVController::show() {
	std::stringstream ss;
	ShellExecuteA(NULL, NULL, "notepad.exe", "C:/Users/Marius/source/repos/asg89files_trial/asg89files_trial/admin.csv", NULL, SW_SHOWMAXIMIZED);
	system(ss.str().c_str());
	system("clear");
}

AdminCSVController::AdminCSVController(MovieRepository& r) : AdminController(r) {

}