#include<iostream>
#include<limits>    // INT_MAX in this lib, has the infinity value
using namespace std;
#define v 5
int choosingV(int dis[],bool setS[]){   //int dis[] is == int *dis
    int max = INT16_MAX,min,set=0;
    for(int i=0;i<v;i++){
        if(setS[i]==false && dis[i]<max){
            min = dis[i];
            max = dis[i];
            set =i;
        }
    }
    return set;
}
void relax(int dis[],int weight,int u,int pos){
    if (dis[pos]>dis[u]+weight){
        dis[pos]=dis[u]+weight;
    }
}
void outgoing(int graph[v][v],int dis[],int u){
    int weight;
    for(int i=0;i<v;i++){
        if (graph[u][i]>0){
            weight = graph[u][i];
            relax(dis,weight,u,i);
        }
    }
}
void dijkstra(int graph[v][v],int src){
    int dis[v]; //
    bool setS[v];
    for(int i=0;i<v;i++){
        dis[i]=INT16_MAX,setS[i]=false;
    }
    dis[src]=0;
    //Now, we are done with the initialization
    //Now, head towards the  picking the smallest value from the dis array
    for(int i=0;i<v;i++){
        int u = choosingV(dis,setS);
        setS[u]=true;
        outgoing(graph,dis,u);
    }
    // Printing the shortest Distance to all the node from the single source
    for(int i=0;i<v;i++){
        cout<<"The Shortest Distance to Vertex "<<i<<" is "<<dis[i]<<endl;
    }
}
int main(){
    int graph[v][v] = {{0, 10, 0, 0, 5},{0, 0, 1, 0, 2},{0, 0, 0, 4, 0},{7, 0, 6, 0, 0},{0, 3, 9, 2, 0}};
    dijkstra(graph,0);
    return 0;
}