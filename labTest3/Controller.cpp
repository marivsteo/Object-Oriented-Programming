#include "Controller.h"

std::vector<Disorder> Controller::getAllDisorders()
{
	return repo.getAllDisorders();
}

std::vector<Disorder> Controller::getDisorderByName(std::string name)
{
	return repo.filterByName(name);
}

std::vector<Disorder> Controller::getDisorderByCatOrName(std::string string)
{
	return repo.getDisorderByCatOrName(string);
}

void Controller::loadRepo(std::string filepath)
{
	repo.loadFromFile(filepath);
}

Controller::Controller()
{
}

Controller::~Controller()
{
}
