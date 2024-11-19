#include <stdio.h>
#include <limits.h>
#define V 5
int minDistance(int dist[],int spSet[]){
	int min=INT_MAX;
	int min_index=-1;
	int i;
	for (i=0;i<V;i++){
		if (spSet[i]==0 && dist[i]<=min){
			min=dist[i];
			min_index=i;
			
		}
	}
	return min_index;
}
void print(int dist[]){
	int i;
	for (i=0;i<V;i++){
		printf("%d\t %d\n",i,dist[i]);
	}
}
void djkstra(int graph[V][V], int src){
	int i,v,count;
	int dist[V];
	int spSet[V];
	for (i=0;i<V;i++){
		dist[i]=INT_MAX;
		spSet[i]=0;
	}
	dist[src]=0;
	for (count=0;count<V-1;count++){
		int u=minDistance(dist,spSet);
		spSet[u]=1;
		for (v=0;v<V;v++){
		if (!spSet[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v]){
			dist[v]=dist[u]+graph[u][v];
		}
			}
}
print(dist);
}
int main(){
	int graph[V][V]={
	{0, 8, 0, 0, 7},
    {0, 0, 5, 0, 3},
    {0, 0, 0, 9, 0},
    {4, 0, 2, 0, 0},
    {0, 6, 0, 1, 0}};
    int src=0;
    djkstra(graph,src);
    
	return 0;
	
}