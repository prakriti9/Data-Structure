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
Node *reverse(Node *head)
    {
        Node *prev = NULL, *curr = head;
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
Node* addOne(Node *head) 
{
    Node *temp = reverse(head);
    Node *tempback =temp;
    while(tempback!= NULL)
    {
        int val = tempback->data + 1;
        if(val <= 9)
        {
            tempback->data = val;
            break;
        }
        else if(val >= 10 and tempback->next!= NULL)
        {
            tempback->data = 0;
            tempback = tempback->next;
        }
        else if(val >= 10 and tempback->next== NULL)
        {
            tempback->data = 0;
            Node *nptr = new Node(1);
            tempback->next = nptr;
            break;
        }
    }
    head = reverse(temp);
    return head;
}

// void display(Node *head)
// {
//     while(head != NULL)
//     {
//         cout <<head->data <<"-> ";
//         head = head->next;
//     }
// }
bool search(Node *head, int val)
{
    if(head == NULL)
        return false;
    
    if(head->data == val)
        return true;
    
    return search(head->next, val);
}

void display(Node *head)
{
    if(head == NULL)
        return;
    display(head->next);
    cout <<head->data << " ";
}
int main()
{
    Node *head = NULL;
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 9);
    // head = addOne(head);
    // display(head);
    cout << search(head, 4);
    return 0;
}