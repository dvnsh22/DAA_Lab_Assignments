/*
Problem 1: Given a graph, design an algorithm and implement it using a program to implement 
           Floyd-Warshall's all pair shortest path algorithm.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#define INF INT_MAX

using namespace std;
using vii = vector<vector<int>>;

void tokenizer(string s, vii &G, int i) {
    stringstream ss(s);
    string word;
    int j = 0;
    while (ss >> word) {
        G[i][j++] = (word == "INF") ? INF : stoi(word);
    }
}

void floydWarshall(vii &G, int V) {
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (G[i][j] > (G[i][k] + G[k][j]) && 
                   (G[k][j] != INF && G[i][k] != INF))
                    G[i][j] = G[i][k] + G[k][j];
            }
        }
    }

    cout << "Shortest Distance Matrix: " << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (G[i][j] == INF)
                cout << "INF ";
            else
                cout << G[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Driver function
int main() {
    int t, v;
    string line;

    // t = No. of test cases
    cin >> t;

    while (t--) {
        cin >> v;
        vii G(v, vector<int> (v));

        getline(cin, line);
        for (int i = 0; i < v; ++i) {
            getline(cin, line);
            tokenizer(line, G, i);
        }
            
        // Function call
        floydWarshall(G, v);
    }
    return 0;
}