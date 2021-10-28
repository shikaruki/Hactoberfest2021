#include<bits/stdc++.h>
// Leetcode interview problem
// Uses prority queue
using namespace std;
class Solution {
public:
    struct comparefn{
        bool operator()(const pair<int, int>&a, const pair<int,int>&b){
            if(a.first==b.first){
                  return a.second>b.second;
            }
            return a.first>b.first;
        };
    };
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,comparefn> pq;
        int n=a.size();
        for(int i=0;i<n;i++){
            pq.push({abs(x-a[i]),a[i]});
        }
        vector<int> ans;
        while(k-- && !pq.empty()){
            pair<int,int> p=pq.top();
            pq.pop();
            ans.push_back(p.second);
            cout<<p.first<<" "<<p.second<<endl;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};