#pragma once

#include <vector>
#include "student_topic.h"

class FileReader {
public:
    static std::vector<StudentTopic> readStudentTopics(std::ifstream& in);
};
