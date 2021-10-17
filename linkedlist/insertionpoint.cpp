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
    // if(head == NULL || head->next == NULL)
    //     return true;

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
int insertion(Node *head1, Node* head2)
{
    Node *temp1 = head1 ,*temp2 = head2;
    
    while(temp1!= temp2)
    {
        
        if(temp1 == NULL)
        {
            temp1 = head2;
        }
        else
        {
            temp1 = temp1->next;
        }
        if(temp2 == NULL)
        {
            temp2 = head1;
        }
        else
        {
            temp2 = temp2->next;
        }   
    }
    return temp1->data;
}
int main()
{
    Node* head1 = NULL;
    head1 = insert(head1, 10);
    head1 = insert(head1, 20);
    head1 = insert(head1, 30);
    head1 = insert(head1, 50);
    head1 = insert(head1, 70);
    Node *head2 = NULL;
    head2 = insert(head2, 100);
    head2 = insert(head2, 200);
    Node *c = head1;
    while(c->data != 50)
    {
        c = c->next;
    }
    head2->next = c;
    
    Node *c2 = head2;
    cout << insertion(head1, head2);
    return 0;
}