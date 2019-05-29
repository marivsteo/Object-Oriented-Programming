#include<assert.h>
#include"ControllerAdmin.h"

int testcontradmin() {
	Repository repo;
	ControllerAdmin c{ repo };

	repo.addMovie(Movie{ "this", "drama", "asdf", 2002 });
	assert(c.getAll().size() == 1);
	c.addMovie("supertramp", "funny", "link", 1919);
	assert(c.getAll().size() == 2);
	assert(c.getAll()[1].getTrailer() == "link");
	c.changeName(0, "notthis");
	assert(c.getAll()[0].getName() == "notthis");
	c.changeGenre(1, "comedy");
	assert(c.getAll()[1].getGenre() == "comedy");
	c.addMovie("aaaa", "bbbb", "cccc", 2020);
	c.changeTrailer(2, "dddd");
	assert(c.getAll()[2].getTrailer() == "dddd");
	c.changeYear(2, 2019);
	assert(c.getAll()[2].getYear() == 2019);
	assert(c.deleteMovie(2));
	assert(!c.changeName(13, "whatever"));
	assert(!c.deleteMovie(13));
	assert(!c.changeTrailer(13, "meh"));

	return 0;
}