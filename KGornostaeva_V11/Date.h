#pragma once

#include <iostream>
#include <sstream>
#include <iomanip>

class Date {
public:
    Date();
    Date(int day, int month, int year);

    void SetYear(const int year);
    int GetYear() const;

    void SetMonth(const int month);
    int GetMonth() const;

    void SetDay(const int day);
    int GetDay() const;

    void print(std::ostream& out) const;
    void create_from_stream(std::istream& stream);

    static bool ValidateDate(const std::string& date);
    static void InvalidDate(const std::string& date);

private:
    int day;
    int month;
    int year;

    bool IsValidDate() const;
};
