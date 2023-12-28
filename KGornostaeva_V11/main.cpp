#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#include <iostream>
#include <fstream>
#include "file_reader.h"
#include "printer.h"

int main() {
    setlocale(LC_ALL, "Ru");

    // Включаем утечки памяти ЭТО Я СРАЗУ НАПИСАЛА ДЛЯ 5 ЛАБЫ
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    try {
        std::ifstream in("input.txt");
        vector<StudentTopic> objects = FileReader::readStudentTopics(in);
        Printer::printStudentTopics(objects);
    }
    catch (const exception& ex) {
        cerr << "Ошибка: " << ex.what() << endl;
        return 1;
    }

    // Выводим информацию об утечках памяти
    _CrtDumpMemoryLeaks();

    return 0;
}