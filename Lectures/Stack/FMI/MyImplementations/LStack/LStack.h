#ifndef _LINKED_STACK_H_
#define _LINKED_STACK_H_

// struct for a single node |DATA|PTR|
template <typename T>
struct StackElement {
    T data;
    StackElement<T> *next;
};

template <typename T>
class LStack {
private:
    StackElement<T> *mTopPtr; // pointer to the top of the stack

    void free();
    void copyStack(const LStack<T> &other);

public:
};