/** Write a Program to implement Prim’s algorithm to find minimum spanning tree of a user defined graph. Use Adjacency
List to represent a graph. */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ---------- Edge Structure ----------
struct Edge {
    int to;
    int weight;
};

// ---------- Graph Class ----------
class Graph {
public:
    int n;                         // number of vertices
    vector<vector<Edge>> adj;      // adjacency list

    Graph(int vertices) {
        n = vertices;
        adj.resize(n);
    }

    // Add undirected edge
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Prim’s Algorithm (OOP method)
    void primMST(int start) {
        vector<int> key(n, 999999);
        vector<int> parent(n, -1);
        vector<bool> inMST(n, false);

        // Min-heap (weight, vertex)
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        key[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;

            // Explore neighbours
            for (const auto& edge : adj[u]) {
                int v = edge.to;
                int w = edge.weight;

                if (!inMST[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }

        // Print MST
        cout << "\nMinimum Spanning Tree (Prim's Algorithm):\n";
        for (int i = 0; i < n; i++) {
            if (parent[i] != -1)
                cout << parent[i] << " -- " << i 
                     << "  (Weight: " << key[i] << ")\n";
        }
    }
};

// ---------------- Main Program ------------------
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

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    g.primMST(start);

    return 0;
}