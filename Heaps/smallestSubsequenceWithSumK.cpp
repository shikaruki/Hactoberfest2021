#include"bits/stdc++.h"
using namespace std ;

int smallestSubSequence(int a[] ,int n ,int k )
{
    priority_queue<int> pq ;
    for (int i = 0; i < n; i++)
    {
        pq.push(a[i]) ;
    }
    int ct =0 ;
    int s =0 ;
    while(s<k && !pq.empty())
    {
        s=s + pq.top() ;
        pq.pop() ;
        ct+=1 ;
    }
    return ct ; 
}

int main()
{
    int a[] ={1,1,3,2,8} ;
    cout<<smallestSubSequence(a,5,13)<<endl ;
}