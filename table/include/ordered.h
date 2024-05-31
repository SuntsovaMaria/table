//#ifndef ORDERED_H
//#define ORDERED_H
#pragma once


template<typename TKey, typename TValue>
struct Pair1 {
    TKey Key;
    TValue Value;
};

template <typename TKey, typename TValue>
class OrderedTables {
private:
    vector<Pair1<TKey, TValue>> values;
public:
    TValue* search(TKey key) {
        int left = 0;
        int right = values.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (values[mid].Key > key)
                right = mid - 1;
            else if (values[mid].Key < key)
                left = mid + 1;
            else
                return &(values[mid].Value);
        }
        return nullptr;
    }

    void insert(TKey key, TValue val) {
        int left = 0;
        int right = values.size() - 1;
        int mid = -1;
        while (left <= right) {
            mid = (left + right) / 2;

            if (values[mid].Key > key)
                right = mid - 1;
            else if (values[mid].Key < key)
                left = mid + 1;
            else
                return;
        }

        Pair1<TKey, TValue> tmp = { key, val };
        if (mid == -1 || values[mid].Key > key) {
            values.insert(values.begin() + left, tmp);
        }
        else {
            values.insert(values.begin() + left, tmp);
        }
    }

    void remove(TKey key) {
        int left = 0;
        int right = values.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (values[mid].Key > key)
                right = mid - 1;
            else if (values[mid].Key < key)
                left = mid + 1;
            else {
                values.erase(values.begin() + mid);
                return;
            }
        }
    }

    void print() const {
        for (const auto& pair : values) {
            cout << pair.Key << " : " << pair.Value << endl;
        }
    }

}; 
//#endif