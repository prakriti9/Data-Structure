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
Node *rev(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
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
Node *reverse(Node *head , int val)
{
    
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
    
    return 0;
}