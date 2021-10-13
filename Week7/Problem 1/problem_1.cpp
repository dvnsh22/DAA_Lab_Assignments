/*
Problem 1: Design an algorithm and implement it using a program to demonstrate Dijkstra's algorithm.
*/

#include <iostream>
#include <climits>
#define MAX 20

using namespace std;

// Function to print path from a node
void printPath(int *path, int i) {
    while (path[i] != -1) {
        cout << i << " ";
        i = path[i];
    }
    cout << i;
}

// Function to print paths from all nodes along with distances
void result(int *dist, int *path, int V, int s) {
    for (int i = 0; i < V; ++i) {
        printPath(path, i);
        cout << " : " << dist[i] << endl;
    }
    cout << endl;
}

// Function to find the vertex with minimum distance value from
// the set of vertices not yet visited
int minDist(int *dist, bool *visited, int V) {
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
 
    return min_index;
}

// Function to implement Dijkstra's algorithm
void dijkstra(int *G[MAX], int V, int s) {
    int *dist = new int[V], *path = new int[V];
    bool *visited = new bool[V]();

    for (int i = 0; i < V; ++i)
        dist[i] = INT_MAX;
    
    path[0] = -1;
    dist[s] = 0;
 
    for (int i = 0; i < V - 1; ++i) {
        int u = minDist(dist, visited, V);
        visited[u] = true;
        
        for (int v = 0; v < V; ++v) {
            if (!visited[v] && G[u][v] && 
                dist[u] != INT_MAX && dist[u] + G[u][v] < dist[v]) {
                dist[v] = dist[u] + G[u][v];
                path[v] = u;
            }
        }
    }

    result(dist, path, V, s);
}

// Driver function
int main() {
    int t, v, s;

    // t = No. of test cases
    cin >> t;

    while (t--) {
        cin >> v;
        int **G = new int*[v];

        for (int i = 0; i < v; ++i) {
            G[i] = new int[v];
            for (int j = 0; j < v; ++j)
                cin >> G[i][j];
        }

        cin >> s;
        
        // Function call
        dijkstra(G, v, s);

        for (int i = 0; i < v; ++i)
            delete[] G[i];
        delete[] G;
    }
    return 0;
}