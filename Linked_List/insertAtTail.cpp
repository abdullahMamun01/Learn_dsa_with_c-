// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;
    Node(int value)
    {
        this->value = value;
        this->Next = NULL;
    }
};

void insertTail(Node *&head , int value){
    Node *newNode = new Node(value); // create new node for insert in tail
    if(head == NULL){
        head = newNode ; // if NULL we set head value is create newNode to point
        return;
    }
    Node *temp = head ;
    
    while(temp->Next != NULL){
        temp = temp->Next; // until temp update untill temp->Next not found NULL 
    }
    // cout<<temp->value <<endl;
    temp->Next = newNode ; // if found null we set newNode to temp->Next = newNode

}

void print_list(Node *n)
{
    while (n != NULL)
    {
        cout << n->value << " ";
        n = n->Next;
    }
}

int main()
{
    Node *head = NULL;
    insertTail(head,100);
    insertTail(head,300);
    print_list(head);
    return 0;
}