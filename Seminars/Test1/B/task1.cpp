#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T value;
    Node<T> *next;
};

template <typename T>
struct Pair {
    T first;
    T second;
};

template <typename T>
void print(Node<T> *list) {
    while (list) {
        cout << list->value << ' ';
        list = list->next;
    }
    cout << '\n';
}

template <typename T>
void free(Node<T> *list) {
    while (list) {
        Node<T> *toDelete = list;
        list = list->next;
        delete toDelete;
    }
}

template <typename T>
int findListLength(Node<T> *list) {
    int length = 0;
    while (list) {
        length++;
        list = list->next;
    }
    return length;
}

template <typename T>
bool isValid(int indx, Node<T> *list) {
    int upperBound = findListLength(list) - 1;
    return indx >= 0 && indx <= upperBound;
}

template <typename T>
void rotateSublists(Node<T> *&list, Node<Pair<T>> *intervals) {
    Node<T> *iter = list;
    Node<T> *toDelete = nullptr;
    Node<T> *toInsert = nullptr;
    Node<T> *prevDel = nullptr;
    Node<T> *prevIns = nullptr;
    int findElIndx = 0;

    if (findListLength(list) == 1 || findListLength(list) == 0) {
        return;
    }

    if (findListLength(list) == 2 && isValid(intervals->value.first, list) && isValid(intervals->value.second, list)) {
        if (intervals->value.first == 0 && intervals->value.second == 1) {
            Node<T> *tmp = list->next;
            tmp->next = list;
            list->next = nullptr;
            list = tmp;
            return;
        } else { // case (1,0), which is basically erasing the first and inserting it at the first pos a.k.a not changed
            return;
        }
    }

    while (intervals != nullptr) {
        iter = list;
        toDelete = nullptr;
        toInsert = nullptr;
        prevDel = nullptr;
        prevIns = nullptr;
        findElIndx = 0;

        if (!(isValid(intervals->value.first, list) && isValid(intervals->value.second, list))) {
            throw "Invalid indexes!";
        }

        while (findElIndx != intervals->value.second) {
            findElIndx++;
            iter = iter->next;
        }

        toDelete = iter;
        iter = list;

        while (iter->next != toDelete) {
            iter = iter->next;
        }

        prevDel = iter;
        iter = list;

        findElIndx = 0;

        while (findElIndx != intervals->value.first) {
            findElIndx++;
            iter = iter->next;
        }

        toInsert = iter;
        iter = list;

        while (iter->next != toInsert) {
            iter = iter->next;
        }

        prevIns = iter;

        prevDel->next = toDelete->next;
        prevIns->next = toDelete;
        toDelete->next = toInsert;

        intervals = intervals->next;
    }
}

int main() {
    Node<int> *list = new Node<int>{
        11,
        new Node<int>{
            4,
            new Node<int>{
                3,
                new Node<int>{
                    7,
                    new Node<int>{
                        13,
                        new Node<int>{
                            4,
                            new Node<int>{5, nullptr}}}}}}};

    Node<Pair<int>> *indexPairs = new Node<Pair<int>>{{1, 3},
                                                      new Node<Pair<int>>{{2, 5},
                                                                          new Node<Pair<int>>{{5, 6}, nullptr}}};
    Node<int> *list2 = new Node<int>{
        11,
        new Node<int>{
            4,
            nullptr}};

    Node<Pair<int>> *indexPairs2 = new Node<Pair<int>>{{0, 1}, nullptr};

    print(list);
    rotateSublists(list, indexPairs);
    print(list);

    print(list2);
    rotateSublists(list2, indexPairs2);
    print(list2);

    free(list);
    free(indexPairs);
    free(list2);
    free(indexPairs2);

    return 0;
}