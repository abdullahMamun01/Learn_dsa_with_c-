// Online C++ compiler to run C++ program online
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
    bool isEmpty()
    {
        return Head == NULL ? true : false;
    }
    ST pop()
    {
        Node<ST> *delNode = Top;
        ST check;
        if (Head == NULL)
        {
            cout << "thre is no element in the list" << endl;
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
    ST top()
    {
        return this->Top->value;
    }

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