#ifndef _CQUEUE_H_
#define _CQUEUE_H_
#define MAX_CAP 3

//!!! WE HAVE ACCESS ONLY TO THE FIRST ELEMENT IN THE QUEUE !!!

template <typename T>
class CQueue {
private:
    int mFront;
    int mBack;
    int mAddedElems;
    T mElements[MAX_CAP];

    int nextIndx(int pos) const;

public:
    // no need for Big 4 since everything is static
    CQueue(); // set the initial values

    void push(const T &elem); // insert in the back position and increment back
    T pop();                  // get the element in position front and increment the front
    T front() const;          // get the front element
    bool empty() const;       // mAddedElems = 0
    bool full() const;        // mAddedElems = MAX_CAP
    int size() const;         // get the number of current elements added to the queue
};

#endif