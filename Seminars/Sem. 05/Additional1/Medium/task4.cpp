#include <iostream>
using namespace std;

struct Dll {
    int data;
    Dll *next;
    Dll *prev;
    Dll(const int &d, Dll *n = nullptr, Dll *p = nullptr) : data(d), next(n), prev(p) {}
};

void freeList(Dll *list) {
    while (list) {
        Dll *toDel = list;
        list = list->next;
        delete toDel;
    }
}

void print(Dll *list) {
    while (list) {
        cout << list->data << ' ';
        list = list->next;
    }
    cout << '\n';
}

void link(Dll *first, Dll *second) {
    if (first)
        first->next = second;
    if (second)
        second->prev = first;
}

Dll *merge2SortedL(Dll *l1, Dll *l2) {
    if (l1 == nullptr) {
        return l2;
    }

    if (l2 == nullptr) {
        return l1;
    }

    // both lists are not empty
    Dll *start = nullptr;
    Dll *last = nullptr;
    // determine the beginning of merged the list
    if (l1->data < l2->data) {
        start = l1;
    } else {
        start = l2;
    }

    while (l1 != nullptr && l2 != nullptr) {
        Dll *next = nullptr;

        if (l1->data <= l2->data) {
            next = l1;
            l1 = l1->next;
        } else {
            next = l2;
            l2 = l2->next;
        }

        // link the next with last
        link(last, next);
        last = next;
    }

    if (l1 == nullptr && l2 == nullptr) {
        return start;
    } else if (l1 == nullptr) { // l2 has more elements
        // create the links
        link(last, l2);
        return start;
    } else { // l1 has more elements
        link(last, l1);
        return start;
    }
}

int main() {
    Dll *n1 = new Dll(2);
    Dll *n2 = new Dll(8);
    Dll *n3 = new Dll(9);

    // create the links between the nodes
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;

    Dll *n4 = new Dll(1);
    Dll *n5 = new Dll(4);

    n4->next = n5;
    n5->prev = n4;

    Dll *res = merge2SortedL(n1, n4);
    print(res);

    freeList(res);
    return 0;
}