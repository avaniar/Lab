#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab1/Header.h"
#include "../Lab1/Source.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		List* list;
		TEST_METHOD_INITIALIZE(setUp)
		{
			list = new List;
		}
		TEST_METHOD_CLEANUP(cleanUp)
		{
			delete list;
		}
		TEST_METHOD(at_correct_index)
		{
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			Assert::AreEqual(list->at(1), 2);
		}
		TEST_METHOD(at_incorrect_index)
		{
			try
			{
				list->at(-1);
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("The index is outside the list.", e.what());
			}
		}
		TEST_METHOD(push_back_correct_data)
		{
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			Assert::AreEqual(list->at(2), 3);
		}
		TEST_METHOD(push_front_correct_data)
		{
			list->push_front(1);
			list->push_front(2);
			list->push_front(3);
			Assert::AreEqual(list->at(0), 3);
		}
		TEST_METHOD(pop_back_correct_size)
		{
			list->push_front(1);
			list->push_front(2);
			list->push_front(3);
			list->pop_back();
			Assert::IsTrue(list->get_size() == 2);
		}
		TEST_METHOD(pop_front_correct_size)
		{
			list->push_front(1);
			list->push_front(2);
			list->push_front(3);
			list->pop_front();
			Assert::IsTrue(list->get_size() == 2);
		}
		TEST_METHOD(insert_correct_data)
		{
			list->push_front(1);
			list->push_front(2);
			list->insert(4, 1);
			Assert::AreEqual(list->at(1), 4);
		}
		TEST_METHOD(get_size_correct_size)
		{
			list->push_front(1);
			list->push_front(2);
			list->push_front(3);
			Assert::IsTrue(list->get_size()==3);
		}
		TEST_METHOD(insert_incorrect_index)
		{
			try
			{
				list->insert(0, -1);
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("The index is outside the list.", e.what());
			}
		}
		TEST_METHOD(remove_correct_data)
		{
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			list->remove(1);
			Assert::AreEqual(list->at(1), 3);
		}
		TEST_METHOD(remove_incorrect_index)
		{
			try
			{
				list->remove(-1);
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("The index is outside the list.", e.what());
			}
		}
		TEST_METHOD(clear_correct_size)
		{
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			list->clear();
			Assert::IsTrue(list->isEmpty());
		}
		TEST_METHOD(set_correct_data)
		{
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			list->set(1, 4);
			Assert::AreEqual(list->at(1),4);
		}
		TEST_METHOD(set_incorrect_index)
		{
			try
			{
				list->set(-1,5);
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("The index is outside the list.", e.what());
			}
		}
		TEST_METHOD(isEmpty_correct_answer)
		{
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			Assert::IsFalse(list->isEmpty());
		}
		TEST_METHOD(push_back__list_correct_size)
		{
			List* list2 = new List;
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			list2->push_back(9);
			list->push_back(*list2);
			Assert::IsTrue(list->get_size()==4);
			list2->clear();
		}
		TEST_METHOD(push_back_list_correct_data)
		{
			List* list2 = new List;
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			list2->push_back(9);
			list->push_back(*list2);
			Assert::AreEqual(list->at(3),9);
			list2->clear();
		}
	};
}
