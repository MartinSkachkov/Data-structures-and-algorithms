#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int LIMIT = 2147483647;

struct PhoneEntry {
    string name; // key
    int number;  // data

    int hash() {
        int sum = 0;
        for (char c : name) {
            sum += c - 'a';
        }
        return abs(sum % LIMIT);
    }
};

class PhoneHashTable {
private:
    size_t size;
    vector<vector<PhoneEntry>> table;

public:
    PhoneHashTable(size_t s);
    void add(PhoneEntry phone);
    void get(PhoneEntry &phone);
    void remove(PhoneEntry phone);
    void print() const;
};

PhoneHashTable::PhoneHashTable(size_t s = 0) : size(s) {
    table.resize(s);
}

void PhoneHashTable::add(PhoneEntry phone) {
    int indx = phone.hash() % size;

    for (size_t i = 0; i < table[indx].size(); i++) {
        if (table[indx][i].name == phone.name) {
            table[indx][i] = phone; // rewrite the data
            return;
        }
    }
    table[indx].push_back(phone);
}

void PhoneHashTable::remove(PhoneEntry phone) {
    int indx = phone.hash() % size;

    for (size_t i = 0; i < table[indx].size(); i++) {
        if (table[indx][i].name == phone.name) {
            swap(table[indx][i], table[indx].back()); // swap with the last element
            table[indx].pop_back();
            return;
        }
    }
}

void PhoneHashTable::get(PhoneEntry &phone) {
    int indx = phone.hash() % size;

    for (size_t i = 0; i < table[indx].size(); i++) {
        if (table[indx][i].name == phone.name) {
            phone = table[indx][i];
        }
    }
}

void PhoneHashTable::print() const {
    for (size_t hash = 0; hash < size; hash++) {
        if (table[hash].empty()) {
            continue;
        }

        cout << "Hash: " << hash << '\n';
        for (size_t elem = 0; elem < table[hash].size(); elem++) {
            cout << table[hash][elem].name << ' ' << table[hash][elem].number << '\n';
        }
    }
}

int main() {
    PhoneHashTable table(3);
    table.add(PhoneEntry{"Martin Skachkov", 123456});
    table.add(PhoneEntry{"John Smith", 568745});
    table.add(PhoneEntry{"Hans L", 687456});

    table.print();
    table.remove(PhoneEntry{"John Smith"});
    table.print();

    return 0;
}