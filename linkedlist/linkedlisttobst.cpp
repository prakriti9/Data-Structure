#include <iostream>
#include <vector>
using namespace std;

class linkedlist
{
    public:
    int data;
    linkedlist * next;
    linkedlist(int val)
    {
        data = val;
        next = NULL;
    }
};
class bst
{
    public:
    int data;
    bst *left, *right;
    bst(int val)
    {
        data = val;
        left = right = NULL;
    }
};

linkedlist *insertLL(linkedlist *head, int val)
{
    linkedlist *newnode = new linkedlist(val);
    if(head == NULL)
    {
        head = newnode;
        return  head;
    }
    linkedlist *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}
void displayLL(linkedlist * head)
{
    while(head!= NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
linkedlist * midnode(linkedlist *head)
{
    linkedlist *fp = head->next, *sp = head;
    while(fp->next == NULL and fp== NULL)
    {
        sp = sp->next;
        fp = fp->next->next;
    }
    return sp;
}
bst * bstcreate(vector <int> v, int s, int e)
{
    if(s > e) return NULL;
    int mid = (s + e + 1) / 2;
    bst * root = new bst(v[mid]);
    root->left = bstcreate(v, s, mid - 1);
    root->right = bstcreate(v, mid + 1, e);
    return root;
}
bst * formbst(linkedlist *head)
{
    vector <int> v;
    int cnt = 0;
    while(head!= NULL)
    {
        v.push_back(head->data);
        head = head->next;
        cnt++;
    }
    return bstcreate(v, 0, cnt - 1);
}

void displayBST(bst *root)
{
    if(root == NULL)
    return;
    displayBST(root->left);
    cout << root->data << " ";
    displayBST(root->right);
}
int main()
{
    linkedlist * head = NULL;
    head = insertLL(head, 10);
    head = insertLL(head, 20);
    head = insertLL(head, 30);
    head = insertLL(head, 40);
    head = insertLL(head, 50);
    head = insertLL(head, 60);
    displayLL(head);
    cout << endl;
    auto bstnode = formbst(head);
    // cout << bstnode ->data << endl;
    displayBST(bstnode);

    return 0;
}