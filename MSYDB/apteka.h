#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <memory>


class Medication {
protected:
    std::string name;
    std::string dosage;
    double price;  

public:
    Medication(const std::string& name, const std::string& dosage, double price)
        : name(name), dosage(dosage), price(price) {}

    virtual ~Medication() = default;

    virtual std::string get_info() const = 0;  

    virtual std::string get_type() const = 0;  
    double get_price() const {  
        return price;
    }

    void set_price(double new_price) {  
        price = new_price;
    }
};


class Solution : public Medication {
public:
    Solution(const std::string& name, const std::string& dosage, double price)
        : Medication(name, dosage, price) {}

    std::string get_info() const override {
        return "Solution: " + name + ", Dosage: " + dosage + ", Price: RUB" + std::to_string(price);
    }

    std::string get_type() const override {
        return "Solution";
    }
};


class Tablet : public Medication {
public:
    Tablet(const std::string& name, const std::string& dosage, double price)
        : Medication(name, dosage, price) {}

    std::string get_info() const override {
        return "Tablet: " + name + ", Dosage: " + dosage + ", Price: RUB" + std::to_string(price);
    }

    std::string get_type() const override {
        return "Tablet";
    }
};


class Powder : public Medication {
public:
    Powder(const std::string& name, const std::string& dosage, double price)
        : Medication(name, dosage, price) {}

    std::string get_info() const override {
        return "Powder: " + name + ", Dosage: " + dosage + ", Price: RUB" + std::to_string(price);
    }

    std::string get_type() const override {
        return "Powder";
    }
};


class Narcotic : public Medication {
public:
    Narcotic(const std::string& name, const std::string& dosage, double price)
        : Medication(name, dosage, price) {}

    std::string get_info() const override {
        return "Narcotic: " + name + ", Dosage: " + dosage + ", Price: RUS" + std::to_string(price);
    }

    std::string get_type() const override {
        return "Narcotic";
    }
};


class Pharmacy {
private:
    std::vector<std::shared_ptr<Medication>> medications;

public:
    void add_medication(const std::shared_ptr<Medication>& medication) {
        medications.push_back(medication);
    }

    void display_medications() const {
        std::cout << "Medications in Pharmacy:\n";
        double total_price = 0;
        for (const auto& med : medications) {
            std::cout << med->get_info() << std::endl;
            total_price += med->get_price();
        }
        std::cout << "Total Price of Medications: RUB" << total_price << std::endl;
    }

    std::string get_medications_info() const {  
        std::string info;
        for (const auto& med : medications) {
            info += med->get_info() + "\n";
        }
        return info.empty() ? "Нет медикаментов\n" : info;
    }

    const std::vector<std::shared_ptr<Medication>>& get_medications() const {
        return medications;
    }
};

