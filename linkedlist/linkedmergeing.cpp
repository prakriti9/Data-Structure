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
// Add 2 linkedlist
Node *newlist(Node *head, Node *head2)
{
    Node *nlist = NULL;
    Node *temp = nlist;
    int c = 0;
    while(head!= NULL || head2 != NULL || c)
    {
        int sum = 0;
        if(head!= NULL)
        {
            sum += head->data;
            head = head->next;
        }
        if(head2!= NULL)
        {
            sum += head2->data;
            head2 = head2->next;
        }
        sum += c;
        int rem = sum % 10;
        Node *nptr = new Node(sum /10);
        temp->next = nptr;
        temp = temp->next;
        
    }
    return nlist;
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
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        head = insert(head , val);
    }
    int m;
    cin >> m;
    Node *head2 = NULL;
    for(int i=0;i<m;i++)
    {
        int val;
        cin>>val;
        head2 = insert(head2 , val);
    }
    Node *nptr = newlist(head , head2);
    Node *temp = nptr;
    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}