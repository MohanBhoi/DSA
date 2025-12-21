#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjList;

public:
    // Constructor
    Graph(int v) {
        vertices = v;
        adjList.resize(v);
    }

    // Add edge (undirected)
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Display graph
    void display() {
        for (int i = 0; i < vertices; i++) {
            cout << i << " -> ";
            for (int node : adjList[i]) {
                cout << node << " ";
            }
            cout << endl;
        }
    }

    // DFS helper
    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int neighbor : adjList[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    // DFS
    void DFS(int start) {
        vector<bool> visited(vertices, false);
        cout << "DFS: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    // BFS
    void BFS(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS: ";

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int neighbor : adjList[v]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Graph representation:\n";
    g.display();

    g.DFS(0);
    g.BFS(0);

    return 0;
}
