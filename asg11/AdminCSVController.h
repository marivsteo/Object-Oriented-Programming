#pragma once
#pragma once
#ifndef ASG8_9_ADMINCSVCONTROLLER_H
#define ASG8_9_ADMINCSVCONTROLLER_H


#include "AdminController.h"

class AdminCSVController : public AdminController {
public:
	explicit AdminCSVController(MovieRepository& r);

	void show() override;

};


#endif //ASG8_9_ADMINCSVCONTROLLER_H