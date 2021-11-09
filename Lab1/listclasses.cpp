#include <iostream>
#include "listclasses.h"
using namespace std;





Node::Node(int Number, Node* next, Node* prev)
{
	SetNumber(Number);
	SetNext(next);
	SetPrev(prev);
}

Node::Node(int Number) : Node(Number, nullptr, nullptr)
{
}

Node::~Node()
{
	//Nothing to delete here :(
}

void Node::SetNext(Node* next)
{
	_next = next;
}

Node* Node::GetNext()
{
	return _next;
}

void Node::SetPrev(Node* prev)
{
	_prev = prev;
}

Node* Node::GetPrev()
{
	return _prev;
}

void Node::SetNumber(int Number)
{
	_number = Number;
}

int Node::GetNumber()
{
	return _number;
}



UnorderedList::UnorderedList()
{
	SetHead(nullptr);
	SetLast(nullptr);
}

UnorderedList::~UnorderedList()
{
	Node* currNode = GetHead();

	while (!(ifPointerEmpty(currNode)))
	{
		currNode = currNode->GetNext();
		delete GetHead();
		SetHead(currNode);
	}
}


Node* UnorderedList::GetHead()
{
	return _head;
}

Node* UnorderedList::GetLast()
{
	return _last;
}

void UnorderedList::SetHead(Node* elem)
{
	_head = elem;
}

void UnorderedList::SetLast(Node* elem)
{
	_last = elem;
}

bool ifPointerEmpty(Node* elem)
{
	return elem == nullptr;
}

//Check is list empty
bool UnorderedList::isEmpty()
{
	return GetHead() == nullptr;
}

//Add num to the end of list
void UnorderedList::push_back(int Number)
{
	Node* newElem = newElem = new Node(Number, nullptr, GetLast());
	if (isEmpty())
	{
		SetHead(newElem);
	}
	else
	{
		GetLast()->SetNext(newElem);
	}
	SetLast(newElem);
}

//Add num to the beginning of the list
void UnorderedList::push_front(int Number)
{
	Node* newElem = new Node(Number, GetHead(), nullptr);;
	if (isEmpty())
	{
		SetLast(newElem);
	}
	else
	{	
		GetHead()->SetPrev(newElem);
	}
	SetHead(newElem);
}

//Pop last elem
void UnorderedList::pop_back()
{
	if (isEmpty())
	{
		throw invalid_argument("Nothin to pop");
	}
	else if (ifPointerEmpty(GetHead()->GetNext()))
	{
		pop_only();
	}
	else
	{
		Node* currNode = GetLast()->GetPrev();
		delete GetLast();
		SetLast(currNode);
		currNode->SetNext(nullptr);
	}
}

//Pop first elem
void UnorderedList::pop_front()
{
	if (isEmpty())
	{
		throw invalid_argument("Nothin to pop");
	}
	else if (ifPointerEmpty(GetHead()->GetNext()))
	{
		pop_only();
	}
	else
	{
		Node* currNode = GetHead()->GetNext();
		delete GetHead();
		SetHead(currNode);
		currNode->SetPrev(nullptr);
	}
}

void UnorderedList::pop_only()
{
	if (ifPointerEmpty(GetHead()))
	{
		throw invalid_argument("Nothing to pop!");
	}
	else if(!(ifPointerEmpty(GetHead()->GetNext())))
	{
		throw invalid_argument("List contains more than 1 element to use pop_only");
	}
	else
	{
		delete GetHead();
		SetHead(nullptr);
		SetLast(nullptr);
	}	
}

//Insert element on this index before old elem with this index
void UnorderedList::insert(int Number, size_t index)
{
	Node* rightElem = FindElem(index);

	if (ifPointerEmpty(rightElem->GetPrev()))
	{
		Node* newElem = new Node(Number, rightElem, nullptr);
		rightElem->SetPrev(newElem);
		SetHead(newElem);
	}
	else
	{
		Node* leftElem = rightElem->GetPrev();
		Node* newElem = new Node(Number, rightElem, leftElem);
		rightElem->SetPrev(newElem);
		leftElem->SetNext(newElem);
	}
}

//Get elem with index
Node* UnorderedList::FindElem(size_t index)
{
	if (index < get_size())
	{
		Node* currNode = GetHead();
		for (int i = 0; i < index; i++)
		{
			currNode = currNode->GetNext();
		}
		return currNode;
	}
	else
	{
		throw out_of_range("Index not found!");
	}

}

//Get number of elem with this index
int UnorderedList::GetElem(size_t index)
{
	Node* node = FindElem(index);
	return node->GetNumber();
}

//Delete elem with this index
void UnorderedList::remove(size_t index)
{
	Node* CurrElem = FindElem(index);

	if (ifPointerEmpty(GetHead()->GetNext()))
	{
		pop_only();
		return;
	}

	if (ifPointerEmpty(CurrElem->GetNext()))
	{
		pop_back();
		return;
	}

	if (ifPointerEmpty(CurrElem->GetPrev()))
	{
		pop_front();
		return;
	}

	CurrElem->GetNext()->SetPrev(CurrElem->GetPrev());
	CurrElem->GetPrev()->SetNext(CurrElem->GetNext());
	delete CurrElem;
}

//Get list size
size_t UnorderedList::get_size()
{
	Node* curNode = GetHead();
	size_t size = 0;
	while (!ifPointerEmpty(curNode))
	{
		size++;
		curNode = curNode->GetNext();
	}
	return size;
}

//Delete all elems in list
void UnorderedList::clear()
{
	this->~UnorderedList();
	return;
}

//Change elem's num
void UnorderedList::set(size_t index, int Number)
{
	Node* currNode = FindElem(index);
	currNode->SetNumber(Number);
}


//Swap elems
void UnorderedList::swap(size_t index1, size_t index2)
{
	Node* Element1 = FindElem(index1);
	Node* Element2 = FindElem(index2);

	int buf = Element1->GetNumber();
	Element1->SetNumber(Element2->GetNumber());
	Element2->SetNumber(buf);
}



ostream& operator << (ostream& stream, const UnorderedList& unorderedlist)
{

	if (ifPointerEmpty(unorderedlist._head))
	{
		stream << "List is empty!" << endl;
	}
	else
	{

		Node* node = unorderedlist._head;

		while (!(ifPointerEmpty(node)))
		{
			stream << node->GetNumber();

			if (!ifPointerEmpty(node->GetNext()))
			{
				stream << " -> ";
				
			}
			else
			{
				break;
			}
			
			node = node->GetNext();
		}
		stream << endl << endl;
	}
	return stream;
}