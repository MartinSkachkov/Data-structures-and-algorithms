#include <iostream>
#include <queue>
using namespace std;

void circularGame(int n, int k) {
    queue<int> people;

    for (size_t i = 1; i <= n; i++) {
        people.push(i);
    }

    while (people.size() != 1) {
        for (size_t i = 1; i < k; i++) {
            int curr = people.front();
            people.pop();
            people.push(curr);
        }
        people.pop();
    }

    cout << "winner: " << people.front();
}

int main() {
    circularGame(5, 2);

    return 0;
}