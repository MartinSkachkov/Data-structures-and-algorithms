#ifndef _STATIC_STACK_H
#define _STATIC_STACK_H
#define MAX_CAPACITY 1024

// no need for Big 4 as there is no dynamic mem

template <typename T>
class StaticStack {
private:
    T mData[MAX_CAPACITY]; // static array
    int mTopIndx;          // last element

public:
    StaticStack(); // set the topIndx to -1

    bool empty() const;
    bool full() const;
    void push(const T &elem);
    T pop();
    T top() const;
};

#endif