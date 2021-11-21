/*
Problem 3: Assume a road construction project is given to a person. The amount he will earn from
           this project is directly proportional to the budget of the project. This person is greedy, so 
           he decided to maximize the budget by constructing those roads who have highest construction cost.
           Design an algorithm and implement it using a program to find the maximum budget required for this project.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using viii = vector<pair<int, pair<int, int>>>;

// Function to find representative element
int find(int u, vector<int> &parent) {
    if (parent[u] < 0)
        return u;

    return find(parent[u], parent);
}

// Function to merge 2 subsets into a set
void unionByWeight(int u, int v, vector<int> &parent) {
    int pu = find(u, parent), pv = find(v, parent);

    if (pu != pv) {
        if (parent[pu] < parent[pv]) {
            parent[pu] += parent[pv];
            parent[pv] = pu;
        }
        else {
            parent[pv] += parent[pu];
            parent[pu] = pv;
        }
    }
}

// Function to implement Kruskal's algorithm
int kruskal(viii &G, int V) {
    int weight = 0;
    vector<int> parent(V, -1);

    sort(G.begin(),G.end(), greater<pair<int, pair<int, int>>>());

    for (int i = 0; i < G.size(); ++i) {
        int s = G[i].second.first;
        int d = G[i].second.second;

        if (find(s, parent) != find(d, parent)) {
            weight += G[i].first;
            unionByWeight(s, d, parent);
        }
    }

    return weight;
}

// Driver function
int main() {
    int t, v, w;

    // t = No. of test cases
    cin >> t;

    while (t--) {
        cin >> v;
        viii G;

        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < v; ++j) {
                cin >> w;
                if (w)
                    G.push_back(make_pair(w, make_pair(i, j)));
            }
        }
        
        // Function call
        cout << "Maximum Spanning Weight: " << kruskal(G, v) << endl << endl;
    }
    return 0;
}