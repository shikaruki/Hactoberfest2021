#include<bits/stdc++.h>
using namespace std;
bool isCyclePresent(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &recStack)
{
    vis[node] = true;
    recStack[node]=true;
    
    for(auto x:adj[node])
    {
        if(!vis[x] && isCyclePresent(x, adj, vis, recStack))
        {
            return true;
        }
        else if(recStack[x])
        {
            return true;
        }
    }
    recStack[node]=false;
    return false;
}
int main()
{
    int nodes,edges;
    cin>>nodes>>edges;
    
    vector<int> adj[nodes]; //Range of nodes value - [0,nodes-1]
    for(int i=0; i<edges; i++)
    {
        int from,to;
        cin>>from>>to;
        
        adj[from].push_back(to);
    }
    
    vector<bool> vis(nodes,false);
    vector<bool> recStack(nodes, false);
    
    for(int i=0; i<nodes; i++)
    {
        if(!vis[i])
        {
            if(isCyclePresent(i, adj, vis, recStack))
            {
                cout<<"Cycle Detected"<<endl;
                return 0;
            }
        }
    }
    cout<<"Cycle not found"<<endl;
}