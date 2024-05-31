#pragma once
#include "list.h"

/*template<typename TKey, typename TValue>
struct Pair {
    TKey key;
    TValue value;
};*/

template<typename TKey, typename TValue>
class UnorderedTablesList {
private:
    List<Pair<TKey, TValue>> elements{};
public:
    TValue* search(TKey key)
    {
        for (auto i = elements.begin(); i != elements.end(); i++)
            if ((*i).key == key)
                return &(*i).value;
        return nullptr;
    }

    void insert(TKey key, TValue value)
    {
        if (search(key)) return;
        elements.insert(elements.end(), { key, value });
    }

    void remove(TKey key)
    {
        for (auto j = elements.begin(); j != elements.end(); j++)
        {
            if ((*j).key == key)
            {
                elements.erase(j);
                return;
            }
        }
    }

    void print() const
    {
        for (auto i = elements.begin(); i != elements.end(); i++) {
            cout << (*i).key << " : " << (*i).value << endl;
        }
    }
};