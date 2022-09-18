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

//Checks whether the value x is present in linked list if not found retun -1 
int searchSpecificValue(Node *head, int searchValue)
{
    Node *temp = head; //copy of head
    int count = 1;
    if(temp == NULL){
        return -1 ;
    };
    while (temp->value != searchValue)
    {
        if(temp->Next == NULL){
            return -1 ;
        }
        temp = temp->Next;
        count++;
    }
    return count;
}

//alternative
// int searchSpecificValue2(Node *head, int searchValue)
// {
//     Node *temp = head;
//     int count = 1;
//     if(temp == NULL){
//         return -1 ;
//     };
//     while (temp != NULL)
//     {
//         if(temp->value == searchValue){
//             return count ;
//         }
//         temp = temp->Next;
//         count++;
//     }
//     return -1;
// }


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
    insertTail(head, 400);
    insertTail(head, 600);
    insertTail(head, 800);
    print_list(head);
    cout << endl;
    int p = searchSpecificValue(head, 30);
    cout << p << endl;
    return 0;
}