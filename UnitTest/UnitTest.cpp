#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab1\listclasses.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest
{
	void pop_back_error()
	{
		UnorderedList List;
		List.pop_back();
	}

	void pop_front_error()
	{
		UnorderedList List;
		List.pop_front();
	}

	void insert_error()
	{
		UnorderedList List;
		List.insert(10, 15);
	}

	void find_elem_error()
	{
		UnorderedList List;
		Node* node = List.FindElem(5);
	}

	void get_elem_error()
	{
		UnorderedList List;
		int num = List.GetElem(3);
	}

	void remove_error()
	{
		UnorderedList List;
		List.push_back(5);
		List.push_back(11);
		List.remove(2);
	}

	void set_error()
	{
		UnorderedList List;
		List.set(3, 15);
	}

	void swap_error()
	{
		UnorderedList List;
		List.push_back(1);
		List.push_back(2);
		List.swap(1, 3);
	}

	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(isEmpty)
		{
			UnorderedList List;
			Assert::IsTrue(List.GetHead() == nullptr);

			List.push_back(5);
			Assert::IsFalse(List.GetHead() == nullptr);
		}
		TEST_METHOD(push_back)
		{
			UnorderedList List;
			List.push_back(5);
			Assert::IsTrue(List.GetLast()->GetNumber() == 5);

			List.push_back(10);
			Assert::IsTrue(List.GetLast()->GetNumber() == 10);
		}
		TEST_METHOD(push_front)
		{
			UnorderedList List;
			List.push_front(1);
			Assert::IsTrue(List.GetHead()->GetNumber() == 1);

			List.push_front(2);
			Assert::IsTrue(List.GetHead()->GetNumber() == 2);
		}
		TEST_METHOD(pop_back)
		{
			void (*func)() = pop_back_error;
			Assert::ExpectException<invalid_argument>(func);

			UnorderedList List;
			List.push_back(5);
			List.push_back(15);

			List.pop_back();
			Assert::IsFalse(List.GetHead() == nullptr);

			List.pop_back();
			Assert::IsTrue(List.GetHead() == nullptr);
		}
		TEST_METHOD(pop_front)
		{
			void (*func)() = pop_front_error;
			Assert::ExpectException<invalid_argument>(func);

			UnorderedList List;
			List.push_back(5);
			List.push_back(15);

			List.pop_front();
			Assert::IsFalse(List.GetHead() == nullptr);

			List.pop_front();
			Assert::IsTrue(List.GetHead() == nullptr);
		}
		TEST_METHOD(insert)
		{
			void (*func)() = insert_error;
			Assert::ExpectException<out_of_range>(func);

			UnorderedList List;
			List.push_back(15);
			List.push_back(115);
			List.insert(10, 0);
			List.insert(11, 1);
			Assert::AreEqual(List.FindElem(0)->GetNumber(), 10);
			Assert::AreEqual(List.FindElem(1)->GetNumber(), 11);
		}
		TEST_METHOD(FindElem)
		{
			void (*func)() = find_elem_error;
			Assert::ExpectException<out_of_range>(func);

			UnorderedList List;
			List.push_back(0);
			List.push_back(1);
			List.push_back(2);

			Node* elem = List.FindElem(1); //Searchng element "1" (0->1->2)

			Assert::IsTrue(List.GetHead()->GetNext() == elem);
		}
		TEST_METHOD(GetElem)
		{
			void (*func)() = get_elem_error;
			Assert::ExpectException<out_of_range>(func);

			UnorderedList List;
			List.push_back(0);
			List.push_back(1);
			List.push_back(2);

			Assert::IsTrue(List.GetHead()->GetNumber() == 0);
			Assert::IsTrue(List.GetHead()->GetNext()->GetNumber() == 1);
		}
		TEST_METHOD(remove)
		{
			void (*func)() = remove_error;
			Assert::ExpectException<out_of_range>(func);

			UnorderedList List;
			List.push_back(0);
			List.push_back(1);

			List.remove(0);
			Assert::IsTrue(List.get_size() == 1);
			Assert::IsTrue(List.GetElem(0) == 1);

			List.remove(0);
			Assert::IsTrue(List.isEmpty());
		}
		TEST_METHOD(get_size)
		{
			UnorderedList List;
			Assert::IsTrue(List.get_size() == 0);

			List.push_back(0);
			List.push_back(1);

			Assert::IsTrue(List.get_size() == 2);
		}
		TEST_METHOD(clear)
		{
			UnorderedList List;
			List.push_back(0);
			List.push_back(1);
			List.clear();
			Assert::IsTrue(List.isEmpty());
		}
		TEST_METHOD(set)
		{
			void (*func)() = set_error;
			Assert::ExpectException<out_of_range>(func);

			UnorderedList List;
			List.push_back(0);
			List.push_back(1);

			List.set(0, 2);
			List.set(1, 3);

			Assert::IsTrue(List.GetElem(0) == 2);
			Assert::IsTrue(List.GetElem(1) == 3);
		}
		TEST_METHOD(swap)
		{
			void (*func)() = swap_error;
			Assert::ExpectException<out_of_range>(func);

			UnorderedList List;
			List.push_back(0);
			List.push_back(1);
			List.swap(0, 1);
			Assert::IsTrue(List.GetElem(0) == 1);
			Assert::IsTrue(List.GetElem(1) == 0);
		}

	};
}
