#ifndef _CQUEUE_H_
#define _CQUEUE_H_
#define MAX_CAP 3

template <typename T>
class CQueue {
private:
    T elements[MAX_CAP];
    int frontE;
    int back;
    int size;

public:
    CQueue();

    void push(const T &element);
    void pop();
    bool empty() const;
    bool full() const;
    T front() const;
};

template <typename T>
CQueue<T>::CQueue() : frontE(0), back(0), size(0) {}

template <typename T>
void CQueue<T>::push(const T &element) {
    if (full()) {
        throw("The queue is full!");
    }
    elements[back] = element;
    size++;
    back++;
    back = back % MAX_CAP;
}

template <typename T>
void CQueue<T>::pop() {
    if (empty()) {
        throw("Can not delete element from an empty queue");
    }
    size--;
    frontE++;
    frontE = frontE % MAX_CAP;
}

template <typename T>
bool CQueue<T>::empty() const {
    return size == 0;
}

template <typename T>
bool CQueue<T>::full() const {
    return size == MAX_CAP;
}

template <typename T>
T CQueue<T>::front() const {
    if (empty()) {
        throw("Can not get elem from an empty queue");
    }
    return elements[frontE];
}

#endif