
#include <iostream>
using namespace std;
int lin(int arr[],int n,int key){
    int low=0;
    int high=n-1;
    int num;
    
    while(low<=high)
    {
    num=(low+high)/2;
        if(key==arr[num])
         return num;
       else if(key<arr[num]){
            high=num-1;
        }
        //  if(key>num){
        else{
            low=num+1;
        }
    }
    return -1;
}

void main()
{
    int key,n,i;
    int arr[n];
    cout<<"enter range ";
    cin>>n;
    for(i=0;i<n;i++){
        cout<<"eneter the "<<i+1<<" number";
        cin>>arr[i];
    }
    
    cout<<"enter the key ";
    //cin>>key;
    int data=lin(arr,n,5);
    if(data==-1)
    cout<<"the number you entered is out of scope";
    else
    cout<<"the number is placed at "<<data <<"position";
  //cout<<"here the num you wants "<<data;

    return 0;
}
