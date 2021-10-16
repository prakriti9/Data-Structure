#include<iostream>
#include <list>
#include <iterator>
using namespace std;

struct myhash{
    int bucket;
    list <int> *table;
    myhash(int b)
    {
        bucket = b;
        table = new list <int>[b];
    }
    void insert(int key)
    {
        int i = key% bucket;
        table[i].push_back(key);
    }
    void del(int key)
    {
        int i = key% bucket;
        table[i].remove(key);
    }
    bool search(int key)
    {
        int i = key% bucket;
        for(auto x: table[i])
        {
            return true;
        }
        return false;
    }
};
int main()
{
    return 0;
}