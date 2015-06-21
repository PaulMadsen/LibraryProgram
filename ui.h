/*
class: ui

purpose: provides every kind of "user interface" prompt. This includes recieving input from
the user and providing it to the library_app to process in meaningful ways. Also recieves requests
from the library app to print data back to the user. In general, if you're adding in a new feature which
the user will directly interact with, you'll want to provide a few functions here so you can keep things
organized. Most calls here are *static*, so the library_app doesn't have an instance of this. 
*/

#ifndef UI_MENU_SYSTEM
#define UI_MENU_SYSTEM

#include <iostream>
#include <memory>
#include <vector>
#include "patron.h"
#include "patron_manager.h"
#include "date.h"

/*
	note: I have a ui_option enum I use, but I can anticipate that there could
	be many more such types of options (for example, and option that holds a user id and book id
	values, recieved by the UI and sent to the manager classes. Feel free to add as many as needed.
*/

enum ui_option {
	/*
		For reference:
		1) List all patrons
		2) Advance time
		3) Exit

		The order here does matter when we process the input
	*/
	SHOW_ALL_PATRONS = 1,
	ADVANCE_TIME,
	EXIT,
	INVALID
	// TODO: Many more options!
};

class ui {
public:
	// Displays the main menu to the user as a text prompt
	static void display_menu(const date& time);

	// Prompts for, recieves, and returns the selected input as a ui_option
	// for processing in run()
	static ui_option get_menu_selected();
	
	// called when the program exits
	static void display_goodbye();

	// lets the user know their input was bad (ex: entering 'k' when an integer was expected)
	static void bad_selection();

	// prompts to show all patrons
	static void display_all_patrons(const std::unique_ptr<patron_manager>& p);

	// prompts involving time advancement in the program
	static void prompt_for_time_advance(int& d, int& h, int& m);
	static void display_advance(int d, int h, int m);

	// clears the main menu so we can redraw it
	static void clear();
};

#endif