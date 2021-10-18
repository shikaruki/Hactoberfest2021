#include <iostream>

using namespace std;

int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);  //euclid thm.
}


int main()
{
    int n;
    cout<<"size : ";
    cin>>n;
    cout<<"enter the array elements : ";
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = arr[0];
    for(int i=1;i<n;i++){
       ans = (ans*arr[i])/gcd(ans,arr[i]);
    }
    cout<<"LCM of the Array : "<<ans<<endl;

}
