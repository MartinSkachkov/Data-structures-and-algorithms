#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

vector<int> asteroidCollision(const vector<int> &asteroids) {
    stack<int> s;
    vector<int> res;
    s.push(asteroids.front());

    for (size_t i = 1; i < asteroids.size(); i++) {
        // collision case
        if (s.top() > 0 && asteroids[i] < 0) {
            if (abs(asteroids[i]) < s.top()) {
                continue;
            } else if (abs(asteroids[i]) > s.top()) {
                while (abs(asteroids[i]) > s.top()) {
                    s.pop();
                }
                continue;
            } else { // equal values
                s.pop();
                continue;
            }
        }
        s.push(asteroids[i]);
    }

    while (!s.empty()) {
        res.push_back(s.top());
        s.pop();
    }

    reverse(res.begin(), res.end());

    return res;
}

int main() {
    vector<int> asteroids;
    int n, asteroid;

    cout << "num of asteroids: ";
    cin >> n;

    for (size_t i = 0; i < n; i++) {
        cin >> asteroid;
        asteroids.push_back(asteroid);
    }

    asteroids = asteroidCollision(asteroids);

    for (int a : asteroids) {
        cout << a << ' ';
    }

    return 0;
}