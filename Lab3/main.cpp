#include <iostream>
#include "queue.h"
#include "stack.h"
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
		cout << "1) Insert\n2) Contains\n3) Remove\n4) Depth-first search\n5) Breadth-first search\n";
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
				case false:
					cout << "Element NOT found!" << endl;
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
				Iterator * dft_iterator;
				dft_iterator = binaryheap.create_dft_iterator();
				while (dft_iterator->has_next())
				{
					cout << dft_iterator->next() << " ";
				}
				cout << endl;
				delete dft_iterator;
				break;
			case 5:
				Iterator * bft_iterator;
				bft_iterator = binaryheap.create_bft_iterator();
				while (bft_iterator->has_next())
				{
					cout << bft_iterator->next() << " ";
				}
				cout << endl;
				delete bft_iterator;
				break;
			default:
				break;
			}
		}
		catch (invalid_argument& ErrorMessage)
		{
			cout << ErrorMessage.what() << endl;
		}
	}
		

	return 0;
}