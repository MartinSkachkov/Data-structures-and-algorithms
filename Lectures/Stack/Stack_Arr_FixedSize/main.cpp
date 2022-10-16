#include "Stack.inl"
#include <iostream>
using namespace std;

int main() {
    Stack<int> s;
    cout << boolalpha << s.empty() << '\n';
    s.pop();

    cout << s.top() << '\n';
    s.push(1);
    cout << s.top() << '\n';
    s.push(2);
    cout << s.top() << '\n';
    s.push(3);
    cout << s.top() << '\n';
    cout << s.capacty() << '\n';
    s.push(4);
    cout << s.top() << '\n';
    cout << s.capacty() << '\n';
    cout << boolalpha << s.full() << '\n';
    s.pop();
    cout << boolalpha << s.full() << '\n';
    cout << s.top() << '\n';
}