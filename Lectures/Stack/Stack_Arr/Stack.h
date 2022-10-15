#ifndef _STACK_H_
#define _STACK_H_
#include <stdlib.h>

template <typename T>
class Stack {
private:
    T *mS;     // stack of values of type T
    int mTop;  // index
    int mSize; // capacity of the stack

    void copyStack(const T *other);   // here we will do the copy of the array
    void copy(const Stack<T> &other); // copy the remaining stuff
    void resize();
    void free();

public:
    Stack(int size);
    Stack(const Stack<T> &other);
    Stack<T> &operator=(const Stack<T> &other);
    ~Stack();

    void push(const T &elem);
    T pop();
    T top() const;
    bool full() const;
    bool empty() const;
    int size() const;
};

#endif