/*
class: serializable

purpose: an interface for types that need to be able to write themselves to streams, 
and read in from streams. 
*/

#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <iosfwd>

class serializable {
public:
	virtual std::istream& read(std::istream&) = 0;
	virtual std::ostream& write(std::ostream&) = 0;
};

#endif