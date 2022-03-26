#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
    }
};

Node *insert(Node *head, int val)
{
    Node *temp = new Node(val);
    if(head == NULL)
    {
        head = temp;
        head->next = head;
    }
    Node *ptr = head;
    if(ptr != NULL)
    {
        while(ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->next = head;
    }

    return head;
}
Node* del(Node *head, int val)
{
    if(head->data == val)
    {
        Node *ptr = head->next;
        Node *temp = head->next;
        while(temp->next != head)
        {
            temp = temp->next;
        }
        temp ->next = ptr;
        delete head;
        // head = ptr;
        return ptr;
    }
    Node *ptr = head;
    while(ptr->next != head and ptr->next->data != val)
    {
        ptr = ptr->next;
    }
    Node *temp = ptr->next;
    ptr->next = temp->next;
    delete temp;
    return head;
}
void display(Node *head)
{
    Node *ptr = head;
    do
    {
        cout << ptr->data << "-> ";
        ptr = ptr->next;

    } while (ptr != head);
    cout << ptr -> data << endl;
}
int main()
{
    Node *head = NULL;
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);
    head = insert(head, 50);
    display(head);

    head = del(head, 10);
    display(head);
    return 0;
}