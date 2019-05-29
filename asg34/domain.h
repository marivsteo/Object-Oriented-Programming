#pragma once

typedef struct {
	char *name;
	char *continent;
	int population;
}Country;

Country createCountry(char *name, char *continent, int population);

char* countryString(Country country);

char* getName(Country *country);

char* getContinent(Country *country);

long long getPopulation(Country * country);

void setName(Country *country, char *name);

void setContinent(Country *country, char *continent);

void setPopulation(Country *country, long long population);

int equals(Country country, Country country2);