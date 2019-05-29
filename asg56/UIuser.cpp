#include"UIuser.h"
#include<sstream>
#include<string>
#include<iostream>
#include<Windows.h>
#include <shellapi.h>
#include <thread>
#include <chrono>
using namespace std;

UIUser::UIUser(ControllerUser& cntrl): c{cntrl} {}

void UIUser::moviesByGenre() {
	std::string genre;
	std::cout << "Input genre: ";
	std::getline(std::cin, genre);
	this->c.storeGenre(genre);

	int opt;
	bool flag = 1;

	system("clear");

	if (!this->c.getQuery().size()) {
		std::cout << "No movie matching the genre!\n";
		return;
	}

	while (flag) {
		try {
			this->getDetails();
		}
		catch (std::exception e) {
			std::cout << "No more movies left!\n";
			flag = 0;
			continue;
		}
		std::cout << "Menu:\n\
		1. Play the trailer\n\
		2. Next movie\n\
		3. Add movie to watchlist\n\
		4. Exit\n\
		Choose an option: ";
		std::cin >> opt;
		std::cin.ignore();
		switch (opt) {
		case 1:
			system("clear");
			this->play();
			break;
		case 2:
			this->nextMovie();
			system("clear");
			break;
		case 3:
			this->addToWatchlist();
			system("clear");
			break;
		case 4:
			flag = 0;
			break;
		}
	}
}

void UIUser::addToWatchlist() {
	this->c.addToWatchlist();
}

void UIUser::nextMovie() {
	this->c.nextMovie();
}

void UIUser::getDetails() {
	Movie movie = this->c.getDetails();
	std::cout << movie << "\n\n";
}

void UIUser::play() {
	Movie movie = this->c.getDetails();
	//std::stringstream ss;
	//ss << "google-chrome" << movie.getTrailer();
	//system(ss.str().c_str());
	ShellExecuteA(NULL, NULL, "chrome.exe", movie.getTrailer().c_str(), NULL, SW_SHOWMAXIMIZED);
	system("clear");
}

void UIUser::getWatchlist() {
	Vector<Movie> watchlist = this->c.getWatchlist();

	if (watchlist.size()) 
		std::cout << watchlist;
	else
		std::cout << "This watchlist is empty!\n";
}

void UIUser::removeWatchlist() {
	if (!this->c.getWatchlist().size()) {
		system("clear");
		std::cout << "This watchlist is empty!\n";
		return;
	}
	int i;
	int like;

	std::cout << "Index of the movie: ";
	std::cin >> i;
	std::cout << "Press 1 if you liked the movie, 0 if you hated it: ";
	std::cin >> like;

	try {
		this->c.removeWatchlist(i, like);
		system("clear");
	}
	catch (std::exception e) {
		std::cout << "Something in the input was invalid!\n";
	}
}

void UIUser::inLoop() {
	bool flag = 1;
	int opt;

	while (flag) {
		std::cout << "Menu:\n\
		1. Movies by genre\n\
		2. See watchlist\n\
		3. Remove movie from watchlist\n\
		4. Exit\n\
		Choose an option: ";
		std::cin >> opt;
		std::cin.ignore();
		switch (opt) {
		case 1:
			this->moviesByGenre();
			break;
		case 2:
			system("clear");
			this->getWatchlist();
			break;
		case 3:
			this->removeWatchlist();
			break;
		case 4:
			flag = 0;
			system("clear");
			break;
		}
	}
}