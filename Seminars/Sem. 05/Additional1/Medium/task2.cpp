#include <iostream>
#include <list>
using namespace std;

void swapKNodes(list<int> &ll, int k) {
    int kCopy = k;
    list<int>::iterator first = ll.begin();
    list<int>::iterator second = ll.end();

    while (first != ll.end() && k != 1) {
        first++;
        k--;
    }

    while (second != ll.begin() && k != 0) {
        second--;
        k--;
    }
    second--; // needs one more time to decrement because initially second was pointing to nullptr
}