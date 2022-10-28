#ifndef _RESIZABLE_STACK_H
#define _RESIZABLE_STACK_H
#define DEFAULT_CAPACITY 10

// since we have dynamic memory we will need to write Big 4

template <typename T>
class RStack {
private:
    T *mData; // array - dynamically allocated
    int mTopIndex;
    int mCapacity;

    void free();                            // deleting the dynamic memory
    void copyStack(const RStack<T> &other); // copies the remaining stuff
    void copyData(const T *other);          // copies the elements of the array
    void resize();                          // resizing the capacity

public:
    RStack();
    RStack(const RStack<T> &other);
    RStack(RStack<T> &&other);
    RStack<T> &operator=(const RStack<T> &other);
    RStack<T> &operator=(RStack<T> &&other);
    ~RStack();

    bool empty() const;
    bool full() const;
    void push(const T &elem);
    T pop();
    T top() const;

    int getCapacity() const { return mCapacity; } // needed for the test
};

#endif