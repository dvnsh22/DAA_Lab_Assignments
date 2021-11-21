/*
Problem 1: Design an algorithm and implement it using a program to demonstrate Prim's algorithm.
*/

#include <iostream>
#include <vector>

using namespace std;
using vii = vector<vector<int>>;

int minKey(vector<int> &key, vector<bool> &visited, int V) {
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; ++v) {
        if (!visited[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
 
    return min_index;
}

// Function to implement Prim's algorithm
int prim(vii &G, int V) {
    int weight = 0;
    vector<int> key(V, INT_MAX);
    vector<bool> visited(V, false);
 
    key[0] = 0;
 
    for (int i = 0; i < V - 1; ++i) {
        int u = minKey(key, visited, V);
        visited[u] = true;
 
        for (int v = 0; v < V; ++v) {
            if (G[u][v] && !visited[v] && G[u][v] < key[v])
                key[v] = G[u][v];
        }
    }

    for (int i = 1; i < V; ++i)
        weight += key[i];

    return weight;
}

// Driver function
int main() {
    int t, v;

    // t = No. of test cases
    cin >> t;

    while (t--) {
        cin >> v;
        vii G(v, vector<int> (v));

        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < v; ++j)
                cin >> G[i][j];
        }

        // Function call
        cout << "Minimum Spanning Weight: " << prim(G, v) << endl << endl;
    }
    return 0;
}