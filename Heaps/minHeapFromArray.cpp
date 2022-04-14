#include"bits/stdc++.h"
using namespace std ;
#define vi vector<int>

void minHeapify(vi &v ,int n, int i)
{
    int smallest = i ;
    int l =2*i+1 ;
    int r =2*i+2 ;
    if(l<n && v[smallest]>v[l])
    {
        smallest=l ;
    }
    if(r<n && v[smallest]>v[r])
    {
        smallest=r ;
    }
    if(smallest !=i)
    {
        int t =v[i] ;
        v[i] =v[smallest] ;
        v[smallest] =t ;
        minHeapify(v,n,smallest) ;
    }
}

int main()
{
    int n ;
    cin>>n ;
    vi v(n) ; 
    for (int i = 0; i < n; i++)
    {
        cin>>v[i] ;
    }
    for (int i = n/2 -1; i >=0; i--)
    {
        minHeapify(v,n,i) ;
    }

    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" " ;
    }
    
    
}