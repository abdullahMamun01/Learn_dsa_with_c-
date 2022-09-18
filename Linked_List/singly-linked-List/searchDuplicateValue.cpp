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
int countLength(Node *head){
    Node *temp = head;
    int count = 0;
    while(temp !=NULL){
        temp = temp->Next ;
        count++;
    }
    return count ;
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
void searDuplicatehValue(Node *head, int searchValue)
{
    Node *temp = head; // copy of head
    int count = 1;
    int flag = 0;
    int size = countLength(head);
    int arr[size] ;
    int k = 0;
    while (temp != NULL)
    {
        if (temp->value == searchValue)
        {
            arr[k] = count ;
            k++;
            flag = 1;
        }
        temp = temp->Next;
        count++;
    }

    if (flag == 0)
    {
        cout << "Sorry value not found in this list" << endl;
    }else{
        // arr[0] = k ;
        for(int i=0;i<k;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;

    }
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
    insertTail(head, 600);
    insertTail(head, 600);
    insertTail(head, 300);
    print_list(head);
    cout << endl;
    searDuplicatehValue(head, 600);
    return 0;
}