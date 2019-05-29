#include "ui.h"
#include <crtdbg.h>

int main()
{
	Repository repo = createRepo(100);
	Controller controller = createController(&repo);
	Console console;

	addCountry(&controller, "Mars", "OuterSpace", 4444444444);
	addCountry(&controller, "Atlantis", "Unknown", 33333333333);
	addCountry(&controller, "Hawaii", "Independent", 222222222);
	addCountry(&controller, "Russia", "Europe?", 1111111111);

	console = createConsole(&controller);
	start(&console);

	_CrtDumpMemoryLeaks();

	return 0;
}