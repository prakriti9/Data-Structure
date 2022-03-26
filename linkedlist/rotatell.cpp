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
    Node *newnode = new Node(val);
    if(head == NULL)
        return newnode;
    
    Node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp ->next;
    }
    temp->next = newnode;
    return head;
}
void display(Node *head)
{
    while(head!= NULL)
    {
        cout << head->data << "-> ";
        head = head->next;
    }
    cout << endl;
}

Node *rotate(Node *head, int k)
{
    if(!head || !head->next || k == 0)  return head;
    Node *temp = head;
    int n=1;
    while(temp->next != NULL)
    {
        n++;
        temp = temp->next;
    }
    temp->next = head;
    k = k % n;
    k = n - k;
    while(k--)
    {
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;
    return head;
}
int main()
{
    Node *head = NULL;
    int n;
    cin >> n;
    for(int i=0; i<n;i++)
    {
        int x;
        cin >> x;
        head = insert(head, x);
    }
    display(head);
    cout << endl;
    head = rotate(head, 4);
    display(head);
    return 0;
}