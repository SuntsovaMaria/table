#pragma once
#include <iostream>
#include <vector>
#include "list.h"  
using namespace std;


template<typename TKey, typename TValue>
struct Pair {
    TKey key;
    TValue value;
};


struct funct1 {
    int operator()(const string& key) {
        int hash = 0;
        for (char ch : key) {
            hash += ch;
        }
        return (hash % 100);
    }
};


struct funct2 {
    size_t operator()(const std::string& key) const {
        const size_t prime = 127;
        size_t hash = 0;
        size_t p_pow = 1;
        for (char ch : key) {
            hash = (hash + (ch - 'a' + 1) * p_pow) % 100;
            p_pow = (p_pow * prime) % 100;
        }
        return hash;
    }
};

template<typename TKey, typename TValue, typename THashFunction>
class HashTable {
private:
    int tablesize = 100;
    vector<List<Pair<TKey, TValue>>> table;
    THashFunction hashFunction;

public:
    HashTable() : table(tablesize) {}
    void insertp(const TKey& key, const TValue& value);
    void deletep(const TKey& key);
    TValue* searchp(const TKey& key);
    void print() const;
};

template<typename TKey, typename TValue, typename THashFunction>
void HashTable<TKey, TValue, THashFunction>::insertp(const TKey& key, const TValue& value) {
    int i = hashFunction(key) % tablesize;
    for (auto it = table[i].begin(); it != table[i].end(); it++) {
        if ((*it).key == key) {
            (*it).value = value;
            return;
        }
    }
    table[i].insert(table[i].end(), { key, value });
}

template<typename TKey, typename TValue, typename THashFunction>
void HashTable<TKey, TValue, THashFunction>::deletep(const TKey& key) {
    int i = hashFunction(key) % tablesize;
    for (auto it = table[i].begin(); it != table[i].end(); it++) {
        if ((*it).key == key) {
            table[i].erase(it);
            return;
        }
    }
}

template<typename TKey, typename TValue, typename THashFunction>
TValue* HashTable<TKey, TValue, THashFunction>::searchp(const TKey& key) {
    int i = hashFunction(key) % tablesize;
    for (auto it = table[i].begin(); it != table[i].end(); it++) {
        if ((*it).key == key) {
            return &((*it).value);
        }
    }
    return nullptr;
}

template<typename TKey, typename TValue, typename THashFunction>
void HashTable<TKey, TValue, THashFunction>::print() const {
    for (int i = 0; i < tablesize; i++) {
        if (!table[i].isempty()) {
            for (auto it = table[i].begin(); it != table[i].end(); it++) {
                cout << (*it).key << ": ";
                (*it).value.print();
            }
            cout << endl;
        }
    }
}