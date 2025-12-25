/** Write a Program to implement Dijkstra’s algorithm to find 
shortest distance between two nodes of a user defined graph.
 Use Adjacency Matrix to represent a graph. */


 #include <iostream>
using namespace std;

#define INF 999999

int findMinDist(int dist[], bool visited[], int n) {
    int minVal = INF, minIndex = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < minVal) {
            minVal = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int graph[20][20], int n, int start) {
    int dist[20];
    bool visited[20];

    // Initialize all distances
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[start] = 0;   // distance to itself is 0

    // Main Dijkstra Loop
    for (int count = 0; count < n - 1; count++) {

        int u = findMinDist(dist, visited, n);
        visited[u] = true;

        // Relaxation step
        for (int v = 0; v < n; v++) {

            if (!visited[v] && graph[u][v] != 0 &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print Final Distances
    cout << "\nShortest distances from node " << start << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "To " << i << " = " << dist[i] << endl;
    }
}

int main() {
    int n;
    int graph[20][20];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix (0 = no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    dijkstra(graph, n, start);

    return 0;
}