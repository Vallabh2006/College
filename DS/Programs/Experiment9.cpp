#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
public:
    Graph(int v) : V(v), adj(v) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfsUtil(int u, vector<bool>& visited) {
        visited[u] = true;
        cout << u << " ";
        for (int v : adj[u])
            if (!visited[v]) dfsUtil(v, visited);
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS: ";
        dfsUtil(start, visited);
        cout << endl;
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        cout << "BFS: ";
        while (!q.empty()) {
            int u = q.front(); q.pop();
            cout << u << " ";
            for (int v : adj[u])
                if (!visited[v]) { visited[v] = true; q.push(v); }
        }
        cout << endl;
    }
};

int main() {
    int V, E, u, v, start;
    cout << "Number of vertices (0 to V-1): ";
    cin >> V;
    Graph g(V);
    cout << "Number of edges: ";
    cin >> E;
    cout << "Enter each edge as 'u v':\n";
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        if (u < 0 || v < 0 || u >= V || v >= V) { cout << "Invalid edge, skipped.\n"; continue; }
        g.addEdge(u, v);
    }
    cout << "Starting vertex: ";
    cin >> start;
    g.DFS(start);
    g.BFS(start);
    return 0;
}
