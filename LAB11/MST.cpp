#include <stdio.h>
#include <limits.h>
#include <iostream>

using namespace std;

const int V = 6;  // Number of vertices in the graph


//Function to find the vertex with minimum key value
int minimumKey(int key[], bool mstSet[]) {
    int minimumKeyIndex = -1;
    int minimumKeyValue = INT_MAX;

    for (int i = 0; i < V; i++) {
        if (!mstSet[i] && key[i] < minimumKeyValue) {
            minimumKeyValue = key[i];
            minimumKeyIndex = i;
        }
    }

    return minimumKeyIndex;
}

//Construct and print MST for a given graph represented by an adjacency matrix.
void primsMST(int graph[V][V]){
    int parent[V];      
    int key[V];         
    bool mstSet[V];    

    // Initialize all keys as infinite and mstSet[] as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Include first vertex in MST
    key[0] = 0;         
    parent[0] = -1;     

    for (int count = 0; count < V-1; count++) {

        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = -1;
        int min_key = INT_MAX;
        for (int v = 0; v < V; v++) {
            if (!mstSet[v] && key[v] < min_key) {
                min_key = key[v];
                u = v;
            }
        }

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    cout << "Edge    :   Weight" << endl;
    for (int i = 1; i < V; i++) {
        printf("%d - %d   :   %d\n", parent[i], i, graph[parent[i]][i]);
    }
}



int main(){
    //Define the graph
    int graph[V][V] = {{0, 3, 0, 0, 0, 1},
                       {3, 0, 2, 1, 10, 0},
                       {0, 2, 0, 3, 0, 5},
                       {0, 1, 3, 0, 5, 0},
                       {0, 10, 0, 5, 0, 4},
                       {1, 0, 5, 0, 4, 0}};

    // Display the edges of Minimum Spanning Tree
    primsMST(graph);

    return 0;
}
