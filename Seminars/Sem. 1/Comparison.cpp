#include <iostream>
using namespace std;

size_t sumPowerOfTwo(size_t n) {
    size_t res = 0; // O(1)

    for (size_t i = 0; i <= n; i++) { // we execute 'n' times an O(1) operation
        res += (1 << i);              // O(1), the operation is 1 * 2^i
    }
    // as a result the for will give us n*O(1)

    return res; // O(1)
} // T = O(1) + n*O(1) + O(1) = c1 + c2*n + c3 = c2*n = n = O(n)

size_t optimised(size_t n) {
    return (1 << (n + 1)) - 1; // O(1)
} // T = O(1);

int main() {
    cout << "Regular: " << sumPowerOfTwo(5) << '\n';
    cout << "Optimised: " << optimised(5) << '\n';
    return 0;
}