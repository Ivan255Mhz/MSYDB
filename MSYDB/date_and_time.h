#pragma once
#pragma warning(disable : 4996)

#include<iostream>
#include<chrono>
#include <string>



class date_m
{
    int day;
	int month;
	int year;
	
public:
	date_m() {
		auto now = std::chrono::system_clock::now();
		std::time_t now_c = std::chrono::system_clock::to_time_t(now);
		std::tm* local_time = std::localtime(&now_c);

		year = local_time->tm_year + 1900;
		month = local_time->tm_mon + 1;
		day = local_time->tm_mday;
	}

	date_m(int d, int m, int y) : day{d},month{m},year{y}{}

	
	int get_year() const {
		return year;
	}
	int get_month() const {
		return month;
	}
	int get_day() const {
		return day;
	}

	std::string date_to_string() const {
		return std::to_string(day) + '-' + std::to_string(month) + '-' + std::to_string(year);
	}

	void restart() {
		auto now = std::chrono::system_clock::now();
		std::time_t now_c = std::chrono::system_clock::to_time_t(now);
		std::tm* local_time = std::localtime(&now_c);

		year = local_time->tm_year + 1900;
		month = local_time->tm_mon + 1;
		day = local_time->tm_mday;
	} 

	void set_day(int day) {
		this->day = day;
	}

	void set_month(int month) {
		this->month = month;
	}

	void set_year(int year) {
		this->year = year;
	}
};

class time_m {
	int hours;
	int minutes;
	int seconds;

public:
	time_m() {
		auto now = std::chrono::system_clock::now();
		std::time_t now_c = std::chrono::system_clock::to_time_t(now);
		std::tm* local_time = std::localtime(&now_c);

		hours = local_time->tm_hour;
		minutes = local_time->tm_min;
		seconds = local_time->tm_sec;
	}

	int get_hours() const {
		return hours;
	}

	int get_minutes() const {
		return minutes;
	}

	int get_seconds() const {
		return seconds;
	}
	std::string time_to_string() const {
		return std::to_string(hours) + ':' + std::to_string(minutes) + ':' + std::to_string(seconds);
	}
	void restart() {
		auto now = std::chrono::system_clock::now();
		std::time_t now_c = std::chrono::system_clock::to_time_t(now);
		std::tm* local_time = std::localtime(&now_c);

		hours = local_time->tm_hour;
		minutes = local_time->tm_min;
		seconds = local_time->tm_sec;
	}
};
