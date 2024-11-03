#pragma once
#include <iostream>

using namespace std;

template <class T> class clsDynamicArray 
{
	private:
		int _Size = 0;
		T* _PtrArray;
	public:
		clsDynamicArray(int Size)
		{
			if (Size < 0)
				Size = 0;
			_Size = Size;
			_PtrArray = new T[_Size];
		}
		
		bool SetItem(int index , T Data )
		{
			if (index > _Size - 1 || _Size < 0)
				return false;
			_PtrArray[index] = Data;
			return true;
		}

		bool IsEmpty()
		{
			return _Size == 0;
		}

		int Size()
		{
			return _Size;
		}

		void PrintList()
		{
			for (int i = 0; i < _Size; i++)
			{
				cout << _PtrArray[i] << " ";
			}
			
			cout << "\n";
		}

		~clsDynamicArray()
		{
			delete[] _PtrArray;
		}
};

