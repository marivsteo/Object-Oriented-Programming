#pragma once
#pragma once
#include"Disorder.h"
#include"Repository.h"

class Controller {
private:
	Repository repo;
public:
	std::vector<Disorder> getAllDisorders();
	std::vector<Disorder> getDisorderByName(std::string name);
	std::vector<Disorder> getDisorderByCatOrName(std::string string);
	void loadRepo(std::string filepath);

	Controller();
	~Controller();
};