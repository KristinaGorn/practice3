#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <locale>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;

    Date(int y, int m, int d) : year(y), month(m), day(d) {}
};

struct StudentTopic
{
    string studentName;
    string topicName;
    Date issueDate;

    StudentTopic(const string& name, const string& topic, const Date& date)
        : studentName(name), topicName(topic), issueDate(date) {}
};

// Функция для чтения данных из файла и заполнения вектора объектами StudentTopic
vector<StudentTopic> readStudentTopics(const string& filename)
{
    vector<StudentTopic> objects;
    ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        cerr << "Ошибка при открытии файла." << endl;
        exit(1);
    }

    string line;
    while (getline(inputFile, line))
    {
        stringstream ss(line);
        string studentName, topicName;
        int year, month, day;
        char dash;

        if (getline(ss, studentName, ',') &&
            getline(ss, topicName, ',') &&
            (ss >> year >> dash >> month >> dash >> day))
        {
            objects.emplace_back(studentName, topicName, Date(year, month, day));
        }
        else
        {
            cerr << "Некорректный формат данных: " << line << endl;
        }
    }

    inputFile.close();
    return objects;
}

// Функция для вывода информации о студентах и их темах
void printStudentTopics(const vector<StudentTopic>& objects)
{
    for (const StudentTopic& obj : objects)
    {
        cout << "Имя студента: " << obj.studentName << endl;
        cout << "Название темы: " << obj.topicName << endl;
        cout << "Дата выдачи: " << obj.issueDate.year << "." << obj.issueDate.month << "." << obj.issueDate.day << endl;
        cout << "________________" << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Ru");
    vector<StudentTopic> objects = readStudentTopics("input.txt");
    printStudentTopics(objects);

    return 0;
}
