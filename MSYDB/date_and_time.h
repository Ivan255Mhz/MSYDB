#pragma once
#pragma warning(disable : 4996)

#include<iostream>
#include<chrono>



class date_and_time
{
	int hours;
	int minutes;
	int seconds;

	int day;
	int month;
	int year;

public:
	date_and_time() {
		auto now = std::chrono::system_clock::now();
		std::time_t now_c = std::chrono::system_clock::to_time_t(now);
		std::tm* local_time = std::localtime(&now_c);

		 hours = local_time->tm_hour;
		 minutes = local_time->tm_min;
		 seconds = local_time->tm_sec;

		 year = local_time->tm_year + 1900;
		 month = local_time->tm_mon + 1;
		 day = local_time->tm_mday;
	}

	int get_hours() const {
		return hours;
	}
	int get_minutes() const {
		return minutes;
	}
	int get_seconds()  const {
		return seconds;
	}
	int get_year() const {
		return year;
	}
	int get_month() const {
		return month;
	}
	int get_day() const {
		return day;
	}
};

