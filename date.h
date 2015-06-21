/*
	class: date
	
	purpose: a wrapper around <ctime> construct time_t
	which simplifies handling dates, reading and writing them to a stream (generally file)
	and has a "nice" output format to cout (MM/DD/YYYY). 
*/

#ifndef DATE_H
#define DATE_H

#include <ctime>
#include <iosfwd>
#include <sstream> // used for writing / reading to streams
#include "serializable.h"

class date : public serializable {
	// internal representation of time (platform dependent)
	time_t time_point;

	// Handy constants to help in generating new times
	const static std::size_t SECONDS_IN_HOUR = 3600;
	const static std::size_t SECONDS_IN_MINUTE = 60;
	const static std::size_t HOURS_IN_DAY = 24;
	const static std::size_t YEAR_SINCE_EPOCH = 1900;
	std::string to_str();
public:
	// default construction produces a date with the current time. 
	date();

	// read from a stream the time (as a string) -- the string must
	// be in the format used to write it out.
	std::istream& read(std::istream& stream);

	// write to a stream the time (as a string). Meant for file io/serialization
	std::ostream& write(std::ostream& stream);

	// get the raw time_t value used by the class in case you want to do something
	// this class can't do!
	time_t raw() const;

	// return a new date object (same as the constructor call)
	static date now();

	// present a human readable version of the date (MM/DD/YYYY - HH MM format)
	friend std::ostream& operator<<(std::ostream& o, const date& d) {
		std::ostringstream ss;
		tm time_buf;
		localtime_s(&time_buf, &d.time_point);
		ss << 1 + time_buf.tm_mon << "/" << time_buf.tm_mday << "/" << 1900 + time_buf.tm_year << " - " << time_buf.tm_hour << " hr " << time_buf.tm_min << " min";
		o << ss.str();
		return o;
	}

	// returns a new date object that is n hours from the date the function is run on. 
	// ex:  date two_hours_later = d.in_n_hours(2); 
	//		date two_hours_ago = d.in_n_hours(-2);
	date in_n_hours(int n) const;

	// returns a new date object that is n days from the date the function is run on. 
	date in_n_days(int n) const;

	// returns a new date object that is n minutes from the date the function is run on.
	date in_n_minutes(int n) const;

	// returns a new date object that is n seconds from the date the function is run on. 
	date in_n_seconds(int n) const;

	// amalgam of in_n series of functions
	date in_n(int day, int hours = 0, int minutes = 0, int seconds = 0) const;

	// comparison operator overloads
	bool operator==(const date& rhs) const;
	bool operator<(const date& rhs) const;
	bool operator>(const date& rhs) const;
};

#endif