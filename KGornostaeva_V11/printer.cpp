#include "printer.h"
#include <iostream>

void Printer::printStudentTopics(const std::vector<StudentTopic>& objects) {
    for (const StudentTopic& obj : objects) {
        obj.print();
    }
}
