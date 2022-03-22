#include <iostream>
#include <vector>

using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

Node *insert(Node *root, int val)
{
    Node *temp = new Node(val);
    if(root == NULL)
    {
        root = temp;
        return root;
    }
    if(root->data > temp->data)
    {
        root->left = insert(root->left, val);
    }
    else if(root->data < temp->data)
    {
        root->right = insert(root->right, val);
    }
    return root;
}

bool search(Node *root, int key)
{
    if(root == NULL)
        return false;

    bool val;
    if(root-> data == key)
    {
        return true;
    }
    else if(key < root->data)
    {
        val = search(root->left, key);
    }
    else if(key > root->data)
    {
        val = search(root->right, key);
    }
    return val;
}

Node *sortedarraybst(vector <int> v, int s, int e)
{
    if(s > e)
        return NULL;

    int m = (s + e)/2;
    Node *root = new Node(v[m]);
    root -> left = sortedarraybst(v, s, m-1);
    root -> right = sortedarraybst(v, m+1, e);

    return root;
}
void displayRLR(Node *root)
{
    if(root == NULL)
        return;
    cout << root -> data << " ";
    displayRLR(root -> left);
    displayRLR(root -> right);
}
int main()
{
    Node *root = NULL;
    int a[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    vector <int> v = {1,2,3,4,5,6,7,8,9};
    for(auto x: a)
    {
        root = insert(root, x);
    }
    displayRLR(root);
    cout << endl;
    cout << search(root, 13);
    cout << endl;
    Node *newnode = sortedarraybst(v, 0, 8);
    displayRLR(newnode);
    return 0;
}