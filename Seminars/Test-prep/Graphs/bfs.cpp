#include <iostream>
using namespace std;
#include <queue>
#include <vector>

void BFS(const vector<vector<int>> &graph, int start) {
    vector<bool> visited(graph.size(), 0); // here we will check which vertex is visited

    queue<int> q; // here we will save the traversed vertices
    q.push(start);

    while (!q.empty()) {
        int currV = q.front();
        q.pop();

        // check if the current vertex is already visited
        if (visited[currV]) {
            continue; // skip it
        }

        // if it is not visited
        visited[currV] = true; // mark it as visited
        cout << currV;         // print it

        // get it's successors
        vector<int> successors;
        for (size_t i = 0; i < graph.size(); i++) {
            if (graph[currV][i] > 0) {
                successors.push_back(i);
            }
        }

        // add the successors to the queue
        for (int v : successors) {
            if (!visited[v]) {
                q.push(v);
            }
        }
    }
}

void addEdge(vector<vector<int>> &graph, int from, int to) {
    graph[from][to] = 1;
    graph[to][from] = 1;
}

int main() {
    vector<vector<int>> graph(5, vector<int>(5, 0));

    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 0, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 1, 3);

    BFS(graph, 2);
}