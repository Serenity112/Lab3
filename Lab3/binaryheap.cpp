#include <iostream>
#include "queue.h"
#include "queue.cpp"
#include "stack.h"
#include "stack.cpp"
using namespace std;


BinaryHeap::BinaryHeap()
{
	_root = nullptr;
	_height = 0;
	_lastLineNodesCount = 0;
}

BinaryHeap::~BinaryHeap()
{
	dft_iterator* new_dft_iterator;
	new_dft_iterator = new dft_iterator(_root);

	Node* _prev = _root;

	while (new_dft_iterator->has_next())
	{
		_prev = new_dft_iterator->_current;

		new_dft_iterator->next();

		delete _prev;
	}
	delete new_dft_iterator->_current;
	delete new_dft_iterator;
}

bool BinaryHeap::empty()
{
	return _root == nullptr;
}

BinaryHeap::Node* BinaryHeap::getRoot()
{
	return _root;
}

BinaryHeap::Node::Node(int data)
{
	_left = nullptr;
	_right = nullptr;
	_parent = nullptr;
	_data = data;
}
	
BinaryHeap::Node* BinaryHeap::findParentOfLast(int _lastLineSize)
{
	Node* parentNode = _root;

	int tempLastLineSize = _lastLineSize;
	int tempLastLineNodesCount = _lastLineNodesCount;

	if (_lastLineNodesCount > _lastLineSize)
	{
		tempLastLineSize *= 2;
	}

	while (tempLastLineSize != 2)
	{
		if (tempLastLineNodesCount <= tempLastLineSize / 2)
		{
			parentNode = parentNode->_left;
			tempLastLineSize /= 2;
		}
		else
		{
			parentNode = parentNode->_right;
			tempLastLineNodesCount = tempLastLineNodesCount - tempLastLineSize / 2;
			tempLastLineSize /= 2;
		}
	}

	return parentNode;
}

void BinaryHeap::insert(int data)
{
	Node* newNode = new Node(data);

	if (_root == nullptr)
	{
		_root = newNode;
		_height = 1;
		_lastLineNodesCount = 1;
	}
	else
	{
		Node* parentNode = _root;

		int _lastLineSize = 1;

		for (int i = 0; i < _height - 1; i++) //Counting last line MAX size
		{
			_lastLineSize *= 2;
		}

		_lastLineNodesCount++;
		if (_lastLineNodesCount > _lastLineSize)
		{
			_height++;
			_lastLineNodesCount = 1;
			_lastLineSize *= 2;
		}

		parentNode = findParentOfLast(_lastLineSize);

		if (parentNode->_left == nullptr)
		{
			parentNode->_left = newNode;
			newNode->_parent = parentNode;
		}
		else
		{
			parentNode->_right = newNode;
			newNode->_parent = parentNode;
		}

		Heapify(newNode);

		return;
	}
}

void BinaryHeap::siftDown(Node* node)
{
		if (node->_left == nullptr && node->_right == nullptr)
		{
			return;
		}

		Node* maxNode = node; //node to swap with

		if (node->_right == nullptr)  //Means LEFT is not NULL
		{
			if (node->_data < node->_left->_data)
			{
				maxNode = node->_left;
			}
			else
			{
				return;
			}
		}

		if (node->_left != nullptr && node->_right != nullptr)
		{
			if (node->_data < node->_right->_data || node->_data < node->_left->_data)
			{
				if (node->_left->_data > node->_right->_data)
				{
					maxNode = node->_left;
				}
				else
				{
					maxNode = node->_right;
				}
			} else
			{
				return;
			}
		}
	
		int temp = node->_data;
		node->_data = maxNode->_data;
		maxNode->_data = temp;
		siftDown(maxNode);
	
}

void BinaryHeap::siftUp(Node* node)
{
	if (node->_parent == nullptr)
	{
		return;
	}
	else
	{
		if (node->_data > node->_parent->_data)
		{
			int temp = node->_data;
			node->_data = node->_parent->_data;
			node->_parent->_data = temp;
			siftUp(node->_parent);
		}
		else
		{
			return;
		}	
	}
}

void BinaryHeap::Heapify(Node* node)
{
	if (node->_parent == nullptr)
	{
		siftDown(node);
	} 
	else if (node->_data > node->_parent->_data)
	{
		siftUp(node);
	}
	else
	{
		siftDown(node);
	}
}

bool BinaryHeap::contains(int data)
{
	try
	{
		findNode(data);
		return true;
	} 
	catch (invalid_argument)
	{
		return false;
	}	
}

BinaryHeap::Node* BinaryHeap::findNode(int data)
{
	dft_iterator* new_dft_iterator;
	new_dft_iterator = new dft_iterator(_root);
	Node* foundNode = nullptr;

	while (new_dft_iterator->has_next())
	{
		foundNode = new_dft_iterator->_current;

		if (new_dft_iterator->next() == data)
		{
			delete new_dft_iterator;
			return foundNode;
		}	
	}
	delete new_dft_iterator;
	throw invalid_argument("Element not found!");
}

void BinaryHeap::remove(int data)
{
	Node* nodeToRemove = findNode(data);

	if (_height == 1)
	{
		delete _root;
		_root = nullptr;
		_height = 0;
		_lastLineNodesCount = 0;
		return;
	}

	int _lastLineSize = 1;

	for (int i = 0; i < _height - 1; i++) //Counting last line MAX size
	{
		_lastLineSize *= 2;
	}

	Node* lastNode = findParentOfLast(_lastLineSize);

	if (lastNode->_right != nullptr) //Cut last node from tree
	{
		lastNode = lastNode->_right;
		lastNode->_parent->_right = nullptr;
	}
	else
	{
		lastNode = lastNode->_left;
		lastNode->_parent->_left = nullptr;
	}

	_lastLineNodesCount--; //height change
	if (_lastLineNodesCount == 0)
	{
		_height--;
		_lastLineNodesCount = 1;
		for (int i = 0; i < _height - 1; i++)
		{
			_lastLineNodesCount *= 2;
		}
	}

	if (lastNode == nodeToRemove)
	{
		delete lastNode;
	}
	else
	{
		int _temp = lastNode->_data;
		lastNode->_data = nodeToRemove->_data;
		nodeToRemove->_data = _temp;

		delete lastNode;

		Heapify(nodeToRemove);

	}
}

//DFT

Iterator* BinaryHeap::create_dft_iterator()
{
	return new dft_iterator(_root);;
}

BinaryHeap::dft_iterator::dft_iterator(Node* root)
{
	_current = root;
	stack = new Stack<Node*>();
}

BinaryHeap::dft_iterator::~dft_iterator()
{
	delete stack;
}

int BinaryHeap::dft_iterator::next()
{
	if (!has_next())
	{
		throw out_of_range("No more elements");
	}
	
	int temp = _current->_data;
	

	if (_current->_right != nullptr)
	{	
		stack->push(_current->_right);
	}
	
	if (_current->_left != nullptr)
	{
		_current = _current->_left;
	}
	else
	{
		try
		{
			_current = stack->top();
			stack->pop();
		}
		catch (out_of_range)
		{
			_current = nullptr;
		}	
	}

	return temp;
}

bool BinaryHeap::dft_iterator::has_next()
{
	return _current != nullptr;
}

//BFT

Iterator* BinaryHeap::create_bft_iterator()
{
	bft_iterator* new_bft_iterator = new bft_iterator(_root);
	new_bft_iterator->queue->push(_root);
	return new_bft_iterator;
}

BinaryHeap::bft_iterator::bft_iterator(Node* root)
{
	_current = root;
	queue = new Queue<Node*>();
}

BinaryHeap::bft_iterator::~bft_iterator()
{
	delete queue;
}

int BinaryHeap::bft_iterator::next()
{
	if (!has_next())
	{
		throw out_of_range("No more elements");
	}
	
	int temp = _current->_data;
	
	if (_current->_left != nullptr)
	{
		queue->push(_current->_left);
	}

	if (_current->_right != nullptr)
	{
		queue->push(_current->_right);
	}

	queue->pop();
		
	try
	{
		_current = queue->front();
	} 
	catch (out_of_range)
	{
		_current = nullptr;
	}

	return temp;
}

bool BinaryHeap::bft_iterator::has_next()
{
	return _current != nullptr;
}