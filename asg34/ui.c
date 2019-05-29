#include "ui.h"

Console createConsole(Controller* controller) {
	Console console;
	console.controller = controller;
	return console;
}

void uiHelp() {
	printf("Available commands: \n");
	printf("1. To add a country enter command: 'add countryName countryContinent countryPopulation'\n");
	printf("2. To delete a country enter command: 'delete countryName' \n");
	printf("3. To update a country enter command: 'update countryName countryContinent countryPopulation' \n");
	printf("4. To search countries that contain a string enter command: 'search string' \n");
	printf("5. To print a country enter command: 'print countryName' \n");
}

void uiAdd(Console* console, char** commands) {
	int result, population;
	population = atoi(commands[3]);
	result = addCountry(console->controller, commands[1], commands[2], population);
	if (result == 0)
		printf("Could not add the element. \n");
	if (result)
		printf("The element was succesfully added. \n");

}

void uiDelete(Console* console, char** commands)
{
	int result;
	
	result = removeElem(console->controller, commands[1]);
	if (result == 0)
		printf("Could not delete the element. \n");
	if (result == 1)
		printf("The element was succesfully deleted. \n");

}


void uiUpdate(Console* console, char**commands) {
	int result, population;
	population = atoi(commands[3]);
	result = updateCountry(console->controller, commands[1], commands[2], population);
	if (result == 0)
		printf("Element was not updated. Maybe it does not even exist. \n");
	if (result)
		printf("The element was succesfully updated. \n");
}

void uiSearch(Console* console, char** commands) {
	char *string;
	string = searchCountry(console->controller, commands[1]);
	if (strcmp(string, "") == 0)
		printf("Not a single country with this name! \n");
	else
		printf(string);
}

void printUi(Console console)
{
	char *string;
	string = str_controller(*(console.controller), "");
}

void start(Console* console) {
	char** commands;
	char *str, *word;
	int words;
	commands = (char**)malloc(sizeof(char*) * 10);
	str = (char*)malloc(sizeof(char) * 1000);
	while (1)
	{
		printf(">> ");
		fgets(str, 1000, stdin);

		for (int i = 0;i < 20;++i)
			commands[i] = (char*)malloc(sizeof(char) * 100);

		words = 0;
		word = strtok(str, " \n\t");
		while (word != NULL)
		{
			strcpy(commands[words], word);
			words++;
			word = strtok(NULL, " \n\t");
		}
		if (words == 1 && strcmp(commands[0], "help") == 0)
			uiHelp();
		else if (words == 1 && strcmp(commands[0], "exit") == 0)
			return;
		else if (words == 4 && strcmp(commands[0], "add") == 0)
			uiAdd(console, commands);
		else if (words == 1 && strcmp(commands[0], "print") == 0)
			printUi(*console);
		else if (words == 2 && strcmp(commands[0], "delete") == 0)
			uiDelete(console, commands);
		else if (words == 4 && strcmp(commands[0], "update") == 0)
			uiUpdate(console, commands);
		else if (words == 2 && strcmp(commands[0], "search") == 0)
			uiSearch(console, commands);
	}
}