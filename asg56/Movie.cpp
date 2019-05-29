#include"Movie.h"
#include<assert.h>
#include<algorithm>

Movie::Movie() {}

Movie::Movie(const std::string& n, const std::string& g, const std::string& t, int y) {
	name = std::string(n);
	genre = std::string(g);
	trailer = std::string(t);
	year = y;
	likes = 0;
}

Movie::Movie(const Movie& movie) {
	name = std::string(movie.getName());
	genre = std::string(movie.getGenre());
	trailer = std::string(movie.getTrailer());
	year = movie.getYear();
	likes = movie.getLikes();
}

Movie& Movie::operator = (const Movie& movie) {
	name = std::string(movie.getName());
	genre = std::string(movie.getGenre());
	trailer = std::string(movie.getTrailer());
	year = movie.getYear();
	likes = movie.getLikes();

	return *this;
}

void Movie::setName(std::string n) {
	this->name = n;
}

std::string Movie::getName() const {
	return this->name;
}

void Movie::setGenre(std::string genre) {
	this->genre = genre;
}


std::string Movie::getGenre() const {
	return this->genre;
}


void Movie::setTrailer(std::string trailer) {
	this->trailer = trailer;
}


std::string Movie::getTrailer() const {
	return this->trailer;
}


void Movie::setYear(int year) {
	this->year = year;
}


int Movie::getYear() const {
	return this->year;
}


void Movie::setLikes(int likes) {
	this->likes = likes;
}


int Movie::getLikes() const {
	return this->likes;
}


bool Movie::operator ==(const Movie movie) const {
	if (movie.getYear() == -1) {
		if (movie.getGenre().size() == 0)
			return true;

		std::string copyone = std::string(this->getGenre());
		std::string copytwo = std::string(movie.getGenre());

		std::transform(copyone.begin(), copyone.end(), copyone.begin(), ::tolower);
		std::transform(copytwo.begin(), copytwo.end(), copytwo.begin(), ::tolower);

		return copyone == copytwo;
	}
	else {
		return this->getName() == movie.getName() && this->getYear() == movie.getYear() && this->getGenre() == movie.getGenre();
	}
}

Movie& Movie::operator ++ () {
	this->likes++;
	return *this;
}

Movie& Movie::operator ++(int) {
	++(*this);
	return *this;
}

std::ostream& operator << (std::ostream& os, const Movie& m) {

	os << m.getName() << " | " << m.getGenre() << " | " << m.getTrailer() << " | " << m.getYear() << " | " << m.getLikes();

	return os;
}