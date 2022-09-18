// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
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

int countLength(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->Next;
        count++;
    }
    return count;
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

//non recursive way 
Node * reverseList(Node* &head){
    Node *prev = NULL;
    Node *current = head;
    Node *next = current->Next;
    while(next !=NULL){
        next = next->Next ;
        current->Next = prev ;
        prev = current ;
        current = next ;
    }

    return prev;
}

Node *reverseKNode(Node *head ,int k){
        if(head == NULL) return head;
        Node *curr = head;
        Node *prev = NULL;
        Node *nxt = curr->Next;
        int count = 0;
  
    /*reverse first k nodes of the linked list */
        while (curr != NULL && count < k) {
            if(curr && prev && nxt){
                cout<<"prev "<<prev->value <<endl;
                cout<<"curr "<<curr->value <<endl;
                cout<<"nxt "<<nxt->value <<endl;
                // cout<<"head "<<head->value<<endl;
            }
            nxt = curr->Next;
            curr->Next = prev;
            prev = curr;
            curr = nxt;
            count++;
        }
        
        if(nxt){
            head->Next = reverseKNode(nxt,k);
            cout<<head->Next->value<<"->";
        }
        
        return prev ;
    }


//with recursive way 
//you have to understand how recursive function work otherwise yoy do not understend this function
Node * recusiveReverseList(Node* &head){
    if(head->Next == NULL){
        return head; 
    }
    /* reverse the rest list and put
     the first element at the end */
    Node *newNode = recusiveReverseList(head->Next);
     head->Next->Next = head; 
     /* tricky step */
     head->Next = NULL ;

    return newNode;
}

int main()
{
    Node *head = NULL;
    insertTail(head, 1);
    insertTail(head, 2);
    insertTail(head, 3);
    insertTail(head, 4);
    insertTail(head, 5);
    insertTail(head, 6);
    head = reverseKNode(head,2) ;
    // print_list(head);
    cout<<endl;



    return 0;
}