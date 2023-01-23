#include <algorithm>
#include <assert.h>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int hashFunc(string str, int n = 139) {
    int sum = 0;
    for (char c : str) {
        sum = sum * 26 + c - 'a'; // shuffles better
    }

    return abs(sum % n);
}

int folding_hash(string str, int shuff = 65407) {
    int n = str.size() / 4.0;
    int finIndx = str.size() - 1;

    string substring;
    int currIndx = 0, sum = 0, counter = 0;

    for (size_t i = 0; i < n; i++) {
        while (currIndx != finIndx && counter != 4) {
            substring.push_back(str[currIndx]);
            currIndx++;
            counter++;
        }

        reverse(substring.begin(), substring.end());
        sum += hashFunc(substring) % n;
        substring.clear();
        counter = 0;
    }

    return sum;
}

///////////////////////////////////////////////////////
int hash_string_lower_upper_digits(string str, int n_ = 65407) {
    int base = 2 * 26 + 10; // lower, upper and 10 digits
    long long n = n_;
    long long sum = 0;

    for (int i = 0; i < (int)str.size(); ++i) {
        // lowers from [0-25], upper [26-51] and digits [52-61]
        int value = 0;
        if (islower(str[i]))
            value = str[i] - 'a';
        else if (isupper(str[i]))
            value = 26 + str[i] - 'A';
        else if (isdigit(str[i]))
            value = 26 + 26 + str[i] - '0';
        else
            assert(false);
        sum = sum * base + value; // base 26 number
        sum %= n;                 // reduce to minimize overflows
    }
    return sum;
}

int hash_string_folding(string str, int n_ = 65407) {
    long long n = n_;
    long long sum = 0;
    for (int i = 0; i < (int)str.size(); i += 4) {
        string block = str.substr(i, 4);
        sum += hash_string_lower_upper_digits(block);
        sum %= n;
    }
    return sum;
}
////////////////////////////////////////////////////////

int main() {
    string str = "aabcdefgAxT334gfg";
    cout << folding_hash(str) << endl;
    string str2 = "MartoEPichIKaraMoskvich";
    cout << folding_hash(str2) << endl;

    cout << hash_string_folding(str) << endl;
    cout << hash_string_folding(str2);
    return 0;
}