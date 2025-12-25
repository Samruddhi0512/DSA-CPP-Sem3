/** Write a Program to accept a graph from a user and represent it
with Adjacency List and perform BFS and DFS traversals on it.
 */
/** 
 *                    UNIT 5   
 */

 #include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100

vector<int> adj[MAX];   // adjacency list
int visited[MAX];       // for BFS/DFS
int n;                  // number of vertices

// ---------------------- DFS (Depth First Search) -------------------------
void DFS(int v) {
    cout << v << " ";
    visited[v] = 1;

    for (int u : adj[v]) {   // traverse all neighbors
        if (!visited[u])
            DFS(u);          // recursive DFS
    }
}

// ---------------------- BFS (Breadth First Search) -----------------------
void BFS(int start) {
    queue<int> q;

    visited[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = 1;
                q.push(u);
            }
        }
    }
}

// ------------------------------ MAIN PROGRAM -----------------------------
int main() {
    int edges;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);   // remove for directed graph
    }

    // ---------------- Display Adjacency List ----------------
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        for (int u : adj[i])
            cout << u << " ";
        cout << endl;
    }

    // ---------------- DFS ----------------
    for (int i = 0; i < n; i++) visited[i] = 0;
    int start;
    cout << "\nEnter starting vertex for DFS: ";
    cin >> start;

    cout << "DFS Traversal: ";
    DFS(start);

    // ---------------- BFS ----------------
    for (int i = 0; i < n; i++) visited[i] = 0;
    cout << "\n\nEnter starting vertex for BFS: ";
    cin >> start;

    cout << "BFS Traversal: ";
    BFS(start);

    cout << endl;
    return 0;
}