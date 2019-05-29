#pragma once
#pragma once
#include "Comparator.h"
#include"Movie.h"

class ComparatorMovieTitleAscending : public Comparator<Movie> {
public:
	bool compare(const Movie& a, const Movie& b);
};