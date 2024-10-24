#include <iostream>
#include "Men.h"
#include "doctor.h"
#include <Windows.h>

/******************************************************************************
*                                                                             *
*     M       M    SSSSSSSS     Y       Y     DDDDDD       BBBBBBB            *
*     MM     MM    S             Y     Y      D     D      B      B           *
*     M M   M M     SSSSSSS       Y   Y       D      D     BBBBBBB            *
*     M  M M  M            S       Y Y        D     D      B      B           *
*     M   M   M     SSSSSSSS        Y         DDDDDD       BBBBBBB            *
*                                                                             *
******************************************************************************/

void display_main_menu() {
    std::cout << "\n==== Меню системы медицинских записей ====\n";
    std::cout << "    1. Добавить новую медицинскую запись\n";
    std::cout << "    2. Просмотреть все медицинские записи\n";
    std::cout << "    3. Найти запись по ФИО пациента\n";
    std::cout << "    4. Удалить запись по ФИО пациента\n";
    std::cout << "    5. Управление врачами\n";
    std::cout << "    6. Выйти\n";
    std::cout << "Выберите опцию: ";
}

void display_doctor_menu() {
    std::cout << "\n==== Меню управления врачами ====\n";
    std::cout << "       1. Добавить врача\n";
    std::cout << "       2. Удалить врача\n";
    std::cout << "       3. Просмотреть всех врачей\n";
    std::cout << "       4. Назначить врача пациенту\n";
    std::cout << "       5. Вернуться в главное меню\n";
    std::cout << "          Выберите опцию: ";
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    MedicalRecordManager record_manager;
    DoctorDatabase doctor_database;
    int option;

    do {
        display_main_menu();
        std::cin >> option;

        switch (option) {
        case 1: {
            // Добавление новой медицинской записи
            std::string fio, diagnosis;
            int day, month, year;
            std::cout << "Введите ФИО пациента: ";
            std::cin.ignore();
            std::getline(std::cin, fio);

            std::cout << "Введите диагноз: ";
            std::getline(std::cin, diagnosis);

            std::cout << "Введите дату рождения пациента (день месяц год): ";
            std::cin >> day >> month >> year;

            Patient patient(FIO(fio, "", ""), date_m(day, month, year));
            Diagnosis diag(diagnosis, date_m());
            MedicalRecord record(patient, diag);

            record_manager.add_record(record);
            std::cout << "Медицинская запись добавлена!\n";
            break;
        }
        case 2:
            // Просмотр всех медицинских записей
            std::cout << record_manager.get_all_records_info();
            break;
        case 3: {
            // Поиск записи по ФИО пациента
            std::string fio;
            std::cout << "Введите ФИО пациента: ";
            std::cin.ignore();
            std::getline(std::cin, fio);
            MedicalRecord* record = record_manager.find_record_by_patient_fio(fio);
            if (record) {
                std::cout << record->get_record_info();
            }
            else {
                std::cout << "Запись не найдена.\n";
            }
            break;
        }
        case 4: {
            // Удаление записи по ФИО пациента
            std::string fio;
            std::cout << "Введите ФИО пациента для удаления: ";
            std::cin.ignore();
            std::getline(std::cin, fio);
            record_manager.delete_record_by_patient_fio(fio);
            std::cout << "Запись удалена (если существовала).\n";
            break;
        }
        case 5: {
            int doctor_option;
            do {
                display_doctor_menu();
                std::cin >> doctor_option;

                switch (doctor_option) {
                case 1: {
                    // Добавить врача
                    std::string doctor_fio, specialization, position;
                    std::cout << "Введите ФИО врача: ";
                    std::cin.ignore();
                    std::getline(std::cin, doctor_fio);

                    std::cout << "Введите специализацию врача: ";
                    std::getline(std::cin, specialization);

                    std::cout << "Введите должность врача: ";
                    std::getline(std::cin, position);

                    Doctor doctor(FIO(doctor_fio, "", ""), specialization, position);
                    doctor_database.add_doctor(doctor);
                    std::cout << "Врач добавлен!\n";
                    break;
                }
                case 2: {
                    // Удалить врача
                    std::string doctor_fio;
                    std::cout << "Введите ФИО врача для удаления: ";
                    std::cin.ignore();
                    std::getline(std::cin, doctor_fio);

                    if (doctor_database.remove_doctor(FIO(doctor_fio, "", ""))) {
                        std::cout << "Врач удален.\n";
                    }
                    else {
                        std::cout << "Врач не найден.\n";
                    }
                    break;
                }
                case 3:
                    // Просмотреть всех врачей
                    doctor_database.print_all_doctors();
                    break;
                case 4: {
                    // Назначить врача пациенту
                    std::string patient_fio, doctor_fio;
                    std::cout << "Введите ФИО пациента: ";
                    std::cin.ignore();
                    std::getline(std::cin, patient_fio);

                    std::cout << "Введите ФИО врача: ";
                    std::getline(std::cin, doctor_fio);

                    Doctor* doctor = doctor_database.find_doctor(FIO(doctor_fio, "", ""));
                    if (doctor) {
                        MedicalRecord* record = record_manager.find_record_by_patient_fio(patient_fio);
                        if (record) {
                            record->assign_doctor(*doctor);
                            std::cout << "Врач назначен пациенту.\n";
                        }
                        else {
                            std::cout << "Пациент не найден.\n";
                        }
                    }
                    else {
                        std::cout << "Врач не найден.\n";
                    }
                    break;
                }
                }
            } while (doctor_option != 5);
            break;
        }
        case 6:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Неправильный ввод. Попробуйте снова.\n";
        }
    } while (option != 6);

    return 0;


	return 0;
}