#include <iostream>
#include <queue>
using namespace std;

void bfs(int graph[][10], int vertices, int start) {
    bool visited[10] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int vertices, edges;
    int graph[10][10] = {0};

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

    cout << "BFS Traversal: ";
    bfs(graph, vertices, start);

    return 0;
}