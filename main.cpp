//
//  main.cpp
//  RandomGraphCPlusPlus
//
//  Created by Yun Wang on 24/08/2015.
//  Copyright (c) 2015 Yun Wang. All rights reserved.
//

#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10
#define PROBABILITY 0.3
#define MAX_LENGTH 5
#define ORIGIN 3
#define DESTINATION 4

void dijkstra(int a, int b, int graph[MAX_NODES][MAX_NODES]);
int minDistance( int dist[],bool visited[]);
int main(int argc, const char * argv[]) {
    // insert code here...
    int i;
    int j;
    int graph[MAX_NODES][MAX_NODES];
    
    for(i=0;i<MAX_NODES;i++){
        for(j=0;j<MAX_NODES;j++){
           graph[i][j]=0;
        }
    }
    
    
    for(i=0;i<MAX_NODES;i++){
        for(j=0;j<MAX_NODES;j++){
            if(i<j){
                if((double) rand() / (RAND_MAX)<PROBABILITY){
                    graph[i][j]=rand()%MAX_LENGTH+1;
                    graph[j][i]=graph[i][j];
                }
            }


            std::cout<<graph[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    
    dijkstra(ORIGIN, DESTINATION, graph);
    std::cout << "random graph generated\n";
    
    
    return 0;
}

void dijkstra(int a, int b, int graph[MAX_NODES][MAX_NODES]){
    int dist[MAX_NODES];
    bool visited[MAX_NODES];
    for(int i=0;i<MAX_NODES;i++){
        dist[i]=INT_MAX;
        visited[i]=false;
    }
    dist[a]=0;
    int count=0;
    while(visited[b]==false){
        
        int node=minDistance(dist,visited);
        visited[node]=true;
        count++;
        for(int i=0;i<MAX_NODES;i++){
            if(!visited[i]&&graph[node][i]
               &&dist[node]!=INT_MAX
               &&dist[node]+graph[node][i]<dist[i])
                dist[i]=dist[node]+graph[node][i];
                
        }
        
        
        if(count==MAX_NODES)
            break;
    }
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < MAX_NODES; i++)
        if(dist[i]==INT_MAX){
            printf("%d not visited or unreachable from source\n",i);
        }
        else
        printf("%d \t\t %d\n", i, dist[i]);
    

}

int minDistance( int dist[],bool visited[]){
    int min=INT_MAX;
    int minIndex=NULL;
    for(int i=0;i<MAX_NODES;i++){
        if(visited[i]==false&&dist[i]<=min){
            min=dist[i];
            minIndex=i;
        }
    }
    return minIndex;
}

