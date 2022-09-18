// Online C++ compiler to run C++ program online
/*
Doubly Linked List is a variation of Linked list in which navigation is possible in both
ways, either forward and backward easily as compared to Single Linked List. Following
are the important terms to understand the concept of doubly linked list.

*Link − Each link of a linked list can store a data called an element.

*Next − Each link of a linked list contains a link to the next link called Next.

*Prev − Each link of a linked list contains a link to the previous link called Prev.

*LinkedList − A Linked List contains the connection link to the first link called 
First and to the last link called Last.
*/


#include <bits/stdc++.h>
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
    newNode->Prev = temp;
}

void print_list(Node *n)
{
    while (n != NULL)
    {
        cout << n->value << " ";
        n = n->Next;
    }
}

void display_reverse(Node *head)
{
    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->Prev;
    }
}
void insert_At_Head(Node *&head, int value)
{
    Node *newHead = new Node(value);
    newHead->Next = head;
    head->Prev = newHead;
    head = newHead;
}

void deleteByValue(Node *head, int val)
{
    Node *temp = head;
    Node *save;
    while (temp != NULL)
    {
        if (temp->value == val)
        {
            save = temp->Next;
            temp = temp->Prev;
            save->Prev = temp;
            temp->Next = save;

        }
        temp = temp->Next;
    }
}
void deleteTail(Node *&head){
    Node *tmp = head ;
    int position = countLength(head);
    for(int i=0;i<position-2 ;i++){
        tmp = tmp->Next ;
    }
    Node *tail = tmp->Next ;
    tmp->Next = NULL ;
    delete tail;

}
// int search_specific_value(Node *head,int value){
//     Node *tmp = head;
//     int count = 1;
//     while(tmp != NULL){
//         tmp = tmp->Next;
//     }
// } 
void delete_by_position(Node *head ,int position) {};
// void deleteByValue(Node *head ,int val){
//     Node *temp = head;
//     while(temp != NULL){
//         if(temp->value == val){
//             Node *saveNext = temp->Next;
//             Node *previous = temp->Prev ;
//             previous->Next = saveNext ;
//             saveNext->Prev = previous ;
//             delete temp;
//         }
//         temp = temp->Next ;
//     }
// }


// 1 2 3 4 5 6
void insetAtPosition(Node *&head, int pos, int value)
{
    Node *temp = head;
     // create new node for insert
    Node *newNode = new Node(value);
    if (pos == 0)
    {
        newNode->Next = head;
        head->Prev = newNode;
        head = newNode;
        return;
    }
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->Next;
    }
    // save temp next node
    Node *saveNext = temp->Next;
   
    if (saveNext == NULL)
    {
        temp->Next = newNode;
        newNode->Prev = temp;
    }
    else
    {
        // point newNode to previous node
        newNode->Prev = temp;
        // update temp next
        temp->Next = newNode;
        // pont newNode next node
        newNode->Next = saveNext;
        // point to saveNext previous
        saveNext->Prev = newNode;
    }
}

int main()
{
    Node *head = NULL;
    insertTail(head, 100);
    insertTail(head, 200);
    insertTail(head, 300);
    insertTail(head, 400);
    insertTail(head, 500);
    insertTail(head, 700);
    insetAtPosition(head, 3, 350);
    display_reverse(head);
    // print_list(head);
    cout << endl;

    return 0;
}