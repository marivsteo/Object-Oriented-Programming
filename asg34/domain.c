#include <string.h>
#include <corecrt_malloc.h>
#include "domain.h"
#include <stdlib.h>

Country createCountry(char* name, char* continent, int population) {
	Country country;
	country.name = name;
	country.continent = continent;
	country.population = population;
	return country;
}

char* getName(Country* country) {
	return country->name;
}

char *countryString(Country country) {
	char *str;
	char *stringPopulation;
	str = (char*)malloc(sizeof(char) * 100);
	stringPopulation = (char*)malloc(sizeof(char) * 50);
	memset(str, 0, sizeof(str));
	strcpy(str, country.name);
	strcat(str, " ");
	strcat(str, country.continent);
	strcat(str, " ");
	_itoa(country.population, stringPopulation, 10);
	strcat(str, "\n\0");
	free(stringPopulation);
	return str;
}

char* getContinent(Country* country) {
	return country->continent;
}

long long getPopulation(Country* country) {
	return country->population;
}

void setName(Country* country, char* name) {
	strcpy(country->name, name);
}

void setContinent(Country* country, char* continent) {
	strcpy(country->continent, continent);
}

void setPopulation(Country* country, long long population) {
	country->population = population;
}

int equals(Country country, Country country2) {
	if ((country.population == country2.population) && (strcmp(country.name, country2.name) == 0) && strcmp(country.continent, country2.continent) == 0)
		return 1;
	return 0;
}