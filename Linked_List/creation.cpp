// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;
};

void print_list(Node  *n)
{
    while (n->Next != NULL)
    {
        cout<<n->value<<" ";
        n = n->Next;
    }
}

int main()
{
    Node *first = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();

    first->value = 1;
     second->value = 2;
    third->value = 3;
     fourth->value = 4;
    first->Next = second;
   
    second->Next = third;
    
    third->Next = fourth;
   
    fourth->Next = NULL;
    print_list(first);
    return 0;
}