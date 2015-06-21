#include "date.h"

date::date() : time_point {time(nullptr)} {}

std::istream& date::read(std::istream& stream) {
	std::string in;
	stream >> in;
	std::istringstream ss(in);
	ss >> time_point;
	return stream;
}

std::string date::to_str() {
	std::stringstream ss;
	ss << time_point;
	return ss.str();
}

std::ostream& date::write(std::ostream& stream) {
	stream << to_str();
	return stream;
}

time_t date::raw() const {
	return time_point;
}

date date::now() {
	return date();
}

date date::in_n_hours(int n) const {
	// get current time as tm
	tm time_buf;
	localtime_s(&time_buf, &time_point);

	// add hours (in terms of seconds)
	time_buf.tm_sec += n * SECONDS_IN_HOUR;
	time_t new_time = mktime(&time_buf);

	// create new time/date and return it
	date new_date;
	new_date.time_point = new_time;
	return new_date;
}

date date::in_n_minutes(int n) const {
	// get current time as tm
	tm time_buf;
	localtime_s(&time_buf, &time_point);

	// add minutes (in terms of seconds)
	time_buf.tm_sec += n * SECONDS_IN_MINUTE;
	time_t new_time = mktime(&time_buf);

	// create new time/date and return it
	date new_date;
	new_date.time_point = new_time;
	return new_date;
}

date date::in_n_days(int n) const {
	// get current time as tm
	tm time_buf;
	localtime_s(&time_buf, &time_point);

	// add days (in terms of seconds)
	time_buf.tm_sec += n * SECONDS_IN_HOUR * HOURS_IN_DAY;
	time_t new_time = mktime(&time_buf);

	// create new time/date and return it
	date new_date;
	new_date.time_point = new_time;
	return new_date;
}

date date::in_n_seconds(int n) const {
	// get current time as tm
	tm time_buf;
	localtime_s(&time_buf, &time_point);

	// add seconds
	time_buf.tm_sec += n;
	time_t new_time = mktime(&time_buf);

	// create new time/date and return it
	date new_date;
	new_date.time_point = new_time;
	return new_date;
}

date date::in_n(int day, int hours, int minutes, int seconds) const {
	date d = *this;
	d = d.in_n_days(day);
	d = d.in_n_hours(hours);
	d = d.in_n_minutes(minutes);
	d = d.in_n_seconds(seconds);
	return d;
}

bool date::operator==(const date& rhs) const {
	return rhs.time_point == time_point;
}

bool date::operator<(const date& rhs) const {
	return time_point < rhs.time_point;
}

bool date::operator>(const date& rhs) const {
	return time_point > rhs.time_point;
}