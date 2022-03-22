#include <bits/stdc++.h>
using namespace std;

// int timeRequiredToBuy(vector<int>& tickets, int k) {
//         int count = 0;
        
//         while(tickets[k] != 0)
//         {
//             for(int i=0;i<tickets.size();i++)
//             {
//                 if(tickets[i] > 0)
//                 {
//                     count++;
//                     tickets[i] = tickets[i] - 1;   
//                 }
//                 // cout << tickets[i] << " ";
                
//             }
//         }
//         return count;
        
// }

void rotate(vector<int>& tickets)
{
    int temp = tickets[0];
    int n = tickets.size();
    for(int i=0;i<n;i++)
    {
        tickets[i] = tickets[i+1];
    }
    tickets[n-1] = temp;
}

int timeRequiredToBuy(vector<int>& tickets, int k) {
        int count = 0;
        
        // while(tickets[k] != 0)
        // {
        //     for(int i=0;i<tickets.size();i++)
        //     {
        //         if(tickets[i] > 0)
        //         {
        //             count++;
        //             tickets[i] = tickets[i] - 1;   
        //         }
                
        //     }
        // }

        for(int i=0;i< tickets.size();i++)
        {
            while(tickets[k] == 0)
            {
                // break;
                rotate(tickets);
            }
            if(tickets[i] > 0)
            {
                tickets[i] = tickets[i] - 1;
                count++;
            }
            cout << tickets[i] << " ";
        }
        return count;
        
}
int main()
{
    vector <int> tickets = {2,3,2};
    int k = 2;
     
    cout << timeRequiredToBuy(tickets, k);
    return 0;
}