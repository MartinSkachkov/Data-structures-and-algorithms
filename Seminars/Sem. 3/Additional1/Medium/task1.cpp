#include <iostream>
#include <queue>
using namespace std;

void sumOfLastKNums(int stream, int k) {
    queue<int> q;

    int sum = 0;
    for (size_t i = 1; i <= stream; i++) {
        q.push(i);
        sum += i;

        if (q.size() > k) {
            sum -= q.front(); // 5 = (1)+2+3+4+5(-1)
            q.pop();
        }

        cout << sum << ' ';
    }
}

int main() {
    sumOfLastKNums(6, 4);

    return 0;
}