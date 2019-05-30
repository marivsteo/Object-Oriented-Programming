#include "Controller.h"


Controller::Controller(std::vector<Movie>& _repo) : repo{ _repo }
{
	this->readFromFile();
	this->watchlist = std::vector<Movie>{  };
	this->listByGenres = std::vector<Movie>{  };
	this->countListByGenres = -1;
}

bool Controller::addMovie(std::string name, std::string genre, int year, int likes, std::string trailer)
{
	Movie movie{ name, genre, year, likes, trailer };
	std::vector<Movie>::iterator it;
	MovieValidator validator;

	try
	{
		validator.validate(movie);
	}
	catch (ValidatorException& e)
	{
		return false;
	}

	it = find(this->repo.begin(), this->repo.end(), movie);
	if (it == this->repo.end())
	{
		this->repo.push_back(movie);
		this->writeToFile();
		return true;
	}
	return false;

}

bool Controller::removeMovie(std::string name, std::string genre)
{
	Movie movie{ name, genre, 0, 0, "" };
	std::vector<Movie>::iterator it;

	it = find(this->repo.begin(), this->repo.end(), movie);
	if (it != this->repo.end())
	{
		this->repo.erase(it);
		this->writeToFile();
		return true;
	}
	return false;
}

std::string Controller::printMovies() const
{
	std::string result;
	std::vector<Movie>::iterator it;

	if (this->repo.size() == 0)
		throw(RepositoryException{ "No movies in the repo!" });
	else {
		for (it = this->repo.begin(); it != this->repo.end(); it++)
		{
			result += it->toString();
			result += "\n";
		}
		return result;
	}
}

std::string Controller::printSortedMovies() const
{
	std::vector<Movie> repo2 = this->repo;
	std::string result;
	std::vector<Movie>::iterator it;

	if (this->repo.size() == 0)
		throw(RepositoryException{ "No movies in the repo!" });

	sort(repo2.begin(), repo2.end(), [](const Movie& a, const Movie& b) {return a.getName() < b.getName(); });

	for (it = repo2.begin(); it != repo2.end(); it++)
	{
		result += it->toString();
		result += "\n";
	}
	return result;
}

bool Controller::updateMovie(std::string name, std::string genre, int year, int likes, std::string trailer)
{
	Movie movie{ name, genre, year, likes, trailer };
	std::vector<Movie>::iterator it;
	MovieValidator validator;

	try
	{
		validator.validate(movie);
	}
	catch (ValidatorException& e)
	{
		return false;
	}

	it = find(this->repo.begin(), this->repo.end(), movie);
	if (it != this->repo.end())
	{
		this->repo.erase(it);
		this->repo.push_back(movie);
		this->writeToFile();
		return true;
	}
	return false;
}

void Controller::generateListByGenres(std::string genre)
{
	Movie movie2;
	std::vector<Movie>::iterator it;

	this->listByGenres.clear();
	this->countListByGenres = 0;

	for (it = this->repo.begin(); it != this->repo.end(); ++it)
	{
		movie2 = *it;
		if (genre == "" || movie2.getGenre().find(genre) != -1)
			this->listByGenres.push_back(movie2);
	}
}

std::string Controller::printListByGenres()
{
	std::string result;
	std::vector<Movie>::iterator it;

	if (this->listByGenres.size() == 0)
		throw(RepositoryException{ "No movies with this genre!" });
	for (it = this->listByGenres.begin(); it != this->listByGenres.end(); it++)
	{
		result += it->toString();
		result += "\n";
	}
	return result;
}

Movie Controller::trailerOnListByGenre()
{
	Movie result;
	std::vector<Movie>::iterator it;

	if (this->countListByGenres == -1 || this->listByGenres.size() == 0)
		return Movie{};

	result = this->listByGenres[this->countListByGenres];
	ShellExecuteA(NULL, NULL, "chrome.exe", result.getTrailer().c_str(), NULL, SW_SHOWMAXIMIZED);

	return result;
}

void Controller::nextTrailerOnListByGenre()
{
	if (this->countListByGenres == this->listByGenres.size() - 1)
		this->countListByGenres = 0;
	else
		this->countListByGenres += 1;

}

std::string Controller::printWatchlist()
{
	std::string result;
	std::vector<Movie>::iterator it;

	if (this->watchlist.size() == 0)
		return "";
	for (it = this->watchlist.begin(); it != this->watchlist.end(); it++)
	{
		result += it->toString();
		result += "\n";
	}
	return result;
}

void Controller::addToWatchlist()
{
	std::vector<Movie>::iterator it;
	Movie movie2;

	if (this->listByGenres.size() == 0)
		return;

	movie2 = this->listByGenres[this->countListByGenres];
	it = find(this->watchlist.begin(), this->watchlist.end(), movie2);
	if (it == this->watchlist.end())
		this->watchlist.push_back(movie2);
}

void Controller::removeFromWatchlist(std::string name, std::string genre, std::string opinion)
{
	Movie movie{ name, genre, 0, 0, "" };
	std::vector<Movie>::iterator it;

	if (opinion != "like" && opinion != "dislike")
		throw(ControllerException{ "No opinion at all!" });

	it = find(this->watchlist.begin(), this->watchlist.end(), movie);
	if (it == this->watchlist.end())
		return;
	else
	{
		this->watchlist.erase(it);
		it = find(this->repo.begin(), this->repo.end(), movie);
		if (it != this->repo.end())
		{
			movie = *it;
			this->repo.erase(it);
			if (opinion == "like")
				movie.incrementLikes();
			this->repo.push_back(movie);
		}
	}
}

void Controller::writeToFile()
{
	std::ofstream fout("movies.txt");
	std::vector<Movie>::iterator it;

	for (it = this->repo.begin(); it != this->repo.end(); it++)
	{
		fout << *it << "\n";
	}
	fout.close();
}

void Controller::readFromFile()
{
	std::ifstream fin("movies.txt");
	Movie movie{};

	this->repo.clear();

	while (fin >> movie)
	{
		this->repo.push_back(movie);
	}
	fin.close();
}