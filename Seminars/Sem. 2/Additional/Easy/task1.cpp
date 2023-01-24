#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverse_word(const string &word) {
    stack<char> s;

    for (char c : word) {
        s.push(c); // the word in the stack will be in reversed order
    }

    string reversed;
    while (!s.empty()) {
        reversed.push_back(s.top());
        s.pop();
    }

    return reversed;
}

string reverse_subwords(const string &str) {
    string currWord;
    string revWord;

    // "abc d efg xy"
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == ' ') { // if we hit white space we reverse the word
            revWord += reverse_word(currWord) + ' ';
            currWord.clear();
        } else if (i == str.size() - 1) { // don't add white space at the end of the last word
            currWord += str[i];           // add the last char before reversing
            revWord += reverse_word(currWord);
            currWord.clear();
        } else { // needed for the white spaces
            currWord += str[i];
        }
    }

    return revWord;
}

int main() {
    string str;
    cout << "string: ";
    getline(cin, str);

    cout << "reversed: " << reverse_subwords(str);

    return 0;
}