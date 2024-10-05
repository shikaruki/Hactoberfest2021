#include "bits/stdc++.h"
using namespace std ;

int main()
{
    int n ;
    cin>>n ;
    int a[n][2] ;
    for (int i = 0; i < n; i++)
    {
        for (int j= 0; j < 2; j++)
        {
            cin>>a[i][j] ;
        }
    }
    int k ;
    cin>>k ;
    priority_queue<pair<int,pair<int,int>>> pq ;
    for (int i = 0; i < n; i++)
    {
        int y = a[i][0]*a[i][0] + a[i][1]*a[i][1] ;
        pq.push({y,{a[i][0],a[i][1]}}) ;
        if(pq.size()>k)
        {
            pq.pop() ;
        }
    }
    while(!pq.empty())
    {
        cout<<pq.top().second.first<<" "<<pq.top().second.second<<endl ;
        pq.pop() ;
    }
}