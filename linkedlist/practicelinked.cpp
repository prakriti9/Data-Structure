// ListNode *curr = head->next, *prev = head;
//         if(head->next == NULL and head == NULL)
//             return head;
        
//         if(head->val == val)
//             return removeElements(head->next, val);
        
//         while(curr!= NULL)
//         {
//             if(curr->val == val)
//             {
//                 while(prev->next != curr)
//                 {
//                     prev = prev->next;
//                 }
//                 prev->next = prev->next->next;
//                 delete curr;
//                 curr = prev;
//             }
//             curr = curr->next;
//         }
//         return head;


#include<bits/stdc++.h>
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

//Insert values in linkedlist
Node* insert(Node* head, int val)
{
    Node *newptr = new Node(val);
    if(head == NULL)
    {
        head = newptr;
        return head;
    }
    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newptr;
    return head;
}

//Display values from linkedlist
void display(Node* head)
{
    Node* temp = head;
    if(head == NULL)
    {
        cout << "There is no element";
        return;
    }
    
    while(temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    
    cout <<"NULL" <<endl;
}

//Displaying middle element
int middle(Node* head)
{
    Node *sp = head, *fp = head;
    while(fp!= NULL and fp->next != NULL)
    {
        sp = sp->next;
        fp = fp->next->next;
    }
    return sp->data;
}
// Deleteting the middle node
Node *delnode(Node *head)
{
    Node *sp=head,*fp=head;
    Node *prev = sp;
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
//Delete the entire list
Node* dellinkelist(Node *head)
{
    Node *prev=head;
    head= head->next;
    if(head == NULL)
    {
        delete prev;
    }
    while(head!=NULL)
    {
        delete prev;
        prev = head;
        head = head->next;
    }
    cout <<"Linked List Is empty now\n";
    return head;
}
//Display reverse of linkedlist
void reversedisplay(Node* head)
{
    if(head == NULL)
        return;
    reversedisplay(head->next);
    cout <<head->data <<" ";
}
//reverse the whole linkedlist
Node* reverse(Node* head)
{
    Node* prev= NULL;
    Node* curr = head;
    Node* next;
    while(curr!= NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    // head = prev;
    return prev;
}

//to check if linkedlist is pallindrome
bool pallindrome(Node* &left, Node* right)
{
    if(right == NULL)
        return true;
    bool first = pallindrome(left, right->next);
    if(first == false)
        return false;
    bool second = (right->data == left->data);
    left = left->next;
    return second;
}

// bool pallindrome(Node *head)
// {
//     Node *prev =  reverse(head);
//     while(head!= NULL and prev!= NULL)
//     {
//         if(head->data != prev->data)
//         {
//             return false;
//         }
//         head = head->next;
//         prev = prev->next;
//     }
//     return true;
// }

//Delete duplicates (sorted)
Node* duplicate(Node* head)
{
    Node* curr = head;
    while(curr->next != NULL)
    {
        if(curr->data == curr->next->data)
        {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }

    }
    return head;
}
// Deleted duplicate(unsorted)
Node* deldup(Node* head)
{
    Node *curr = head, *pre = curr;
    set <long long int> s;
    while(curr!= NULL)
    {
        if(s.count(curr->data))
        {
            Node* temp = curr->next;
            
            pre->next = curr->next;
            delete curr;
        }
        else
        {
            s.insert(curr->data);
            pre = curr;
        }
        curr= pre->next;
    }
    return head;
}
// To detect loop in linkedlist
bool hasloop(Node *head)
{
    Node* sp=head, *fp=head;
    while(fp!= NULL and fp->next != NULL)
    {
        sp = sp->next;
        fp = fp->next->next;
        if(sp == fp)
        {
            return true;
        }
    }
    return false;
}
//Delete loops from linked list
Node* delloop(Node *head)
{
    Node *sp = head, *fp = head;
    while(fp!= NULL and fp->next != NULL)
    {
        fp = fp->next->next;
        sp = sp->next;
        if(fp == sp)
            break;
    }
    if(sp == fp)
    {
        sp = head;
        while(fp->next != sp->next)
        {
            sp = sp->next;
            fp = fp->next;
        }
        fp->next = NULL;
    }
    return head;
}
int main()
{
    Node* head = NULL;
    // head = insert(head, 10);
    // head = insert(head, 20);
    // head = insert(head, 30);
    // head = insert(head, 40);
    // head = insert(head, 50);
    // display(head);
    // cout << middle(head);
    // head = delnode(head);
    // display(head);
    // head = dellinkelist(head);
    // display(head);
    // reversedisplay(head);
    // head = reverse(head);


    // head = insert(head, 10);
    // head = insert(head, 20);
    // head = insert(head, 10);
    // head = insert(head, 30);
    // head = insert(head, 20);
    // display(head);
    // if(pallindrome(head))
    // {
    //     cout<<"Pallindrome";
    // }
    // else
    // {
    //     cout <<"Not Pallindrome";
    // }
    // head = duplicate(head);
    // display(head);

    // head = deldup(head);
    // display(head);

    // For creating a loop in linkedlist
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);
    head = insert(head, 50);

    Node* curr = head;
    Node* temp = head;
    while(curr->next!= NULL)
        curr = curr->next;
    while(temp->data!= 20)
        temp = temp->next;
    curr-> next = temp;

    // cout << hasloop(head) << endl; 
    // head = delloop(head);
    // cout << hasloop(head) << endl;
    
    // display(head);
    head = dellinkelist(head);
    display(head);
    return 0;
}