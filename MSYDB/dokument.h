#pragma once
#include "date_and_time.h"

class dokument 
{
	std::string tipe;
	std::string name;
	int num;
	date_m date;

public:

	std::string get_tipe() const {
		return tipe;
	}

	std::string get_name() const {
		return name;
	}

	int get_num() const {
		return num;
	}

	std::string get_date() const {
		return date.date_to_string();
	}
};

