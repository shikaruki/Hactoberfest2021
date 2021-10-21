#include "bits/stdc++.h"
using namespace std ;

int minimumCost(int a[] ,int n)
{
    priority_queue<int,vector<int> ,greater<int>> pq ;
    for (int i = 0; i < n; i++)
    {
        pq.push(a[i]) ;
    }
    int ts =0 ;
    while(pq.size()>=2)
    {
        int x1 = pq.top() ;
        pq.pop() ;
        int y1 = pq.top() ;
        pq.pop() ;
        int z = x1+y1 ;
        ts=ts+z ;
        pq.push(z) ;
    }
    return ts ;
}

int main()
{
    int a[] ={1,2,3,4,5} ;
    cout<<minimumCost(a,5)<<endl ;
    //parindo ko manjil milegi ykeen unke par bolte h aksar vo log kamosh rhte h jinke hunar bolte h
}