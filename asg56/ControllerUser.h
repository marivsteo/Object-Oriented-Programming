#pragma once
#include"DynVector.h"
#include"Repository.h"

class ControllerUser {
private:
	Repository& repo;
	Vector<Movie> watchlist;
	Vector<Movie> query;
	int curr;
public:
	ControllerUser(Repository& r);

	void storeGenre(const std::string&);

	void addToWatchlist();

	void nextMovie();

	Movie getDetails();

	void removeWatchlist(int, int);

	Vector<Movie> getWatchlist();

	Vector<Movie> getQuery();
};