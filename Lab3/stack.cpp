#include <iostream>
#include "stack.h"
using namespace std;


template <class T> Stack<T>::Node::Node(T node, Node* prev)
{
	_node = node;
	_prev = prev;
}

template <class T> Stack<T>::Node::Node(T node) : Node(node, nullptr) { }


template <class T> Stack<T>::Stack()
{
	_head = nullptr;
}

template <class T> 
Stack<T>::~Stack()
{
	while (!empty())
	{
		pop();
	}
}

template <class T> void Stack<T>::push( T node)
{
	Node* newNode = new Node(node, _head);
	_head = newNode;
}

template <class T> void Stack<T>::pop()
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

template <class T> bool Stack<T>::empty()
{
	return _head == nullptr;
}

template <class T> T Stack<T>::top()
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