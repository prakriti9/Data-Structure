#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

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
Node *rev(Node *head)
    {
        Node *curr = head, *next ,*prev = NULL;
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
}
int getDecimalValue(Node* head) {
        
    Node *temp = rev(head);
    
    int r = 0;
    long long int val = 0;
    while(temp != NULL)
    {
        val = val + (temp->data) * pow(2,r);
        r++;
        temp = temp->next;
        
    }
    
    return val;
}
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
    // display(head);
    cout << getDecimalValue(head);
    return 0;
} 
