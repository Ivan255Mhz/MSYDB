#pragma once
#include "dokument.h"
#include <vector>

class Doctor {
    FIO doctor_fio;
    std::string specialization;
    std::string position;

public:
    Doctor() = default;

    Doctor(const FIO& fio, const std::string& spec, const std::string& pos)
        : doctor_fio(fio), specialization(spec), position(pos) {}

    FIO get_fio() const {
        return doctor_fio;
    }

    std::string get_specialization() const {
        return specialization;
    }

    std::string get_position() const {
        return position;
    }

    std::string doctor_info() const {
        return "Доктор: " + doctor_fio.get_FIO() + ", Специализация: " + specialization + ", Должность: " + position;
    }

    friend std::ostream& operator<<(std::ostream& os, const Doctor& doc) {
        os << doc.doctor_info();
        return os;
    }
};

class DoctorDatabase {
private:
    std::vector<Doctor> doctors;

public:
    
    void add_doctor(const Doctor& doctor) {
        doctors.push_back(doctor);
    }

    
   bool remove_doctor(const FIO& fio) {
        for (auto it = doctors.begin(); it != doctors.end(); ++it) {
            if (it->get_fio() == fio) {
                doctors.erase(it);
                return true;
            }
        }
        return false; 
    }

   
   Doctor* find_doctor(const FIO& fio) {
       for (auto& doctor : doctors) {
           if (doctor.get_fio() == fio) {
               return &doctor;  
           }
       }
       return nullptr;  
   }

    
    void print_all_doctors() const {
        if (doctors.empty()) {
            std::cout << "Нет докторов в базе данных.\n";
            return;
        }

        for (const auto& doctor : doctors) {
            std::cout << doctor << "\n";
        }
    }

    
};