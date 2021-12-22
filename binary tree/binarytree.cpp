#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *insertinBinary(Node *head, int val)
{
    Node *nptr = new Node(val);
    if(head == NULL)
    {
        head = nptr;
        return head;
    }
    if(head -> data < nptr -> data)
    {
        head -> right = insertinBinary(head->right, val);
    }
    else{
        head -> left = insertinBinary(head->left, val);
    }
    return head;
}

void displayRtLR(Node *head)
{ 
    if(head == NULL)
        return;

    cout << head->data << " ";
    displayRtLR(head->left);
    displayRtLR(head->right);
}
void displayLRRt(Node *head)
{
    if(head == NULL)
        return;

    displayLRRt(head->left);
    displayLRRt(head->right);
    cout << head->data << " ";
}
void displayLRtR(Node *head)
{
    
    if(head == NULL)
        return;

    displayLRtR(head->left);
    cout << head->data << " ";
    displayLRtR(head->right);
}
// -------------- Level Order Traversal -------------------
void levelorder(Node *head) // BFS(Breath first search)
{
    if(head == NULL)
        return;
    queue <Node*> q;
    q.push(head);
    
    while(!q.empty())
    {
        int n = q.size();
        for(int i=0;i<n;i++)
        {
            Node *curr = q.front();
            q.pop();
            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL)
            q.push(curr->right);
            cout << curr->data <<" ";
        }
    }
}
// --------------- is BST ------------
int maximum(Node *head)
{
    if(head == NULL)
        return INT_MIN;
    
    return max(head->data, max(maximum(head->left), maximum(head-> right)));
}
int minimum(Node *head)
{
    if(head == NULL)
        return INT_MAX;
    
    return min(head->data, min(minimum(head->left), minimum(head-> right)));
}
bool isBST(Node *head)
{
    if (head == NULL)
        return true;
    int maxLeft = maximum(head->left);
    int miniRight = minimum(head->right);
    bool res = (head->data > maxLeft) and (head->data <= miniRight) and isBST(head->left) and isBST(head->right);
    return res;
}
int countnode(Node *head)
{
    int val = 0;
    if(head == NULL)
        return 0;
    while(head!= NULL)
    {
        val++;
        head = head->left;
        head = head->right;
    }
  return val;  
}
int main()
{
    Node * head = NULL;
    // head = insertinBinary (head, 50);
    // head = insertinBinary (head, 20);
    // head = insertinBinary (head, 5);
    // head = insertinBinary (head, 100);
    // head = insertinBinary (head, 60);
    // head = insertinBinary (head, 65);
    // head = insertinBinary (head, 35);
    head = insertinBinary (head, 50);
    head = insertinBinary (head, 70);
    head = insertinBinary (head, 60);
    head = insertinBinary (head, 20);
    head = insertinBinary (head, 90);
    head = insertinBinary (head, 10);
    head = insertinBinary (head, 40);
    head = insertinBinary (head, 100);
    // displayRtLR(head); // Root->Left->Right
    // cout << endl;
    // displayLRRt(head); // Left->Right->Root
    // cout << endl;
    // displayLRtR(head); // Left->Root->Right
    // cout << endl;
    levelorder(head);
    cout << endl;
    cout << isBST(head);
    return 0;
}