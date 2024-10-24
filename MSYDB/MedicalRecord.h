#pragma once
#include "dokument.h"
#include "apteka.h"
#include "doctor.h"
#include <iomanip>
#include <sstream>



class Patient {
private:
    FIO patient_fio;
    date_m date_of_birth;

public:
    Patient() = default;

    Patient(const FIO& fio, const date_m& dob)
        : patient_fio(fio), date_of_birth(dob) {}

    std::string get_fio() const {
        return patient_fio.get_FIO();
    }

    date_m get_birth_date() const {
        return date_of_birth;
    }
};

class Prescription {
private:
    std::shared_ptr<Medication> medication;
    std::string dosage_instructions;

public:
    Prescription(const std::shared_ptr<Medication>& med, const std::string& dosage)
        : medication(med), dosage_instructions(dosage) {}

    std::shared_ptr<Medication> get_medication() const {
        return medication;
    }

    std::string get_prescription_info() const {
        return medication->get_info() + ", ���������� �� ���������: " + dosage_instructions;
    }
};

class DocumentManager {
private:
    std::vector<std::shared_ptr<dokument>> documents;

public:
    void add_document(const std::shared_ptr<dokument>& doc) {
        documents.push_back(doc);
    }

    std::string get_documents_info() const {
        std::string info;
        for (const auto& doc : documents) {
            info += "��������: " + std::to_string(doc->get_num_doc()) + ", ���: " + doc->get_FIO() + ", ���� ������: " + doc->get_date_iss() + "\n";
        }
        return info.empty() ? "��� ����������\n" : info;
    }
};

class Diagnosis {
private:
    std::string diagnosis;
    date_m diagnosis_date;

public:
    Diagnosis() = default;

    Diagnosis(const std::string& diag, const date_m& date)
        : diagnosis(diag), diagnosis_date(date) {}

    std::string get_diagnosis_info() const {
        return "�������: " + diagnosis + ", ����: " + diagnosis_date.date_to_string();
    }
};

class MedicalRecord {
private:
    static int record_counter;  
    int record_number;  
    Patient patient;  
    Diagnosis diagnosis;  
    Pharmacy pharmacy;  
    DocumentManager documents;  
    Doctor assigned_doctor;  

public:
    MedicalRecord() = default;

    
    MedicalRecord(const Patient& p, const Diagnosis& d)
        : record_number(++record_counter), patient(p), diagnosis(d) {}

    
    void add_prescription(const std::shared_ptr<Prescription>& prescription) {
        pharmacy.add_medication(prescription->get_medication());
    }

    
    void add_document(const std::shared_ptr<dokument>& doc) {
        documents.add_document(doc);
    }

    std::string get_patient_fio() const {
        return patient.get_fio();
    }
   
    void assign_doctor(const Doctor& doctor) {
        assigned_doctor = doctor;
    }

    
    std::string get_record_info() const {
        std::ostringstream record;

        record << "------------------------------------------------------------\n";
        record << "| " << std::setw(15) << "����� ������" << "| " << std::setw(30) << record_number << "|\n";
        record << "------------------------------------------------------------\n";
        record << "| " << std::setw(15) << "�������" << "| " << std::setw(30) << patient.get_fio() << "|\n";
        record << "------------------------------------------------------------\n";
        record << "| " << std::setw(15) << "�������" << "| " << std::setw(30) << diagnosis.get_diagnosis_info() << "|\n";
        record << "------------------------------------------------------------\n";
        record << "| " << std::setw(15) << "������" << "| " << std::setw(30) << assigned_doctor.doctor_info() << "|\n";
        record << "------------------------------------------------------------\n";

        
        record << "| " << std::setw(15) << "���������" << "|\n";
        record << "------------------------------------------------------------\n";
        if (!pharmacy.get_medications_info().empty()) {
            record << "| " << std::setw(15) << "��������" << "| " << std::setw(30) << "���������" << "|\n";
            record << pharmacy.get_medications_info();  
        }
        else {
            record << "| ��� ����������� ��������                          |\n";
        }
        record << "------------------------------------------------------------\n";

        // ����� ���������� � ����������
        record << "| " << std::setw(15) << "���������" << "|\n";
        record << "------------------------------------------------------------\n";
        if (!documents.get_documents_info().empty()) {
            record << "| " << std::setw(15) << "��������" << "| " << std::setw(30) << "���" << "|\n";
            record << documents.get_documents_info();  
        }
        else {
            record << "| ��� ����������                                    |\n";
        }
        record << "------------------------------------------------------------\n";

        return record.str();
    }
};





