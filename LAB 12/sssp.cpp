#include <iostream>
#include <vector>
using namespace std;

#define INF 9999999
#define V 6

void printPath(vector<int>& parent, int node) {
    if (parent[node] == -1) {
        cout << node << " => ";
        return;
    }
    printPath(parent, parent[node]);
    cout << node << " => ";
}

void Dijkstra(int graph[V][V], int src) {
    int dist[V]; 
    bool visited[V]; 
    vector<int> parent(V, -1); // Array to store the shortest path parent

    for (int i = 0; i < V; ++i) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[src] = 0; 

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; ++count) {
        int u, minDist = INF;

        // Find the vertex with the minimum distance value among the unvisited vertices
        for (int v = 0; v < V; ++v) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                u = v;
            }
        }

        visited[u] = true; 

        // Update the distances of the adjacent vertices of the visited vertex
        for (int v = 0; v < V; ++v) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u; // Update the parent for shortest path
            }
        }
    }

    // Print the shortest distances and paths from the source to all other nodes
    for (int i = 0; i < V; ++i) {
        cout << "Shortest Time from city " << src << " to city " << i << ": " << dist[i] << endl;
        cout << "Path: ";
        printPath(parent, i);
        cout << endl;
    }
}

int main() {
    int G[V][V] = {
        {0,10,0,0,15,5},
        {10,0,10,30,0,0},
        {0,10,0,12,5,0},
        {0,30,12,0,0,20},
        {15,0,5,0,0,0},
        {5,0,0,20,0,0}
    };

    Dijkstra(G, 2); 

    return 0;
}
