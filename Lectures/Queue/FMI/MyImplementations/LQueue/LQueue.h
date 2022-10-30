#ifndef _LQueue_H_
#define _LQueue_H_

template <typename T>
struct QueueElement {
    T mData;
    QueueElement<T> *mNext;
};

template <typename T>
class LQueue {
private:
    QueueElement<T> *mHead;
    QueueElement<T> *mTail;
    unsigned mSize;

    void copyQueue(const LQueue<T> &other);
    void free();

public:
    LQueue();
    LQueue(const LQueue<T> &other);
    LQueue(LQueue<T> &&other);
    LQueue<T> &operator=(const LQueue<T> &other);
    LQueue<T> &operator=(LQueue<T> &&other);
    ~LQueue();

    void push(const T &element);
    void pop();
    bool empty() const;
    const T &front() const;
    T &front();
    unsigned size() const;
};

#endif