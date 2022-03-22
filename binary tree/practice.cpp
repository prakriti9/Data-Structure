#include <iostream>
#include <stack>
#include <queue>
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

// recursive method
// Node *insert(Node* head, int val)
// {
//     Node *newnode = new Node(val);
//     if(head == NULL)
//     {
//         return newnode;
//     }
//     if(head->data < val)
//     {
//         head->right = insert(head->right, val);
//     }
//     else 
//     {
//         head->left = insert(head->left, val);
//     }
//     return head;
// }

// Iterative insertion method
Node *insert(Node *head, int val)
{
    Node *temp = new Node(val);
    if(head == NULL)    return temp;

    Node *prev = NULL, *curr = head;

    while(curr!= NULL)
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

    if(prev == NULL) // only when empty tree is given
    {
        return temp;
    }
    else if(prev->data > val)
    {
        prev ->left = temp;
    }
    else if(prev->data < val)
    {
        prev->right = temp;
    }
    return head;
}

// Deletion program takes place
Node *getsucess(Node *curr)
{
    curr = curr->right;
    while(curr!= NULL and curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
Node * del(Node *head, int val)
{
    if(head == NULL)
        return head;
    else if(head->data > val)
    {
        head->left = del(head->left, val);
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
        else if(head->left == NULL)
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
            Node *succ = getsucess(head);
            head->data = succ->data;
            head->right = del(head->right, val);
        }  
    }
    return head;
}

void display(Node* head)
{
    if(head == NULL)
        return;
    
    display(head->left);
    cout << head-> data << "-> ";
    display(head->right);
}

int height(Node *head)
{
    if(head == NULL)
        return 0;
    
    return (1 + max(height(head->left),height(head->right)));
}
// Diameter of the tree
int diameter(Node *head)
{
    if(head == NULL)
        return 0;

    int d1 = height(head->left) + height(head->right);
    int d2 = diameter(head->left);
    int d3 = diameter(head->right);

    return max(d1, max(d2, d3));
}
void displayPre(Node *head)
{
    stack <Node *> s;
    s.push(head);

    while(!s.empty())
    {
        Node* temp;
        temp = s.top();
        cout << temp->data<< ", ";
        s.pop();

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

void displayIn(Node* head)
{
    stack <Node* > s;
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
            cout << temp->data << ", ";
            s.pop();
            temp = temp->right;
        }
    }
}

void levelorder(Node *head)
{
    queue <Node *> q;

    q.push(head);
    q.push(NULL);
    while(!q.empty())
    {
        auto temp = q.front();
        q.pop();
        if(temp == NULL)
        {
            cout << endl;
            if(!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << "-> ";
            if(temp->left != NULL)
            {
                q.push(temp->left);
            }
            if(temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}
// build a tree form level order values
Node *insertlevel()
{
    int d;
    cin >> d;
    Node *head = new Node(d);

    queue <Node *> q;
    q.push(head);
    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        int c1, c2;
        cin >> c1 >> c2;
        if(c1 != -1)
        {
            Node *newnode = new Node(c1);
            temp->left = newnode;
            q.push(temp->left);
        }
        if(c2!= -1)
        {
            Node *newnode = new Node(c1);
            temp->right = newnode;
            q.push(temp->right);
        }

    }

    return head;
}
int main()
{
    Node *head = NULL;
    head = insert(head, 50);
    head = insert(head, 20);
    head = insert(head, 10);
    head = insert(head, 60);
    head = insert(head, 70);
    head = insert(head, 90);
    head = insert(head, 100);
    head = insert(head, 12);
    
    displayIn(head);
    // head = del(head, 50);
    // cout << endl;
    // displayPre(head);
    // cout << endl << endl;
    // levelorder(head);
    // cout << endl;

    // Node *head1 = NULL;
    // head1 = insertlevel();
    
    // // levelorder(head1);
    // cout << height(head) << endl;
    // cout << diameter(head) << " ";
    return 0;
}