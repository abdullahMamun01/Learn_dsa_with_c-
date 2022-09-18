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
struct UniqeArray
{
    int position[100];
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

// search duplicate value
UniqeArray searchByUniqueValue(Node *head, int searchValue)
{
    Node *temp = head; // copy of head
    UniqeArray Array;
    int count = 1;
    // int flag = 0;
    int k = 1;
    while (temp != NULL)
    {
        if (temp->value == searchValue)
        {
            Array.position[k] = count;
            k++;
            // flag = 1;
        }
        temp = temp->Next;
        count++;
    }

    // if (flag == 0)
    // {
    //     cout << "Sorry value not found in this list" << endl;
    // }
    Array.position[0] = k;
    return Array;
}

void print_list(Node *n)
{
    while (n != NULL)
    {
        cout << n->value << " ";
        n = n->Next;
    }
}
// void deleteDuplicateValue(Node *&head ,int value){
//     UniqeArray *duplicate = searchByUniqueValue(head,value);
//     // int length = duplicate->position[0];


// }
int main()
{
    Node *head = NULL;
    insertTail(head, 100);
    insertTail(head, 200);
    insertTail(head, 300);
    insertTail(head, 400);
    insertTail(head, 300);
    insertTail(head, 700);
    print_list(head);
    cout<<endl;


    UniqeArray searchByValue = searchByUniqueValue(head, 300);

    if(searchByValue.position[0] == 1){
        cout << "Sorry value not found in this list" << endl;
    }else{
        int k = searchByValue.position[0];
        for(int i=1;i<k ;i++){
            cout<<searchByValue.position[i]<<" ";
        }
    }
    return 0;
}