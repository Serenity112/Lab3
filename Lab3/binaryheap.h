#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>
#include "iterator.h"

template <class T>
class Queue;

template <class T>
class Stack;

class BinaryHeap
{
private:
	class Node
	{
	public:
		Node(int);

		Node* _parent;
		Node* _left;
		Node* _right;

		int _data;	
	};

	Node* _root;

	int _height;
	int _lastLineNodesCount;

	void Heapify(Node*);

	void siftDown(Node*);

	void siftUp(Node*);

public:
	BinaryHeap();

	~BinaryHeap();

	bool empty();

	bool contains(int);

	void insert(int);

	void remove(int);

	Node* findNode(int);

	Node* findParentOfLast(int);

	Node* getRoot();

	Iterator* create_dft_iterator();

	Iterator* create_bft_iterator();

	class dft_iterator : public Iterator
	{
	public:
		friend class BinaryHeap;

		dft_iterator(Node*);

		~dft_iterator();

		bool has_next() override;

		int next() override;

	private:
		Stack<Node*>* stack;

		Node* _current;
	};

	class bft_iterator : public Iterator
	{
	public:
		friend class BinaryHeap;

		bft_iterator(Node*);

		~bft_iterator();

		bool has_next() override;

		int next() override;


	private:
		Queue<Node*>* queue;

		Node* _current; 
	};
};

#endif