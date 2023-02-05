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

Dll *reverseDllNodes(Dll *head) {
    // if we have an empty list or list with one node just return the pointer, nothing to change
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // more than one element
    Dll *curr = head;
    Dll *next = head->next;
    Dll *afterNext = next->next;

    // handle the fisrt elem
    // link the curr and next element correctly
    curr->prev = next;
    curr->next = nullptr;
    next->next = curr;

    // move to the next two nodes which we will link
    curr = next;
    next = afterNext;

    while (next) {
        afterNext = next->next;
        curr->prev = next;
        next->next = curr;
        curr = next;
        next = afterNext;
    }

    // put an end of the list
    curr->prev = nullptr;

    return curr;
}

int main() {
    Dll *n1 = new Dll(1);
    Dll *n2 = new Dll(2);
    Dll *n3 = new Dll(3);
    Dll *n4 = new Dll(4);
    Dll *n5 = new Dll(5);

    // create the links between the nodes
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;
    n4->next = n5;
    n5->prev = n4;

    Dll *res = reverseDllNodes(n1);
    print(res);

    freeList(res);
    return 0;
}
