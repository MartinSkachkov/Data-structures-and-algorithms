#include <iostream>
#include <queue>
#include <string>
using namespace std;

void generateAllBinaries(int n) {
    queue<string> q;
    string start = "1";
    q.push(start);

    while (n) {
        string curr = q.front();
        cout << curr << ' ';
        q.pop();

        q.push(curr + "0");
        q.push(curr + "1");
        n--;
    }
}

int main() {
    generateAllBinaries(16);

    return 0;
}