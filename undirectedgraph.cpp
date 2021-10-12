Question
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 
  
  
  
  solution
  bool depthfirstsearch(int v,int p,vector<int>adj[],vector <bool>&visited){
        visited[v]=true;
        for(auto i:adj[v]){
            if(!visited[i]){
                if(depthfirstsearch(i,v,adj,visited))
                return true;
            }
            else if(i!=p){
                return true;
            }
            
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool flag=depthfirstsearch(i,-1,adj,visited);
                if(flag)
                return true;
            }
        }
        return false;
    }
