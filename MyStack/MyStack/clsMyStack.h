#pragma once
#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

template <class T> class clsMyStack
{
	protected:
		clsDblLinkedList <T> _MyList;
	public:

		void Push(T Data)
		{
			_MyList.InsertAtBeginning(Data);
			return;
		}

		void Pop()
		{
			_MyList.DeleteFirstNode();
			return;
		}

		int Size()
		{
			return _MyList.Size();
		}

		T Top()
		{
			return _MyList.GetItem(0);
		}

		T Bottom()
		{
			return _MyList.GetItem(Size() - 1);
		}

		bool UpdateItem(int index , T NewVal)
		{
			return _MyList.UpdateItem(index, NewVal);
		}

		void Reverse()
		{
			_MyList.Reverse();
			return;
		}

		bool IsEmpty()
		{
			return _MyList.IsEmpty();
		}

		bool InsertAfter(int Index, T Value)
		{
			return _MyList.InsertAfter(Index, Value);
		}

		void InsertAtFront(T Value)
		{
			_MyList.InsertAtBeginning(Value);
			return;
		}

		void Clear()
		{
			_MyList.Clear();
			return;
		}

		T GetItem(int Index)
		{
			return _MyList.GetItem(Index);
		}

		void InsertAtBack(T Value)
		{
			_MyList.InsertAtEnd(Value);
			return;
		}

		void Print()
		{
			_MyList.PrintList();
			return;
		}

};

/*#pragma once

#include <iostream>
#include "clsMyQueue.h"
using namespace std;
template <class T>

class  clsMyStack:public   clsMyQueue <T>
{

public :
	
	void push(T Item)
	{
		clsMyQueue <T>::_MyList.InsertAtBeginning(Item);
	}

	T Top()
	{
		return clsMyQueue <T>::front();
		
	}

	T Bottom()
	{
		return clsMyQueue <T>::back();

	}
	
};

*/