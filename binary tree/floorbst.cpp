#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *insert(Node *head, int val)
{
    Node *temp = new Node(val);
    if(head == NULL)
        return temp;
    
    Node *prev = NULL, *curr = head;
    while(curr != NULL)
    {
        prev = curr;
        if(curr ->data > val)
        {
            curr = curr->left;
        }
        else if(curr->data < val)
        {
            curr = curr->right;
        }
        else
            return head;
    }
    if(prev == NULL)
        return temp;
    else if(prev->data > val)
    {
        prev->left = temp;
    }
    else if(prev->data < val)
    {
        prev->right = temp;
    }
    return head;
}
int main()
{
    Node* head = NULL;
    head = insert(head, 50);
    head = insert(head, 30);
    head = insert(head, 70);
    head = insert(head, 20);
    head = insert(head, 40);
    head = insert(head, 60);
    head = insert(head, 80);
    
    return 0;
}