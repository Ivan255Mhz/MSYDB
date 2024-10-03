#pragma once
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include "dokument.h"

class MedicalRecord {
private:
    static int record_counter; // ����������� ���������� ��� �������� �������� ������ ������� �������
    int record_number;          // ����� ������� ������� �������
    FIO patient_fio;           // ��� ��������
    date_m date_of_admission;  // ���� �����������
    time_m time_of_admission;  // ����� �����������
    std::string diagnosis;      // �������
    std::vector<std::string> treatments; // ����������

    // ������ ��� �������� ����������
    std::vector<std::shared_ptr<dokument>> documents;

public:
    // ����������� �� ���������
    MedicalRecord() = default;

    // ����������� � �����������
    MedicalRecord(const FIO& fio, const std::string& diag)
        : record_number(++record_counter),
        patient_fio(fio),
        date_of_admission(),
        time_of_admission(),
        diagnosis(diag) {}

    // ����� ��� ���������� �������
    void add_treatment(const std::string& treatment) {
        treatments.push_back(treatment);
    }

    // ����� ��� ���������� ���������
    void add_document(const std::shared_ptr<dokument>& doc) {
        documents.push_back(doc);
    }

    // ����� ��� ��������� ���� ���������� ��� ������
    std::string get_documents_info() const {
        std::string info;
        for (const auto& doc : documents) {
            info += "��������: " + std::to_string(doc->get_num_doc()) + ", ���: " + doc->get_FIO() + ", ���� ������: " + doc->get_date_iss() + "\n";
        }
        return info.empty() ? "��� ����������\n" : info;
    }

    // ����� ��� ��������� ���������� � ��������
    FIO get_patient_fio() const {
        return patient_fio;
    }

    // ����� ��� ��������� ��������
    void set_diagnosis(const std::string& diag) {
        diagnosis = diag;
    }

    // ����� ��� ��������� ������ ������
    std::string record_to_string() const {
        std::string record = "����� ������� �������: " + std::to_string(record_number) + "\n";
        record += "�������: " + patient_fio.get_FIO() + "\n";
        record += "���� �����������: " + date_of_admission.date_to_string() + "\n";
        record += "����� �����������: " + time_of_admission.time_to_string() + "\n";
        record += "�������: " + diagnosis + "\n";
        record += "����������:\n";

        for (const auto& treatment : treatments) {
            record += "- " + treatment + "\n";
        }

        record += "���������:\n" + get_documents_info(); // ��������� ���������� � ����������

        return record;
    }

    // ���������� ��������� ������
    friend std::ostream& operator<<(std::ostream& os, const MedicalRecord& record) {
        os << record.record_to_string();
        return os;
    }
};






