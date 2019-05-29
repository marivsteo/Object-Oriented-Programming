#pragma once
#include "domain.h"
#include<stdlib.h>

typedef Country TElem;
typedef struct {
	int length;
	int capacity;
	TElem *array;
}Repository;

Repository createRepo(int capacity);

void destroyRepo(Repository repo);

char *str_repository(Repository repo, char *str);

int add(Repository *repo, TElem elem);

int removeElem(Repository *repo, char* countryName);

int updateElem(Repository *repo, char *countryName, char *continent, long long population);