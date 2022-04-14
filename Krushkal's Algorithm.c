#include <stdio.h>
#define I 65535
int edge[1000][3];
int set[1000];
int included[1000];
void join(int u,int v)
{
     if(set[u]<set[v])
      {
         set[u]+=set[v];
         set[v]=u;
       }
     else
      {
         set[v]+=set[u];
         set[u]=v;
      }
}
int find(int u)
    {
        int x=u,v=0;
        while(set[x]>0)
        x=set[x];
        while(u!=x)
     {
        v=set[u];
        set[u]=x;
        u=v;
      }
    return x;
  }
int t[2][100];
int krushkals()
{  int edges,vertex,b,temp;
    printf("Enter number of Edges and Vertex in your graph\n");
    scanf("%d%d",&edges,&vertex);
    for(b=0;b<edges;b++)
    {
        temp=b+1;
        printf("Enter %d edges 2 vertex with weights: ",temp);
        scanf("%d%d%d",&edge[b][0],&edge[b][1],&edge[b][2]);
    }
    for(b=0;b<edges-1;b++)
        set[b]=-1;
    int u=0,v=0,i=0,j,k=0,min=65535;
    while(i<vertex-1)
    {
        min=65535;
        for(j=0;j<edges;j++)
         {
            if(included[j]==0 && edge[j][2]<min)
              {
                 u=edge[j][0];v=edge[j][1];min=edge[j][2];
                 k=j;
               }
          }
        if(find(u)!= find(v))
         {
            t[0][i]=u;t[1][i]=v;
            join(find(u),find(v));
            included[k]=1;
             i++;
          }
       else included[k]=1;
     }
    printf("Spanning Tree\n");
      for(i=0;i<6;i++)
         printf("%d %d\n",t[0][i],t[1][i]);
  return 0;
    }
int main()
  {   krushkals();
       return 0;
     }
