#include"DynVector.h"
#include"Repository.h"
#include"ControllerAdmin.h"
#include"ControllerUser.h"
#include"UIadmin.h"
#include"UIuser.h"

int main() {
	Repository repo;
	repo.addMovie(Movie{ "Avengers Endgame", "Superhero", "https://www.youtube.com/watch?v=TcMBFSGVi1c", 2019 });
	repo.addMovie(Movie{ "Avengers Infinity War", "Superhero", "https://www.youtube.com/watch?v=6ZfuNTqbHE8", 2018 });
	repo.addMovie(Movie{ "Black Panther", "Superhero", "https://www.youtube.com/watch?v=xjDjIWPwcPU", 2018 });
	repo.addMovie(Movie{ "Cloud Atlas", "Mystery", "https://www.youtube.com/watch?v=hWnAqFyaQ5s&t=153s", 2012 });
	repo.addMovie(Movie{ "The Lobster", "Drama", "https://www.youtube.com/watch?v=vU29VfayDMw", 2015 });
	repo.addMovie(Movie{ "Gladiator", "Drama", "https://www.youtube.com/watch?v=uvbavW31adA", 2000 });
	repo.addMovie(Movie{ "Scarface", "Drama", "https://www.youtube.com/watch?v=7pQQHnqBa2E", 1983 });

	int opt = -1;
	while (opt < 0 or opt >1) {
		std::cout << "Choose: 0 for Admin, 1 for User: ";
		std::cin >> opt;
	}
	std::cin.ignore();

	if (!opt) {
		ControllerAdmin c{ repo };
		UIAdmin ui{ c };
		ui.inLoop();
	}
	else {
		ControllerUser c{ repo };
		UIUser ui{ c };
		ui.inLoop();
	}
	return 0;
}