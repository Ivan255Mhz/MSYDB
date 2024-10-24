#pragma once
#include "MedicalRecord.h"
#include <algorithm>


class MedicalRecordManager {
private:
    std::vector<MedicalRecord> records; 
    void sort_records_by_patient_fio() {
        std::sort(records.begin(), records.end(), [](const MedicalRecord& a, const MedicalRecord& b) {
            return a.get_patient_fio() < b.get_patient_fio();
            });
    }

public:
   
    void add_record(const MedicalRecord& record) {
        records.push_back(record);
        sort_records_by_patient_fio();  
    }

   std::string get_all_records_info() const {
        if (records.empty()) {
            return "Нет медицинских записей.\n";
        }

        std::ostringstream all_records_info;
        for (const auto& record : records) {
            all_records_info << record.get_record_info() << "\n";  
        }
        return all_records_info.str();
    }

    
    MedicalRecord* find_record_by_patient_fio(const std::string& fio) {
        for (auto& record : records) {
            if (record.get_patient_fio() == fio) {  
                return &record;
            }
        }
        return nullptr; 
    }

    
    void delete_record_by_patient_fio(const std::string& fio) {
        records.erase(std::remove_if(records.begin(), records.end(),
            [&fio](const MedicalRecord& record) {
                return record.get_patient_fio() == fio;  
            }), records.end());
    }
};
