#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    std::cout << v.size(); // 0
    int n = 5;

    v.resize(n);
    std::cout << v.size(); // 5

    for (size_t i = 0; i < n; i++) {
        v[i] = i;
        std::cout << v.at(i) << ' '; //.at() checks if the index is valid and if there is a value at this index
    }

    // std::cout << v.at(8); // error
    std::cout << v.size(); // 5

    v.resize(10); // fills the rest with zeroes -- 0 1 2 3 4 0 0 0 0 0
    for (size_t i = 0; i < 10; i++) {
        std::cout << v.at(i) << ' ';
    }
    std::cout << v.size(); // 10

    v.push_back(15);
    std::cout << v.size(); // 11

    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v.at(i) << ' '; // 0 1 2 3 4 0 0 0 0 0 15
    }

    return 0;
}