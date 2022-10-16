#ifndef _STACK_H_
#define _STAACK_H_
#define MAX_SIZE 10

// we don't have dynamic memory so there is no need for Big 4
template <typename T>
class Stack {
private:
    T mS[MAX_SIZE];
    int mTop;
    int mCapacity;

public:
    Stack();

    void push(const T &elem);
    T pop();
    T top() const;
    bool empty() const;
    bool full() const;
    int capacty() const;
};

#endif