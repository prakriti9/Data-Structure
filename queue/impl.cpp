#include <iostream>
using namespace std;
#define n 20

class queue{
    int *arr;
    int front, back;

    public:
    queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }
    void push(int x)
    {
        if(back == n-1)
        {
            cout << "Overflow\n";
            return;
        }
        back++;
        arr[back] = x;
        if(front == -1)
        {
            front++;
        }
    }
    void pop()
    {
        if(front == -1)
        {
            cout << "Underflow\n";
            return;
        }
        int val = arr[front];
        cout <<"\nElement deleted is: "<< val;
        front++;
    }
    void display()
    {
        if(front == -1)
        {
            cout <<"No element to display";
            return;
        }
        for(int i=front;i<=back;i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int seek()
    {
        if(front == -1 || front > back)
        {
            return -1;
        }
        return arr[front];
    }
    bool isempty()
    {
        if(front == -1 || front > back)
        {
            return true;
        }
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
    cout << endl;
    q.display();
    cout << q.seek();
    return 0;
}