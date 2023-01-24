#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

vector<int> dailyTemperatures(const vector<int> &temperatures) {
    stack<int> s;
    int counter = 0;
    vector<int> daysToWait;

    for (size_t currT = 0; currT < temperatures.size(); currT++) {
        for (size_t i = temperatures.size() - 1; i != currT; i--) {
            s.push(temperatures[i]);
        }

        bool flag = 0;
        while (!s.empty()) {
            counter++;
            if (s.top() > temperatures[currT]) {
                daysToWait.push_back(counter);
                flag = 1;
                break;
            }
            s.pop();
        }

        if (!flag) {
            daysToWait.push_back(0);
        }

        counter = 0;
        // remove the left shit
        while (!s.empty()) {
            s.pop();
        }
    }

    return daysToWait;
}

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    for (int day : dailyTemperatures(temperatures)) {
        cout << day << ' ';
    }

    return 0;
}