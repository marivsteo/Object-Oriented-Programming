#pragma once
#include "Movie.h"
#include<vector>

class UndoRedoAction
{
public:
	virtual ~UndoRedoAction();
	virtual void executeUndo() = 0;
	virtual void executeRedo() = 0;
};

class UndoRedoAdd : public UndoRedoAction
{
private:
	Movie addedMovie;
	std::vector<Movie>& repository;

public:
	UndoRedoAdd(Movie movie, std::vector<Movie>& repo);
	void executeUndo();
	void executeRedo();
};

class UndoRedoDelete : public UndoRedoAction
{
private:
	Movie deletedMovie;
	std::vector<Movie>& repository;

public:
	UndoRedoDelete(Movie movie, std::vector<Movie>& repo);
	void executeUndo();
	void executeRedo();
};

class UndoRedoUpdate : public UndoRedoAction
{
private:
	Movie oldMovie, newMovie;
	std::vector<Movie>& repository;

public:
	UndoRedoUpdate(Movie movie1, Movie movie2, std::vector<Movie>& repo);
	void executeUndo();
	void executeRedo();
};