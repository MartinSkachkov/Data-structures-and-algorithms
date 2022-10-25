#include <iostream>
#include <queue>
#include <string>

void generateBinaries2(unsigned int n) {
    std::queue<std::string> q;
    q.push("1");

    for (size_t i = 0; i < n; i++) {
        q.push(q.front() + "0");
        q.push(q.front() + "1");

        std::cout << q.front() << ' ';
        q.pop();
    }
}

void generateBinaries(unsigned int n) {
    std::queue<std::string> q;
    q.push("1");

    while (n) {
        std::string currNum = q.front();
        q.pop();
        std::cout << currNum << ' ';

        q.push(currNum + "0");
        q.push(currNum + "1");

        n--;
    }
}

int main() {
    unsigned n;
    std::cout << "n: ";
    std::cin >> n;
    generateBinaries(n);
    std::cout << std::endl;
    generateBinaries2(n);
}