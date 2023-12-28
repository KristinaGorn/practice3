#pragma once

#include <string>
#include <iostream>
#include "date.h"
using namespace std;

struct StudentTopic {
public:
    StudentTopic(const std::string& name, const std::string& topic, const Date& date);
    StudentTopic() : studentName(""), topicName(), issueDate() {}

    void SetName(const std::string name);
    std::string GetName() const;

    void SetDate(const Date date);
    Date GetDate() const;

    void SetTopic(const std::string topic);
    std::string GetTopic() const;

    void read(std::istream& in);
    void print(std::ostream& out = std::cout) const;

    static bool ValidateName(const std::string& name);
    static void InvalidName(const std::string& name);

    static bool ValidateTopicName(const std::string& topic_name);
    static void InvalidTopicName(const std::string& topic_name);

private:
    std::string studentName;
    std::string topicName;
    Date issueDate;
};