#include <iostream>
#include <stack>
#include <string>
using namespace std;

int num_div(int num) {
    int len = 0;

    while (num != 0) {
        num /= 10;
        len++;
    }

    int res = 1;
    while (len != 0) {
        res *= 10;
        len--;
    }

    return res / 10;
}

int reverse_num(int num) {
    stack<int> s;
    int div = num_div(num);

    // 1234
    while (num != 0) {
        s.push(num / div);
        num %= div;
        div /= 10;
    }

    while (!s.empty()) {
        num += s.top();
        s.pop();
        num *= 10;
    }

    return num / 10;
}

int main() {
    int num;
    cout << "num: ";
    cin >> num;

    cout << "reversed num: " << reverse_num(num);

    return 0;
}