/** Write a Program to implement Prim’s algorithm to find minimum
spanning tree of a user defined graph. Use Adjacency List to
represent a graph. */
/** 
 *                    UNIT 5   
 */

 #include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 999999

// ----------------------- Structure for Graph Edge ------------------------
struct Edge {
    int to;     // destination vertex
    int weight; // weight of the edge
};

// ----------------------- Graph as Adjacency List -------------------------
vector<Edge> adj[100];   // adjacency list
int n;                    // number of vertices

// ----------------------- Prim's Algorithm -------------------------------
void primMST(int start) {
    vector<int> key(n, INF);      // minimum edge weight to reach vertex
    vector<int> parent(n, -1);    // store MST structure
    vector<bool> inMST(n, false); // track visited nodes

    // Min-heap (priority queue) of (weight, vertex)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    key[start] = 0;               // start from given node
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // avoid revisiting nodes
        if (inMST[u]) continue;

        inMST[u] = true;

        // Explore all adjacent vertices
        for (auto edge : adj[u]) {
            int v = edge.to;
            int weight = edge.weight;

            // If v is not in MST and weight < key[v], update it
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    // ---------------- Print MST -------------------
    cout << "\nMinimum Spanning Tree (Prim's Algorithm):\n";
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1)
            cout << parent[i] << " -- " << i
                 << "  (Weight: " << key[i] << ")\n";
    }
}

// ----------------------- MAIN PROGRAM -------------------------------
int main() {
    int edges;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges in the format (u v weight):\n";
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        // undirected graph → add both directions
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int start;
    cout << "\nEnter starting vertex for Prim's Algorithm: ";
    cin >> start;

    primMST(start);

    return 0;
}