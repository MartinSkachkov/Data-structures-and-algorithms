#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void reverseStack(stack<int> &s, stack<int> &tmp) {
    while (!s.empty()) {
        tmp.push(s.top());
        s.pop();
    }
}

// 3 6 2 7 5
int countDays(const vector<int> &flowers) {
    stack<int> rev;
    stack<int> tmp;
    int days = 0;

    for (size_t i = 0; i < flowers.size(); i++) {
        rev.push(flowers[i]); // reversed order
    }
    reverseStack(rev, tmp);

    int fst = tmp.top(); // 3
    tmp.pop();
    while (!tmp.empty()) {
        int snd = tmp.top(); // 6
        tmp.pop();

        if (fst < snd) {
            rev.push(fst); // 3
            fst = tmp.top();
            tmp.pop();
            days++;
        } else {
            rev.push(fst);
            rev.push(snd);
            fst = snd;
        }
    }

    return days;
}

int main() {
    vector<int> flowers;
    int n;
    cout << "flowers: ";
    cin >> n;

    if (n < 2) {
        throw "Small size!";
    }

    for (size_t i = 0; i < n; i++) {
        int curr;
        cin >> curr;
        flowers.push_back(curr);
    }
    cout << countDays(flowers);
    return 0;
}