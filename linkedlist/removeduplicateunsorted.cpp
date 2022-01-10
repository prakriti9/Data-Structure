#include <iostream>
#include <unordered_map>
// #include <map>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
// Insert new node
Node* insertAtEnd(Node *head, int val)
{
    Node *nptr = new Node(val);
    if(head == NULL)
    {
        head = nptr;
        return nptr;
    }
    Node *curr = head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = nptr;
    return head;
}

// Node * removeDuplicates( Node *head) 
// {
//     map<int , int>m;
//     m[head->data]++;
//     Node *temp=head;
    
//     while(temp->next!=NULL)
//     {
//         m[temp->data]=1;
//         if(m[temp->next->data]==1)
//         {
//             temp->next=temp->next->next;
//         }
//         else
//         {
//             temp=temp->next;
//         }
//     }  
//     return head;   
// }
Node* removeduplicated(Node *head)
{
    if(head == NULL)
        return head;
        
    unordered_map <int, bool> mp;
    Node *ptr = head;
    mp[ptr->data] = 1;
    while(ptr->next != NULL)
    {
        int x = ptr->next->data;
        if(mp.find(x) == mp.end())
        {
            mp[x] = true;
            ptr = ptr->next;
        }
        else
        {
            ptr->next = ptr->next->next;
        }
    }
    return head;
}
void display(Node *head)
{
    while(head)
    {
        cout << head->data <<"-> ";
        head = head->next;
    }
    cout <<"NULL\n";
}
int main()
{
    Node *head = NULL;
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int val;
        cin >> val;
        head = insertAtEnd(head, val);
    }
    
    display(head);
    cout << endl;
    Node *tp = removeduplicated(head);
    display(tp);
    return 0;
}