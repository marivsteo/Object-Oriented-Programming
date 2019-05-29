#include<assert.h>
#include"DynVector.h"
#include"Movie.h"
#include<iostream>

int dynvecttest() {
	Vector<int> v;
	int a = 35;
	for (int i = 0; i < 200; i++)
		v.addElem(i);
	assert(v[33] == 33);
	assert(v.size() == 200);
	v.remove(22);
	assert(v[22] == 23);
	v.remove(54);
	v.remove(14);
	assert(v.size() == 197);

	v = v + a;
	assert(v[198] == 35);

	Vector<Movie> movies;
	movies.addElem(Movie{ "unu","unu","unu",2019 });
	movies.addElem(Movie{ "doi","doi","doi",2018 });
	movies.addElem(Movie{ "trei","trei","trei",2017 });
	movies.addElem(Movie{ "patru","patru","patru",2016 });
	movies.remove(1);
	assert(movies.size() == 3);
	movies.remove(1);
	assert(movies.size() == 2);
	return 0;

}
