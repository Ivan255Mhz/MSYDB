#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <chrono>
#include <string>

class date_m {
    int day;
    int month;
    int year;

public:
    
    date_m() {
        set_to_current_date();
    }

    date_m(int d, int m, int y) : day{ d }, month{ m }, year{ y } {}

    int get_year() const { return year; }
    int get_month() const { return month; }
    int get_day() const { return day; }
    
    std::string date_to_string() const {
        return "Date: " + std::to_string(day) + '-' + std::to_string(month) + '-' + std::to_string(year);
    }

    void restart() {
        set_to_current_date();
    }

    void set_day(int d) {
        if (d >= 1 && d <= 31)  
            day = d;
    }

    void set_month(int m) {
        if (m >= 1 && m <= 12)
            month = m;
    }

    void set_year(int y) {
        year = y;
    }

    friend std::ostream& operator<<(std::ostream& os, const date_m& date) {
        os << date.date_to_string();
        return os;
    }

private:
    
    void set_to_current_date() {
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        std::tm* local_time = std::localtime(&now_c);

        year = local_time->tm_year + 1900;
        month = local_time->tm_mon + 1;
        day = local_time->tm_mday;
    }
};

class time_m {
    int hours;
    int minutes;
    int seconds;

public:
    
    time_m() {
        set_to_current_time();
    }

    
    int get_hours() const { return hours; }
    int get_minutes() const { return minutes; }
    int get_seconds() const { return seconds; }

    
    std::string time_to_string() const {
        return "Time: " + std::to_string(hours) + ':' + std::to_string(minutes) + ':' + std::to_string(seconds);
    }

    
    void restart() {
        set_to_current_time();
    }

    
    friend std::ostream& operator<<(std::ostream& os, const time_m& time) {
        os << time.time_to_string();
        return os;
    }

private:
    
    void set_to_current_time() {
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        std::tm* local_time = std::localtime(&now_c);

        hours = local_time->tm_hour;
        minutes = local_time->tm_min;
        seconds = local_time->tm_sec;
    }
};
