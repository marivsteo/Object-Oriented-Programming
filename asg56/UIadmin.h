#pragma once
#include"ControllerAdmin.h"
#include<string>

class UIAdmin {
private:
	ControllerAdmin& cntrl;

	void addMovie();

	void deleteMovie();

	void changeName();

	void changeGenre();

	void changeTrailer();

	void changeYear();

	void displayAll();

public:
	UIAdmin(ControllerAdmin& cntrl);

	void inLoop();
};