// Online C++ compiler to run C++ program online
/*
A Stack is a linear data structure that follows the LIFO (Last-In-First-Out) principle.
 Stack has one end, whereas the Queue has two ends (front and rear). 
 Whenever an element is added in the stack, it is added on the top(last element) of the stack, 
 and the element can be deleted only from the stack.
*/
#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T value;
    Node *Next;
    Node *Prev;
    Node(T value)
    {
        this->value = value;
        this->Next = NULL;
        this->Prev = NULL;
    }
};

template <typename ST>
class Stack
{
public:
    Node<ST> *Head;
    Node<ST> *Top;
    int count = 0;

public:
    Stack()
    {
        Head = NULL;
        Top = NULL;
    }
    //When we insert an element in a stack then the operation is known as a push
    void push(ST value)
    {
        Node<ST> *newNode = new Node<ST>(value);
        if (Head == NULL)
        {
            Head = newNode;
            Top = newNode;
            count++;
            return;
        }

        Top->Next = newNode;
        newNode->Prev = Top;
        Top = newNode;
        count++;
    }
    //It determines whether the stack is empty or not.
    bool isEmpty()
    {
        return Head == NULL ? true : false;
    }
    /* 
     When we delete an element from the stack, the operation is known as a pop.
     In a stack, the element is always deleted from top(last element) position
      Pop function does not take any value as parameter
     */
    ST pop()
    {
        Node<ST> *delNode = Top;
        ST check;
        if (Head == NULL)
        {
            cout << "thre is no element in the list" << endl;
            return ;
        }
        if (Head == Top)
        {
            Head = NULL;
            Top = NULL;
        }
        else
        {

            Top = delNode->Prev;
            Top->Next = NULL;
        }
        check = delNode->value;
        count--;
        delete delNode;
        return check;
    }
    ST getValue()
    {
        return this->Head->value;
    }
    void display()
    {
        Node<ST> *tmp = Head;
        while (tmp != NULL)
        {
            cout << tmp->value << " ";
            tmp = tmp->Next;
        }
        cout << endl;
    }
    //return top element in the stack
    ST top()
    {
        return this->Top->value;
    }
    //It returns the total number of elements available in a stack.
    int size()
    {
        return count;
    }
    ST mid()
    {
        int midPoint = this->size() / 2;
        int eventOrNot = this->size() % 2 == 0 ? (midPoint - 1) : midPoint;
        midPoint = eventOrNot;
        Node<ST> *tmp = Head;
        for (int i = 1; i <= midPoint; i++)
        {
            tmp = tmp->Next;
        }
        return tmp->value;
    }
};