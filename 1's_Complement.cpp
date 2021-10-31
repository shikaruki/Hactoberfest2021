#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a= floor(log2(n))+1;
   int b = ((1 << a) - 1);
   int c=b^n;
    cout<<c;
}
