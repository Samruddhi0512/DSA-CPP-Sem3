/** Write a Program to implement Dijkstra’s algorithm
 *  to find shortest distance between two nodes of a user defined graph. 
 * Use Adjacency List to represent a graph. */

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
    int n;                          // number of vertices
    vector<vector<Edge>> adj;       // adjacency list

    Graph(int vertices) {
        n = vertices;
        adj.resize(n);
    }

    // Add directed edge u -> v with weight w
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
    }

    // Dijkstra Algorithm
    void dijkstra(int start) {
        vector<int> dist(n, 999999);  
        dist[start] = 0;

        // Min-heap (distance, vertex)
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto edge : adj[u]) {
                int v = edge.to;
                int w = edge.weight;

                // Relaxation
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        // Print shortest distances
        cout << "\nShortest Distances from vertex " << start << ":\n";
        for (int i = 0; i < n; i++) {
            cout << "To " << i << " = " << dist[i] << endl;
        }
    }
};

// ---------------- MAIN PROGRAM ------------------
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

    g.dijkstra(start);

    return 0;
}