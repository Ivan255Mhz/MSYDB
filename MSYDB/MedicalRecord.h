#pragma once
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include "dokument.h"

class MedicalRecord {
private:
    static int record_counter; // Статическая переменная для хранения текущего номера истории болезни
    int record_number;          // Номер текущей истории болезни
    FIO patient_fio;           // ФИО пациента
    date_m date_of_admission;  // Дата поступления
    time_m time_of_admission;  // Время поступления
    std::string diagnosis;      // Диагноз
    std::vector<std::string> treatments; // Назначения

    // Вектор для хранения документов
    std::vector<std::shared_ptr<dokument>> documents;

public:
    // Конструктор по умолчанию
    MedicalRecord() = default;

    // Конструктор с параметрами
    MedicalRecord(const FIO& fio, const std::string& diag)
        : record_number(++record_counter),
        patient_fio(fio),
        date_of_admission(),
        time_of_admission(),
        diagnosis(diag) {}

    // Метод для добавления лечения
    void add_treatment(const std::string& treatment) {
        treatments.push_back(treatment);
    }

    // Метод для добавления документа
    void add_document(const std::shared_ptr<dokument>& doc) {
        documents.push_back(doc);
    }

    // Метод для получения всех документов как строки
    std::string get_documents_info() const {
        std::string info;
        for (const auto& doc : documents) {
            info += "Документ: " + std::to_string(doc->get_num_doc()) + ", ФИО: " + doc->get_FIO() + ", Дата выдачи: " + doc->get_date_iss() + "\n";
        }
        return info.empty() ? "Нет документов\n" : info;
    }

    // Метод для получения информации о пациенте
    FIO get_patient_fio() const {
        return patient_fio;
    }

    // Метод для установки диагноза
    void set_diagnosis(const std::string& diag) {
        diagnosis = diag;
    }

    // Метод для получения строки записи
    std::string record_to_string() const {
        std::string record = "Номер истории болезни: " + std::to_string(record_number) + "\n";
        record += "Пациент: " + patient_fio.get_FIO() + "\n";
        record += "Дата поступления: " + date_of_admission.date_to_string() + "\n";
        record += "Время поступления: " + time_of_admission.time_to_string() + "\n";
        record += "Диагноз: " + diagnosis + "\n";
        record += "Назначения:\n";

        for (const auto& treatment : treatments) {
            record += "- " + treatment + "\n";
        }

        record += "Документы:\n" + get_documents_info(); // Добавляем информацию о документах

        return record;
    }

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const MedicalRecord& record) {
        os << record.record_to_string();
        return os;
    }
};






