#pragma once
#include "dokument.h"
class Doctor {
    FIO doctor_fio;
    std::string specialization;
    std::string position;

public:
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

