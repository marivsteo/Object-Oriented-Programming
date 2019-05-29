#pragma once
#include"Repository.h"

class ControllerAdmin {
private:
	Repository& repo;
public:
	ControllerAdmin(Repository& r);

	Vector<Movie> getAll();

	void addMovie(const std::string& n, const std::string& g, const std::string& t, int y);

	bool deleteMovie(int i);

	bool changeName(int i, const std::string& name);

	bool changeGenre(int i, const std::string& genre);

	bool changeTrailer(int i, const std::string& trailer);

	bool changeYear(int i, int year);
};