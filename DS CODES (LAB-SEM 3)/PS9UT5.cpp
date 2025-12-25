/* Write a Program to implement Kruskal’s algorithm to find the minimum
 spanning tree of a user defined graph. Use Adjacency List to represent a graph. */

 #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// -------- Edge Structure --------
struct Edge {
    int u, v, w;
};

// -------- Disjoint Set (Union-Find) --------
class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find(parent[v]); // path compression
    }

    void unionSet(int a, int b) {
        a = find(a);
        b = find(b);

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
};

// -------- Graph Class (Adjacency List) --------
class Graph {
public:
    int n;
    vector<vector<pair<int,int>>> adj;  // not required by Kruskal, but per question
    vector<Edge> edges;                 // edge list for Kruskal

    Graph(int vertices) {
        n = vertices;
        adj.resize(n);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  // undirected graph

        edges.push_back({u, v, w});
    }

    void kruskalMST() {
        // Sort edges ascending by weight
        sort(edges.begin(), edges.end(),
             [](Edge a, Edge b) { return a.w < b.w; });

        DisjointSet ds(n);

        cout << "\nMinimum Spanning Tree (Kruskal’s Algorithm):\n";

        int mstWeight = 0;

        for (auto e : edges) {
            // Check if including this edge forms a cycle
            if (ds.find(e.u) != ds.find(e.v)) {
                cout << e.u << " -- " << e.v
                     << "  (Weight: " << e.w << ")\n";

                mstWeight += e.w;

                ds.unionSet(e.u, e.v);
            }
        }

        cout << "Total Weight of MST: " << mstWeight << endl;
    }
};

// --------------------- MAIN ---------------------
int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;

    Graph g(n);

    cout << "Enter number of edges: ";
    cin >> m;

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    g.kruskalMST();

    return 0;
}