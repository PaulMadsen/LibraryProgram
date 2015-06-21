#include "patron.h"

// implementation file for class patron
patron::patron() {
	// used for reading from a file since the other constructor has info we don't have yet! (There is 
	// a better way to do this -- just provide an overload for operator>>, make the default ctor private,
	// but still not an ideal solution. exploring what works best. 
}

patron::patron(std::size_t _id, const std::string& fname, const std::string& lname, type ptype) 
: id{ _id }, first_name{ fname }, last_name{ lname }, patron_type{ptype}
{
	creation_date = date(); // now
}

// Read the patron in from a stream. No error checking! If this explodes, it explodes. I think we can anticipate
// as a pre-condition that the file is in the proper format. 
std::istream& patron::read(std::istream& i) {
	std::string ptype;
	i >> id >> first_name >> last_name >> ptype;
	creation_date.read(i);
	if ("Adult" == ptype)
		patron_type = type::ADULT;
	else patron_type = type::CHILD;
	return i;
}

// write the patron out to a stream.
std::ostream& patron::write(std::ostream& o) {
	// a patron is written out in following format: id first_name last_name patron_type creation_date
	std::string ptype;
	if (type::ADULT == patron_type)
		ptype = "Adult";
	else ptype = "Child";
	o << id << " " << first_name << " " << last_name << " " << ptype << " ";
	creation_date.write(o);
	o << "\n"; // end of record, so we write out a new line 
	return o;
}

// print the patron to a stream using the << operator. This does a nice printout, and is not the same as
// calling write(), which is for saving and restoring objects of type patron. 
std::ostream& operator<<(std::ostream& o, const patron& pat) {
	o << "Id: " << pat.id << " Name: " << pat.first_name << " " << pat.last_name << " Status: ";
	if (pat.patron_type == patron::type::ADULT) {
		o << "Adult";
	}
	else {
		o << "Child";
	}
	o << " Created: " << pat.creation_date;
	return o;
}