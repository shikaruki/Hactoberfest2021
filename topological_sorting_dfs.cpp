#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
map<T,list<T> > l;
public:
  void addEdge(T x,T y){
      //directed graph 
      l[x].push_back(y);
  }


void dfs_helper(T src,map<T,bool>&visited,list<T> &ordering){
    visited[src]=true;
    for(auto p:l[src]){
        if(!visited[p])
        dfs_helper(p,visited,ordering);
    }
    ordering.push_front(src);
}

void dfs(){
    map<T,bool> visited;
    list<T> ordering;
    //first of all make all the nodes as not visited

    for(auto x:l){
        visited[x.first]=false;
    } 
    for(auto p:l){
        if(!visited[p.first]){
               dfs_helper(p.first,visited,ordering); 
        }  
    }
    for(auto n:ordering){
        cout<<n<<" ";
    }    
}
};


int main() {
    Graph<string> g;
    g.addEdge("Python","DataProcessing");
    g.addEdge("Python","Pytorch");
    g.addEdge("Python","ML");
    g.addEdge("DataProcessing","ML");
    g.addEdge("Pytorch","DL");
    g.addEdge("ML","DL");
    g.addEdge("DL","FaceRecogination");
    g.addEdge("Dataset","FaceRecogination");
    g.dfs();
}