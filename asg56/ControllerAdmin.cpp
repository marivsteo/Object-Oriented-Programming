#include"ControllerAdmin.h"
#include<iostream>

ControllerAdmin::ControllerAdmin(Repository& r) : repo{r} {}

Vector<Movie> ControllerAdmin::getAll() {
	return this->repo.getAll();
}

void ControllerAdmin::addMovie(const std::string& n, const std::string& g, const std::string& t, int y) {
	Movie movie{ n, g, t, y };
	this->repo.addMovie(movie);
}

bool ControllerAdmin::deleteMovie(int i) {
	return this->repo.deleteMovie(i);
}

bool ControllerAdmin::changeName(int i, const std::string& name) {
	return this->repo.changeName(i, name);
}

bool ControllerAdmin::changeGenre(int i, const std::string& genre) {
	return this->repo.changeGenre(i, genre);
}

bool ControllerAdmin::changeTrailer(int i, const std::string& trailer) {
	return this->repo.changeTrailer(i, trailer);
}

bool ControllerAdmin::changeYear(int i, int year) {
	return this->repo.changeYear(i, year);
}