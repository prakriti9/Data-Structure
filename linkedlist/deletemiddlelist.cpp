#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
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

Node* insertval(Node *head, int val)
{
    Node* newnode = new Node(val);
    if(head == NULL)
    {
        head = newnode;
        return head;
    }
    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}
Node* delmiddle(Node *head)
{
    Node* sp = head, *fp = head;
    Node* prev = sp;
    while(fp!= NULL and fp->next != NULL)
    {
        prev = sp;
        sp = sp->next;
        fp = fp->next->next;
    }

    prev->next = sp->next;
    delete sp;
    return head;
}
Node* deletelinkedlist(Node* head)
{
    auto pre = head;
    head = head->next;
    while(head != NULL)
    {
        delete pre;
        pre = head;
        head = head ->next; 
    }
    cout << "List is empty";
    return head;
}
//Just print reverse
void printrev(Node *head)
{
    if(head==NULL)
        return;
    printrev(head->next);
    cout <<head->data <<" ";
}
Node* reverselinkedlist(Node* head)
{
    Node *prev=NULL, *curr = head;
    Node *next;
    while(curr!= NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
//To print if linklist is pallindorm
// bool pallindrome(Node* &left, Node* right)
// {
//     if(right == NULL)
//         return true;
//     bool first = pallindrome(left, right->next);
//     if(first == false)
//         return false;
//     bool second = (right->data == left->data);
//     left = left->next;
//     return second;
// }

bool pallindrome(Node *head)
{
    Node *prev =  reverselinkedlist(head);
    while(head!= NULL and prev!= NULL)
    {
        if(head->data != prev->data)
        {
            return false;
        }
        head = head->next;
        prev = prev->next;
    }
    return true;
}
// delete duplicates from linked list(list is sorted)
Node* duplicate(Node *head)
{
    Node* curr = head;
    while(curr->next != NULL)
    {
        if(curr->data == curr->next->data)
        {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else
        {
            curr = curr -> next;
        }
    }
    return head;
}
// delete when list is unsorted
Node* delunsorted(Node *head)
{
    Node* curr = head, *pre = curr;
    set <long long int> s;
    while(curr != NULL)
    {
        if(s.count(curr->data))
        {
            pre->next = curr->next;
            delete curr;
        }
        else{
            s.insert(curr->data);
            pre = curr;
        }
        curr = pre->next;
    }
    return head;
}
void display(Node* head)
{
    Node * temp = head;
    while(temp != NULL)
    {
        cout << temp->data <<"-> ";
        temp = temp->next;
    }
    cout <<"NULL";
    cout <<endl;
}
int main()
{
    Node* head = NULL;
    head = insertval(head, 70);
    head = insertval(head, 10);
    head = insertval(head, 10);
    head = insertval(head, 30);
    head = insertval(head, 70);
    // display(head);
    // cout << endl;

    // head = delmiddle(head);
    // display(head);
    // cout << endl;

    // head = delmiddle(head);
    // display(head);
    // cout << endl;
    // head = deletelinkedlist(head);
    // display(head);
    // head = reverselinkedlist(head);
    // display(head);
    // cout << pallindrome(head,head);
    // printrev(head);
    // head = duplicate(head);
    head = delunsorted(head);
    display(head);
    return 0;
}