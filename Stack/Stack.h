// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *Next;
    Node *Prev;
    Node(int value)
    {
        this->value = value;
        this->Next = NULL;
        this->Prev = NULL;
    }
};

class Stack
{
public:
    Node *Head;
    Node *Top;
    int count = 0;

public:
    Stack()
    {
        this->Head = NULL;
        this->Top = NULL;
    }
    void push(int value)
    {
        Node *newNode = new Node(value);
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
    int isEmpty()
    {
        return Head == NULL ? true : false;
    }
    int pop()
    {
        Node *delNode = Top;
        int check;
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
    void display()
    {
        Node *tmp = Head;
        while (tmp != NULL)
        {
            cout << tmp->value << " ";
            tmp = tmp->Next;
        }
        cout<<endl;
    }
    int top(){
        return this->Top->value ;

    }

        int
        size()
    {
        return count;
    }
};
