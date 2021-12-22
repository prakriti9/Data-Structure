#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node *&head, int val)
{
    Node *temp = new Node(val);
    if(head == NULL)
    {
        head = temp;
        return head;
    }
    else if(head->data < temp->data)
    {
        head->right = insert(head->right, val);
    }
    else
    {
        head->left = insert(head->left, val);
    }
    return head;
}
void displayLRR(Node *head)
{
    if(head == NULL)
        return;
    displayLRR(head->left);
    cout << head->data <<" ";
    displayLRR(head->right);
}
void preorder(Node *head)
{
    stack <Node *> s;
    s.push(head);
    while(!s.empty())
    {
        auto temp = s.top();
        s.pop();
        cout << temp->data << " ";
        if(temp->right != NULL)
        {
            s.push(temp->right);
        }
        if(temp->left != NULL)
        {
            s.push(temp->left);
        }
    }
}
void inorder(Node *head)
{
    stack <Node* > st;
    Node *temp = head;
    while(true)
    {
        if(temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }
        else
        {
            if(st.empty())  break;
            temp = st.top();
            st.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
    }
}
void displayRLR(Node *head)
{
    if(head == NULL)
        return;
    cout << head->data <<" ";
    displayRLR(head->left);
    displayRLR(head->right);
}

void levelorder(Node *head)
{
    queue <Node *> q;
    q.push(head);
    while(!q.empty())
    {
        auto temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
    }
}
void reverselevelorder(Node *head)
{
    queue <Node *> q;
    q.push(head);
    while(!q.empty())
    {
        auto temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
    }
}

void leftview(Node *head)
{
    if(head== NULL)
        return;
    cout << head->data << " ";
    leftview(head->left);
}
int main()
{
    Node *head = NULL;
    insert(head, 7);
    insert(head, 5);
    insert(head, 8);
    insert(head, 4);
    insert(head, 6);
    insert(head, 9);

    preorder(head);
    cout << endl;
    displayRLR(head);
    cout << endl;
    inorder(head);


    // cout << endl;
    // levelorder(head);
    // cout << endl;
    // leftview(head);
    
    return 0;
}