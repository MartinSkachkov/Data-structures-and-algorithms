#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

set<string> getDistinctStrings(const string &str) {
    set<string> s;
    string concat;

    for (size_t i = 0; i < str.size(); i++) {
        concat.push_back(str[i]);
        s.insert(concat);
        for (size_t j = i + 1; j < str.size(); j++) {
            concat += str[j];
            sort(concat.begin(), concat.end());
            s.insert(concat);
        }
        concat.clear();
    }

    return s;
}

int main() {
    string input;
    cin >> input;

    set<string> res = getDistinctStrings(input);

    cout << res.size() << '\n';
    for (string s : res) {
        cout << s << ", ";
    }

    return 0;
}