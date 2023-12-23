// Q1. Input: A file containing following details for some n 
// Graph with n vertices in the format
// V1 : (e1, w1) (e2, w2) (e3,w3)
// V2 : (e4, w4) (e5, w5)
// .				  
// .
// .
// Vn: (ei,wi) (ej,wj)

// Output: Minimum spanning tree in adjacency list format

// E.g. - Input
// 1: ((1,2),1) ((1,3),1)
// 2: ((2,1),1) ((2,3),1)
// 3: ((3,1),1) ((3,2),1)

// Output
// 1: ((1,2),1) ((1,3),1)
// 2: ((2,1),1)
// 3: ((3,1),1)



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int V, E;
    struct Edge* edges;
};

// Function to create a graph
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    graph->edges[graph->E].src = src;
    graph->edges[graph->E].dest = dest;
    graph->edges[graph->E].weight = weight;
    graph->E++;
}

// Function to print the minimum spanning tree
// Function to print the minimum spanning tree
void printMST(int parent[], struct Graph* graph) {
    printf("Minimum Spanning Tree:\n");
    for (int i = 1; i < graph->V; i++) {
        // Find the edge corresponding to the parent-child pair
        int src = parent[i];
        int dest = i;
        int weight = 0;

        // Search for the edge in the graph's edges array
        for (int j = 0; j < graph->E; j++) {
            if (graph->edges[j].src == src && graph->edges[j].dest == dest) {
                weight = graph->edges[j].weight;
                break;
            }
        }

        printf("(%d, %d) - %d\n", src+1, dest+1, weight+1);
    }
}


// Function to construct and find the minimum spanning tree
void findMinimumSpanningTree(struct Graph* graph) {
    int parent[graph->V]; // Array to store constructed MST
    int key[graph->V]; // Key values used to pick minimum weight edge
    bool mstSet[graph->V]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE and mstSet[] as false
    for (int i = 0; i < graph->V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include the first vertex in MST
    key[0] = 0; // Make key 0 so that this vertex is picked as the first vertex
    parent[0] = -1; // First node is always the root of MST

    // The MST will have V vertices
    for (int count = 0; count < graph->V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u;
        int min = INT_MAX;
        for (int v = 0; v < graph->V; v++) {
            if (!mstSet[v] && key[v] < min) {
                u = v;
                min = key[v];
            }
        }

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < graph->V; v++) {
            if (!mstSet[v] && graph->edges[u].weight < key[v]) {
                parent[v] = u;
                key[v] = graph->edges[u].weight;
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph);
}

int main() {
    int V, E;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &E);

    // Create a graph
    struct Graph* graph = createGraph(V, E);

    printf("Enter the edges in the format (src, dest, weight):\n");
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }

    // Find the minimum spanning tree
    findMinimumSpanningTree(graph);

    // Free dynamically allocated memory
    free(graph->edges);
    free(graph);

return 0; } 
