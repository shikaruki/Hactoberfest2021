#include"bits/stdc++.h"
using namespace std ;

priority_queue<int ,vector<int>> pmax ;
priority_queue<int ,vector<int>, greater<int>> pmin ;

float findmedian(int x)
{
    if(pmax.empty() || pmax.top()>x)
    {
        pmax.push(x) ;
    }else
    {
        pmin.push(x) ;
    }

    if(pmax.size()>pmin.size()+1)
    {
        pmin.push(pmax.top()) ;
        pmax.pop() ;
    }else if(pmin.size()>pmax.size()+1)
    {
        pmax.push(pmin.top()) ;
        pmin.pop() ;
    }

    if(pmax.size() > pmin.size())
    {
        return pmax.top() ;
    }else if(pmin.size() > pmax.size())
    {
        return pmin.top() ;
    }else
    {
        return (pmax.top() + pmin.top())/2.0 ;
    }
    return -1 ;
}

int main()
{
    int n ;
    cin>>n ;
    vector<int> v(n) ;
    for(int i =0 ;i<n ;i++)
    {
        cin>>v[i] ;
        cout<<findmedian(v[i])<<endl ;
    }
}