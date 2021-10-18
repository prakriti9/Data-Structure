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
Node *reverse(Node *head)
{
    if(head == NULL or head->next == NULL)
        return head;
    
    Node *curr = head, *prev = NULL, *next;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void display(Node *head)
{
    while(head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
Node *addNodes(Node *head1, Node *head2)
{
    Node *h1 = reverse(head1);
    Node *h2 = reverse(head2);
    Node *temp = NULL;
    Node *curr = NULL;
    int c = 0;
    Node *c1 = h1, *c2 = h2;
    while(c1 != NULL and c2 != NULL)
    {
        int sum = c1->data + c2->data + c;
        Node *nptr = new Node(sum%10);
        if(temp == NULL)
        {
            temp = nptr;
            curr = temp;
        }
        else 
        {
            curr->next = nptr;
            curr = curr->next;
        }
        c = sum/10;
        c1 = c1->next;
        c2 = c2->next;
    }
    while(c1 != NULL)
    {
        int val = c1->data + c;

        Node* ptr = new Node(val%10);
        curr->next = ptr;
        curr = curr->next;
        c = val/10;
        c1 = c1->next;
    }
    while(c2 != NULL)
    {
        int val = c2->data + c;

        Node* ptr = new Node(val%10);
        curr->next = ptr;
        curr = curr->next;
        c = val/10;
        c = val/10;
        c2 = c2->next;
    }
    if(c != 0)
    {
        curr->next = new Node(c);
    }
    return reverse(temp);
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
    // display(head);

    int m;
    cin >> m;
    Node *head2 = NULL;
    for(int i=0;i<m;i++)
    {
        int val;
        cin>>val;
        head2 = insert(head2 , val);
    }
    cout << endl;
    // display(head2);
    Node* temp = addNodes(head, head2);
    
    display(temp);
    return 0;
}