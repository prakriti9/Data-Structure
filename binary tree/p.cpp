#include <iostream>
#include <stack>
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
        if(curr->data > val)
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
        prev ->right = temp;
    }
    return head;
}

void inorder(Node *head)
{
    stack <Node*> s;
    Node *temp = head;
    while(true)
    {
        if(temp!= NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        else
        {
            if(s.empty())   break;
            
            temp = s.top();
            cout << temp->data << ".... ";
            s.pop();
            temp = temp->right;
        }
    }
}

Node *getsucess(Node *curr)
{
    // Node *c = curr->right;
    curr = curr->right;
    while(curr!= NULL and curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node *del(Node *head, int val)
{
    if(head == NULL)
        return head;

    if(head ->data > val)
    {
        head -> left = del(head->left, val);
    }
    else if(head->data < val)
    {
        head->right = del(head->right, val);
    }
    else
    {
        if(head->left == NULL and head->right == NULL)
        {
            Node *temp = head;
            delete temp;
            head = NULL;
        }
        else if(head->left ==  NULL)
        {
            Node *temp = head->right;
            delete head;
            return temp;
        }
        else if(head->right == NULL)
        {
            Node *temp = head->left;
            delete head;
            return temp;
        }
        else
        {
            Node* curr = getsucess(head);
            head->data = curr->data;
            head->right = del(head->right, val);
        }
    }
    return head;
}
// Node *getsucess(Node *curr)
// {
//     curr = curr->right;
//     while(curr != NULL and curr->left != NULL)
//     {
//         curr = curr->left;
//     }
//     return curr;
// }
// Node *del(Node *head, int val)
// {
//     if(head == NULL)
//         return head;

//     if(head->data > val)
//     {
//         head ->left = del(head->left, val);
//     }
//     else if(head->data < val)
//     {
//         head ->right = del(head->right, val);
//     }
//     else
//     {
//         if(head->left == NULL and head->right == NULL)
//         {
//             Node *temp = head;
//             delete temp;
//             head = NULL;
//         }
//         else if(head->left == NULL)
//         {
//             Node *temp = head->right;
//             delete head;
//             return temp;
//         }
//         else if(head->right == NULL)
//         {
//             Node *temp = head->left;
//             delete head;
//             return temp;
//         }
//         else
//         {
//             Node *curr = getsucess(head);
//             head->data = curr->data;
//             head->right = del(head->right, val);
//         }
//     }
//     return head;
// }
// void displayPre(Node *head)
// {
//     if(head == NULL)
//         return;
    
//     stack <Node*> s;
//     s.push(head);

//     while(!s.empty())
//     {
//         auto temp = s.top();

//         cout << temp->data << ", ";
//         s.pop();

//         if(temp->right != NULL)
//         {
//             s.push(temp->right);
//         }
//         if(temp->left != NULL)
//         {
//             s.push(temp->left);
//         } 
//     }
//     // return head;
// }

void display(Node *head)
{
    if(head == NULL)
        return;
    cout << head->data << ", ";
    display(head->left);
    display(head->right);
}
int main()
{
    Node *head = NULL;
    head = insert(head, 50);
    head = insert(head, 30);
    head = insert(head, 70);
    head = insert(head, 20);
    head = insert(head, 40);
    head = insert(head, 60);
    head = insert(head, 80);
    // display(head);
    // cout << endl;
    // head = del(head, 20);
    head = del(head, 50);
    inorder(head);
    return 0;
}