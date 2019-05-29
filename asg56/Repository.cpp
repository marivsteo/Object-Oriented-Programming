#include"Repository.h"

Repository::Repository() {}

Vector<Movie> Repository::getAll() {
	return Vector<Movie>(this->movies);
}

void Repository::addMovie(const Movie& movie) {
	this->movies.addElem(movie);
}

bool Repository::deleteMovie(int i) {
	try {
		this->movies.remove(i);
		return true;
	}
	catch (std::exception e) {
		return false;
	}
}

bool Repository::changeName(int i, const std::string& name) {
	try {
		this->movies[i].setName(name);
		return true;
	}
	catch (std::exception e) {
		return false;
	}
}


bool Repository::changeGenre(int i, const std::string& genre) {
	try {
		this->movies[i].setGenre(genre);
		return true;
	}
	catch (std::exception e) {
		return false;
	}
}


bool Repository::changeTrailer(int i, const std::string& trailer) {
	try {
		this->movies[i].setTrailer(trailer);
		return true;
	}
	catch (std::exception e) {
		return false;
	}
}


bool Repository::changeYear(int i, int year) {
	try {
		this->movies[i].setYear(year);
		return true;
	}
	catch (std::exception e) {
		return false;
	}
}


bool Repository::incLikes(int i) {
	try {
		this->movies[i]++;
		return true;
	}
	catch (std::exception e) {
		return false;
	}
}


Movie& Repository::operator [] (int i) const {
	return this->movies[i];
}