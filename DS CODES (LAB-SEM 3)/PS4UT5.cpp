/** Write a Program to implement Dijkstra’s algorithm to find
shortest distance between two nodes of a user defined graph.
Use Adjacency List to represent a graph.**/
/** 
 *                    UNIT 5   
 */

 #include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 9999999

// -------------------- Structure to store adjacency list edges -------------
struct Edge {
    int to;      // destination vertex
    int weight;  // weight of the edge
};

// -------------------- Dijkstra's Algorithm -------------------------------
void dijkstra(int start, int n, vector<Edge> adj[]) {
    vector<int> dist(n, INF);   // distance from start to each node
    dist[start] = 0;

    // min-heap (distance, node)
    priority_queue<pair<int,int>, 
                   vector<pair<int,int>>, 
                   greater<pair<int,int>>> pq;

    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // explore neighbors
        for (auto edge : adj[u]) {
            int v = edge.to;
            int w = edge.weight;

            // relaxation
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    // ---------------- Print Distances ----------------
    cout << "\nShortest distances from node " << start << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "To " << i << " = " << dist[i] << endl;
    }
}

// -------------------- MAIN PROGRAM ---------------------------------------
int main() {
    int n, m;

    cout << "Enter number of vertices: ";
    cin >> n;

    vector<Edge> adj[100];

    cout << "Enter number of edges: ";
    cin >> m;

    cout << "Enter edges in format (u v weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        // For undirected graph, also add: adj[v].push_back({u, w});
    }

    int start;
    cout << "\nEnter starting vertex for Dijkstra: ";
    cin >> start;

    dijkstra(start, n, adj);

    return 0;
}