#include "bits/stdc++.h"
using namespace std ;

void kclasestNumber(int a[] ,int n ,int k ,int x)
{
    priority_queue<pair<int,int>> pq ;
    for (int i = 0; i < n; i++)
    {
        pq.push({abs(a[i]-x),a[i]}) ;
        if(pq.size()>k)
        {
            pq.pop() ;
        }
    }
    while (!pq.empty())
    {
        cout<<pq.top().second<<" " ;
        pq.pop() ;
    }
}

int main()
{
    int a[] = {5,6,7,8,9} ;
    kclasestNumber(a,5,3,7);
}