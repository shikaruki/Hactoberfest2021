#include "bits/stdc++.h"
using namespace std ;

void sortAkSortedArray(int a[] ,int n ,int k)
{
    priority_queue<int ,vector<int> ,greater<int>> pq ;
    vector<int> v ;
    for (int i = 0; i < n; i++)
    {
        pq.push(a[i]) ;
        if(pq.size()>k)
        {
            v.push_back(pq.top()) ;
            pq.pop() ;
        }
    }
    while (!pq.empty())
    {
        v.push_back(pq.top()) ;
        pq.pop() ;
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" " ;
    }
}

int main()
{
    int a[] = {6,5,3,2,8,10,7} ;
    sortAkSortedArray(a,7,3) ;
}