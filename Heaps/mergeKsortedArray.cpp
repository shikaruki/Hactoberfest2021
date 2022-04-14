#include "bits/stdc++.h"
#define pi pair<int,pair<int,int>> 
using namespace std ;

vector<int> mergeKsorted(vector<vector<int>> v ,int k)
{
    priority_queue<pi,vector<pi>,greater<pi>> pq ;
    for (int i = 0; i < k; i++)
    {
        pq.push({v[i][0],{i,0}}) ;
    }
    
    vector<int> m ;
    while (!pq.empty())
    {
        m.push_back(pq.top().first) ;
        int x = pq.top().second.first ;
        int y = pq.top().second.second + 1 ;
        pq.pop() ;
        if(x<k && y<k){
        pq.push({v[x][y],{x,y}}) ;
        }
    }
    return m ;
}

int main()
{
    int n ;
    cin>>n ;
    vector<vector<int>> a(n) ;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>a[i][j] ;
        }
    }
    
}