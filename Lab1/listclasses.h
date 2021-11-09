#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
using namespace std;

class Node
{
public:
	Node(int Number);

	Node(int Number, Node* next, Node* prev);

	~Node();

	Node* GetNext();

	Node* GetPrev();

	void SetNext(Node* next);

	void SetPrev(Node* prev);

	void SetNumber(int Number);

	int GetNumber();

private:
	Node* _next;
	Node* _prev;
	int _number;
};



class UnorderedList
{
public:
	UnorderedList();

	~UnorderedList();

	Node* GetHead();

	Node* GetLast();

	void SetHead(Node* elem);

	void SetLast(Node* elem);

	void push_back(int);

	void push_front(int);

	void pop_back();

	void pop_front();

	

	void insert(int, size_t);

	Node* FindElem(size_t index);

	int GetElem(size_t);

	void remove(size_t);

	size_t get_size();

	void clear();

	void set(size_t, int);

	bool isEmpty();

	void swap(size_t, size_t);

	friend ostream& operator << (ostream& stream, const UnorderedList& unorderedlist);

private:
	void pop_only();

	Node* _head;
	Node* _last;
};

bool ifPointerEmpty(Node*);

#endif