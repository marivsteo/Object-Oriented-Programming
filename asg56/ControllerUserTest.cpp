#include<assert.h>
#include"Repository.h"
#include"ControllerUser.h"

int contrusertest() {
	Repository repo;
	repo.addMovie(Movie{ "this1","comedy", "https://youtu.be/BkL9l7qovsE", 1912 });
	repo.addMovie(Movie{ "this2","comedy", "https://youtu.be/6hB3S9bIaco", 1921 });
	repo.addMovie(Movie{ "this3","comedy", "https://youtu.be/OXrcDonY-B8", 1943 });
	ControllerUser c{ repo };
	c.storeGenre("comedy");
	assert(c.getQuery().size() == 3);
	for (int i = 0; i < 3; i++)
		c.nextMovie();
	Movie movie = c.getDetails();
	assert(movie.getName() == "this1");

	c.addToWatchlist();
	assert(c.getWatchlist()[0].getName() == "this1");

	c.storeGenre("comedy");
	assert(c.getQuery().size() == 2);

	c.removeWatchlist(0, 1);
	c.storeGenre("comedy");
	assert(c.getQuery()[0].getLikes() == 1);
	return 0;
}