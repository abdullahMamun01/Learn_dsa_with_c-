// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
struct UniqeArray
{
    int position[100];
};
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
    if(n == NULL){
        cout<<"Linked list empty"<<endl;
    }
    while (n != NULL)
    {
        cout << n->value << " ";
        n = n->Next;
    }
}

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
void isertAtSpecificPosition(Node *head, int position, int value)
{
    /*
    1.Traverse the Linked list upto position-1 nodes.
    2.Once all the position-1 nodes are traversed, allocate memory and the given data to the new node.
    3.Point the next pointer of the new node to the next of current node.
    4.Point the next pointer of current node to the new node.
    */
    // copy of head
    Node *temp = head;
    // create new node for insert value specific position
    Node *newNode = new Node(value);
    int i = 1; // if we count index we have to start with 0
    // traverse positon-1 because we have to finde out insert befor positon
    while (i < position - 1)
    {
        // update node until position-1
        temp = temp->Next;
        i++;
    }
    // current node is position-1 node
    Node *currenNode = temp;
    // we have link with  newNode to currentNode of next node
    newNode->Next = currenNode->Next;
    // after link newNode next node now we have update connecting the currentNode to next node
    currenNode->Next = newNode;
}
// Checks whether the value x is present in linked list if not found retun -1
int search_specific_value(Node *head,int valu){
    Node *tmp = head;
    int count = 1;
    while(tmp->Next != NULL){
        if(tmp->value == valu){
            break ;
        }
        tmp = tmp->Next;
        count++ ;
    }
    
    return count;
} ;
void searDuplicatehValue(Node *head, int searchValue)
{
    Node *temp = head; // copy of head
    int count = 1;
    int flag = 0;
    int size = countLength(head);
    int arr[size];
    int k = 0;
    while (temp != NULL)
    {
        if (temp->value == searchValue)
        {
            arr[k] = count;
            k++;
            flag = 1;
        }
        temp = temp->Next;
        count++;
    }

    if (flag == 0)
    {
        cout << "Sorry value not found in this list" << endl;
    }
    else
    {
        // arr[0] = k ;
        for (int i = 0; i < k; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void insertBySearchValue(Node *head, int searchValue, int insertValue)
{
    Node *temp = head;
    int pos = searchSpecificValue(temp, searchValue);
    cout << pos << endl;
    isertAtSpecificPosition(temp, pos + 1, insertValue);
}
void deleteionAtHead(Node *&head)
{
    Node *newHead = head; // save head
    if (newHead == NULL)
    {
        cout << "head is empty.please insert before delete" << endl;
        return;
    }
    head = newHead->Next; // update head
    delete newHead;       // delete head
}
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
    Node *deletNode = temp->Next ;
    temp->Next = deletNode->Next;
    delete deletNode;

}
void deletionAtTail(Node *&head)
{
    Node *temp = head;
    if (temp != NULL && temp->Next != NULL)
    {
        int pos = countLength(head);
        for (int i = 0; i < pos - 2; i++)
        {
            temp = temp->Next;
        }
    
        Node *tail = temp->Next;
        temp->Next = NULL;
        delete tail;
    }else{
        if(temp == NULL){
            cout<<"Head is empty"<<endl;
        }else{
            deleteionAtHead(head);
        }
    }

    // Node *tail = temp ;
    // delete temp ;
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
void deleteByValue(Node * &head ,int value){
    int position = searchSpecificValue(head,value);
    deleteAtSpecificPosition(head,position);
}

int findMid(Node *&head){
    Node *slow = head;
    Node *fast = head;
    while(fast !=NULL && fast->Next !=NULL){
        slow = slow->Next ;
        fast= fast->Next->Next ;
    }
    return slow->value ;
}

void deleteDuplicateValue(Node *&head ,int value){
    // UniqeArray dupli = searchByUniqueValue(head,value);
    Node *t = head;
    // int length = dupli.position[0];
    // for(int i=1;i<length;i++){
    //     int pos = dupli.position[i];
    //     deleteAtSpecificPosition(head,pos+1);

    // }
    int count = 1 ;
    while(t !=NULL){
        t = t->Next ;
        count++;
        if(t->value == value){
          deleteAtSpecificPosition(head,count+1);
            // cout<<count<<endl;
        }
    }
 

}

int main()
{
    Node *head = NULL;
    insertTail(head, 100); //1
    insertTail(head, 200);//2
    insertTail(head, 300);//3
    insertTail(head, 400);//3
    insertTail(head, 300);//4
    insertTail(head, 600);//5
     insertTail(head, 300);//6
     insertTail(head, 900);//7
    deleteDuplicateValue(head,300);
    // insertTail(head, 300);
    // insertTail(head, 400);
    // insertTail(head, 500);
    // insertTail(head, 600);
    // insertTail(head, 700);
    // insertTail(head, 800);
    // deleteionAtHead(head);
    // deletionAtTail(head);
    // deleteionAtHead(head);
    // insertBySearchValue(head, 400, 450);
    // cout << endl;
    // cout<<"Choice 1 : Insertion at Head "<<endl
    //     <<"Choice 2 : Insertion at Tail "<<endl
    //     <<"Choice 3 : Insertion at specific positin "<<endl
    //     <<"Choice 4 : Search a value (unique list) "<<endl
    //     <<"Choice 5 : Search a value (for duplicate list)"<<endl
    //     <<"Choice 6 : Insertion at Head "<<endl
    //     <<"Choice 7 : Deletion at Head "<<endl
    //     <<"Choice 0 : Exit "<<endl ;
    // cout<<"Next choice : ";
    // int choice ;
    // cin>>choice;
    // while(choice !=0){}
    print_list(head);
    return 0;
}