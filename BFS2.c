#include <stdio.h>
#include "5.Graph_Adj_mat.c"
#include <stdlib.h>
#include <stdbool.h>

int f = -1, r = -1;

bool isempty(int *q)
{
    return (f == -1 && r == -1);
}

void enqueue(int *q, int data)
{
    if (isempty(q))
        f++;
    q[r++] = data;
}

int dequeue(int *q){
    int current = q[f++];
    if(f==r && f!=-1){
        f=-1;
        r=-1;
    }
    else
        f=0;
    return current;
}

void bfs(GRAPH *g,int source){
    int queue[MAX];
    int visited[MAX];
    enqueue(queue,source);
    while(!(isempty(queue))){
    for(int i =1;i< g->vertex ; i++){
        int k = dequeue(queue);
        if(g->adjMatrix[k][i] && visited[i]){
            enqueue(queue,i);
            visited[i] = 1;
            printf("%d " , i);
        }
    }
    }
}