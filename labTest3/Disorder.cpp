#include "Disorder.h"
#include<vector>
#include<sstream>
#include<fstream>

std::string Disorder::getCategory()
{
	return this->category;
}

std::string Disorder::getName()
{
	return this->name;
}

std::string Disorder::getSymptoms()
{
	return this->symptoms;
}

Disorder::Disorder(std::string category, std::string name, std::string symptoms)
{
	this->category = category;
	this->name = name;
	this->symptoms = symptoms;
}

std::string Disorder::toString()
{
	std::string info = "";
	info += this->category;
	info += "; ";
	info += this->name;
	info += "; ";
	info += this->symptoms;

	return info;
}

Disorder::Disorder()
{
}

Disorder::~Disorder()
{
}

std::vector<std::string> tokenize(std::string stringToBeRead, char delimiter) {
	std::string token;
	std::vector<std::string> result;
	std::stringstream ss(stringToBeRead);

	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}

std::istream& operator>>(std::ifstream& inputStream, Disorder& disorder) {
	std::string line;
	getline(inputStream, line);

	std::vector<std::string> tokens = tokenize(line, '|');

	if (tokens.size() != 3)
		return inputStream;

	std::string::size_type sizeType;
	disorder.category = tokens[0];
	disorder.name = tokens[1];
	disorder.symptoms = tokens[2];
	return inputStream;
}