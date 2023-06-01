#include <iostream>
#include <vector>
#include <climits>
#include <stack>

using namespace std;


//Function for finding and printing the shortest path
void printPath(const vector<int>& parent, int destination) {
    stack<int> path;
    int current = destination;
    while (current != -1) {
        path.push(current);
        current = parent[current];
    }

    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
    cout << endl;
}

//function to implemect dijkstra algorithm
int dijkstra(const vector<vector<int>>& graph, int citiesCount, int source, int destination) {

    vector<int> distance(citiesCount, INT_MAX);     
    vector<bool> visited(citiesCount, false); 
    vector<int> parent(citiesCount, -1); 

    distance[source] = 0; // Distance from source to itself is 0

    // Finding the shortest path from source to all other vertices
    for (int count = 0; count < citiesCount - 1; ++count) {
        int u = -1;

        // Finding the vertex with the minimum distance among unvisited vertices
        for (int v = 0; v < citiesCount; ++v) {
            if (!visited[v] && (u == -1 || distance[v] < distance[u]))
                u = v;
        }

        visited[u] = true; // Marking the selected vertex as visited

        // Updating the distances of the adjacent vertices of the selected vertex
        for (int v = 0; v < citiesCount; ++v) {
            if (!visited[v] && graph[u][v] != 0 && distance[u] != INT_MAX &&
                distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    //Print the shortest path
    cout << "Shortest path from city " << source << " to city " << destination << ": ";
    printPath(parent, destination);

    return distance[destination];
}

int main() {
    int citiesCount = 6;

    //graph for the given scenario
    vector<vector<int>> graph = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    //initializing the source you select
    int source = 5;


    for (int destination = 0; destination < 6; destination++) {
        if (source == destination) continue;
        int shortestTime = dijkstra(graph, citiesCount, source, destination);
        cout << "Sortest time from city " << source << " to "<< destination << " is " << shortestTime << endl;
        cout<<endl;
    }

    return 0;
}
