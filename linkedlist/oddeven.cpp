#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node* insertAtEnd(Node *head, int val)
{
    Node *nptr = new Node(val);
    if(head == NULL)
    {
        head = nptr;
        return nptr;
    }
    Node *curr = head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = nptr;
    return head;
}
void display(Node *head)
{
    while(head)
    {
        cout << head->data <<"-> ";
        head = head->next;
    }
    cout <<"NULL\n";
}
Node *evenodd(Node *head)
{
    // Node *newlist = new Node(-1);
    Node *curr = head;
    Node *even = new Node(-1);
    Node *odd = new Node(-1);
    Node *e=even , *o = odd;
    while(curr!= NULL)
    {
        Node *newnode = new Node(curr->data);
        if(curr->data % 2 == 0)
        {
            e->next = newnode;
            e = e->next;
        }
        else
        {
            o->next = newnode;
            o = o->next;
        }
        curr = curr->next;
    }
    Node *ev = even;
    while(ev->next != NULL)
    {
        ev = ev->next;
    }
    ev->next = odd->next;
    return even->next;
}

int main()
{
    Node *head = NULL;
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int val;
        cin >> val;
        head = insertAtEnd(head, val);
    }
    Node *my = evenodd(head);
    display(my);
    return 0;
}