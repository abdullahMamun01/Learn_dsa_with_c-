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
void deleteAtSpecificPosition(Node *head, int position){
    // copy of head
    Node *temp = head;//if we count index we have to start with 0
    int i = 1;
    // traverse positon-1 because we have to finde out delete before positon .
    //suppose if we want to delet position 3 we have finde out position 2
    while(i< position-1){
        temp = temp->Next ;
        i++;
    }
    Node *currentNode = temp ;
    Node *deletNode = currentNode->Next ;
    currentNode->Next = currentNode->Next->Next ;
    delete deletNode;

}
void insertTail(Node *&head, int value)
{
    Node *newNode = new Node(value); // create new node for insert in tail
    if (head == NULL)
    {
        head = newNode; // if NULL we set head value is create newNode to point
        return;
    }
    Node *temp = head;

    // traverse to the last node
    while (temp->Next != NULL)
    {
        temp = temp->Next; // temp update untill temp->Next != NULL
    }
    temp->Next = newNode; // if found null we set newNode to temp->Next = newNode
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
    insertTail(head, 100);
    insertTail(head, 200);
    insertTail(head, 300);
    insertTail(head, 500);
    insertTail(head, 600);
    insertTail(head, 700);
    // before insert 100 200 300 500 600 700
    // isertAtSpecificPosition(head, 4, 400);
    // after insert 100 200 300 400 500 600 700
    deleteAtSpecificPosition(head,3) ;
    print_list(head);
    return 0;
}