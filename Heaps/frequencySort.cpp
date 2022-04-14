#include "bits/stdc++.h"
#define p pair<int,int> 
using namespace std ;

class myComparator{
    public:
    int operator()(p& p1 ,p& p2)
    {
        if(p1.first < p2.first)
        {
            return true ;
        }else if(p1.first > p2.first)
        {
            return false ;
        }else
        {
            if(p1.second > p2.second)
            return true ;
            else return false ;
        }
    }
};

void frequencySort(int a[] ,int n)
{
    priority_queue<p,vector<p>,myComparator> pq ;
    unordered_map<int,int> mp ;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]]++ ;
    }
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        pq.push({i->second,i->first}) ;
    }
    while(!pq.empty())
    {
        for (int i = 0; i < pq.top().first; i++)
        {
            cout<<pq.top().second<<"  " ;
        }
        pq.pop() ;
    }
}

int main()
{
    int a[] ={5,5,4,6,4} ;
    frequencySort(a,5) ;
}