#include "UndoAction.h"

UndoRedoAdd::UndoRedoAdd(Movie movie, std::vector<Movie>& repo) : repository(repo)
{
	this->addedMovie = movie;
}

void UndoRedoAdd::executeUndo()
{
	//this->repository.deleteMovie(this->addedMovie);
	auto movieIterator = std::find(this->repository.begin(), this->repository.end(), addedMovie);

	if (movieIterator != this->repository.end())
	{
		this->repository.erase(movieIterator);
	}

}

void UndoRedoAdd::executeRedo()
{
	//this->repository.addMovie(this->addedMovie);
	this->repository.push_back(addedMovie);
}

UndoRedoDelete::UndoRedoDelete(Movie movie, std::vector<Movie>& repo) : repository(repo)
{
	this->deletedMovie = movie;
}

void UndoRedoDelete::executeUndo()
{
	//this->repository.addMovie(this->deletedMovie);
	this->repository.push_back(deletedMovie);
}

void UndoRedoDelete::executeRedo()
{
	//this->repository.deleteMovie(this->deletedMovie);
	auto movieIterator = std::find(this->repository.begin(), this->repository.end(), deletedMovie);

	if (movieIterator != this->repository.end())
	{
		this->repository.erase(movieIterator);
	}
}

UndoRedoAction::~UndoRedoAction()
{
}

UndoRedoUpdate::UndoRedoUpdate(Movie movie1, Movie movie2, std::vector<Movie>& repo) : repository(repo)
{
	this->oldMovie = movie1;
	this->newMovie = movie2;
}

void UndoRedoUpdate::executeUndo()
{
	//this->repository.updateMovie(this->oldMovie);
	auto movieIterator = std::find(this->repository.begin(), this->repository.end(), oldMovie);

	if (movieIterator != this->repository.end())
	{
		this->repository.at(movieIterator - this->repository.begin()) = oldMovie;
	}
}

void UndoRedoUpdate::executeRedo()
{
	//this->repository.updateMovie(this->newMovie);
	auto movieIterator = std::find(this->repository.begin(), this->repository.end(), newMovie);

	if (movieIterator != this->repository.end())
	{
		this->repository.at(movieIterator - this->repository.begin()) = newMovie;
	}
}
