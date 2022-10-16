#ifndef _STRANGE_STACK_H_
#define _STRANGE_STACK_H_

template <typename T>
class StrangeStack {
private:
    T *stack;
    int capacity;
    int top;
    int size; // curr num of elements in the stack

    void free();
    void copy(const StrangeStack<T> &other);
    void copyStack(const T *stack);
    void resize();

public:
    StrangeStack(int capacity);
    StrangeStack(const StrangeStack<T> &other);
    StrangeStack<T> &operator=(const StrangeStack<T> &other);
    ~StrangeStack();

    // design choices - return if the operations were successfully executed
    int addedElements() const; // number of added elements so far (getter for the size)
    bool push(const T &elem);
    bool pop();
    bool peek() const;

    bool full() const;
    bool empty() const;

    int getTop() const;
};

#endif