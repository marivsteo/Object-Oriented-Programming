#pragma once

#include <string>
#include <iostream>

class Movie;

std::ostream& operator<<(std::ostream& stream, const Movie& movie);

std::istream& operator>>(std::istream& stream, Movie& movie);

class Movie
{
	friend std::ostream& operator<<(std::ostream& fout, const Movie& movie);

	friend std::istream& operator>>(std::istream& is, Movie& movie);

private:
	std::string name;
	std::string genre;
	int year;
	int likes;
	std::string trailer;

public:
	Movie(std::string name, std::string genre, int year, int likes, std::string trailer);

	Movie();

	Movie(const Movie& movie);

	void setName(std::string n);

	Movie& operator=(const Movie& movie);

	void setGenre(std::string g);

	void setTrailer(std::string t);

	void setYear(int y);

	void setLikes(int l);

	bool operator==(const Movie& movie) const;

	bool operator!=(const Movie& movie) const;

	std::string toString() const;

	std::string getName() const { return this->name; }

	std::string getGenre() const { return this->genre; }

	std::string getTrailer() const { return this->trailer; }

	int getLikes() const { return this->likes; }

	int getYear() const { return this->year; }

	void incrementLikes();

};