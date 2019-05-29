#pragma once
#include"ControllerUser.h"

class UIUser {
private:
	ControllerUser& c;

	void moviesByGenre();

	void nextMovie();

	void getDetails();

	void addToWatchlist();

	void removeWatchlist();

	void getWatchlist();

	void play();

public:

	UIUser(ControllerUser& cntrl);

	void inLoop();
};