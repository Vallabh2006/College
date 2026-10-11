#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;

void dfs(int u, vector<bool>& vis) {
    vis[u] = true;
    cout << u << " ";
    for (int v : adj[u])
        if (!vis[v]) dfs(v, vis);
}

void bfs(int start, int V) {
    vector<bool> vis(V, false);
    queue<int> q;
    vis[start] = true;
    q.push(start);
    cout << "BFS: ";
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int v : adj[u])
            if (!vis[v]) { vis[v] = true; q.push(v); }
    }
    cout << endl;
}

int main() {
    int V, E, u, v, start;
    cout << "Vertices and Edges: ";
    cin >> V >> E;
    adj.resize(V);

    cout << "Enter edges (u v):\n";
    while (E--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Start vertex: ";
    cin >> start;

    vector<bool> vis(V, false);
    cout << "DFS: ";
    dfs(start, vis);
    cout << endl;

    bfs(start, V);
    return 0;
}
