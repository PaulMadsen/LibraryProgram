#ifndef LIBRARY_APP
#define LIBRARY_APP

#include <memory>
#include "ui.h" // all menu controls/prompts
#include "date.h"
#include "patron_manager.h"

class library_app {
private:
	// determines if the library app is running. if false,
	// will exit the app
	bool running;
	std::unique_ptr<patron_manager> patron_mgr;
	date time;
public:
	// If the application itself needs resources (say, needs to read in the current
	// date) then do it in the constructor. 
	library_app(const std::string& patron_filename);

	// Application entry point. Equivelent to "main",
	// but I wrapped everything up into a class so we can control the scope
	// easier. If the entire application needs access to something, you can just
	// add it as a private data member, and use it! (avoids the "it's not OOP enough complaint")
	void run();
};

#endif