#include <iostream>
using namespace std;

//във функцията не боравим със самите променливи от main а с техни копия и така те няма да променят аналозите им в main
void redirectC(int *ptr, int dest) { // pass-by-value ( we create a copy(new variable 'ptr,'dest') of the passed variables and assign the values to the 'ptr' and 'dest')
    ptr = &dest;                     // Във функцията redirect на ptr се прави копие. После това копие започва да сочи към dest
    //'dest' has a temp address as it is statically allocated and after the end of the function it will be deleted
}

//тук боравим със самите променливи от main
void redirectR(int *&ptr, int &dest) { // pass-by-ref
    ptr = &dest;
}

void redirectP(int **ptr, int &dest) {
    *ptr = &dest;
}

int main() {
    int a = 10; // creates a memory block of type int, links the name 'a' with the mem. block and initializes the memory with a value '10'
    int b = 12;
    int *ptr = &a; // we get the address of a(position in memory)

    redirectC(ptr, b);
    cout << *ptr; // prints 10

    redirectR(ptr, b);
    cout << *ptr; // prints 12

    redirectP(&ptr, a);
    cout << *ptr; // prints 10

    return 0;
}