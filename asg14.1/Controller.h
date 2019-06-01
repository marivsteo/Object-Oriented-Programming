#pragma once
#pragma once

#include "Movie.h"
#include "ValidateMovie.h"
#include "Exceptions.h"
#include "undoAction.h"
#include <string>
#include <Windows.h>
#include <shellapi.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include "UndoAction.h"

class Controller
{
protected:
	std::vector<Movie>& repo;
	std::vector<Movie> watchlist;
	std::vector<Movie> listByGenres;
	int countListByGenres;
	std::vector<std::unique_ptr<UndoRedoAction>> undoRedoActions;
	int currentActionPosition;

public:
	Controller(std::vector<Movie>& repo);

	void deleteRedo();


	bool addMovie(std::string name, std::string genre, int year, int likes, std::string trailer);

	bool removeMovie(std::string name, std::string genre);

	std::string printMovies() const;

	std::string printSortedMovies() const;

	bool updateMovie(std::string name, std::string genre, int year, int likes, std::string trailer);

	void generateListByGenres(std::string genre);

	std::string printListByGenres();

	Movie trailerOnListByGenre();

	std::string printWatchlist();

	void addToWatchlist();

	void removeFromWatchlist(std::string name, std::string genre, std::string opinion);

	void readFromFile();

	bool undo();

	bool redo();

	void undoLastAction();

	void writeToFile();

	void nextTrailerOnListByGenre();
};