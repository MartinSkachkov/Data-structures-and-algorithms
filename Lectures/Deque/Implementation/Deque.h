#ifndef _DEQUE_H_
#define _DEQUE_H_
#define MAX_SIZE 5

template <typename T>
class Deque {
private:
    T mElements[MAX_SIZE];
    int mFront;
    int mRear;
    int mAddedElems;

private:
    Deque();

    void push_front(const T &element);
    void push_rear(const T &element);
    T pop_front();
    T pop_rear();
    T rear();
    T front() const;
    bool empty() const;
    bool full() const;
};

#endif