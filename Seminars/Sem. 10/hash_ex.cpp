#include <iostream>
#include <string>
using namespace std;
// hash function converts an input (number, string, object) to random value
// we will always have collisions -> solution to this will be a better hash function
// abs reduces the overflow to + number
// % operator is still our friend to reduce values to a range
// using a prime number with % ⇒ may generate better distribution of values according to number theory, but still collisions occurs

int hash_num(int val, int n = 139) {
    return abs(val % n); // random value based on the input
}

int hash_string(string str, int n = 139) {
    int sum = 0;
    for (char c : str) {
        sum += c - 'a';
    }
    return abs(sum % n); // random value based on the input
}

int better_hash_string(string str, int n = 139) {
    int sum = 0;
    for (char c : str) {
        sum = sum * 26 + c - 'a'; // shuffles better
    }
    return abs(sum % n); // random value based on the input
}

int main() {
    cout << hash_num(5) << endl;               // 5
    cout << hash_num(999999999999999) << endl; // overflows bust since we have abs the result will always be + (39) (other sol will be to use bigger data types)
    cout << hash_num(526) << endl;             // 109

    cout << hash_string("abc", 7) << endl;    // 3
    cout << hash_string("abcde", 7) << endl;  // 3
    cout << hash_string("abcde", 11) << endl; // 10

    // as we can se we have a collision so we need to think for a better hash func for the string
    cout << better_hash_string("abc", 7) << endl;    // 0
    cout << better_hash_string("abcde", 7) << endl;  // 5
    cout << better_hash_string("abcde", 11) << endl; // 2

    return 0;
}