#include "ValidateMovie.h"

void MovieValidator::validate(Movie& movie)
{
	if (movie.getName().length() == 0)
		throw(ValidatorException{ "Missing name!" });
	if (movie.getGenre().length() == 0)
		throw(ValidatorException{ "Missing genre!" });
	if (movie.getTrailer().length() == 0)
		throw(ValidatorException{ "Missing trailer!" });
	if (movie.getYear() == 0)
		throw(ValidatorException{ "Year of the movie is 0. First movie ever made was in 1888!" });
	if (movie.getLikes() == 0)
		throw(ValidatorException{ "0 likes?!" });
}