#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node *prev;
    Node *next;

    Node(int val, Node * pre = NULL, Node *nx = NULL)
    {
        data = val;
        prev = pre;
        next = nx;
    }
};
Node *insert(Node *root, int val)
{
    Node *temp = new Node(val);
    if(root == NULL)
    {
        root = temp;
        return temp;
    }
    
    if(root-> data < val)
    {
        root->next = insert(root ->next, val);
    }
    else if(root -> data > val)
    {
        root -> prev = insert(root -> prev, val);
    }
    
    return root;
}
// Node* del (Node *root, int val)
// {
//     if(root == NULL)
//         return root;
    
//     if(root->data > val)
//     {
//         root->prev = del(root->prev, val);
//     }
//     else if(root->data < val)
//     {
//         root->next = del(root->next, val);
//     }
//     else
//     {
//         if(root->prev == NULL and root->next == NULL)
//         {
//             Node *temp = root;
//             delete temp;
//             root = NULL;
//         }
//         else if(root->prev == NULL)
//         {
//             Node *temp = root;
//             root = root->next;
//             delete temp;
//         }
//         else if(root->next == NULL)
//         {
//             Node *temp = root;
//             root = root->prev;
//             delete temp;
//         }
//         else
//         {
//             Node *temp = root->next;
//             while(temp->prev != NULL)
//             {
//                 temp = temp->prev;
//             }
//             root->data = temp->data;
//             root ->next = del(root->next, temp->data);
//         }
//     }
//     return root;
// }

Node *del(Node *root, int val)
{
    if(root == NULL)
        return root;
    if(root-> data > val)
    {
        root->prev = del(root ->prev, val);
    }
    else if(root-> data < val)
    {
        root -> next = del(root->next, val);
    }
    else
    {
        if(root->prev == NULL and root ->next == NULL)
        {
            Node *temp = root;
            delete root;
            root = NULL;
        }
        else if(root->prev == NULL)
        {
            Node *temp = root;
            root = root->next;
            delete temp;
        }
        else if(root->next == NULL)
        {
            Node *temp = root;
            root = root->prev;
            delete temp;
        }
        else
        {
            Node *temp = root->next;
            while(temp->prev != NULL)
            {
                temp = temp->prev;
            }
            root ->data = temp->data;
            root ->next = del(root -> next, temp->data);
        }
    }
    return root;
}

int height(Node *root)
{
    // int max = 0;
    if(root == NULL)
        return 0;
    
    return (1 + max(height(root->prev), height(root->next)));

}
void display(Node *root)

{
    if(root == NULL)
        return;
    display(root->prev);
    cout << root->data << ", ";
    display(root->next);
}

// void displaynotrecurrIn(Node *root)
// {
//     if (root == NULL) return;
//     stack <Node*> s;
//     Node * temp = root;

//     while (!s.empty() || temp != NULL) {
//         while (temp != NULL) {
//             s.push(temp); // root, root->left, root->left->left, NULL
//             //  50, 30, 10
//             temp = temp -> prev;
//         }
//         temp = s.top();  // root->left->left 
//         //  10
//         cout << temp -> data << ", "; // 10
//         s.pop(); // root->left->left
//         temp = temp -> next; // root->left->left->right
//     }
// }


void displaynotrecurrPre(Node *root)
{
    if (root == NULL) 
        return;
    
    stack <Node *> st;
    st.push(root);

    while(!st.empty())
    {
        Node *temp;
        temp = st.top();
        cout << temp->data << ", ";
        
        st.pop();

        if(temp->next != NULL)
        {
            st.push(temp -> next); 
        }
        if(temp->prev != NULL)
        {
            st.push(temp -> prev);
        }      
    }
}

void displaynotrecurrPost(Node *root)
{
    if (root == NULL) 
        return;

    stack <Node *> s1, s2;
    s1.push(root);

    while(!s1.empty())
    {
        Node *temp;
        temp = s1.top();
        cout << temp->data << ", ";
        s1.pop();
        s2.push(temp);
        if(temp->prev != NULL)
            s1.push(temp->prev);

        if(temp->next != NULL)
        s1.push(temp->next);   
    }
    while(!s2.empty())
    {
        cout << s2.top() -> data << ", ";
        s2.pop();
    }
}

int main()
{
    Node *root = NULL;
    int ar[] = {100, 90, 40, 80, 140, 120, 160};
    int n = sizeof(ar)/ sizeof(int);
    for(int i=0; i<n;i++)
    {
        root = insert(root, ar[i]);
    }
    display(root);
    cout << endl;
    root = del(root, 40);
    cout << endl;
    display(root);
    cout << endl;
    cout << height(root);
    return 0;
}