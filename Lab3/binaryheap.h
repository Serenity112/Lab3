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
		friend class BinaryHeapTest;

		Node(int);

		int _data;

		Node* _parent;
		Node* _left;
		Node* _right;
	};

	Node* _root;

	int _height;
	int _lastLineNodesCount;

	void siftDown(Node*);

	void siftUp(Node*);

	

public:

	friend class Stack<Node*>;
	friend class Queue<Node*>;

	BinaryHeap();

	~BinaryHeap();

	bool empty();

	bool contains(int);

	void insert(int);

	void remove(int);

	
	Node* getRoot();

	Node* findNode(int);

	Node* findParentOfLast(int);

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