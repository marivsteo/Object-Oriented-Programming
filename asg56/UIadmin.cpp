#include"ControllerAdmin.h"
#include"UIadmin.h"
#include<iostream>

UIAdmin::UIAdmin(ControllerAdmin& c): cntrl{c} {}

void UIAdmin::addMovie() {
	std::string name;
	std::string genre;
	int year;
	std::string trailer;

	std::cout << "Movie name: ";
	std::getline(std::cin, name);

	std::cout << "Movie genre: ";
	std::getline(std::cin, genre);

	std::cout << "Movie trailer: ";
	std::getline(std::cin, trailer);

	std::cout << "Movie year: ";
	std::cin >> year;

	this->cntrl.addMovie(name, genre, trailer, year);
}

void UIAdmin::deleteMovie() {
	int i;
	std::cout << "Index to be removed: ";
	std::cin >> i;

	bool res = this->cntrl.deleteMovie(i);
	if (!res)
		std::cout << "The index is invalid!\n";
}

void UIAdmin::displayAll() {
	std::cout << this->cntrl.getAll() << '\n';
}

void UIAdmin::changeName() {
	int i;
	std::string name;

	std::cout << "Index of the movie whose name is to be changed: ";
	std::cin >> i;
	std::cin.ignore();

	std::cout << "New name for the movie: ";
	std::getline(std::cin, name);

	bool res = this->cntrl.changeName(i, name);
	if (!res)
		std::cout << "The index is invalid!\n";
}

void UIAdmin::changeGenre() {
	int i;
	std::string genre;

	std::cout << "Index of the movie whose genre is to be changed: ";
	std::cin >> i;
	std::cin.ignore();

	std::cout << "New genre for the movie: ";
	std::getline(std::cin, genre);

	bool res = this->cntrl.changeGenre(i, genre);
	if (!res)
		std::cout << "The index is invalid!\n";
}

void UIAdmin::changeTrailer() {
	int i;
	std::string trailer;

	std::cout << "Index of the movie whose trailer is to be changed: ";
	std::cin >> i;
	std::cin.ignore();

	std::cout << "New trailer for the movie: ";
	std::getline(std::cin, trailer);

	bool res = this->cntrl.changeTrailer(i, trailer);
	if (!res)
		std::cout << "The index is invalid!\n";
}

void UIAdmin::changeYear() {
	int i;
	int year;

	std::cout << "Index of the movie whose year is to be changed: ";
	std::cin >> i;

	std::cout << "New year for the movie: ";
	std::cin >> year;

	bool res = this->cntrl.changeYear(i, year);
	if (!res)
		std::cout << "The index is invalid!\n";
}

void UIAdmin::inLoop() {
	int opt;
	bool flag = true;

	while (flag)
	{
		std::cout << "Menu: \n\
		1. List all movies\n\
		2. Add a movie\n\
		3. Delete a movie\n\
		4. Change movie name\n\
		5. Change movie genre\n\
		6. Change movie trailer\n\
		7. Change movie year\n\
		8. Exit\n\
		Choose an option: ";
		std::cin >> opt;
		std::cin.ignore();
		switch (opt) {
		case 1:
			system("clear");
			displayAll();
			break;
		case 2:
			addMovie();
			system("clear");
			break;
		case 3:
			deleteMovie();
			system("clear");
			break;
		case 4:
			changeName();
			system("clear");
			break;
		case 5:
			changeGenre();
			system("clear");
			break;
		case 6:
			changeTrailer();
			system("clear");
			break;
		case 7:
			changeYear();
			system("clear");
			break;
		case 8:
			flag = false;
			system("clear");
			break;
		}
	}
}