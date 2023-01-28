#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <list>
using namespace std;

template <class T>
void insertSorted(std::list<T> &ll, const T &elem) {
    auto iter = ll.begin();
    while (iter != ll.end()) {
        if (*iter > elem) {
            ll.insert(iter, elem);
            break;
        }
        iter++;
    }
    if (iter == ll.end()) {
        ll.push_back(elem);
    }
}

int main() {
    list<int> ll;
    srand(time(0));

    for (size_t i = 0; i < 5555; i++) {
        insertSorted(ll, rand());
    }

    for (int x : ll) {
        cout << x;
    }
    std::cout << is_sorted(ll.begin(), ll.end());
    return 0;
}