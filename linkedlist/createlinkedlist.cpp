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
void display(Node *head)
{
    while(head != NULL)
    {
        cout <<head->data <<"-> ";
        head = head->next;
    }
    cout <<"NULL\n";
}
bool isPallindrom(Node *&left, Node *right)
{
    if(right == NULL)
        return true;
    bool first = isPallindrom(left, right->next);
    if(first == false)
        return false;
    bool second = (left->data == right->data);
    left = left->next;
    return second;
}
int middleelement(Node * head)
{
    Node *sp = head, *fp = head;
    while(fp!=NULL and fp->next != NULL)
    {
        fp = fp->next->next;
        sp = sp->next;
    }
    return sp->data;
}
bool detectloop(Node *head)
{
    Node *sp = head, *fp = head;
    while(fp!= NULL and fp->next != NULL)
    {
        sp = sp->next;
        fp = fp->next->next;
        if(sp == fp)
            return true;
    }
    return false;
}
Node *delloop(Node *head)
{
    Node *sp = head,*fp = head;
    while(fp!= NULL and fp->next!= NULL)
    {
        sp = sp->next;
        fp = fp->next->next;
        if(sp == fp)
            break;
    }
    if(sp == fp)
    {
        while(sp->next != fp->next)
        {
            sp = sp->next;
            fp = fp->next;
        }
        fp->next = NULL;
    }
    return head;
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
    Node* curr = head;
    Node* temp = head;
    while(curr->next!= NULL)
        curr = curr->next;
    while(temp->data!= 20)
        temp = temp->next;
    curr-> next = temp;
    // cout << middleelement(head) <<endl;
    // cout << isPallindrom(head, head) << endl;
    cout << detectloop(head) <<endl;
    head = delloop(head);
    cout << detectloop(head) <<endl;
    return 0;
}


