// 2 Linked list give, add them

#include <iostream>
using namespace std;
int count = 0;

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
Node *insert(Node *head, int val)
{
    Node *nptr = new Node(val);
    if(head == NULL)
    {
        head = nptr;
        return head;
    }
    Node *curr = head;
    while(curr->next != NULL)
    {
        curr = curr->next; 
    }
    curr ->next = nptr;
    return head;
}

Node *merge(Node *head1, Node *head2)
{
    Node *c1 = head1, *c2 = head2;
    Node *newlist = new Node(-1);
    Node *trav = newlist;
    
    while(c1!= NULL and c2!= NULL)
    {
        if(c1->data < c2->data)
        {
            trav->next = c1;
            c1 = c1->next;
        }
        else
        {
            trav->next = c2;
            c2 = c2->next;
        }
        trav = trav->next;
    }
    while(c1!= NULL)
    {
        trav->next = c1;
        c1 = c1->next;
        trav = trav->next;
    }
    while(c2!= NULL)
    {
        trav->next = c2;
        c2 = c2->next;
        trav = trav->next;
    }
    return newlist->next;
}
void display(Node *head)
{
    while(head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node *head = NULL;
    int n;
    cin >> n;
    int m;
    cin >> m;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        head = insert(head , val);
    }
    display(head);

    Node *head2 = NULL;
    for(int i=0;i<m;i++)
    {
        int val;
        cin>>val;
        head2 = insert(head2 , val);
    }
    cout << endl;
    display(head2);
    cout << endl;
    Node *newnode = merge(head, head2);
    display(newnode);
    return 0;
}