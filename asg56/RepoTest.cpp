#include <assert.h>
#include "Repository.h"
#include "Movie.h"

int repotest() {
	Repository repo;
	repo.addMovie(Movie{ "this1", "comedy", "link1", 2002 });
	repo.addMovie(Movie{ "this2", "comedy", "link2", 2003 });
	Vector<Movie> all = repo.getAll();
	assert(all.size() == 2);

	all.remove(0);

	all[0].setName("Ralph");
	assert(repo[0].getName() != "Ralph");
	repo.incLikes(0);
	assert(repo[0].getLikes() == 1);
	assert(repo.getAll()[0].getLikes() == 1);
	repo.deleteMovie(0);
	assert(repo.getAll().size() == 1);

	assert(!repo.deleteMovie(13));

	assert(repo.changeName(0, "CastAway"));
	assert(!repo.changeName(13, "CastAwayRemake"));

	assert(repo.changeGenre(0, "drama"));
	assert(!repo.changeGenre(13, "drama"));


	assert(repo.changeTrailer(0, "whatALink"));
	assert(!repo.changeTrailer(13, "WhatALink"));

	assert(repo.changeYear(0, 1054));
	assert(!repo.changeYear(13, 1054));

	assert(repo.incLikes(0));
	assert(!repo.incLikes(13));


	std::cout << all << '\n';
	return 0;
}