#pragma once
#include<string>

class Disorder {
private:
	std::string category;
	std::string name;
	std::string symptoms;

public:
	std::string getCategory();
	std::string getName();
	std::string getSymptoms();

	Disorder(std::string category, std::string name, std::string symptoms);
	std::string toString();
	Disorder();
	~Disorder();


	friend std::istream& operator>>(std::ifstream& inputStream, Disorder& disorder);
};