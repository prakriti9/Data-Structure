#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Insert the values in linked list
Node* insert(Node* head, int val)
{
    Node* nptr = new Node(val);
    if(head == NULL)
    {
        head = nptr;
        return head;
    }
    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nptr;

    return head;
}
//Delete middle element
Node *delmid(Node* head)
{
    Node* sp = head, *fp = head;
    Node* prev;
    while(fp!= NULL and fp->next != NULL)
    {
        prev = sp;
        sp= sp->next;
        fp= fp->next->next;
    }
    prev->next = sp->next;
    delete sp;
    return head;
}
// Printing the middle elemnt of linkedlist
int middleval(Node* head)
{
    Node* sp = head, *fp = head;
    while(fp!=NULL and fp->next != NULL)
    {
        sp = sp->next;
        fp = fp->next->next;
    }
    return sp->data;
}
// Printing linkedlist in reverse order
void printreverse(Node * head)
{
    if(head == NULL)
        return;
    
    printreverse(head->next);
    cout << head->data <<"-> ";
}
// Reversing linkedlist in revese format(Iterative method)
Node *reverselinked(Node *head)
{
    Node *prev= NULL, *curr= head;
    Node *next;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}
// Reverse a linkedlist in recursively manner
Node * reverserecusively(Node *head)
{
    if(!head || !head->next)
        return head;
    
    Node *nexthead = reverserecusively(head->next);
    Node *tail = head->next;
    tail->next = head;
    head->next = NULL;
    return nexthead;
}

//Delete the value in linkedlist
void display(Node * head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp -> data <<"-> ";
        temp = temp -> next;
    }
    cout <<"NULL";
    cout <<endl;
}
int main()
{
    Node* head = NULL;
    // Insertion of all the values in linkedlist
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);
    head = insert(head, 50);

    // Displaying the values in linkedlist
    // display(head);

    // Deleting the middle element of the linkedlist
    // delmid(head);

    // Displaying the values in linkedlist
    display(head);

    // The middle value if the linkedlist
    // cout << middleval(head) <<endl;

    // Printing linkedlist in reversed value
    // cout<<"Printing Linked List in reversed format: \n";
    // printreverse(head);

    // Reversing the linkedlist
    // head = reverselinked(head);
    // display(head);

    // Pallindrom linkedlist
    head = reverserecusively(head);
    display(head);
    return 0;
}