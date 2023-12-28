#pragma once

#include "student_topic.h"
#include <iostream>
#include <string>

StudentTopic::StudentTopic(const std::string& name, const std::string& topic, const Date& date)
    : studentName(name), topicName(topic), issueDate(date) {}

void StudentTopic::SetName(const std::string name)
{
	studentName = name;
}

std::string StudentTopic::GetName() const
{
	return studentName;
}

void StudentTopic::SetDate(const Date date)
{
	issueDate = date;
}

Date StudentTopic::GetDate() const
{
	return issueDate;
}

void StudentTopic::SetTopic(const std::string topic)
{
	topicName = topic;
}

std::string StudentTopic::GetTopic() const
{
	return topicName;
}

void StudentTopic::read(std::istream& in)
{
	std::string student_name;
	if (std::getline(in, student_name, ','))
	{
		this->SetName(student_name);
		std::string student_topic;
		if (std::getline(in, student_topic, ','))
		{
			this->SetTopic(student_topic);
		}
		Date input_date;
		input_date.create_from_stream(in);
		this->SetDate(input_date);

	}
	in.ignore();
}

void StudentTopic::print(std::ostream& out) const {
    out << "Имя студента: " << this->GetName() << std::endl;
    out << "Название темы: " << this->GetTopic() << std::endl;
	Date output_date = this->GetDate();
	output_date.print(out);
}

bool StudentTopic::ValidateName(const std::string& name) {
	static const std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
	for (char ch : name) {
		if (alphabet.find(ch) == std::string::npos) {
			return false;
		}
	}
	return true;
}

void StudentTopic::InvalidName(const std::string& name)
{
	static const std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";

	if (name.empty() || !ValidateName(name) || name.find_first_not_of(alphabet) != std::string::npos) {
		throw std::runtime_error("Неправильное Имя!");
	}
	ValidateName(name);
}

bool StudentTopic::ValidateTopicName(const std::string& topic_name) {
	static const std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789`~!@#$%^&()_+-={[]};',. ";
	for (char ch : topic_name) {
		if (alphabet.find(ch) == std::string::npos) {
			return false;
		}
	}
	return true;
}

void StudentTopic::InvalidTopicName(const std::string& topic_name)
{
	static const std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789`~!@#$%^&()_+-={[]};',. ";

	if (topic_name.empty() || !ValidateTopicName(topic_name) || topic_name.find_first_not_of(alphabet) != std::string::npos) {
		throw std::runtime_error("Неправильное Название Темы !");
	}
	ValidateName(topic_name);
}