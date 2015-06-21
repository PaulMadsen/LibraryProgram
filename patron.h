/*
class: patron

purpose: models a patron in the library system. Is able to read and write itself
to files, knows when it is created, and has a few attributes like an id, name, etc. 
*/

#ifndef PATRON_H
#define PATRON_H

#include <string>
#include "serializable.h"
#include "date.h"

class patron : public serializable {
public:
	enum type { ADULT, CHILD };

	// create a new patron. 
	patron(std::size_t id, const std::string& fname, const std::string& lname, type ptype = type::ADULT);
	
	// create an "empty" patron (you would do this only if you intend to read the patron in from a stream
	patron();

	// reading and writing functionality
	std::istream& read(std::istream&);
	std::ostream& write(std::ostream&);

	// useful getters
	inline std::size_t get_id() { return id; }

	// overloaded << for "nice" printing
	friend std::ostream& operator<<(std::ostream& o, const patron& pat);
private:
	std::size_t id;
	std::string first_name;
	std::string last_name;
	type patron_type;
	date creation_date;
};

#endif