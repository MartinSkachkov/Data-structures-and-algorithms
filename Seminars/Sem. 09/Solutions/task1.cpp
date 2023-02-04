#include <iostream>
#include <set>
#include <string>
using namespace std;

int getDistinctStrings(const string &str) {
    set<string> s; // here we save the result
    string concat;

    // aaab
    // ij
    for (size_t i = 0; i < str.size(); i++) {
        concat.push_back(str[i]); // concat = "a"
        s.insert(concat);         // "a"
        for (size_t j = i + 1; j < str.size(); j++) {
            concat += str[j]; // aa, aaa, aaab
            s.insert(concat);
        }
        concat.clear(); // remove the current content so that we can proceed with the new ones
    }

    for (string elem : s) {
        cout << elem << '\n';
    }

    return s.size();
}

int main() {
    string input;
    cin >> input;

    cout << getDistinctStrings(input);
    return 0;
}