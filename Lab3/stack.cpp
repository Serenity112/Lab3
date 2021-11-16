#include <iostream>
#include "stack.h"
using namespace std;

Stack::Node::Node(BinaryHeap::Node* node, Node* prev)
{
	_node = node;
	_prev = prev;
}

Stack::Node::Node(BinaryHeap::Node* node) : Node(node, nullptr) { }


Stack::Stack()
{
	_head = nullptr;
	_count = 0;
}

int Stack::getSize()
{
	return _count;
}

void Stack::push(BinaryHeap::Node* node)
{
	_count++;
	Node* newNode = new Node(node, _head);
	_head = newNode;
}

void Stack::pop()	
{
	if (empty())
	{
		throw out_of_range("No more elements");
	}
	else
	{
		_count--;
		Node* temp = _head;
		_head = _head->_prev;
		delete temp;
	}
}

bool Stack::empty()
{
	return _head == nullptr;
}

BinaryHeap::Node* Stack::top()
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