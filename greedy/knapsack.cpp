#include <bits/stdc++.h>
using namespace std;

bool mycomp(pair<int, int> a, pair<int, int> b)
{
    double r1 = (double) a.first / a.second;
    double r2 = (double) b.first/ b.second;
    return r1 > r2;
}
double kanpsack(vector <pair <int, int>> v, int n, int bgwt)
{
    sort(v.begin(), v.end(), mycomp);
    double res = 0.0;
    for(int i=0;i <n;i++)
    {
        if(v[i].second <= bgwt)
        {
            res += v[i].first;
            bgwt -= v[i].second;
        }
        else
        {
            res += v[i].first * ((double) bgwt / v[i].second);
            break;
        }
    }
    return res;
}
int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int bagwt;
    cin >> bagwt;
    int n = *(&val + 1) - val;
    vector <pair<int ,int>> v;
    for(int i=0;i<n;i++)
    {
        v.push_back({val[i], wt[i]});
    }
    cout << kanpsack(v , n , bagwt);
    return 0;
}