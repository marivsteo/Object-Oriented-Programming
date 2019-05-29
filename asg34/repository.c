#include "repository.h"
#include <string.h>

Repository createRepo(int capacity) {
	Repository repo;
	repo.length = 0;
	repo.capacity = capacity;
	repo.array = (TElem*)malloc(capacity * sizeof(TElem));
	return repo;
}

char *str_repository(Repository repo, char* str) {
	char *result, *aux;
	result = (char*)malloc(sizeof(char) * 50 * repo.length);
	aux = (char*)malloc(sizeof(char) * 50);
	memset(result, 0, sizeof(result));
	for (int i = 0;i < repo.length;++i)
	{
		if (strlen(str) == 0 || strstr(repo.array[i].name, str) != NULL || strstr(repo.array[i].continent, str) != NULL)
		{
			aux = countryString(repo.array[i]);
			strcat(result, aux);
		}
	}
	free(aux);
	return result;
}

void destroyRepo(Repository repo) {
	int i;
	for (i = 0;i < repo.length;++i)
	{
		free(repo.array[i].name);
		free(repo.array[i].continent);
	}
	free(repo.array);
}

int add(Repository* repo, TElem elem) {
	if (repo->length + 1 == repo->capacity)
	{
		Country* newArray = (TElem*)malloc((2 * repo->capacity) * sizeof(TElem));
		for (int i = 0;i < repo->length;++i)
		{
			newArray[i] = repo->array[i];
		}
		repo->capacity *= 2;
		for (int i = 0;i < repo->length;++i)
		{
			free(repo->array[i].name);
			free(repo->array[i].continent);
		}
		free(repo->array);
		repo->array = newArray;
	}
	for (int i = 0;i < repo->length;++i)
	{
		if (equals(repo->array[i], elem))
			return 0;
		repo->length += 1;
		repo->array[repo->length - 1] = elem;
		return 1;
	}
}

int removeElem(Repository* repo, char* countryName) {
	for(int i=0;i<repo->length;++i)
		if (strcmp(repo->array[i].name, countryName)==0)
		{
			//free(repo->array[i].name);
			//free(repo->array[i].continent);
			for (int j = i;j < repo->length - 1; ++j)
				repo->array[j] = repo->array[j + 1];
			repo->length -= 1;
			return 1;
		}
	return 0;
}

int updateElem(Repository* repo, char* name, char* continent, long long population) {
	for (int i = 0;i < repo->length;++i)
	{
		if (strcmp(repo->array[i].name, name) == 0)
		{
			strcpy(repo->array[i].continent, continent);
			repo->array[i].population = population;
			return 1;
		}
	}
	return 0;
}

char* searchElem(Repository* repo, char* string) {
	char *str;
	str = (char*)malloc(sizeof(char) * 1000 * repo->length);
	for (int i = 0;i < repo->length;++i)
	{
		if (strstr(repo->array[i].name, string)) {
			strcat(str, countryString(repo->array[i]));
			strcat(str, " \n");
		}
	}
	return *str;
}