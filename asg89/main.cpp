#include "DbRepository.h"
#include "DbMovieRepo.h"
#include "AdminCSVController.h"
#include "AdminHtmlController.h"
#include "AbstractRepository.h"
#include "CSVMovieRepo.h"
#include "AdminController.h"
#include "UserController.h"
#include "AdminUI.h"
#include "UserUI.h"


int main() {
	AdminController* c;
	MovieRepository* admin_repo;
	bool option = false;
	bool controllerOption = false;

	std::cout << "CSV(0) / Html(1)? ";
	std::cin >> controllerOption;

	std::cout << "Admin(0) / User(1)? ";
	std::cin >> option;

	std::cin.ignore();

	admin_repo = new CSVMovieRepo{ "admin.csv" };

	if (!controllerOption) {
		c = new AdminCSVController{ *admin_repo };
	}
	else {
		c = new AdminHtmlController{ *admin_repo };
	}

	if (!option) {
		AdminUI ui{ *c };
		ui.input_loop();
	}
	else {
		MovieRepository* watchlist;
		watchlist = new CSVMovieRepo{ "user.csv" };
	

		UserController user{ *admin_repo, *watchlist };
		UserUI ui{ user };
		ui.input_loop();

		//        delete watchlist;
	}

	//    delete admin_repo;
	return 0;
}