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

Node *reveseingps(Node *head, int k)
{
    if(head == NULL)
    return NULL;

    int count = 1;
    Node *prev = NULL, *curr = head, *temp;
    while(curr != NULL and count <= k)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        count++;
    }
    if(temp != NULL)
    {  
        head->next = reveseingps(temp, k);
    }
    return prev;
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
    head = insert(head, 60);
    head = insert(head, 70);
    head = insert(head, 80);

    display(head);
    cout << endl;
    head = reveseingps(head, 3);
    display(head);
    return 0;
}