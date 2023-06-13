#include <stdio.h>
#include <limits.h>

#define V 5

int minKey(int a[],int checked[]){
     int min=INT_MAX;
     int m=INT_MAX;
     int i;
     for (i = 0; i < V; i++)
     {
          if(min>=a[i] && checked[i]==0){
               m = i;
               min = a[i];
          }
          // printf("%d ",min);
     }
     return m;
}

int minValue(int a[],int checked[]){
     int min=INT_MAX;
     int i;
     for (i = 0; i < V; i++)
     {
          if(min>=a[i] && checked[i]==0){
               min = a[i];
          }
          // printf("%d ",min);
     }
     return min;
}

void primMST(int graph[V][V]){
     int y = 0;
     int A[V];
     int checked[V];
     int mst[V];
     for (int i = 0; i < V; i++)
     {
          A[i] = INT_MAX;
          checked[i] = 0;
     }
     A[0] = 0;
     for (int i = 0; i < V; i++)
     {
          int u = minKey(A,checked);
          int c = minValue(A,checked);
          // printf("(%d) ",c);
          mst[y] = c;
          y++;
          // printf("\n----%d-----\n",u);
          checked[u] = 1;
          int j,min_Index=10;
          for (j = 0; j < V; j++)
          {
               // int min=A[j];
               if(graph[u][j]<A[j] && graph[u][j]!=0 && checked[j]==0){
                    A[j] = graph[u][j];
                    min_Index = j;
                    // A[min_Index] = min;
                    // printf("%d = %d\n",min_Index,min);
               }
          }
     }
     for (int i = 0; i < V; i++)
     {
          printf("%d ",mst[i]);
     }
}

int main()
{
     int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
     primMST(graph);
     return 0;
}