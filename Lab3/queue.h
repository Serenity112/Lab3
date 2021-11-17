#ifndef QUEUE_H	
#define QUEUE_H
#include <iostream>
#include "binaryheap.h"

template <class T>
class Queue
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

	Node* _last;

public:
	Queue();

	void pop();

	void push(T);

	bool empty();

	T front();

	T back();

};

#endif