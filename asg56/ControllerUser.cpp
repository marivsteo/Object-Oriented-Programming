#include"ControllerUser.h"

ControllerUser::ControllerUser(Repository& r) : repo{ r } {
	this->curr = -1;
}

void ControllerUser::storeGenre(const std::string& genre) {
	Movie movie{ "", genre, "", -1 };
	Vector<Movie> res{};

	Vector<Movie> all = this->repo.getAll();

	for (int i = 0; i < all.size(); i++) {
		if (all[i] == movie)
			res.addElem(Movie(all[i]));
	}
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < this->watchlist.size(); j++)
			if (res[i] == this->watchlist[j])
				res.remove(i);
	}
	this->query = res;
	this->curr = 0;
}

void ControllerUser::nextMovie() {
	if (this->curr == -1) throw std::exception();
	int allCount = this->query.size();
	this->curr = (this->curr == allCount - 1) ? (0) : (this->curr + 1);
}

void ControllerUser::addToWatchlist() {
	if (!this->query.size())
		return;
	this->watchlist.addElem(Movie(this->query[this->curr]));
	this->query.remove(this->curr);
}

Movie ControllerUser::getDetails() {
	return this->query[this->curr];
}

void ControllerUser::removeWatchlist(int i, int liked) {
	if (i < 0 or i >= this->watchlist.size() or liked < 0 or liked >1)
		throw std::exception();
	Movie movie = this->watchlist[i];
	for (int k = 0; k < this->repo.movies.size() and liked; k++) {
		if (this->repo.movies[k] == movie) {
			int likes = this->repo.movies[k].getLikes() + 1;
			this->repo.movies[k].setLikes(likes);
			break;
		}
	}
	this->watchlist.remove(i);
}

Vector<Movie> ControllerUser::getQuery() {
	if (this->curr == -1)
		throw std::exception();
	return Vector<Movie>(this->query);
}

Vector<Movie> ControllerUser::getWatchlist() {
	return Vector<Movie>(this->watchlist);
}