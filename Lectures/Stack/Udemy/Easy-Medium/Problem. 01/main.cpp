#include "StrangeStack.inl"
#include <iostream>
using namespace std;

int main() {
    StrangeStack<int> s(3);
    cout << s.empty() << endl;
    cout << s.getTop() << endl;
    cout << s.push(1) << endl;
    cout << s.getTop() << endl;
    cout << s.push(2) << endl;
    cout << s.getTop() << endl;
    cout << s.push(3) << endl;
    cout << s.push(4) << endl;
    cout << s.getTop() << endl;
    cout << s.push(4) << endl;
}