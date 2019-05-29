#pragma once
#include "repository.h"
#include "string.h"

typedef struct {
	Repository *repo;
}Controller;

Controller createController(Repository *repo);

int addCountry(Controller *controller, char *name, char *continent, long long population);

char *str_controller(Controller controller, char *str);