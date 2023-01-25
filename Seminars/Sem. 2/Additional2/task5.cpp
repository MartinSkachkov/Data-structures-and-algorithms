#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isLetter(char c) {
    return c >= 'a' && c <= 'z';
}

string simplifyPath(const string &path) {
    stack<string> newPath;
    string dir;
    string loc;

    for (size_t i = 0; i < path.size(); i++) {
        // skip the / & .. .
        if (path[i] == '/' || path[i] == '.') {
            continue;
        } else { // we found a directory
            while (i < path.size() && isLetter(path[i])) {
                dir.push_back(path[i]);
                i++;
            }
            i--;
            newPath.push(dir);
            dir.clear();
        }
    }

    stack<string> revNewPath;

    while (!newPath.empty()) {
        revNewPath.push(newPath.top());
        newPath.pop();
    }

    if (!revNewPath.empty()) {
        while (!revNewPath.empty()) {
            loc += '/' + revNewPath.top();
            revNewPath.pop();
        }
    } else {
        loc += '/';
    }

    return loc;
}

int main() {
    string input1 = "/home/";
    string input2 = "/../";
    string input3 = "/home//foo/";
    string input4 = "/a/./b/../../c/";
    string input5 = "/a//b////c/d//././/..";

    cout << simplifyPath(input1) << '\n';
    cout << simplifyPath(input2) << '\n';
    cout << simplifyPath(input3) << '\n';
    cout << simplifyPath(input4) << '\n';
    cout << simplifyPath(input5) << '\n';

    return 0;
}
