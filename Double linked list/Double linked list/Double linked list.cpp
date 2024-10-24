// Double linked list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
template <class T> class clsDblLinkedList
{
    int size = 0;
    public:
        static class node
        {
            public:
                T Data;
                node* next;
                node* prev;
        };
        node* head = NULL;
        node* tail = NULL;
        
        void InsertAtBeginning(T Data)
        {
            if (head == NULL)
            {
                head = new node();
                head->Data = Data;
                head->next = NULL;
                head->prev = NULL;
                tail = new node();
                tail->Data = Data;
                tail->next = NULL;
                tail->prev = NULL;
                size++;
                return;
            }
            node* NewNode = new node();
            NewNode->Data = Data;
            NewNode->next = head;
            if (head->next == NULL)
                tail->prev = NewNode;
            head->prev = NewNode;
            head = NewNode;
            size++;
            cout << tail->Data << endl;
            return;
        }

        void InsertAtEnd(T Data)
        {
            if (head == NULL)
            {
                head = new node();
                head->Data = Data;
                head->next = NULL;
                head->prev = NULL;
                tail = new node();
                tail->Data = Data;
                tail->next = NULL;
                tail->prev = NULL;
                size++;
                return;
            }
            node* NewNode = new node();
            NewNode->Data = Data;
            
            node* Temp = head;
            while (Temp->next != NULL)
                Temp = Temp->next;
            NewNode->prev = Temp;
            Temp->next = NewNode;
            tail = NewNode;
            size++;
            //cout << Temp->next->Data << endl;
            return;
        }

        node* Find(T Data)
        {
            if (head == NULL)
                return NULL;
            node* Temp = head;
            if (Temp->Data == Data)
                return Temp;
            while (Temp != NULL)
            {
                if (Temp->Data == Data)
                    return Temp;
                Temp = Temp->next;
            }
            return Temp = NULL;
        }

        void InsertAfter(node* node1 , T Data)
        {
            node* NewNode = new node();
            if (head == node1 && head->next != NULL)
            {
                NewNode->Data = Data;
                NewNode->prev = head;
                NewNode->next = head->next;
                head->next->prev = NewNode;
                head->next = NewNode;
                size++;
                return;
            }
            else if (head == node1 && head->next == NULL)
            {
                NewNode->Data = Data;
                NewNode->prev = head;
                NewNode->next = head->next;
                head->next = NewNode;
                tail = NewNode;
                size++;
                return;
            }
            node* Current = head->next;
            while (Current->next != NULL)
            {
                if (Current == node1)
                {
                    NewNode->Data = Data;
                    NewNode->prev = Current;
                    NewNode->next = Current->next;
                    Current->next->prev = NewNode;
                    Current->next = NewNode;
                    size++;
                    return;
                }
                Current = Current->next;
            }
            if (Current == node1)
            {
                NewNode->Data = Data;
                NewNode->prev = Current;
                NewNode->next = Current->next;
                Current->next = NewNode;
                tail = NewNode;
                size++;
                return;
            }
            return;
        }

        void DeleteFirstNode()
        {
            node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }

        void DeleteNode(T Data)
        {
            node* temp = head;
            if (head->Data == Data)
            {
                head = head->next;
                delete temp;
                size--;
                return;
            }
            while (temp->next != NULL)
            {
                if (temp->Data == Data)
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                    size--;
                    return;
                }
                temp = temp->next;
            }
            if (temp->Data == Data)
            {
                temp->prev->next = temp->next;
                tail = temp->prev;
                delete temp;
                size--;
                return;
            }
            return;
        }

        void DeleteLastNode()
        {
            node* temp = head;
            if (head->next == NULL)
            {
                head = head->next;
                delete temp;
                size--;
                return;
            }
            while (temp->next != NULL)
                temp = temp->next;
            tail = temp->prev;
            temp->prev->next = NULL;
            delete temp;
            size--;
            return;
        }

        void DeleteNode(node*& NodeToDelete) 
        {

            /*
                1-Set the next pointer of the previous node to the next pointer of the current node.
                2-Set the previous pointer of the next node to the previous pointer of the current node.
                3-Delete the current node.
            */
            if (head == NULL || NodeToDelete == NULL) {
                return;
            }
            if (head == NodeToDelete) {
                head = NodeToDelete->next;
            }
            if (NodeToDelete->next != NULL) {
                NodeToDelete->next->prev = NodeToDelete->prev;
            }
            if (NodeToDelete->prev != NULL) {
                NodeToDelete->prev->next = NodeToDelete->next;
            }
            delete NodeToDelete;
        }

        int Size()
        {
            return size;
        }

        bool IsEmpty()
        {
            return head == NULL;
            // return size == 0 ;
        }

        void Clear()
        {
            while(head != NULL)
            {
                node* Temp = head;
                head = head->next;
                size--;
                delete Temp;
            }
            return;
        }

        void PrintNode()
        {
            node* temp = head;
            if (head == NULL)
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

        void Reverse()
        {
            node* temp = tail;
            if (tail == NULL)
                return;
            while (temp != NULL)
            {
                cout << temp->Data << endl;
                temp = temp->prev;
            }

            return;
        }

        void  Reverse()
        {
            Node* current = head;
            Node* temp = nullptr;
            while (current != nullptr) {
                temp = current->prev;
                current->prev = current->next;
                current->next = temp;
                current = current->prev;
            }

            if (temp != nullptr) {
                head = temp->prev;
            }
        }

};
int main()
{
    clsDblLinkedList <int> dbllinked;
    dbllinked.InsertAtBeginning(3);
    //dbllinked.DeleteFirstNode();
    //dbllinked.DeleteLastNode();
    //dbllinked.DeleteNode(3);
    dbllinked.InsertAtBeginning(2);
    dbllinked.InsertAtBeginning(1);
    dbllinked.InsertAtEnd(4);
    dbllinked.InsertAtBeginning(0);
    dbllinked.PrintNode();
    clsDblLinkedList <int> :: node* node1 = dbllinked.Find(0);
    
    dbllinked.InsertAfter(node1, 5);
    cout << endl;
    dbllinked.PrintNode();
    cout << endl;
    dbllinked.PrintNode();
    cout << "Size: " << dbllinked.Size() << endl;
  
    dbllinked.Reverse();
    cout << "\n//\n";
    dbllinked.Clear();
    dbllinked.PrintNode();
    cout << "Size: " << dbllinked.Size();
}
/*//ProgrammingAdvices.com
//Mohammed Abu-Hadhoud

#pragma once
#include <iostream>
using namespace std;


template <class T>
class clsDblLinkedList
{

public:

    class Node
    {

    public:
        T value;
        Node* next;
        Node* prev;
    };

    Node* head = NULL;

    void InsertAtBeginning(T value)
    {

        /*
            1-Create a new node with the desired value.
            2-Set the next pointer of the new node to the current head of the list.
            3-Set the previous pointer of the current head to the new node.
            4-Set the new node as the new head of the list.
        */

/*Node* newNode = new Node();
newNode->value = value;
newNode->next = head;
newNode->prev = NULL;

if (head != NULL) {
    head->prev = newNode;
}
head = newNode;


    }

    // Print the linked list
    void PrintList()

    {
        Node* Current = head;

        while (Current != NULL) {
            cout << Current->value << " ";
            Current = Current->next;
        }
        cout << "\n";


    }

    Node* Find(T Value)
    {
        Node* Current = head;
        while (Current != NULL) {

            if (Current->value == Value)
                return Current;

            Current = Current->next;
        }

        return NULL;

    }

    void InsertAfter(Node* current, T value) {


        /*  1 - Create a new node with the desired value.
             2-Set the next pointer of the new node to the next node of the current node.
             3-Set the previous pointer of the new node to the current node.
             4-Set the next pointer of the current node to the new node.
             5-Set the previous pointer of the next node to the new node(if it exists).
        */

       /* Node* newNode = new Node();
        newNode->value = value;
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;


    }

    void InsertAtEnd(T value) {

        /*
            1-Create a new node with the desired value.
            2-Traverse the list to find the last node.
            3-Set the next pointer of the last node to the new node.
            4-Set the previous pointer of the new node to the last node.
        */


      /*  Node* newNode = new Node();
        newNode->value = value;
        newNode->next = NULL;
        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }


    }

    void DeleteNode(Node*& NodeToDelete) {

        /*
            1-Set the next pointer of the previous node to the next pointer of the current node.
            2-Set the previous pointer of the next node to the previous pointer of the current node.
            3-Delete the current node.
        */
       /* if (head == NULL || NodeToDelete == NULL) {
            return;
        }
        if (head == NodeToDelete) {
            head = NodeToDelete->next;
        }
        if (NodeToDelete->next != NULL) {
            NodeToDelete->next->prev = NodeToDelete->prev;
        }
        if (NodeToDelete->prev != NULL) {
            NodeToDelete->prev->next = NodeToDelete->next;
        }
        delete NodeToDelete;


    }

    void DeleteFirstNode()
    {

        /*
            1-Store a reference to the head node in a temporary variable.
            2-Update the head pointer to point to the next node in the list.
            3-Set the previous pointer of the new head to NULL.
            4-Delete the temporary reference to the old head node.
        */

       /* if (head == NULL) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;

    }

    void DeleteLastNode() {

        /*
            1-Traverse the list to find the last node.
            2-Set the next pointer of the second-to-last node to NULL.
            3-Delete the last node.
        */

       /* if (head == NULL) {
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* current = head;
        // we need to find the node before last node.
        while (current->next->next != NULL)
        {
            current = current->next;
        }

        Node* temp = current->next;
        current->next = NULL;
        delete temp;

    }

};

*/
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
