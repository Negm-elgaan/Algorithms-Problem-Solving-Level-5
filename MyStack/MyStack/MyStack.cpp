// MyStack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "clsMyStack.h"
using namespace std;

int main()
{
    clsMyStack <int> MyStack;

    MyStack.Push(10);
    MyStack.Push(20);
    MyStack.Push(30);
    MyStack.Push(40);
    MyStack.Push(50);


    cout << "\nStack: \n";
    MyStack.Print();

    cout << "\nStack Size: " << MyStack.Size();
    cout << "\nStack Top: " << MyStack.Top();
    cout << "\nStack Bottom: " << MyStack.Bottom();

    MyStack.Pop();

    cout << "\n\nStack after pop() : \n";
    MyStack.Print();

    //Extension #1
    cout << "\n\n Item(2) : " << MyStack.GetItem(2);

    //Extension #2
    MyStack.Reverse();
    cout << "\n\nStack after reverse() : \n";
    MyStack.Print();

    //Extension #3
    MyStack.UpdateItem(2, 600);
    cout << "\n\nStack after updating Item(2) to 600 : \n";
    MyStack.Print();

    //Extension #4
    MyStack.InsertAfter(2, 800);
    cout << "\n\nStack after Inserting 800 after Item(2) : \n";
    MyStack.Print();


    //Extension #5
    MyStack.InsertAtFront(1000);
    cout << "\n\nStack after Inserting 1000 at top: \n";
    MyStack.Print();

    //Extension #6
    MyStack.InsertAtBack(2000);
    cout << "\n\nStack after Inserting 2000 at bottom: \n";
    MyStack.Print();

    //Extension #7
    MyStack.Clear();
    cout << "\n\nStack after Clear(): \n";
    MyStack.Print();

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
