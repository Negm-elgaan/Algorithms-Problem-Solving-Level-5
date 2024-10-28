#pragma once
#include <iostream>
using namespace std;
template <class T> class clsMyQueue
{
    private:
	    T Data;
        int _Size = 0;
        static class node
        {
            public:
                T Data;
                node* next;
                node* prev;
        };
        clsMyQueue::node* Head = NULL;
        clsMyQueue::node* Tail = NULL;
    public:
        void Push(T Data)
        {
            if (Head == NULL)
            {
                Head = new node();
                Head->Data = Data;
                Tail = new node();
                Tail->Data = Data;
                _Size++;
                return;
            }
            clsMyQueue::node* NewNode = new node();
            if (Head->next == NULL)
            {
                Head->next = NewNode;
            }
            NewNode->Data = Data;
            Tail->next = NewNode;
            NewNode->prev = Tail;
            Tail = NewNode;
            _Size++;
            return;
        }

        void Pop()
        {
            if (Head == NULL)
            {
                return;
            }
            clsMyQueue::node* Temp = Head;
            Head = Head->next;
            _Size--;
            delete Temp;
            return;
        }

        int Size()
        {
            return _Size;
        }

        T Front()
        {
            return Head->Data;
        }

        T Back()
        {
            return Tail->Data;
        }

        void Print()
        {
            clsMyQueue::node* temp = Head;
            if (Head == NULL)
            {
                return;
            }
            while (temp != NULL)
            {
                cout << temp->Data << endl;
                temp = temp->next;
            }

            return;
        }
};
/*#pragma once

#include <iostream>
#include "clsDblLinkedList.h"


using namespace std;
template <class T>

class clsMyQueue
{

protected:
	clsDblLinkedList <T> _MyList;

public:

	void push(T Item)
	{
		_MyList.InsertAtEnd(Item);
	}

	
	void pop()
	{
		_MyList.DeleteFirstNode();
	}

   void Print()
	{
		_MyList.PrintList();
	}

	int Size()
	{
		return _MyList.Size();
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	T front()
	{
		return _MyList.GetItem(0);
	}

	T back()
	{
		return _MyList.GetItem(Size() - 1);
	}

	
	
};


*/

