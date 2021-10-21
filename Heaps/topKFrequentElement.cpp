#include"bits/stdc++.h"
using namespace std ;

void kfrequent(int a[] ,int n ,int k)
{
    unordered_map<int,int> mp; 
    for (int i = 0; i < n; i++)
    {
        mp[a[i]]++ ;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq ;
    for (auto i=mp.begin() ; i!=mp.end() ; i++)
    {
        pq.push({i->second ,i->first}) ;
        if(pq.size()>k)
        {
            pq.pop() ;
        }
    }
    while(!pq.empty())
    {
        cout<<pq.top().second<<" " ;
        pq.pop() ;
    }
}

int main()
{
    int a[] = {3,1,4,4,5,2,6,1} ;
    kfrequent(a,8,2) ;
}
