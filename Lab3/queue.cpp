#include <iostream>
#include "queue.h"
using namespace std;


template <class T> Queue<T>::Node::Node(T node)
{
	_node = node;
	_prev = nullptr;
}

template <class T> Queue<T>::Queue()
{
	_head = nullptr;
	_last = nullptr;
}

template <class T> void Queue<T>::push(T node)
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

template <class T> void Queue<T>::pop()
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

template <class T> bool Queue<T>::empty()
{
	return _head == nullptr;
}

template <class T> T Queue<T>::front()
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

template <class T> T Queue<T>::back()
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