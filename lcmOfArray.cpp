include <iostream>
using namespace std;
int getLCM(int a, int b){
   int m;
   m = (a > b) ? a : b;
   while(true){
      if(m % a == 0 && m % b == 0)
      return m;
      m++;
   }
}
int getLCMArray(int arr[], int n){
   int lcm = getLCM(arr[0], arr[1]);
   for(int i = 2; i < n; i++){
      lcm = getLCM(lcm, arr[i]);
   }
   return lcm;
}
int main() {
   int arr[] = {4, 6, 12, 24, 30};
   int n = sizeof(arr)/sizeof(arr[0]);
   cout << "LCM of array elements: " << getLCMArray(arr, n);
}
