/** Write a Program to implement Kruskal’s algorithm to find the
minimum spanning tree of a user defined graph. Use Adjacency
List to represent a graph.**/
/** 
 *                    UNIT 5   
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// --------------------------- Edge Structure ----------------------------
struct Edge {
    int u, v, w;  // u -- v (weight w)
};

// --------------------------- Disjoint Set (Union-Find) ------------------
int findParent(int v, vector<int>& parent) {
    if (parent[v] == v)
        return v;
    return parent[v] = findParent(parent[v], parent); // path compression
}

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

// --------------------------- Kruskal Algorithm --------------------------
void kruskalMST(vector<Edge>& edges, int n) {

    // Sort edges based on weight
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) { return a.w < b.w; });

    vector<int> parent(n), rank(n, 0);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    cout << "\nMinimum Spanning Tree (Kruskal’s Algorithm):\n";

    int mst_weight = 0;

    for (auto e : edges) {
        // Check if current edge forms a cycle
        if (findParent(e.u, parent) != findParent(e.v, parent)) {

            cout << e.u << " -- " << e.v
                 << " (Weight: " << e.w << ")\n";

            mst_weight += e.w;

            // Union the two sets
            unionSet(e.u, e.v, parent, rank);
        }
    }

    cout << "\nTotal Weight of MST: " << mst_weight << endl;
}

// --------------------------- MAIN PROGRAM ------------------------------
int main() {
    int n, m;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    vector<Edge> edges;

    cout << "Enter edges in format (u v weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        // For adjacency list version, both directions would be added,
        // but edge list is enough for Kruskal.
    }

    kruskalMST(edges, n);

    return 0;
}