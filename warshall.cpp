#include<iostream>
using namespace std;
#define max 10
#define V 4
#define INF 999
int adj[max][max];
void printSolution(int adj[][V]);

void warshall(int adj[][max]){
  int dist[V][V]={0};
for (int i=0;i<V;i++) {
          for (int j=0;j<V;j++) {
              dist[i][j] = adj[i][j];
          }
      }

for (int k=0;k<V;k++) {
  for (int i=0;i<V;i++) {
    for (int j=0;j<V;j++) {
      if (dist[i][k] + dist[k][j] < dist[i][j])
          dist[i][j] = dist[i][k] + dist[k][j];
              }
            }
        }
      printSolution(dist);
  }


void printSolution(int dist[][V]) {

      cout<<"Following matrix shows the shortest distances"
              " between every pair of vertices \n";
      for (int i=0;i<V;i++) {
          for (int j=0;j<V;j++) {
              if (dist[i][j] == 999)
                  cout<<"INF";
              else
                  cout<<dist[i][j];
          }
          cout<<"\n";
      }
  }




int main()
{

  int edges,i,j,origin,dest,max_edges;
  int graph_type,weight;
  cout<<"\nenter 2for undirected graph & 1 for directed";
  cin>>graph_type;
  if(graph_type==1)
  {
    max_edges=max*(max-1)/2;//
  }
  else
  {
    max_edges=max*(max-1);//
  }
  for(i=1;i<=max_edges;i++)
  {
    cout<<"enter edge %d (-1 -1 to exit):"<<i;
    cin>>origin;
    cin>>dest;
    cin>>weight;
    if((origin==-1) && (dest==-1))
    break;
    if(origin>9 || dest>9 || origin<0 || dest<0)
    {
      cout<<"\ninvalid vertex";
      i--;
    }
    else
    {
      adj[origin][dest]=weight;
      if(graph_type==2)
      adj[dest][origin]=weight;
    }
  }
  warshall(adj);
 return 0;
}
