//
// Created by Test on 11/6/2025.
//
#ifndef HASHTABLESC_H
#define HASHTABLESC_H
#include "hashTemplate.h"
template <typename keyType, typename valueType>
class hashTableSC : public hashTable<keyType, valueType> {
private:
    std::list<valueType>* arr;
public:
    using hashTable<keyType, valueType>::capacity;
    using hashTable<keyType, valueType>::keyValuePair;
    explicit hashTableSC()
       : hashTable<keyType, valueType>()
    {
        arr = new std::list<typename hashTable<keyType, valueType>::keyValuePair>[capacity];
    }
    ~hashTableSC() override {
        delete[] arr;
    }
    void insert(const keyType& key, const valueType& value) override {
        arr[hash(key)].push_back(std::make_pair(key, value));
    }
    bool remove(const keyType& key) override {
        auto before = arr[hash(key)].size();
        arr[hash(key)].remove_if([key](const std::pair<keyType, valueType>& p) {
        return p.first == key;
        });
        auto after = arr[hash(key)].size();
        if (after < before)
            return true;
        return false;
    }
    valueType search(const keyType& key) const override {
        auto it = std::find_if(arr[hash(key)].begin(), arr[hash(key)].end(),
                           [key](const std::pair<int, std::string>& p) {
                               return p.first == key;
                           });
        return it->second;
    }
};
#endif //HASHTABLESC_H
