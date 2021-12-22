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

Node *insert(Node * root, int val)
{
    Node *nptr = new Node(val);
    if(root == NULL)
    {
        root = nptr;
        return root;
    }
    if(root->data > nptr->data)
    {
        root->left = insert(root->left, val);
    }
    if(root->data < nptr->data)
    {
        root->right = insert(root->right, val);
    }
    return root;
}
int noofnode(Node* root)
{
    if(root == NULL)
        return 0;
    int count = 0;
    while(root != NULL)
    {
        count++;
        root = root->left;
        root = root->right;
    }
    return count;
}
void preorder(Node *root)
{
    if(root == NULL)
        return;
    cout << root ->data << " ";
    preorder(root->left);
    // cout << endl;
    preorder(root->right);
}
void inorder(Node *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root ->data << " ";
    inorder(root->right);
}
void postorder(Node *root)
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root ->data << " ";
}
int main()
{
    
    Node *root = NULL;
    root = new Node(1);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // root = insert(root, 1);
    // root = insert(root, 2);
    // root = insert(root, 4);
    // root = insert(root, 5);
    // root = insert(root, 3);
    // root = insert(root, 6);
    // root = insert(root, 7);
    // root = insert(root, 8);
    preorder(root);
    cout <<endl;
    postorder(root);
    cout <<endl;
    inorder(root);
    cout<<endl;
    cout << noofnode(root);
    return 0;
}