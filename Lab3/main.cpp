#include <iostream>
#include "queue.h"
#include "queue.cpp"
#include "stack.h"
#include "stack.cpp"
#include "iterator.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	BinaryHeap binaryheap;
	
	int result = 0;
	int data = 0;
	
	cout << "Enter option:\n";
	while (result != 10)
	{
		cout << "1) Insert\n2) Contains\n3) Remove\n4) Depth-first search\n5) Breadth-first search\n6) Exit\n";
		cin >> result;
		try
		{
			switch (result)
			{
			case 1: //insert
				cout << "Enter data:\n";
				cin >> data;
				binaryheap.insert(data);
				break;
			case 2: //contains
				cout << "Enter data:\n";
				cin >> data;
				switch (binaryheap.contains(data))
				{
				case true:
					cout << "Element found!" << endl;
					break;
				case false:
					cout << "Element NOT found!" << endl;
					break;
				}
				break;
			case 3: //remove
				cout << "Enter data:\n";
				cin >> data;
				try
				{
					binaryheap.remove(data);
				}
				catch (invalid_argument& ErrorMessage)
				{
					cout << ErrorMessage.what() << endl;
				}	
				break;
			case 4:
				Iterator * new_dft_iterator;
				new_dft_iterator = binaryheap.create_dft_iterator();

				if (new_dft_iterator->has_next())
				{
					while (new_dft_iterator->has_next())
					{
						cout << new_dft_iterator->next() << " ";
					}
					cout << endl;
				}
				else
				{
					cout << "Heap is empty" << endl;
				}		

				delete new_dft_iterator;
				break;
			case 5:
				Iterator * new_bft_iterator;
				new_bft_iterator = binaryheap.create_bft_iterator();
				if (new_bft_iterator->has_next())
				{
					while (new_bft_iterator->has_next())
					{
						cout << new_bft_iterator->next() << " ";
					}
					cout << endl;
				}
				else
				{
					cout << "Heap is empty" << endl;
				}
				delete new_bft_iterator;
				break;
			case 6:
				throw out_of_range("Exit program");
				break;			
			}
		}
		catch (out_of_range)
		{
			break;
		}
	}

	return 0;
}