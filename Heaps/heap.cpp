#include<iostream>
using namespace std ;
int b =10 ;
void heapifyDown(int a[],int n)
{
    int t =a[0] ;
    a[0]=a[n-1] ;
    a[n-1]=t ;
    n=n-1 ;
    int i = 0 ;
    int j = 2*i+1 ;
    int k = 2*i+2 ;
    while(i<n && j<n && k<n)
    {
        
        if(a[j]>a[k] )
        {
            if(a[i]<a[j])
            {
                int t = a[i] ;
                a[i]=a[j] ;
                a[j]=t;
                i=j ;
            }
// int a[]={20,19,18,15,17,12,11,10,9,14} ;
        }else 
        {
            if(a[i]<a[k])
            {
                int t = a[i] ;
                a[i]=a[k] ;
                a[k]=t;
                i=k ;
            }
        }
         j = 2*i+1 ;
         k = 2*i+2 ;
    }

    for(int i =0 ; i<b ;i++)
    {
        cout<<a[i]<<" " ;
    }
    cout<<endl ;
}

void heapsort(int a[] ,int n)
{
        for(int i =0 ;i<n-2 ;i++)
        {
            heapifyDown(a,n-i) ;
        }
}

int main()
{
    int a[]={20,19,18,15,17,12,11,10,9,14} ;
    heapsort(a,10) ;
}