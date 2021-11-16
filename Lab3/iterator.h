#ifndef ITERATOR_H
#define ITERATOR_H

class Iterator
{
public:
	virtual int next() = 0;
	virtual bool has_next() = 0;
};

#endif ITERATOR_H