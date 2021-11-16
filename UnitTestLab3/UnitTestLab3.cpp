#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab3\queue.h"
#include "..\Lab3\stack.h"
#include "..\Lab3\iterator.h"
#include "..\Lab3\binaryheap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTestLab3
{
	//BinaryHeapTest
	void findNode_error()
	{
		BinaryHeap binaryheap;
		binaryheap.insert(1);
		binaryheap.insert(5);
		binaryheap.findNode(2);
	}
	
	void remove_error()
	{
		BinaryHeap binaryheap;
		binaryheap.insert(1);
		binaryheap.insert(5);
		binaryheap.remove(2);
	}
	
	//Queue

	//Stack	

	TEST_CLASS(BinaryHeapTest)
	{
	public:
		TEST_METHOD(empty)
		{
			BinaryHeap binaryheap;
			Assert::IsTrue(binaryheap.empty());

			binaryheap.insert(10);
			Assert::IsFalse(binaryheap.empty());
		}
		TEST_METHOD(insert)
		{
			BinaryHeap binaryheap;
			Assert::IsTrue(binaryheap.empty());

			binaryheap.insert(10);
			binaryheap.insert(9);
			binaryheap.insert(8);
			binaryheap.insert(7);
			binaryheap.insert(6);
			binaryheap.insert(5);

			int array[7] = { 10, 9, 8, 7, 6, 5 };
			int i = 0;

			Iterator* bft_iterator;
			bft_iterator = binaryheap.create_bft_iterator();
			while (bft_iterator->has_next())
			{
				Assert::IsTrue(bft_iterator->next() == array[i]);
				i++;
			}
			delete bft_iterator;
		}
		TEST_METHOD(insert_with_sift)
		{
			BinaryHeap binaryheap;

			binaryheap.insert(8);
			binaryheap.insert(10);
			binaryheap.insert(11);
			binaryheap.insert(9);
			binaryheap.insert(5);
			binaryheap.insert(7);
			binaryheap.insert(3);

			int array[7] = { 11, 9, 10, 8, 5, 7, 3 };
			int i = 0;

			Iterator* bft_iterator;
			bft_iterator = binaryheap.create_bft_iterator();
			while (bft_iterator->has_next())
			{
				Assert::IsTrue(bft_iterator->next() == array[i]);
				i++;
			}
			delete bft_iterator;	
		}
		TEST_METHOD(findNode)
		{
			void (*func)() = findNode_error;
			Assert::ExpectException<invalid_argument>(func);

			BinaryHeap binaryheap;

			binaryheap.insert(8);
			binaryheap.insert(10);
			binaryheap.insert(11);
			binaryheap.insert(9);
			binaryheap.insert(5);
			binaryheap.insert(7);
			binaryheap.insert(3);

			Assert::IsTrue(binaryheap.findNode(7) == binaryheap.getRoot()->_right->_left);
			Assert::IsTrue(binaryheap.findNode(5) == binaryheap.getRoot()->_left->_right);
			Assert::IsTrue(binaryheap.findNode(10) == binaryheap.getRoot()->_right);
		}
		TEST_METHOD(remove_with_sift)
		{
			void (*func)() = remove_error;
			Assert::ExpectException<invalid_argument>(func);

			BinaryHeap binaryheap;

			binaryheap.insert(8);
			binaryheap.insert(10);
			binaryheap.insert(11);
			binaryheap.insert(9);
			binaryheap.insert(5);
			binaryheap.insert(7);
			binaryheap.insert(3);

			Iterator* bft_iterator;

			//Removing 9
			binaryheap.remove(9);
			int array1[6] = { 11, 8, 10, 3, 5, 7 };
			int i = 0;

			bft_iterator = binaryheap.create_bft_iterator();
			while (bft_iterator->has_next())
			{
				Assert::IsTrue(bft_iterator->next() == array1[i]);
				i++;
			}
			delete bft_iterator;

			//Removing 7
			binaryheap.remove(7);
			int array2[5] = { 11, 8, 10, 3, 5 };
			i = 0;

			bft_iterator = binaryheap.create_bft_iterator();
			while (bft_iterator->has_next())
			{
				Assert::IsTrue(bft_iterator->next() == array2[i]);
				i++;
			}
			delete bft_iterator;

			//Removing 10
			binaryheap.remove(10);
			int array3[4] = { 11, 8, 5, 3};
			i = 0;

			bft_iterator = binaryheap.create_bft_iterator();
			while (bft_iterator->has_next())
			{
				Assert::IsTrue(bft_iterator->next() == array3[i]);
				i++;
			}
			delete bft_iterator;
		}
		TEST_METHOD(remove)
		{
			BinaryHeap binaryheap;

			binaryheap.insert(11);
			binaryheap.insert(10);
			binaryheap.insert(9);

			Iterator* bft_iterator;

			
			int array1[3] = { 11, 10, 9 };
			int i = 0;
			bft_iterator = binaryheap.create_bft_iterator();
			while (bft_iterator->has_next())
			{
				Assert::IsTrue(bft_iterator->next() == array1[i]);
				i++;
			}
			delete bft_iterator;

			//removing 9
			binaryheap.remove(9);
			int array2[2] = { 11, 10 };
			i = 0;
			bft_iterator = binaryheap.create_bft_iterator();
			while (bft_iterator->has_next())
			{
				Assert::IsTrue(bft_iterator->next() == array2[i]);
				i++;
			}
			delete bft_iterator;

			//removing 10
			binaryheap.remove(10);
			int array3[1] = { 11 };
			i = 0;
			Assert::IsTrue(binaryheap.getRoot()->_data == 11);

			//removing 11
			binaryheap.remove(11);
			Assert::IsTrue(binaryheap.empty());

		}
		TEST_METHOD(findParentOfLast)
		{
			BinaryHeap binaryheap;

			binaryheap.insert(8);
			binaryheap.insert(10);
			binaryheap.insert(11);
			binaryheap.insert(9);
			binaryheap.insert(5);
			binaryheap.insert(7);

			Assert::IsTrue(binaryheap.findParentOfLast(4) == binaryheap.getRoot()->_right);

			binaryheap.remove(7);
			Assert::IsTrue(binaryheap.findParentOfLast(4) == binaryheap.getRoot()->_left);

		}
		TEST_METHOD(contains)
		{
			BinaryHeap binaryheap;
			binaryheap.insert(11);
			binaryheap.insert(10);
			binaryheap.insert(9);
			binaryheap.insert(8);

			Assert::IsTrue(binaryheap.contains(11));

			Assert::IsFalse(binaryheap.contains(12));

			binaryheap.remove(11);

			Assert::IsFalse(binaryheap.contains(11));
		}
		TEST_METHOD(dft_iterator)
		{
			BinaryHeap binaryheap;
			binaryheap.insert(11);
			binaryheap.insert(10);
			binaryheap.insert(9);
			binaryheap.insert(8);
			binaryheap.insert(7);
			binaryheap.insert(6);
			binaryheap.insert(5);

			Iterator* dft_iterator;

			int array1[7] = { 11, 10, 8, 7, 9, 6, 5};
			int i = 0;
			dft_iterator = binaryheap.create_dft_iterator();
			while (dft_iterator->has_next())
			{
				Assert::IsTrue(dft_iterator->next() == array1[i]);
				i++;
			}
			delete dft_iterator;
		}
		TEST_METHOD(bft_iterator)
		{
			BinaryHeap binaryheap;
			binaryheap.insert(11);
			binaryheap.insert(10);
			binaryheap.insert(9);
			binaryheap.insert(8);
			binaryheap.insert(7);
			binaryheap.insert(6);
			binaryheap.insert(5);

			Iterator* bft_iterator;

			int array1[7] = { 11, 10, 9, 8, 7, 6, 5 };
			int i = 0;
			bft_iterator = binaryheap.create_bft_iterator();
			while (bft_iterator->has_next())
			{
				Assert::IsTrue(bft_iterator->next() == array1[i]);
				i++;
			}
			delete bft_iterator;
		}

	};

	TEST_CLASS(QueueTest)
	{
		TEST_METHOD(pop)
		{
		}

		TEST_METHOD(push)
		{
			BinaryHeap binaryheap;
			binaryheap.insert(3);
			binaryheap.insert(2);
			binaryheap.insert(1);

			Queue queue;
			queue.push(binaryheap.getRoot());
			queue.push(binaryheap.getRoot()->_left);
			queue.push(binaryheap.getRoot()->_right);
		}

		TEST_METHOD(front)
		{}

		TEST_METHOD(empty)
		{}

		TEST_METHOD(back)
		{}
	};

	TEST_CLASS(StackTest)
	{
		TEST_METHOD(push)
		{}

		TEST_METHOD(pop)
		{}

		TEST_METHOD(top)
		{}

		TEST_METHOD(empty)
		{}
	};
}
