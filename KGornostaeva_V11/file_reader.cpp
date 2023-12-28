#pragma once

#include "file_reader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

vector<StudentTopic> FileReader::readStudentTopics(std::ifstream& in) {
    vector<StudentTopic> objects;
    string line;
    while (in) {
        StudentTopic file;
        file.read(in);
        objects.emplace_back(file);
    }

    return objects;
}
