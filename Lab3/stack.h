#ifndef STACK_H
#define STACK_H
#include <iostream>

#include "binaryheap.h"



class Stack
{
private:
	class Node
	{
	public:
		Node(BinaryHeap::Node*);
		Node(BinaryHeap::Node*, Node*);

		BinaryHeap::Node* _node;
		Node* _prev;
	};

	Node* _head;

	int _count;

public:
	Stack();

	int getSize();

	void pop();

	void push(BinaryHeap::Node*);

	bool empty();

	BinaryHeap::Node* top();
};

#endif