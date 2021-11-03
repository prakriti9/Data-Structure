#include<iostream>
using namespace std;

void reverse(int *ar, int left, int right)
{
    while(left < right)
    {
        swap(ar[left++], ar[right--]);
    }
}
void rotate(int ar[], int n, int d)
{
    reverse(ar, 0, d-1);
    reverse(ar, d, n-1);
    reverse(ar, 0, n-1);
    
}
int main()
 {
	int t;
	cin >> t;
	while(t--)
	{
	    int n, d;
	    cin >> n >> d;
	    d = d%n;
	    int ar[n];
	    for(int i=0; i<n;i++)
	    {
	        cin >> ar[i];
	    }
	    rotate(ar, n ,d);
	    
	    for(int i=0;i<n;i++)
	    {
	        cout << ar[i] << " ";
	    }
        cout << endl;
	}
	return 0;
}