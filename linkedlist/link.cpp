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
// Insert new node
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
// Display the middle val
int middleval(Node *head)
{
    Node* sp = head, *fp = head;
    while(fp!= NULL and fp->next != NULL)
    {
        fp = fp->next->next;
        sp = sp->next;
    }
    return sp->data;
}
// Does the linkedlist have cycles
bool iscycle(Node *head)
{
    Node *sp = head, *fp = head;
    while(fp!= NULL and fp->next!= NULL)
    {
        fp = fp->next->next;
        sp = sp->next;
        if(fp == sp)
            return true;
    }
    return false;
}
// Deleting mid value
Node *delmid(Node *head)
{
    Node *sp = head, *fp = head;
    Node *prev = sp;
    while(fp!= NULL and fp->next !=NULL)
    {
        prev = sp;
        fp = fp->next->next;
        sp = sp->next;
    }
    prev->next = sp->next;
    delete sp;
    return head;
}
// Reverse recurseively
Node * recurr(Node *head)
{
    if(!head || !head->next)
        return head;
    
    Node *nexthead = recurr(head->next);
    Node *nexttail = head->next;
    nexttail->next = head;
    head->next = NULL;

    return nexthead;
}
// Iterative way for reversing Linkdlist
Node *reverse(Node *head)
{
    Node *prev = NULL ,*curr = head;
    Node *next;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
// Move last node at first
Node *movelastfirst(Node *head)
{
    Node * curr = head;
    while(curr->next->next != NULL)
    {
        curr = curr->next;
    }
    Node *temp = curr->next;
    curr->next = NULL;
    temp->next = head;
    return temp;
}
// remove duplicates when LL is sorted
Node *removesorted(Node *head)
{
    Node *curr = head;
    while(curr->next != NULL)
    {
        if(curr->data == curr->next->data)
        {
            Node *nptr = curr->next;
            curr->next = nptr->next;
            delete nptr;
        }
        else{
            curr = curr->next;
        }
    }
    return head;
}
bool isPallindrome(Node *&left, Node *right)
{
    if(right == NULL)
        return true;
    
    bool first = isPallindrome(left, right ->next);
    if(first == false)
        return false;
    bool second = (left->data == right->data);
    left = left->next;
    return second;
}
// print LL in reverse order
void printreverse(Node *head)
{
    if(head == NULL)
        return;
    printreverse(head->next);
    cout << head->data <<"->";
}
// If there r cycle remove it
Node *removecycle(Node *head)
{
    Node *sp = head, *fp = head;
    while(fp!= NULL and fp->next != NULL)
    {
        fp = fp->next->next;
        sp = sp->next;
        if(fp == sp)
        {
            break;
        }
    }
    if(sp == head)
    {
        sp = head;
        while(fp->next != sp->next)
        {
            sp = sp->next;
            fp = fp->next;
        }
        fp->next = NULL;
    }
    return head;

}
Node * dilLL(Node *head)
{
    Node *prev = head;
    head = head->next;
    if(head == NULL)
        delete prev;
    while(head != NULL)
    {
        delete prev;
        prev = head;
        head = head->next;
    }
    return head;
}
// Find the values of starting of loop
int startingofloop(Node *head)
{
    Node *sp = head, *fp = head;
    while(fp!=NULL and fp->next != NULL)
    {
        fp = fp->next->next;
        sp = sp->next;
        if(fp == sp)
        {
            break;
        }
    }
    if(sp == fp)
    {
        sp = head;
        while(fp != sp)
        {
            fp = fp->next;
            sp = sp->next;
        }

    }
    return sp->data;
}
// Displaying LL
void display(Node *head)
{
    while(head)
    {
        cout << head->data <<"-> ";
        head = head->next;
    }
    cout <<"NULL\n";
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
    // head = insertAtEnd(head, 20);
    // head = insertAtEnd(head, 30);
    // head = insertAtEnd(head, 40);
    // head = insertAtEnd(head, 50);
    display(head);
    // cout << middleval(head);
    // head = delmid(head);
    // printreverse(head);
    // display(head);
    // head = reverse(head);
    // display(head);
    // head = recurr(head);
    // display(head);
    // Node *temp = head;
    // while(temp->data != 20)
    // {
    //     temp = temp->next;
    // }
    // Node *nptr = head;
    // while(nptr->next != NULL)
    // {
    //     nptr = nptr->next;
    // }
    // nptr->next = temp;

    // cout << iscycle(head) << endl;
    // cout << startingofloop(head) << endl;
    // head = removesorted(head);
    // display(head);
    // head = movelastfirst(head);
    // display(head);
    // cout << isPallindrome(head, head);
    head = dilLL(head);
    display(head);
    return 0;
}