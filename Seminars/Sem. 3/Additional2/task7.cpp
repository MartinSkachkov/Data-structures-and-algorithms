#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

struct Node {
    int currX, currY, currDist;
};

int row[] = {-1, 0, 0, 1};
int col[] = {0, -1, 1, 0};

bool isValid(const vector<vector<int>> &matrix, const vector<vector<bool>> &visited, int i, int j) {
    return (i >= 0 && i < matrix.size()) && (j >= 0 && j < matrix[0].size()) && matrix[i][j] && !visited[i][j];
}

int findShortestPath(const vector<vector<int>> &matrix, const pair<int, int> &src, const pair<int, int> &dest) {
    // matrix = empty, start = 0, dest = 0
    if (matrix.size() == 0 || matrix[src.first][src.second] == 0 || matrix[dest.first][dest.second] == 0) {
        return -1;
    }

    // creating the visited matrix mxn
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<bool>> visited;
    visited.resize(m, vector<bool>(n));

    queue<Node> q;

    int i = src.first;
    int j = src.second;

    visited[i][j] = true;
    q.push({i, j, 0});

    while (!q.empty()) {
        Node node = q.front();
        q.pop();

        int i = node.currX, j = node.currY, d = node.currDist;
        if (i == dest.first && j == dest.second) {
            return d;
        }

        for (size_t dir = 0; dir < 4; dir++) {
            if (isValid(matrix, visited, i + row[dir], j + col[dir])) {
                visited[i + row[dir]][j + col[dir]] = true;
                q.push({i + row[dir], j + col[dir], d++});
            }
        }
    }

    return -1;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
        {0, 1, 1, 1, 1, 1, 0, 1, 0, 1},
        {0, 0, 1, 0, 1, 1, 1, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 1, 0, 1},
        {0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
        {0, 0, 1, 0, 0, 1, 1, 0, 0, 1},
    };

    pair<int, int> src = make_pair(0, 0);
    pair<int, int> dest = make_pair(7, 5);

    int minDist = findShortestPath(matrix, src, dest);

    if (minDist != -1) {
        cout << "min dist: " << minDist;
    } else {
        cout << "error!";
    }

    return 0;
}