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

void print_list(Node *n)
{
    while (n != NULL)
    {
        cout << n->value << " ";
        n = n->Next;
    }
}
void insertList(Node *head, int pos, int value)
{
    if (pos == 0)
    {
        Node *new_node = new Node(value);
        Node *prev_head = head;
        head = new_node;
        head->Next = prev_head;
        return;
    }
    Node *tmp = head; // we have to copy of heade node . we can not touch head node
    for (int i = 0; i < pos - 1; i++)
    {
        tmp = tmp->Next; //
    }
    cout << tmp->Next->value << endl; // because of we have to connect after insert node to next node link
    Node *insert = new Node(value);   // create new node for insert value
    Node *save_next = tmp->Next;      // we have save next node before insert value
    tmp->Next = insert;               // now connect with present node to insert new node
    insert->Next = save_next;         // afeter insert we have connect next node
}
int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    head->Next = second;
    second->Next = third;
    third->Next = fourth;
    insertList(head, 2, 100);
    print_list(head);
    return 0;
}