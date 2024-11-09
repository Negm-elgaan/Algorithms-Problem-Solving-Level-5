// Dyanmic Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "clsDynamicArray.h"

using namespace std;

int main()
{

    clsDynamicArray <int> MyDynamicArray(5);

    MyDynamicArray.SetItem(0, 10);
    MyDynamicArray.SetItem(1, 20);
    MyDynamicArray.SetItem(2, 30);
    MyDynamicArray.SetItem(3, 40);
    MyDynamicArray.SetItem(4, 50);

    cout << "\nIs Empty?  " << MyDynamicArray.IsEmpty();
    cout << "\nArray Size: " << MyDynamicArray.Size() << "\n";
    cout << "\nArray Items: \n";

    MyDynamicArray.PrintList();
    cout << endl << endl;
    MyDynamicArray.Resize(7);
    MyDynamicArray.SetItem(5, 60);
    MyDynamicArray.SetItem(6, 70);
    MyDynamicArray.InsertAt(0, 100);
    MyDynamicArray.InsertAfter(3, 200);
    MyDynamicArray.InsertBefore(2, 300);
    MyDynamicArray.InsertAtBeginning(1);
    MyDynamicArray.InsertAtEnd(0);
    MyDynamicArray.PrintList();
    MyDynamicArray.DeleteItemAt(0);
    
    MyDynamicArray.PrintList();
    cout << endl << endl;
    MyDynamicArray.Reverse();
    MyDynamicArray.Reverse();
    MyDynamicArray.Reverse();
    MyDynamicArray.PrintList();
    MyDynamicArray.Clear();
    MyDynamicArray.SetItem(0, 10);
    MyDynamicArray.SetItem(1, 20);
    MyDynamicArray.SetItem(2, 30);
    cout << endl << endl;
    MyDynamicArray.PrintList();
    cout << endl;

    MyDynamicArray.PrintList();

    system("pause>0");

}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
