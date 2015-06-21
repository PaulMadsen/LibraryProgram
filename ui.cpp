#include "ui.h"

// implementation file for class ui

using namespace std;

// the main menu
void ui::display_menu(const date& time) {
	// small menu to get started here...
	cout << "Library Menu\n";
	cout << "-------------------------------------------\n";
	cout << "The time is: " << time << "\n";
	cout << "-------------------------------------------\n";
	cout << "1) List all patrons\n";
	cout << "2) Advance time" << endl;
	cout << "3) Exit" << endl;
}

// pauses and then clears the screen. If anyone is interested, it'd
// be nice to redo this segment in a way that uses actual C++ code to the same thing,
// since this is non-standard functionality
void ui::clear() {
	system("pause");
	system("cls");
}

// show all patrons -- the data for this is passed in by the library_app class
// which has access to the patron manager. This is a common strategy I have used up
// to this point; the library_app simply delegates work, and recieves work from all the
// other components in the program. 
void ui::display_all_patrons(const std::unique_ptr<patron_manager>& pm) {
	cout << "\nAll patrons: " << endl;
	cout << "-------------------------------------------\n";
	vector<const patron> p = pm->get_all_patrons();
	for (const patron& patron : p) {
		cout << patron << endl;
	}
}

// Prompts involved in getting the desired time advancement from the user, and informing them
void ui::prompt_for_time_advance(int& d, int& h, int& m) {
	cout << "Please enter time advance values (format: d h m): ";
	cin >> d >> h >> m;
}

void ui::display_advance(int d, int h, int m) {
	cout << "Advancing time by " << d << " day(s), " << h << " hour(s), and " << m << " minutes" << endl;
}

void ui::display_goodbye() {
	cout << "Thanks for using the library software! Exiting..." << endl;
}

void ui::bad_selection() {
	cout << "Sorry, the selection you made was invalid" << endl;
}

ui_option ui::get_menu_selected() {
	// prompts the user for input and returns
	// their selection to be handled
	cout << "Select: ";
	int selection;
	cin >> selection;
	if (cin) {
		if (ui_option::EXIT == selection)
			return ui_option::EXIT;
		else if (ui_option::SHOW_ALL_PATRONS == selection)
			return ui_option::SHOW_ALL_PATRONS;
		else if (ui_option::ADVANCE_TIME == selection)
			return ui_option::ADVANCE_TIME;
		else return ui_option::INVALID;
	}
	else {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return ui_option::INVALID;
	}
}