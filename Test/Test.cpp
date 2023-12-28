#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include "../KGornostaeva_V11/Date.h"
#include "../KGornostaeva_V11/Date.cpp"
#include "../KGornostaeva_V11/Student_topic.h"
#include "../KGornostaeva_V11/Student_topic.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestProject
{
	TEST_CLASS(TestProject)
	{
	public:

		TEST_METHOD(ValidFormatDate)
		{
			std::vector<std::string> Cases
			{
				"2021.10.12",
				"2001.1.1",
				"2023.12.11"
			};
			for (int i = 0; i < Cases.size(); i++)
			{
				bool result = Date::ValidateDate(Cases[i]);
				Assert::IsTrue(result);
			}
		}
		TEST_METHOD(InvalidFormatDate)
		{
			std::vector<std::string> Cases
			{
				"10.12.2023",
				"ab.cd.df",
				"Hello"
				"2023/12/11"

			};
			for (int i = 0; i < Cases.size(); i++)
			{
				try
				{
					Date::InvalidDate(Cases[i]);
					Assert::Fail();
				}
				catch (std::runtime_error& e)
				{
					return;
				}
			}
		}
		TEST_METHOD(ValidFormatName)
		{
			std::vector<std::string> Cases
			{
				"Danya Uvieev",
				"Lola Rola",
				"Chak Noris",
			};
			for (int i = 0; i < Cases.size(); i++)
			{
				bool result = StudentTopic::ValidateName(Cases[i]);
				Assert::IsTrue(result);
			}
		}
		TEST_METHOD(InvalidFormatName)
		{
			std::vector<std::string> Cases
			{
				"Hello?",
				"20|24",
				"Пока"

			};
			for (int i = 0; i < Cases.size(); i++)
			{
				try
				{
					StudentTopic::InvalidName(Cases[i]);
					Assert::Fail();
				}
				catch (std::runtime_error& e)
				{
					return;
				}
			}
		}
		TEST_METHOD(ValidFormatTopicName)
		{
			std::vector<std::string> Cases
			{
				"Topic1",
				"Topic1488",
				"Very_Important_Topic",
				"Final Topic",
			};
			for (int i = 0; i < Cases.size(); i++)
			{
				bool result = StudentTopic::ValidateTopicName(Cases[i]);
				Assert::IsTrue(result);
			}
		}
		TEST_METHOD(InvalidFormatTopicName)
		{
			std::vector<std::string> Cases
			{
				"Hello?",
				"20|24",
				"Пока"

			};
			for (int i = 0; i < Cases.size(); i++)
			{
				try
				{
					StudentTopic::InvalidTopicName(Cases[i]);
					Assert::Fail();
				}
				catch (std::runtime_error& e)
				{
					return;
				}
			}
		}
		TEST_METHOD(ValidTestFileData)
		{
			std::istringstream input("Ivan Ivanov,Topic 1,2023.12.11");
			std::string name = "Ivan Ivanov";
			std::string topic_name = "Topic 1";
			StudentTopic file;
			file.read(input);
			Assert::AreEqual(name, file.GetName());
			Assert::AreEqual(topic_name, file.GetTopic());
			Date date;
			date = file.GetDate();
			Assert::AreEqual(2023, static_cast<int>(date.GetYear()));
			Assert::AreEqual(12, static_cast<int>(date.GetMonth()));
			Assert::AreEqual(11, static_cast<int>(date.GetDay()));
			
		}
		TEST_METHOD(InvalidTestMenu)
		{
			std::vector<std::string> cases
			{
				"1231 13123.1 3213 1 fadasd",
				"aaad 131 vdvs a1",
				"da312 das 123"
			};
			for (int i = 0; i < cases.size(); i++)
			{
				std::istringstream input(cases[i]);
				try
				{
					StudentTopic file;
					file.read(input);
					throw std::runtime_error("Error in runtime");
				}
				catch (const std::runtime_error& e)
				{
					std::cerr << "Error Message: " << e.what() << std::endl;
				}
			}
		}
		TEST_METHOD(ValidMenuWrite)
		{
			std::istringstream input("Ivan Ivanov,Topic 1,2023.12.11");
			StudentTopic file;
			file.read(input);
			std::ostringstream expected_output;
			expected_output << "Имя студента: " << file.GetName() << std::endl;
			expected_output << "Название темы: " << file.GetTopic() << std::endl;
			Date date = file.GetDate();
			date.print(expected_output);
			std::ostringstream actual_output;
			file.print(actual_output);
			Assert::AreEqual(expected_output.str(), actual_output.str());
		}

		TEST_METHOD(ValidDateWrite)
		{
			std::istringstream input("2023.12.11");
			Date date;
			const char point = '.';
			date.create_from_stream(input);
			std::ostringstream expected_output;
			expected_output << "Дата выдачи: "
				<< date.GetYear() << point
				<< std::setfill('0') << std::setw(2) << date.GetMonth() << point
				<< std::setfill('0') << std::setw(2) << date.GetDay() << std::endl;
			std::ostringstream actual_output;
			date.print(actual_output);
			Assert::AreEqual(expected_output.str(), actual_output.str());
		}

};
}
