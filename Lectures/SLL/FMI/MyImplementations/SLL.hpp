#ifndef _SINGLY_LINKED_LIST_
#define _SINGLY_LINKED_LIST_
#include <cstdlib>

template <typename T>
class LinkedList {
private:
    struct LLNode {
        T mData;
        LLNode *mNext;
        LLNode(const T &element, LLNode *next = nullptr) : mData(element), mNext(next) {}
    };

    LLNode *head;
    LLNode *tail;
    size_t listSize;

    void free();
    void copy(const LinkedList<T> &other);

public:
    class Iterator {
    private:
        LLNode *currentNode;
        Iterator(LLNode *ptr) : currentNode(ptr) {}

    public:
        Iterator &operator++() {
            if (currentNode == nullptr) {
                return *this;
            }
            currentNode = currentNode->mNext;
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        T &operator*() {
            return currentNode->mData;
        }

        bool operator==(const Iterator &other) const {
            return currentNode == other.currentNode;
        }

        bool operator!=(const Iterator &other) const {
            return currentNode != other.currentNode;
        }

        friend class LinkedList; // трябва ни за да миже когато правим итератор към началото или края да имаме достъп до конструктора на Iterator, който е в private секция
    };

    class ConstIterator {
    private:
        const LLNode *currentNode;
        ConstIterator(LLNode *ptr) : currentNode(ptr) {}

    public:
        ConstIterator &operator++() {
            if (currentNode == nullptr) {
                return *this;
            }
            currentNode = currentNode->mNext;
            return *this;
        }

        ConstIterator operator++(int) {
            ConstIterator tmp = *this;
            ++(*this);
            return tmp;
        }

        const T &operator*() const {
            return currentNode->mData;
        }

        bool operator==(const ConstIterator &other) const {
            return currentNode == other.currentNode;
        }

        bool operator!=(const ConstIterator &other) const {
            return currentNode != other.currentNode;
        }

        friend class LinkedList;
    };

    LinkedList();
    LinkedList(const LinkedList<T> &other);
    LinkedList(LinkedList<T> &&other);
    LinkedList<T> &operator=(const LinkedList<T> &other);
    LinkedList<T> &operator=(LinkedList<T> &&other);
    ~LinkedList();

    Iterator begin() {
        return Iterator(head);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

    ConstIterator begin() const {
        return ConstIterator(head);
    }

    ConstIterator end() const {
        return ConstIterator(nullptr);
    }

    ConstIterator cbegin() {
        return ConstIterator(head);
    }

    ConstIterator cend() {
        return ConstIterator(nullptr);
    }

    void pushBack(const T &elem);
    void popBack();

    void pushFront(const T &elem);
    void popFront();

    const T &back() const;
    T &back();
    const T &front() const;
    T &front();

    bool empty() const;
    size_t size() const;
};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &other) {
    copy(other);
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList<T> &&other) {
    head = other.head;
    tail = other.tail;
    listSize = other.listSize;

    other.head = other.tail = nullptr;
    other.listSize = 0;
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &other) {
    if (this == other) {
        return *this;
    }
    free();
    copy(other);
    return *this;
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> &&other) {
    if (this == other) {
        return *this;
    }
    free();
    head = other.head;
    tail = other.tail;
    listSize = other.listSize;

    other.head = other.tail = nullptr;
    listSize = 0;

    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    free();
}

template <typename T>
void LinkedList<T>::free() {
    while (head) {
        LLNode *toDelete = head;
        head = head->mNext;
        delete toDelete;
    }
    listSize = 0;
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T> &other) {
    listSize = other.listSize;
    LLNode *iter = other.head;

    while (iter) {
        pushBack(iter->mData);
        iter = iter->mNext;
    }
}

template <typename T>
void LinkedList<T>::pushBack(const T &elem) {
    LLNode *newElem = new LLNode(elem);

    if (empty()) {
        head = newElem;
        tail = newElem;
    } else {
        tail->mNext = newElem;
        tail = newElem;
    }

    listSize++;
}

template <typename T>
void LinkedList<T>::popBack() {
    if (empty()) {
        throw "List is empty!";
    }

    if (head == tail) {
        delete tail;
        head = tail = nullptr;
    } else {
        LLNode *tmp = head;
        while (tmp->mNext != tail) {
            tmp = tmp->mNext;
        }

        delete tail;
        tail = tmp;
        tail->mNext = nullptr;
    }

    listSize--;
}

template <typename T>
void LinkedList<T>::pushFront(const T &elem) {
    LLNode *newElem = new LLNode(elem);

    if (empty()) {
        head = newElem;
        tail = newElem;
    } else {
        newElem->mNext = head;
        head = newElem;
    }

    listSize++;
}

template <typename T>
void LinkedList<T>::popFront() {
    if (empty()) {
        throw "List is empty!";
    }

    if (head == tail) {
        delete tail;
        head = tail = nullptr;
    } else {
        LLNode *tmp = head;
        head = head->mNext;
        delete tmp;
    }

    listSize--;
}

template <typename T>
bool LinkedList<T>::empty() const {
    return head == nullptr && tail == nullptr;
}

template <typename T>
size_t LinkedList<T>::size() const {
    return listSize;
}

template <typename T>
const T &LinkedList<T>::back() const {
    if (empty()) {
        throw "List is empty!";
    }
    return tail->mData;
}

template <typename T>
T &LinkedList<T>::back() {
    if (empty()) {
        throw "List is empty!";
    }
    return tail->mData;
}

template <typename T>
const T &LinkedList<T>::front() const {
    if (empty()) {
        throw "List is empty!";
    }
    return head->mData;
}

template <typename T>
T &LinkedList<T>::front() {
    if (empty()) {
        throw "List is empty!";
    }
    return head->mData;
}
#endif