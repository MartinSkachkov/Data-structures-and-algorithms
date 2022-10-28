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
    LStack();
    LStack(const LStack<T> &other);
    LStack(LStack<T> &&other);
    LStack<T> &operator=(const LStack<T> &other);
    LStack<T> &operator=(LStack<T> &&other);
    ~LStack();

    void push(const T &data);
    T pop();
    T &top();             // getting the last included element + option for changing it
    const T &top() const; // getting the last included element
    bool empty() const;
};

#endif