#include "library_app.h"

using namespace std;

int main(int argc, char** argv) {
	
	// set up the whole application and run it!
	library_app app("patrons.txt");
	app.run();
	
	return 0;
}