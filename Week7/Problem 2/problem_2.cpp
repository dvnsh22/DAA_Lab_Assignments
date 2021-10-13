/*
Problem 2: Design an algorithm and implement it using a program to demonstrate Bellman-Ford's algorithm.
*/

#include <iostream>
#include <climits>
#define MAX 20

using namespace std;

// Function to print path from a node
void printPath(int *path, int i, int s) {
    while (i != s) {
        cout << i << " ";
        i = path[i];
    }
    cout << i;
}

// Function to print paths from all nodes along with distances
void result(int *dist, int *path, int V, int s) {
    for (int i = 0; i < V; ++i) {
        printPath(path, i, s);
        cout << " : " << dist[i] << endl;
    }
    cout << endl;
}

// Function to implement Bellman-Ford's algorithm
void bellmanFord(int *G[MAX], int V, int s) {
    int *dist = new int[V], *path = new int[V]();

    for (int i = 0; i < V; ++i)
        dist[i] = INT_MAX;
    
    path[s] = s;
    dist[s] = 0;
 
    for (int i = 0; i < V - 1; ++i) {
        for (int u = 0; u < V; ++u) {
            for (int v = 0; v < V; ++v) {
                if (G[u][v] && dist[u] + G[u][v] < dist[v]) {
                    dist[v] = dist[u] + G[u][v];
                    path[v] = u;
                }
            }
        }
    }

    for (int u = 0; u < V; ++u) {
        for (int v = 0; v < V; ++v) {
            if (G[u][v] && dist[u] + G[u][v] < dist[v]) {
                cout << "Negative cycle detected" << endl;
                return;
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
        bellmanFord(G, v, s);

        for (int i = 0; i < v; ++i)
            delete[] G[i];
        delete[] G;
    }
    return 0;
}