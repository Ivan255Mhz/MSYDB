#pragma once
#include "date_and_time.h"

class dokument 
{
	int number;
	std::string FIO;
	date_m date;
public:
	
	dokument() {}

	dokument(int num, std::string& FIO, date_m date) {

	}

	int get_number() const {
		return number;
	}

	std::string get_FIO() const {
		return FIO;
	}

	date_m get_date() const {
		return date;
	}

	std::string get_date_str() {
		return date.date_to_string();
	}

	void set_num(int num) {
		number = num;
	}

	void set_FIO(std::string& FIO) {
		this->FIO = FIO;
	}

	void set_date(date_m& date) {
		this->date = date;
	}

	void set_date(int d, int m, int y) {
		date.set_day(d);
		date.set_month(m);
		date.set_year(y);
	}
};

class pasport : public dokument 
{

};