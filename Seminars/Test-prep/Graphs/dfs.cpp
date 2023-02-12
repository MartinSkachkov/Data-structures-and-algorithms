#include <iostream>
using namespace std;
#include <vector>

void DFSrec(vector<vector<pair<int, int>>> &graph, int start, vector<bool> &visited) {
    visited[start] = true; // mark the current vertex as visited

    vector<pair<int, int>> children = graph[start]; // get the curr vertex' children
    cout << start << ' ';                           // print the current one

    // for every children of the current vertex if it is not visited go
    for (auto currChild : children) {
        if (!visited[currChild.first]) {
            DFSrec(graph, currChild.first, visited);
        }
    }
}

void DFS(vector<vector<pair<int, int>>> &graph, int start) {
    vector<bool> visited(graph.size(), 0);
    DFSrec(graph, start, visited);
}

void addEdge(vector<vector<pair<int, int>>> &graph, int from, int to, int w) {
    graph[from].push_back({to, w});
    graph[to].push_back({from, w});
}

int main() {
    vector<vector<pair<int, int>>> graph(5);

    addEdge(graph, 0, 2, 1);
    addEdge(graph, 0, 3, 1);
    addEdge(graph, 0, 1, 1);
    addEdge(graph, 2, 3, 1);
    addEdge(graph, 1, 4, 1);
    addEdge(graph, 3, 4, 1);
    addEdge(graph, 1, 3, 1);

    DFS(graph, 0);
}