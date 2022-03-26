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
int nthnodefromend(Node *head, int n)
{
    Node *first =head, *second = head;
    int c = 0;
    while(second!= NULL and c!=n)
    {
        second = second->next;
        c++;
    }
    while(second)
    {
        second = second->next;
        first = first->next;
    }
    return first->data;
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
int main()
{
    Node* head = NULL;
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 30);
    head = insert(head, 20);
    head = insert(head, 10);
    display(head);
    // cout << endl;
    // cout << nthnodefromend(head , 2);
    head = reverse(head);
    display(head);
    
}