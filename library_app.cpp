#include "library_app.h"

// implementation file for class library_app 

library_app::library_app(const std::string& patron_filename) 
: running{ true }, patron_mgr{ new patron_manager(patron_filename) }
{}

void library_app::run() {
	
	// show main menu and handle the user options
	while (running) { // equivelent to our applications "main"

		ui::display_menu(time);
		switch (ui::get_menu_selected()) {
		case ui_option::EXIT:
			ui::display_goodbye();
			running = false;
			break;
		case ui_option::SHOW_ALL_PATRONS:
			// not implemented yet!
			ui::display_all_patrons(patron_mgr);
			break;
		case ui_option::ADVANCE_TIME:
			int d, h, m;
			ui::prompt_for_time_advance(d, h, m);
			ui::display_advance(d, h, m);
			time = time.in_n(d, h, m);
			break;
		case ui_option::INVALID:
			ui::bad_selection();
			break;
		}
		
		// gets rid of previously printed menu screen
		ui::clear();
	}
}
