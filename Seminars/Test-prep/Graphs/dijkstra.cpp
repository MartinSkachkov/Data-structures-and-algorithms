/*
Алгоритъм на Дийкстра за най-къс път в граф от даден връх до всички останали.
Приложим е върху:
* ориентиран граф без отрицателен цикъл
* неориентиран граф без отрицателни ребра
Сложност: O(M log(N))
Визуализация: https://www.cs.usfca.edu/~galles/visualization/Dijkstra.html
*/

#include <iostream>
#include <queue>
#include <vector>

#define INF 999999
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int start) {
    priority_queue<pair<int, int>> q;
    vector<int> dist(graph.size(), INF);

    dist[start] = 0;
    q.push({start, 0});

    while (!q.empty()) {
        int currV = q.top().first;
        q.pop();

        for (size_t i = 0; i < graph[currV].size(); i++) {
            int currNeighbour = graph[currV][i].first;
            int currWeight = graph[currV][i].second;

            if (dist[currNeighbour] > dist[currV] + currWeight) {
                dist[currNeighbour] = dist[currV] + currWeight;
                q.push({dist[currV], currV});
            }
        }
    }
    return dist;
}

void print(const vector<int> &d) {
    for (int i = 1; i < d.size(); i++)
        cout << i << ": " << (d[i] != INF ? d[i] : -1) << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);

    int v, u, w;
    for (int i = 0; i < m; i++) {
        cin >> v >> u >> w;
        graph[v].push_back(make_pair(u, w));
        graph[u].push_back(make_pair(v, w));
    }

    cin >> v;
    vector<int> d = dijkstra(graph, v);
    print(d);

    return 0;
}