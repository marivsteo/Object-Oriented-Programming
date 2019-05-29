#pragma once
#include<string>
#include"DynVector.h"
#include"Movie.h"

class Repository {
	friend class ControllerUser;
private:
	Vector<Movie> movies;
public:
	Repository();

	Vector<Movie> getAll();

	void addMovie(const Movie& movie);

	bool deleteMovie(int i);

	bool changeName(int i, const std::string& name);

	bool changeGenre(int i, const std::string& genre);

	bool changeTrailer(int i, const std::string& trailer);

	bool changeYear(int i, int year);

	bool incLikes(int i);

	Movie& operator [] (int i) const;
};