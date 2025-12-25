/** Write a Program to implement Kruskal’s algorithm to find the minimum spanning tree 
 * of a user defined graph. Use Adjacency Matrix to represent a graph. */
/** 
 *                    UNIT 5   
 */

 #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// -------- Structure for edges ----------
struct Edge {
    int u, v, w;    // start, end, weight
};

// -------- Find parent (Union-Find) ------
int findParent(int v, vector<int>& parent) {
    if (parent[v] == v)
        return v;
    return parent[v] = findParent(parent[v], parent); // path compression
}

// -------- Union two sets ---------------
void unionSet(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = findParent(a, parent);
    b = findParent(b, parent);

    if (a != b) {
        if (rank[a] < rank[b])
            parent[a] = b;
        else if (rank[a] > rank[b])
            parent[b] = a;
        else {
            parent[b] = a;
            rank[a]++;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int adj[20][20];

    cout << "Enter adjacency matrix (0 for no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    // ---------------- Collect all edges ----------------
    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {      // upper triangle only
            if (adj[i][j] != 0) {
                edges.push_back({i, j, adj[i][j]});
            }
        }
    }

    // ---------------- Sort edges by weight -------------
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) { return a.w < b.w; });

    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    cout << "\nMinimum Spanning Tree (Kruskal):\n";
    int mstWeight = 0;

    // ---------------- Kruskal's Algorithm ---------------
    for (auto e : edges) {
        if (findParent(e.u, parent) != findParent(e.v, parent)) {
            cout << e.u << " -- " << e.v << " (Weight: " << e.w << ")\n";
            mstWeight += e.w;
            unionSet(e.u, e.v, parent, rank);
        }
    }

    cout << "Total Weight of MST: " << mstWeight << endl;

    return 0;
}