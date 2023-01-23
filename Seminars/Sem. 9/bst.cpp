#include "Graph-Impl\AdjacencyListGraph\AdjListGraph.h"
#include <iostream>
using namespace std;

int main() {
    AdjListGraph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    bfs(g, 0);

    return 0;
}
