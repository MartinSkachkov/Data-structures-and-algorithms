#include <iostream>
#include <map>
#include <string>
using namespace std;

int minUniqueSubstrings(const string &str) {
    map<char, int> mp;
    size_t counter = 1;

    // abacaba
    // mp['a'] = 0 -> mp['a'] = 1
    // mp['b'] = 0 -> mp['b'] = 1
    // mp['a'] -> counter++; clear map
    for (char c : str) {
        if (mp[c] > 0) {
            counter++;
            mp.clear();
        }
        mp[c]++;
    }
    return counter;
}

int main() {
    string input;
    cin >> input;

    cout << minUniqueSubstrings(input);

    return 0;
}