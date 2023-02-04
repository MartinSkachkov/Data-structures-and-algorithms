#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

set<string> getDistinctStrings(const string &str) {
    set<string> s; // here we save the unique elems
    string concat; // generating the substrings

    for (size_t i = 0; i < str.size(); i++) {
        concat.push_back(str[i]);
        s.insert(concat);
        for (size_t j = i + 1; j < str.size(); j++) {
            concat += str[j];
            s.insert(concat);
        }
        concat.clear();
    }

    return s; // return by copy so everything is ok
}

set<string> commonSubstrings(const string &str1, const string &str2) {
    set<string> dist1 = getDistinctStrings(str1);
    set<string> dist2 = getDistinctStrings(str2);

    set<string> intersect;
    set_intersection(dist1.begin(), dist1.end(), dist2.begin(), dist2.end(),
                     std::inserter(intersect, intersect.begin()));
    return intersect;
}

int main() {
    string input1, input2;
    cin >> input1 >> input2;

    set<string> res = commonSubstrings(input1, input2);
    cout << res.size() << '\n';
    for (string s : res) {
        cout << s << '\n';
    }

    return 0;
}