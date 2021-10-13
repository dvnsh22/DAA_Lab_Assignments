/*
Problem 3: Given a directed graph with two vertices (source and destination). Design an algorithm 
and implement it using a program to find the weight of the shortest path from source to destination
with exactly 'k' edges on the path.
*/

#include <iostream>
#include <climits>
#define MAX 20

using namespace std;

// Function to find weight of shortest path from source to destination
// node with exactly 'k' edges in between
int findWeight(int *G[MAX], int V, int s, int d, int k) {
    if (k == 0 && s == d)
        return 0;

    if (k == 1 && G[s][d])
        return G[s][d];

    if (k <= 0)
        return -1;
    
    int weight = INT_MAX;
    for (int i = 0; i < V; ++i) {
        if (G[s][i] && s != i && d != i) {
            int w = findWeight(G, V, i, d, k - 1);

            if (w != -1 && w != INT_MAX)
                weight = min(weight, G[s][i] + w);
        }
    }

    return weight;
}

// Driver function
int main() {
    int t, v, s, d, k;

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

        cin >> s >> d;
        cin >> k;
        
        // Function call
        int w = findWeight(G, v, s, d, k);

        if (w != INT_MAX)
            cout << "Weight of shortest path from (" << s << ", " << d << ") with " << k << " edges: " << w;
        else
            cout << "No path of length " << k << " is available";
        cout << endl << endl;

        for (int i = 0; i < v; ++i)
            delete[] G[i];
        delete[] G;
    }
    return 0;
}