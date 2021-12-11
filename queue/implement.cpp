#include <bits/stdc++.h>
// #include <queue>
using namespace std;
#define n 20

class queues{
    int *arr;
    int front;
    int back;

    public:
    queues()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }
    void push(int x)
    {
        if(back == n - 1)
        {
            cout << "Overflow ";
            return;
        }
        back++;
        arr[back] = x;
        if(front == -1)
            front++;
    }
    void pop()
    {
        if(front == -1 || front > back)
        {
            cout << "Underflow";
            return;
        }
        int val = arr[front];
        cout << "\nElement deleted: " << val << endl;;
        front++;
    }
    void display()
    {
        for(int i=front; i<= back;i++)
        {
            cout << arr[i] << " ";
        }
    }
    void rev()
    {
        int f = front, e = back;
        while(f<= e)
        {
            swap(arr[f++], arr[e--]);
        }
        // front = arr[0];
        // back = arr[n-1];
    }
    int peek()
    {
        if(front == -1 || front > back)
        {
            cout << "Underflow";
            return -1;
        }
        return arr[front];
    }
    bool empty()
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
    queues q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.display();
    // q.pop();
    cout << endl;
    // q.display();
    // cout << q.peek();
    q.rev();
    q.display();
    return 0;
}