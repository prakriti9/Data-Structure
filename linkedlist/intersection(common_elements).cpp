#include <iostream>
#include <set>
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
Node* findIntersection(Node* head1, Node* head2)
{
    Node *newlist = new Node(-1);
    Node *curr = newlist;
    
    set <int> s;
    Node *temp = head2;
    while(temp!= NULL)
    {
        s.insert(temp->data);
        temp = temp->next;
    }
    // for(auto a: s)
    //     cout << a << endl;

    Node *temp2 = head1;
    while(temp2!= NULL)
    {
        if(s.find(temp2->data) != s.end())
        {
            Node *newnode = new Node(temp2->data);
            curr->next = newnode;
            curr = curr->next;
        }
        temp2 = temp2->next;
    }
    return newlist->next;
}

void display(Node *head)
{
    while(head != NULL)
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
    Node *head2 = NULL;
    int m;
    cin >> m;
    for(int i=0;i<m;i++)
    {
        int val;
        cin>>val;
        head2 = insert(head2 , val);
    }
    // display(head);
    // cout << endl;
    // display(head2);
    cout << endl;
    Node *x = findIntersection(head, head2);
    display(x);
    return 0;
}