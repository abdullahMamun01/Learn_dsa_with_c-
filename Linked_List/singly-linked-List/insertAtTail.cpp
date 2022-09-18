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
    
    //traverse to the last node
    while(temp->Next != NULL){
        temp = temp->Next; // temp update untill temp->Next != NULL 
        
    }
    temp->Next = newNode ; // if found null we set newNode to temp->Next = newNode

}
void insertBetweenList(Node *&head ,int value){
     Node *tmp = head;
        Node *tmpNext = head->Next ;
        while(tmp->Next &&  !(tmp->value <= value && tmpNext->value >= value)){
            tmp = tmp->Next;
            tmpNext = tmpNext->Next ;
        }
    Node *newNode = new Node(value);
    tmp->Next = newNode ;
    newNode->Next = tmpNext;
}

void deleteFromList(Node *&head){
    Node *tmp = head;
    head = head->Next ;
    delete tmp;
}
void circularLinkedList(Node *&head){
    Node *tmp = head ;
    while(tmp->Next !=NULL){
        tmp = tmp->Next ;
    }
    tmp->Next = head ;
    // cout<<tmp->value<<endl;
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
    insertTail(head,14);
    insertTail(head,25);
    insertTail(head,33);
    insertTail(head,47);
    insertBetweenList(head,40);
    deleteFromList(head);
    circularLinkedList(head);
    print_list(head);
    return 0;
}