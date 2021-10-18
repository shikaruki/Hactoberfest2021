#include<iostream>
#include<cstdio>
#include<vector>
// Include headers as needed
#define S 20
using namespace std;
void print(const vector<int> & v) 
{
   for (int i = 0; i < v.size(); ++i) 
      cout << v.at(i) << " ";
   cout << endl;
}
// Write the split() function as specified above
void split(vector<int>&vec)
{
  vector<int>sp;
  for(int i=0;i<vec.size();i++)
  {
    if(vec[i]%2==0)
    {
    sp.push_back(vec[i]/2);
      sp.push_back(vec[i]/2);
    }
    else
    {
      sp.push_back(vec[i]/2+1);
      sp.push_back(vec[i]/2);
    }
  }
  vec=sp;
}
int main()
{
  int x[S],n,min,max;
  cin>>n;
  for(int i=0;i<n;i++) cin>>x[i];
  vector<int> v(x, x + n);
  split(v);
  print(v);
  return 0;
}
