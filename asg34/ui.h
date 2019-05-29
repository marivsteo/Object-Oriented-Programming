#pragma once
#include "service.h"
#include "stdio.h"

typedef struct {
	Controller *controller;
}Console;

Console createConsole(Controller *controller);

void start(Console *console);