#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// -----------------INSERTION-------------------
Node *insertAthead(Node *head, int val)
{
    Node * nptr = new Node(val);
    if(head == NULL)
    {
        head = nptr;
        return head;
    }
    nptr->next = head;
    head = nptr;

    return head;
}
Node *insertAtSpecific(Node *head, int val, int pos)
{
    Node *nptr = new Node(val);
    int count = 1;
    Node *temp = head;
    while(temp->next != NULL)
    {
        if(pos-1 == count)
        {
            auto nexttemp = temp->next;
            temp->next = nptr;
            nptr->next = nexttemp;
        }
        count++;
        temp = temp->next;
    }
    return head;
}

Node *insertAtEnd(Node *head, int val)
{
    Node * nptr = new Node(val);
    if(head == NULL)
    {
        insertAthead(head, val);
    }
    
    Node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nptr;
    return head;
}
// ------------------------------------------------
// ---------------DELETION-------------------------

Node *delAtHead(Node *head)
{
    if(head == NULL)
        return NULL;
    
    Node * temp = head->next;
    delete head;
    return temp;
}

Node *delAtPosition(Node *head, int pos)
{
    if(head == NULL)
        return NULL;
    int count = 1;
    Node *temp = head;
    while(temp)
    {
        if(pos-1 == count)
        {
            Node *delnode = temp->next;
            temp->next = delnode->next;
            delete delnode;
        }
        count++;
        temp = temp->next;
    }
    return head;
}

Node *delFromEnd(Node *head)
{
    if(head == NULL)
        return NULL;
    
    Node *temp = head;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *delnode = temp->next;
    delete delnode;
    temp->next = NULL;

    return head;
}

// ------------------------------------------------
void display(Node *head)
{
    while(head != NULL)
    {
        cout << head->data <<" ";
        head = head -> next;
    }
    cout << "NULL" << endl;
}

int countLinkedSize(Node *head)
{
    if(head == NULL)
        return 0;
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

int main()
{
    Node *head = NULL;
    
    head = insertAthead(head, 10);
    head = insertAthead(head, 20);
    head = insertAthead(head, 30);
    // display(head);
    head = insertAtEnd(head, 100);
    head = insertAtEnd(head, 200);

    // display(head);
    // head = insertAtSpecific(head, 80, 2);
    // display(head);
    // head = delAtHead(head);
    // display(head);
    // head = delFromEnd(head);
    // display(head);
    // head = delAtPosition(head, 2);
    
    display(head);
    cout << countLinkedSize(head);
    return 0;
}