// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;
    Node(int value){
        this->value = value;
        this->Next = NULL;
    }
};

void print_list(Node  *n)
{
    while (n != NULL)
    {
        cout<<n->value<<" ";
        n = n->Next;
    }
}


void delete_list(Node *head,int pos){
    Node *tmp = head;
    for(int i=0;i<pos-1;i++){
        tmp= tmp->Next;
    }
    Node *save = tmp->Next->Next;
    delete tmp->Next ; 
    tmp->Next = save ;
    
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    head->Next = second;
    second->Next = third;
    third->Next = fourth;
    // insertList(head,0,100);
    delete_list(head,2);
    print_list(head);
    return 0;
}