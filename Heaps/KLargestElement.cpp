#include "bits/stdc++.h"
using namespace std ;

int klargestElement(int a[] , int n ,int k)
{
    priority_queue<int ,vector<int>, greater<int>> pq ;
    for (int i = 0; i < n; i++)
    {
        pq.push(a[i]) ;
        if(pq.size()>k)
        {
            pq.pop() ;
        }
    }
    return pq.top() ;
}

int main()
{
    int a[] = {1, 23, 12, 9, 30, 2, 50};
    cout<<klargestElement(a,7,3) <<endl ;
}