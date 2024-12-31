#include <stdio.h>
#include <stdio.h>
#include <5.Graph_Adj_mat.c>
#include <stdbool.h>

bool is_connected(GRAPH *g)
{
    int queue[MAX];
    int front = 0;
    int rear = 0;
    int visited[MAX] = {0};

    int start = 1;
    int count = 1;
    queue[rear++] = start;
    visited[start] = 1;

    for (int i = 0; i < g->vertex; i++)
    {
        int current = queue[front++];
        while (front < rear)
        {
            if (!visited[i] && g->adjMatrix[current][i] == 1)
            {
                queue[rear++] = i;
                visited[i] = 1;
                count++;
            }
        }
    }
    return count == g->vertex;
}

bool cycle_detect(GRAPH *g)
{
    int queue[MAX];
    int Parent[MAX];
    int visited[MAX];
    int front, rear;

    for (int i = 0; i < g->vertex; i++)
    {
        Parent[i] = -1;
        visited[i] = 0;
    }

    for (int s = 1; s < g->vertex; s++)
    {
        if (!visited[s])
        {
            front = rear = 0;
            queue[rear++] = s;
            visited[s] = 1;

            while (front < rear)
            {
                int current = queue[front++];
                for (int i = 0; i < g->vertex; i++)
                {
                    if (g->adjMatrix[current][i] && !visited[i])
                    {
                        queue[rear++] = i;
                        visited[i] = 1;
                        Parent[current] = 1;
                    }
                    else if (i != Parent[current])
                        return true;
                }
            }
        }
    }
    return false;
}
