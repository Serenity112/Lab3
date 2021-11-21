#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "binaryheap.h"

template <class T>
class Stack
{
private:

	class Node
	{
	public:
		Node(T);
		Node(T, Node*);

		T _node;
		Node* _prev;
	};

	Node* _head;
public:
	Stack();

	~Stack();

	void pop();

	void push( T elem);

	bool empty();

	T top();
};

#endif