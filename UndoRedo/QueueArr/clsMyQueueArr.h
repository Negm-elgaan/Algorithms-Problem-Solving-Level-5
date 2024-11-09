#pragma once

#include <iostream>
#include "clsDynamicArray.h"


using namespace std;
template <class T>

class clsMyQueueArr
{

protected:
    clsDynamicArray <T> _MyDynamicArr;

public:

    void push(T Item)
    {
        _MyDynamicArr.InsertAtEnd(Item);
    }


    void pop()
    {
        _MyDynamicArr.DeleteFirstitem();
    }

    void Print()
    {
        _MyDynamicArr.PrintList();
    }

    int Size()
    {
        return  _MyDynamicArr.Size();
    }

    bool IsEmpty()
    {
        return  _MyDynamicArr.IsEmpty();
    }

    T front()
    {
        return _MyDynamicArr.Getitem(0);
    }

    T back()
    {
        return  _MyDynamicArr.Getitem(Size() - 1);
    }

    void Reverse()
    {
        _MyDynamicArr.Reverse();
    }

    bool UpdateItem(int index, T newval)
    {
        return  _MyDynamicArr.SetItem(index, newval);
    }

    T GetItem(int index)
    {
        return _MyDynamicArr.Getitem(index);
    }

    void InsertAtFront(T Data)
    {
        _MyDynamicArr.InsertAtBeginning(Data);
    }

    void InsertAtBack(T Data)
    {
        _MyDynamicArr.InsertAtEnd(Data);
    }

    bool InsertAfter(int index, T Data)
    {
        return  _MyDynamicArr.InsertAfter(index, Data);
    }

    void Clear()
    {
        _MyDynamicArr.Clear();
    }
};