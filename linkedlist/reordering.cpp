#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node()
    {
        next = NULL;
    }
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node* insert(Node *head, int val)
{
    Node* nptr = new Node(val);
    if(head == NULL)
    {
        head = nptr;
        return head;
    }
    Node* temp = head;
    while(temp -> next!= NULL)
    {
        temp = temp ->next;
    }
    temp->next = nptr;
    return head;

}
Node *reverse(Node *head)
{
    if(!head || !head->next)
        return head;
    
    Node *nextnode = reverse(head->next);
    Node *tailnode = head->next;
    tailnode->next = head;
    head->next = NULL;
    return nextnode;
}

Node* reorder(Node *head)
{
    Node *sp = head, *fp = head;
    while(fp!= NULL and fp->next != NULL)
    {
        fp = fp->next->next;
        sp = sp->next;
    }
    Node *head1 = sp;
    Node *head2 = sp->next;
    head1->next = NULL;
    head2 = reverse(head2);
    Node *temp;
    while(!head1 and !head2)
    {
        temp = head1;
        temp->next = head2->next;
        temp = temp->next;
        head1 = head1->next;
        head2 = head2->next;
    }
    while(!head1)
    {
        temp->next = head1;
    }
    while(!head2)
    {
        temp->next = head2;
    }
    return temp;

}
void display(Node *head)
{
    while(head != NULL)
    {
        cout <<head->data <<"-> ";
        head = head->next;
    }
    cout <<"NULL\n";
}

int main()
{
    Node* head = NULL;
    head = insert(head, 10);
    head = insert(head, 30);
    head = insert(head, 40);
    head = insert(head, 80);
    head = insert(head, 20);
    // head = insert(head, 10);
    display(head);
    head = reorder(head);
    display(head);
    
}