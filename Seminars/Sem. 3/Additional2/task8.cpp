#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

void initQueue(queue<int> &fighters, const vector<int> &f) {
    for (size_t i = 0; i < f.size(); i++) {
        fighters.push(f[i]);
    }
}

// f = -1, -2, 4, 5, 6, -3, -6, -7, -8, 2, 3
vector<int> bridgeFight(const vector<int> &f) {
    stack<int> leftFighters;
    queue<int> fighters;
    vector<int> alive;

    initQueue(fighters, f);

    // -6, -7, -8, 2, 3
    while (!fighters.empty()) {
        // collision case
        if (!leftFighters.empty() && leftFighters.top() > 0 && fighters.front() < 0) {
            if (leftFighters.top() > abs(fighters.front())) {
                fighters.pop();
            } else if (leftFighters.top() < abs(fighters.front())) {
                leftFighters.pop();
            } else {
                leftFighters.pop();
                fighters.pop();
            }
        } else {
            leftFighters.push(fighters.front()); //  4, 5, 6
            fighters.pop();
        }
    }

    vector<int> toRev;
    while (!leftFighters.empty()) {
        toRev.push_back(leftFighters.top());
        leftFighters.pop();
    }

    reverse(toRev.begin(), toRev.end());
    alive.insert(alive.end(), toRev.begin(), toRev.end());
    return alive;
}

int main() {
    vector<int> fighters = {-1, -2, 4, 5, 6, -3, -6, -7, -8, 2, 3};
    vector<int> alive = bridgeFight(fighters);

    if (alive.empty()) {
        cout << '\n';
    } else {
        for (int fighter : alive) {
            cout << fighter << ' ';
        }
    }

    return 0;
}