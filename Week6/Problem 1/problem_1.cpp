/*
Problem 1: Given a (directed/undirected) graph, design an algorithm and implement it 
using a program to find if a path exists between two given vertices or not. (Hint: Use DFS)
*/

#include <iostream>
#include <stack>
#define MAX 20

using namespace std;

// Function to check whether a path exists between 2 nodes of graph or not
bool isPath(int *G[MAX], int V, int s, int d) {
    stack<int> st;
    bool *visited = new bool[V]();

    st.push(s);
    visited[s] = 1;
     
    while (!st.empty()) {
        int u = st.top();
        st.pop();

        for (int v = 0; v < V; ++v) {
            if (G[u][v] && v == d)
                return true;

            if (G[u][v] && !visited[v]) {
                st.push(v);
                visited[v] = 1;
            }
        }
    }

    return false;
}

// Driver function
int main() {
    int t, v, s, d;

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

        // Function call
        if (isPath(G, v, s, d))
            cout << "Yes, path exists";
        else
            cout << "No, path doesn't exist";
        cout << endl;

        delete[] G;
    }
    return 0;
}