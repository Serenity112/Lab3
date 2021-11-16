#include <iostream>
#include "queue.h"
using namespace std;


Queue::Node::Node(BinaryHeap::Node* node)
{
	_node = node;
	_prev = nullptr;
}

Queue::Queue()
{
	_head = nullptr;
	_last = nullptr;
}

void Queue::push(BinaryHeap::Node* node)
{
	Node* newNode = new Node(node);
	if (empty())
	{
		_head = newNode;
		_last = newNode;
	}
	else
	{
		_last->_prev = newNode;
		_last = newNode;
	}
}

void Queue::pop()
{
	if (empty())
	{
		throw out_of_range("No more elements");
	}
	else
	{
		Node* temp = _head;
		_head = _head->_prev;
		delete temp;
	}
}

bool Queue::empty()
{
	return _head == nullptr;
}

BinaryHeap::Node* Queue::front()
{
	if (empty())
	{
		throw out_of_range("Empty");
	}
	else
	{
		return _head->_node;
	}
	
}

BinaryHeap::Node* Queue::back()
{
	if (empty())
	{
		throw out_of_range("Empty");
	}
	else
	{
		return _last->_node;
	}
	
}