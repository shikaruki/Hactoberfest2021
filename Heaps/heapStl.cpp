#include"bits/stdc++.h"
using namespace std ;

int main()
{
    priority_queue<int,vector<int>> pq ; // [MAX HEAP]
    pq.push(1) ;
    pq.push(2) ;
    pq.push(4) ;
    pq.push(3) ;
    cout<<pq.top()<<endl ;
    pq.pop() ;
    cout<<pq.top()<<endl ;
    cout<<endl ;
    priority_queue<int ,vector<int> ,greater<int>> pqmin ; // [MIN HEAP]
    pqmin.push(1) ;
    pqmin.push(2) ;
    pqmin.push(4) ;
    pqmin.push(3) ;
    cout<<pqmin.top()<<endl ;
    pqmin.pop() ;
    cout<<pqmin.top()<<endl ;
}