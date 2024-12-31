// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 10
// typedef struct graph
// {
//     int vertex;
//     int adj[MAX][MAX];
// } Graph;

// void creatematrix(Graph *g)
// {
//     printf("Enter no of vertices");
//     scanf("%d", &(g->vertex));
//     int from, to;
//     for (int i = 1; i < g->vertex; i++)
//     {
//         g->adj[0][i] = i;
//         g->adj[i][0] = i;
//         for (int j = 1; j < g->vertex; j++)
//         {
//             g->adj[i][j] = 0;
//         }
//     }
// int c=1;
//     while (c!=0)
//     {
//         printf("enter the from and to vertices");
//         scanf("%d %d", &from, &to);
//         if (to > 0 && to <= g->vertex && from > 0 && from <= g->vertex)
//         {
//             g->adj[from][to] = 1;
//         }
//         printf("enter 1 for con and 0 for finish");
//         scanf("%d",&c);
//     }
// }

// void display(Graph *g)
// {
//     for (int i = 0; i < g->vertex; i++)
//     {
//         printf("\n");
//         for (int j = 0; j < g->vertex; j++)
//         {
//             if (i == 0 && j == 0)
//             {
//                 printf(" ");
//             }
//             else
//             {
//                 printf("%d ", g->adj[i][j]);
//             }
//         }
//     }
// }

// int main(){
//     Graph *g= (Graph*)malloc(sizeof(Graph));
//     creatematrix(g);
//     display(g);
//     free(g);
// }

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct graph {
    int vertex;
    int adj[MAX][MAX];
} Graph;

void creatematrix(Graph *g) {
    printf("Enter the number of vertices (max %d): ", MAX - 1);
    scanf("%d", &(g->vertex));
    if (g->vertex <= 0 || g->vertex >= MAX) {
        printf("Invalid number of vertices. Exiting.\n");
        exit(1);
    }

    // Initialize the adjacency matrix
    for (int i = 0; i <= g->vertex; i++) {
        for (int j = 0; j <= g->vertex; j++) {
            g->adj[i][j] = 0; // Set all to 0 initially
        }
    }

    // Set row and column labels
    for (int i = 1; i <= g->vertex; i++) {
        g->adj[0][i] = i; // Column labels
        g->adj[i][0] = i; // Row labels
    }

    // Input edges
    printf("Enter edges as pairs of vertices (from to), or -1 -1 to stop:\n");
    while (1) {
        int from, to;
        scanf("%d %d", &from, &to);
        if (from == -1 && to == -1) {
            break; // Exit the loop
        }
        if (from > 0 && from <= g->vertex && to > 0 && to <= g->vertex) {
            g->adj[from][to] = 1; // Mark edge in adjacency matrix
        } else {
            printf("Invalid edge. Please enter vertices between 1 and %d.\n", g->vertex);
        }
    }
}

void display(Graph *g) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i <= g->vertex; i++) {
        for (int j = 0; j <= g->vertex; j++) {
            if (i == 0 && j == 0) {
                printf("  "); // Top-left corner empty
            } else {
                printf("%d ", g->adj[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    Graph *g = (Graph *)malloc(sizeof(Graph)); // Allocate memory for the graph
    if (!g) {
        printf("Memory allocation failed. Exiting.\n");
        return 1;
    }

    creatematrix(g); // Create the adjacency matrix
    display(g);      // Display the adjacency matrix

    free(g); // Free the allocated memory
    return 0;
}
