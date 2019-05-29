#pragma once
#pragma once
#include"Disorder.h"
#include<vector>
#include<assert.h>

class Repository {
private:
	std::vector<Disorder> disorderList;

public:

	void addDisorder(Disorder& disorder);
	std::vector<Disorder> getAllDisorders();
	void loadFromFile(std::string filepath);
	std::vector<Disorder> filterByName(std::string name);
	std::vector<Disorder> getDisorderByCatOrName(std::string string);

	Repository();
	~Repository();
};

class Tests {
private:
	Repository repo;
public:
	void testGetByNameOrCategory();
};