/*
class: patron_manager

purpose: used by the library_app to interact with patrons. Is responsible for:
1) Reading the patron data in from a file
2) Writing that data out to the file on application exit
3) Providing a way to get a list of all the users on the system
4) Adding users, or deleting them
5) Searching for users
6) Providing user information that might be needed by other functionality (transactions, media, etc)

The patron manager also protects access to patrons. Most objects -- even though they are copies -- 
are marked const, because no system other than the patron manager should be able to make significant changes here. 

*/

#ifndef PATRON_MANAGER_H
#define PATRON_MANAGER_H

#include <map>
#include <vector>
#include <fstream>
#include "patron.h"



class patron_manager {
	// all patrons, once read in, are stored as a map for quick access. 
	std::map<std::size_t, patron> patrons;
public:
	// constructor takes the filename that has all the patrons stored in it
	patron_manager(const std::string& file_name_with_patrons);

	// return a patron with an id. Return value is a pair -- if the boolean value is
	// false, it means that patron does not exist in the system
	std::pair<const patron, bool> get_patron_with_id(std::size_t) const;

	// get a list of all the patrons as a vector.
	std::vector<const patron> get_all_patrons() const;

};

#endif