#ifndef _SLL_H_
#define _SLL_H_

template <typename T>
struct LinkedListElement {
    T mData;
    LinkedListElement<T> *mNext;
};

// итераторът трябва да знае за съществуването на LinkedList
template <typename T>
class LinkedList;

template <typename T>
class LinkedListIterator {
private:
    using LLE = LinkedListElement<T>;
    using I = LinkedListIterator<T>;
    LLE *mPtr;

    friend LinkedList<T>; // искаме LinkedList да има достъп до private член данните на итератора

public:
    LinkedListIterator(LLE *pos = nullptr);
    I next() const;
    bool valid() const;
    const T &getData() const;
    T &getData();
    operator bool() const;
    I &operator++();   // ++it
    I operator++(int); // it++
    T &operator*();    //*it
    bool operator==(const I &other) const;
    bool operator!=(const I &other) const;
    I &operator+=(unsigned n);
};

template <typename T>
class LinkedList {
private:
    using LLE = LinkedListElement<T>;
    using I = LinkedListIterator<T>;

    LLE *mHead;
    LLE *mTail;

    void free();

public:
    LinkedList();
    LinkedList(const LinkedList<T> &other);
    LinkedList(LinkedList<T> &&other);
    LinkedList<T> &operator=(const LinkedList<T> &other);
    LinkedList<T> &operator=(LinkedList<T> &&other);
    ~LinkedList();

    I begin() const;
    I end() const;
    bool empty() const;
    const T &getAt(const I &it) const;
    T &getAt(const I &it);

    bool insertBefore(const I &it, const T &x);
    bool insertAfter(const I &it, const T &x);
    bool insertFirst(const T &x);
    bool insertLast(const T &x);

    bool deleteBefore(const I &it, const T &elem); //?
    bool deleteAfter(const I &it, const T &elem);  //?
    bool deleteAt(const I &iter, T &pos);
};

#endif