#include <assert.h>
#include "DynVector.h"
#include "Movie.h"


int movietest() {
	Movie movie{ "GetOit", "Fantasy", "niceLink", 2017 };
	Movie movie1{ "", "Fantasy", "", -1 };
	Movie movie2{ "", "", "", -1 };

	Movie movie3 = movie;
	movie3 = Movie(movie);
	assert(movie == movie3);
	assert(movie == movie1);

	std::cout << movie3;

	movie3.setName("whatever");
	movie3.setGenre("nice");
	movie3.setYear(2012);
	movie3.setTrailer("notrailer");

	assert(movie3.getName() != movie.getName());
	assert(movie3.getYear() == 2012);
	assert(movie3.getTrailer() == "notrailer");
	assert(movie3.getGenre() == "nice");

	movie.setLikes(13);
	assert(movie.getLikes() == 13);
	assert(movie == movie1);
	assert(movie == movie2);
	++movie;
	++movie;
	assert(movie.getLikes() == 15);
	movie++;
	assert(movie.getLikes() == 16);

	return 0;
}