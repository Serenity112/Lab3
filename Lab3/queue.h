#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

#include "binaryheap.h"

class Queue
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

	Node* _last;

public:
	Queue();

	void pop();

	void push(BinaryHeap::Node*);

	bool empty();

	BinaryHeap::Node* front();

	BinaryHeap::Node* back();

};

#endif