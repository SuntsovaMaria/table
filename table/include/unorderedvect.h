#pragma once
#include <vector>

using namespace std;

/*template<typename TKey, typename TValue>
struct Pair {
    TKey key;
    TValue value;
};*/

template<typename TKey, typename TValue>
class UnorderedTables {
private:
    vector<Pair<TKey, TValue>> elements{};
public:
    TValue* search(TKey key) {
        for (auto& i : elements) {
            if (i.key == key) {
                return &i.value;
            }
        }
        return nullptr;
    }

    void insert(TKey key, TValue val) {
        if (search(key)) return;
        elements.push_back({ key, val });
    }

    void remove(TKey key) {
        int i = 0;
        for (auto& j : elements) {
            if (j.key == key) {
                elements.erase(elements.begin() + i);
                break;
            }
            i++;
        }
    }

    
    void print() {
        for (auto& i : elements) {
            cout << i.key << " = " << i.value << endl;
        }

    }
};