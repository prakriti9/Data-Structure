#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class queue{

    node *front;
    node *back;

    public:
    queue()
    {
        front = NULL;
        back = NULL;
    }
    void push(int x)
    {
        node *temp = new node(x);
        
        if(front == NULL)
        {
            front = temp;
            back = temp;
            return;
        }
        back->next = temp;
        back = temp;
    }
    void pop()
    {
        if(front == NULL)
        {
            cout << "Queue empty";
            return;
        }
        node *temp = front;
        cout << "\nElement delete : " << temp -> data << endl;
        front = front->next;
        delete temp;
    }
    void display()
    {
        node *temp = front;
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int peek()
    {
        if(front == NULL)
            return -1;
        
        return front->data;
    }
    bool empty()
    {
        if(front == NULL)
            return true;

        return false;
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.display();
    q.pop();
    q.display();
    return 0;
}