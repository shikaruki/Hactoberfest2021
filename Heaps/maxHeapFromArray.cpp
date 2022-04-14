#include"bits/stdc++.h"
using namespace std ;
#define vi vector<int>

void heapify(vi &v , int n ,int i)
{
    int largest =i ;
    int l =2*i+1 ;
    int r =2*i+2 ;
    if(l<n && v[largest]<v[l])
    {
        largest=l ;
    }
    if(r<n && v[largest]<v[r])
    {
        largest=r ;
    }
    if(largest !=i)
    {
        int t =v[i] ;
        v[i] =v[largest] ;
        v[largest] = t ;
        heapify(v,n,largest) ;
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
    for(int i =n/2-1 ;i>=0 ;i--)
    {
        heapify(v,n,i) ;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<v[i] <<" " ;
    }cout<<endl ;
    
}