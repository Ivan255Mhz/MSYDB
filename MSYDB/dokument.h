#pragma once
#include "date_and_time.h"

class FIO{
	std::string surname;
	std::string name;
	std::string patronymic;
public:
   FIO() : surname{ "" }, name{ "" }, patronymic{ "" } {}

   FIO(const std::string &sname, const  std::string &name, const std::string &patr) : surname{sname}, name{name},patronymic{patr}{}

   std::string get_FIO() const {
	   return surname + " " + name + " " + patronymic;
   }

   void set_suname(const std::string& suname) {
	   surname = suname;
   }

   void set_name(const std::string& name) {
	   this->name = name;
   }

   void set_patro(const std::string& patro) {
	   patronymic = patro;
   }

   std::string get_sumane() const {
	   return surname;
   }

   std::string get_name() const {
	   return name;
   }

   std::string get_patro() const {
	   return patronymic;
   }

   bool operator==(const FIO& other) const {
	   return surname == other.surname && name == other.name && patronymic == other.patronymic;
   }

   bool operator!=(const FIO& other) const {
	   return !(*this == other);
   }

   friend std::ostream& operator<<(std::ostream& os, const FIO& fio) {
	   os << fio.surname << " " << fio.name << " " << fio.patronymic;
	   return os;
   }

};

class dokument {
protected:

	int num_dokument{};
	FIO fio_huuman;
	date_m date_of_issue;
	
public:

	dokument() = default;

    dokument(int num, const  FIO &fio, const date_m &date) : num_dokument{num}, fio_huuman{fio}, date_of_issue{date}{}

	virtual int get_num_doc() const = 0;

	virtual std::string get_FIO() const = 0;

	virtual std::string get_date_iss() const = 0;

	
};

class pasport : public dokument {
public:
	pasport(int num, const FIO& fio, const date_m& date)
		: dokument(num, fio, date) {}

	int get_num_doc() const override {
		return num_dokument;
	}

	std::string get_FIO() const override {
		return fio_huuman.get_FIO();
	}

	std::string get_date_iss() const override {
		return date_of_issue.date_to_string();
	}
};

class polis : public dokument {
public:
	polis(int num, const FIO& fio, const date_m& date)
		: dokument(num, fio, date) {}

	int get_num_doc() const override {
		return num_dokument;
	}

	std::string get_FIO() const override {
		return fio_huuman.get_FIO();
	}

	std::string get_date_iss() const override {
		return date_of_issue.date_to_string();
	}
};

class snils : public dokument {
public:
	snils(int num) : dokument(num, FIO(), date_m()) {}

	int get_num_doc() const override {
		return num_dokument;
	}

	std::string get_FIO() const override {
		return "Нет данных";
	}

	std::string get_date_iss() const override {
		return "Нет даты";
	}
};