#include "service.h"

Controller createController(Repository* repo) {
	Controller controller;
	controller.repo = repo;
	return controller;
}

int addCountry(Controller* controller, char* name, char* continent, long long population) {
	char *countryName, *countryContinent;
	countryName = (char*)malloc((strlen(name) + 1) * sizeof(char));
	countryContinent = (char*)malloc((strlen(continent) + 1) * sizeof(char));
	strcpy(countryName, name);
	strcpy(countryContinent, continent);
	Country newCountry = createCountry(countryName, countryContinent, population);
	int result = add(controller->repo, newCountry);
	return result;
}

int deleteCountry(Controller* controller, char* countryName) {
	int result = removeElem(controller->repo, countryName);
	return result;
}

int updateCountry(Controller* controller, char* countryName, char* continent, long long population) {
	int result = updateElem(controller->repo, countryName, continent, population);
	return result;
}

char* searchCountry(Controller* controller, char* name) {
	char *str;
	str = searchElem(controller->repo, name);
	return *str;
}

char *str_controller(Controller controller, char* str) {
	return str_repository(*(controller.repo), str);
}