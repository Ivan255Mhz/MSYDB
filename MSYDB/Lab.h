#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <random>
#include <iomanip>

class LabTest {
private:
    std::string test_name;
    std::string instructions;

public:
    LabTest(const std::string& name, const std::string& instr)
        : test_name(name), instructions(instr) {}

    std::string get_test_name() const {
        return test_name;
    }

    std::string get_instructions() const {
        return instructions;
    }

    std::string get_test_info() const {
        return "������: " + test_name + ", ����������: " + instructions;
    }
};

class Laboratory {
private:
    std::vector<LabTest> tests;

public:
    void assign_test(const LabTest& test) {
        tests.push_back(test);
    }

    void print_all_tests() const {
        if (tests.empty()) {
            std::cout << "��� ����������� ��������.\n";
            return;
        }
        for (const auto& test : tests) {
            std::cout << test.get_test_info() << std::endl;
        }
    }

    void generate_lab_report(const std::string& patient_name) const {
        if (tests.empty()) {
            std::cout << "��� ����������� �������� ��� ������ � ����.\n";
            return;
        }

        
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(1000000, 9999999);
        int direction_code = dist(gen);

        
        std::ofstream file("lab_direction_" + std::to_string(direction_code) + ".txt");

        file << "����������� �� ������� ��� ��������: " << patient_name << "\n";
        file << "��� �����������: " << direction_code << "\n\n";
        file << "����������� �������:\n";

        for (const auto& test : tests) {
            file << "- " << test.get_test_name() << ": " << test.get_instructions() << "\n";
        }

        file.close();

        std::cout << "����������� � ����� " << direction_code << " ������� �������������.\n";
    }
};

