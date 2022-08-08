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
/* 
1.Traverse the Linked list upto position-1 nodes.
2.Once all the position-1 nodes are traversed, allocate memory and the given data to the new node.
3.Point the next pointer of the new node to the next of current node.
4.Point the next pointer of current node to the new node.


 */
void isertAtSpecificPosition(Node *head ,int position,int value){
    //copy of head
    Node *temp = head;
    //create new node for insert value specific position
    Node *newNode = new Node(value);
    int i = 1; //if we count index we have to start with 0 
    //traverse positon-1 because we have to finde out insert befor positon
    while(i< position-1){
        //update node until position-1 
        temp = temp->Next ;
        i++;
    }
    //current node is position-1 node
    Node *currenNode = temp ;
    //we have link with  newNode to currentNode of next node 
    newNode->Next = currenNode->Next;
    //after link newNode next node now we have update connecting the currentNode to next node
    currenNode->Next = newNode ;
    


}
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
    insertTail(head,200);
    insertTail(head,300);
    insertTail(head,500);
    insertTail(head,600);
    insertTail(head,700);
    //before insert 100 200 300 500 600 700 
    isertAtSpecificPosition(head,4,400);
    //after insert 100 200 300 400 500 600 700 
    print_list(head);
    return 0;
}