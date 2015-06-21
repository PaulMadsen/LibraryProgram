#include "patron_manager.h"

using namespace std;

// constructor reads in all patron objects from the database, and adds them to
// memory
patron_manager::patron_manager(const std::string& file_name_with_patrons) {
	ifstream patron_file(file_name_with_patrons);
	if (patron_file.is_open()) {
		while (!patron_file.eof()) {
			patron p;
			p.read(patron_file);
			if (patron_file.eof()) break;
			// if here, we can insert the patron into our map.
			patrons.insert(std::pair<std::size_t, patron>(p.get_id(), std::move(p)));
		}
	}
	patron_file.close();
}

// get a patron with a particular id if it exists
pair<const patron, bool> patron_manager::get_patron_with_id(std::size_t id) const {
	if (patrons.find(id) == patrons.end()) return pair<patron, bool>(patron(), false);
	return pair<const patron, bool>(patrons.find(id)->second, true);
}

// get all patrons
vector<const patron> patron_manager::get_all_patrons() const {
	vector<const patron> all_patrons;
	for (auto it = patrons.cbegin(); it != patrons.cend(); ++it) {
		all_patrons.push_back(it->second);
	}
	return move(all_patrons);
}