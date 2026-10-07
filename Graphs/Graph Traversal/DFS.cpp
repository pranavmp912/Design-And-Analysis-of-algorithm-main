#include <iostream>
using namespace std;

void dfs(int graph[][10], bool visited[], int vertices, int current) {
    visited[current] = true;
    cout << current << " ";

    for (int i = 0; i < vertices; i++) {
        if (graph[current][i] == 1 && !visited[i]) {
            dfs(graph, visited, vertices, i);
        }
    }
}

int main() {
    int vertices, edges;
    int graph[10][10] = {0};
    bool visited[10] = {false};

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges:\n";

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;

    cout << "DFS Traversal: ";
    dfs(graph, visited, vertices, start);

    return 0;
}