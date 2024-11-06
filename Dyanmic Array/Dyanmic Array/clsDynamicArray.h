#pragma once
#include <iostream>

using namespace std;

template <class T> class clsDynamicArray 
{
	private:
		int _Size = 0;
		T* _PtrArray;
		T* _TempArray;
		T* _RevArray;
	public:
		clsDynamicArray(int Size)
		{
			if (Size < 0)
				Size = 0;
			_Size = Size;
			_PtrArray = new T[_Size];
			_RevArray = new T[_Size];
		}
		
		bool SetItem(int index , T Data)
		{
			if (index > _Size - 1 || _Size < 0)
				return false;
			_PtrArray[index] = Data;
			_RevArray[_Size - index - 1] = Data;
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
			
			return;
		}

		void Resize(int NewSize = 0)
		{
			if (NewSize == _Size)
				return;

			if (NewSize < 0)
				NewSize = 0;

			_TempArray = new T[NewSize];

			//limit the original size to the new size if it is less.
			if (NewSize < _Size)
				_Size = NewSize;

			delete[] _RevArray;
			_RevArray = new T[NewSize];
			//copy all data from original array until the size
			for (int i = 0; i < _Size; i++)
			{
				_TempArray[i] = _PtrArray[i];
				_RevArray[NewSize - i - 1] = _PtrArray[i];
			}

			_Size = NewSize;

			delete[] _PtrArray;
			_PtrArray = _TempArray;
			return;
			

		}

		T Getitem(int Index = 0)
		{
			if (Index < 0 || Index >= _Size)
				return NULL;

			return _PtrArray[Index];
		}

		bool Reverse()
		{
			if (_PtrArray == nullptr)
				return false;

			_TempArray = _PtrArray;
			_PtrArray = _RevArray;
			_RevArray = _TempArray;

			return true;
		}

		void Clear()
		{
			delete[] _PtrArray;
			delete[] _RevArray;
		}

		void Delete()
		{
			_Size = 0;
			delete[] _PtrArray;
			delete[] _RevArray;
			_PtrArray = new T[0];
			_RevArray = new T[0];
		}

		~clsDynamicArray()
		{
			delete[] _PtrArray;
			delete[] _TempArray;
			delete[] _RevArray;
		}
};

