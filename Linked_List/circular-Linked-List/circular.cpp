// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
/* 
defination : 
A circular linked list is a type of linked list in which 
the first and the last nodes are also connected to each other to form a circle.
where single list last node's next equal null but circular linked list's
last node's next equal Head ; 
 */
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
// circular linked list create function
void circularList(Node *&head)
{
    Node *tmp = head;
    while (tmp->Next != NULL)
    {
        tmp = tmp->Next;
    }
    //connect to head
    tmp->Next = head;
}
void insertTail(Node *&head, int value)
{
    // create new node for insert in tail
    Node *newNode = new Node(value); 
    if (head == NULL)
    {
    
        head = newNode;
        newNode->Next = head;
        return;
    }
    Node *temp = head;

    while (temp->Next != head)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
    //connect to head
    newNode->Next = head ; 
    
}

void displayList(Node *&head)
{
      //check head equal NULL
    
    Node *temp = head;
    if(head == NULL ){
        cout<<"No value in the list now"<<endl ;
        return;
    }
    //using do while loop check before update temp node
    do
    {
        cout << temp->value << " ";
        temp = temp->Next;

    } while (temp != head);
}
void deleteTail(Node *&head)
{
    Node *temp = head;
    if (temp == NULL)
    {
        cout << "There is no value in the list" << endl;
        return;
    }
    while (temp->Next->Next != head)
    {
        temp = temp->Next;
    };
    if(temp->Next == head){
        head = NULL;
        return;
    }
    //save head;
    Node *saveHead = head;
    //save next node 
    Node *deleteTail = temp->Next;
    //do connect with head
    temp->Next = saveHead;
    //delete tail node
    delete deleteTail;
}

void deleteHead(Node *&head)
{
    if (head == NULL)
    {
        cout << "There is no value in the list" << endl;
        return;
    }
    
    Node *temp = head;
    if(head->Next == NULL){
       head = NULL;
       return;
    }
    //save head node
    Node *delNode = head;
    //will continue untill temp's Next equal head;
    while (temp->Next != head)
    {
        temp = temp->Next;
    }
    head = delNode->Next;
    temp->Next = delNode->Next;
    delete delNode;
}
void delete_list(Node *head, int pos)
{

    Node *tmp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        tmp = tmp->Next;
    }
    Node *save = tmp->Next->Next;
    delete tmp->Next;
    tmp->Next = save;
}

int main()
{
    Node *head = NULL;
    cout << "Choice 1 : Insertion at Head " << endl
         << "Choice 2 : Insertion at Tail " << endl
         << "Choice 3 : Deletion at head " << endl
         << "Choice 4 : Deletion at Tail " << endl
         << "Choice 5 : Display value " << endl

         << "Choice 0 : Exit " << endl;

    int choice;
    cin >> choice;
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            break;
        case 2:
            cout << "Insert value : ";
            int insert;
            cin >> insert;
            insertTail(head, insert);
            break;
        case 3:
            deleteHead(head);
            break;
        case 4:
            deleteTail(head);
            break;
        case 5 :
            displayList(head);
            cout<<endl;
            break;
        default:
            break;
        }
        cout << "Next choice : ";
        cin >> choice;
    }
    displayList(head);
    return 0;
}