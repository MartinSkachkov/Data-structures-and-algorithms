#include <algorithm>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

vector<pair<int, int>> compressIntervals(const vector<pair<int, int>> &intervals) {
    stack<pair<int, int>> working;
    stack<pair<int, int>> res;

    for (size_t i = 0; i < intervals.size(); i++) {
        working.push(intervals[i]);
    }

    pair<int, int> fst = working.top();
    working.pop();
    pair<int, int> snd = working.top();
    working.pop();
    if (fst.first <= snd.second) {
        res.push({snd.first, fst.second});
    } else {
        res.push(fst);
        res.push(snd);
    }

    while (!working.empty()) {
        fst = res.top();
        res.pop();
        snd = working.top();
        working.pop();
        if (fst.first <= snd.second) {
            res.push({snd.first, fst.second});
        } else {
            res.push(fst);
            res.push(snd);
        }
    }

    vector<pair<int, int>> compressed;
    while (!res.empty()) {
        compressed.push_back(res.top());
        res.pop();
    }

    return compressed;
}

int main() {
    vector<pair<int, int>> intervals;
    int n;
    cout << "intervals count: ";
    cin >> n;

    int start, end;
    for (size_t i = 0; i < n; i++) {
        cout << "start: ";
        cin >> start;
        cout << "end: ";
        cin >> end;

        intervals.push_back({start, end});
    }

    cout << "compressed:\n";
    if (n < 2) {
        for (pair<int, int> i : intervals) {
            cout << '{' << i.first << ',' << i.second << '}' << '\n';
        }
    } else {
        for (pair<int, int> i : compressIntervals(intervals)) {
            cout << '{' << i.first << ',' << i.second << '}' << '\n';
        }
    }

    return 0;
}