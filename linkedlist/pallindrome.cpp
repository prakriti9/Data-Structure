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
bool pallindrome(Node *head)
{
    if(head == NULL || head->next == NULL)
        return true;
    if(head->next->next == NULL)
    {
        if(head->data != head->next->data)
        {
            return false;
        }
    }
    Node *sp = head, *fp = head;
    while(fp!= NULL and fp->next != NULL)
    {
        fp = fp->next->next;
        sp = sp->next;
    }
    Node *nexttemp = sp->next;
    sp->next = NULL;
    nexttemp = reverse(nexttemp);
    Node *c1 = head;
    Node *c2 = nexttemp;
    bool res = true;
    while(c1 != NULL and c2 != NULL)
    {
        if(c1->data != c2->data)
        {
            res = false;
            break;
        }
        c1 = c1->next;
        c2 = c2->next;
    }
    nexttemp = reverse(nexttemp);
    sp->next = nexttemp;
    return res;
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

    // Node* head = NULL;
    // head = insert(head, 10);
    // head = insert(head, 20);
    // head = insert(head, 30);
    // head = insert(head, 50);
    // head = insert(head, 20);
    // head = insert(head, 10);
    // head = insert(head, 45);
    display(head);
    cout << pallindrome(head);
    
    return 0;
}