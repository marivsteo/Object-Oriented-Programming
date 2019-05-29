#include "Repository.h"
#include<fstream>
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

void Repository::addDisorder(Disorder& disorder)
{
	this->disorderList.push_back(disorder);
}

std::vector<Disorder> Repository::getAllDisorders()
{
	return this->disorderList;
}


void Repository::loadFromFile(std::string filepath)
{
	ifstream file(filepath);
	if (!file.is_open()) return;

	Disorder disorder = Disorder();

	while (file >> disorder)
		addDisorder(disorder);

	file.close();
}

std::vector<Disorder> Repository::filterByName(std::string name)
{
	std::vector<Disorder> filteredList;

	for (auto disorder : this->disorderList)
		if (disorder.getName() == name)
			filteredList.push_back(disorder);

	return filteredList;
}

//this function gets all disorders that have a given string as a name or category
//input: a string
//output: a list containing all disorders that were matched
std::vector<Disorder> Repository::getDisorderByCatOrName(std::string string)
{
	std::vector<Disorder> filteredList;

	for (auto disorder : this->disorderList)
		if (disorder.getName() == string || disorder.getCategory() == string)
			filteredList.push_back(disorder);

	return filteredList;
}

Repository::Repository()
{
}

Repository::~Repository()
{
}

void Tests::testGetByNameOrCategory()
{
	Disorder disorder1{  };
	repo.addDisorder(disorder1);

}
