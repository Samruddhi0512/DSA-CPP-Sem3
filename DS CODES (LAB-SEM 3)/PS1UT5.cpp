/** Write a Program to accept a graph from a user and represent it
with Adjacency Matrix and perform BFS and DFS traversals on it. */
/** 
 *                    UNIT 5   
 */

 #include <iostream>
#include <queue>
using namespace std;

#define MAX 20   // maximum number of vertices

// ---------------------- GLOBAL VARIABLES ------------------------
int adj[MAX][MAX];   // adjacency matrix
int visited[MAX];    // for DFS and BFS
int n;               // number of vertices

// ---------------------- DFS (Depth First Search) ----------------
void DFS(int v) {
    cout << v << " ";
    visited[v] = 1;

    // check all vertices
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i); // recursive call
        }
    }
}

// ---------------------- BFS (Breadth First Search) --------------
void BFS(int start) {
    queue<int> q;

    visited[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

// ---------------------- MAIN PROGRAM ---------------------------
int main() {
    int edges, src, dest;
    
    cout << "Enter number of vertices: ";
    cin >> n;

    // Initialize adjacency matrix with 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (source destination):\n";
    for (int i = 0; i < edges; i++) {
        cin >> src >> dest;
        adj[src][dest] = 1;
        adj[dest][src] = 1;  // remove this line for a directed graph
    }

    // Display adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }

    // DFS Traversal
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int start;
    cout << "\nEnter starting vertex for DFS: ";
    cin >> start;

    cout << "DFS Traversal: ";
    DFS(start);
    cout << endl;

    // BFS Traversal
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    cout << "\nEnter starting vertex for BFS: ";
    cin >> start;

    cout << "BFS Traversal: ";
    BFS(start);
    cout << endl;

    return 0;
}