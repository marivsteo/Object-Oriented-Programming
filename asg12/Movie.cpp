#include "Movie.h"
#include<utility>
#include<algorithm>

Movie::Movie(std::string name, std::string genre, int year, int likes, std::string trailer)
{
	this->name = name;
	this->genre = genre;
	this->year = year;
	this->likes = likes;
	this->trailer = trailer;
}

Movie::Movie()
{
	this->name = " ";
	this->genre = " ";
	this->year = 0;
	this->likes = 0;
	this->trailer = " ";
}

Movie::Movie(const Movie& movie)
{
	this->name = movie.name;
	this->genre = movie.genre;
	this->year = movie.year;
	this->likes = movie.likes;
	this->trailer = movie.trailer;
}

void Movie::setName(std::string n) {
	this->name = std::move(n);
}


void Movie::setGenre(std::string g) {
	this->genre = std::move(g);
}


void Movie::setTrailer(std::string t) {
	this->trailer = std::move(t);
}


void Movie::setYear(int y) {
	this->year = y;
}


void Movie::setLikes(int l) {
	this->likes = l;
}


bool Movie::operator==(const Movie& movie) const
{
	return this->name == movie.name && this->genre == movie.genre;
}

bool Movie::operator!=(const Movie& movie) const
{
	return this->name != movie.name || this->genre != movie.genre;
}

std::string Movie::toString() const
{
	return this->name + " " + this->genre + " " + std::to_string(this->year) + " " + std::to_string(this->likes) + " " + this->trailer;
}

Movie& Movie::operator=(const Movie& movie)
{
	this->name = movie.name;
	this->genre = movie.genre;
	this->year = movie.year;
	this->likes = movie.likes;
	this->trailer = movie.trailer;
	return *this;
}

void Movie::incrementLikes()
{
	this->likes += 1;
}

std::ostream& operator<<(std::ostream& stream, const Movie& movie)
{
	stream << movie.getName() << ' ' << movie.getGenre() << ' ' << movie.getYear() << ' ' << movie.getLikes() << ' ' << movie.getTrailer();
	return stream;
}

std::istream& operator>>(std::istream& stream, Movie& movie)
{
	/*std::string x;

	getline(is, x, ',');
	m.setName(x);

	getline(is, x, ',');
	m.setGenre(x);

	getline(is, x, ',');
	m.setTrailer(x);

	getline(is, x, ',');
	m.setYear(std::stoi(x));

	getline(is, x, ',');
	m.setLikes(std::stoi(x));

	return is;*/
	std::string name, genre, trailer;
	int year, likes;

	stream >> name >> genre >> year >> likes >> trailer;
	movie = Movie{ name, genre, year, likes, trailer };
	return stream;
}