#include <iostream>
#include <stack>

// 1234
// num = num + (s.top() * 1)
// num = num + (s.top() * 10)
// num = num + (s.top() * 100)
//...

unsigned int reverseDigits(unsigned int num) {
    std::stack<unsigned int> s;
    unsigned int lastDigit = 0;

    while (num != 0) {
        lastDigit = num % 10;
        s.push(lastDigit);
        num /= 10;
    }

    unsigned int tens = 1; //!!!
    while (!s.empty()) {
        num += s.top() * tens;
        tens *= 10;
        s.pop();
    }
    return num;
}

int main() {
    unsigned int num;
    std::cin >> num;
    std::cout << reverseDigits(num);

    return 0;
}