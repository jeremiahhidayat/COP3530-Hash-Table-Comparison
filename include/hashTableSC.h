//
// Created by Test on 11/6/2025.
//
#ifndef HASHTABLESC_H
#define HASHTABLESC_H
#include "hashTemplate.h"
#include <utility>
using namespace std;
template <typename keyType, typename valueType>
class hashTableSC : public hashTable<keyType, valueType> {
private:
    std::list<typename hashTableSC::keyValuePair>* arr;
public:
    using hashTable<keyType, valueType>::capacity;
    using hashTable<keyType, valueType>::size;
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
        ++size;
        if(size / capacity >= 0.75) {
            capacity *= 2;
            auto* new_arr = new std::list<typename hashTableSC::keyValuepPair>[capacity];
            for (int i = 0; i < static_cast<int>(capacity / 2); i++) {
                auto it = arr[i].begin();
                while (it != arr[i].end()) {
                    new_arr[hash(it->first)].push_back(make_pair(it->first, it->second));
                }
            }
            delete[] arr;
            arr = new_arr;
        }
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
        auto& bucket = arr[hash(key)];
        auto it = std::find_if(bucket.begin(), bucket.end(),
                               [key](const std::pair<int, std::string>& p) {
                                   return p.first == key;
                               });

        if (it != bucket.end()) {
            return it->second;
        } else {
            throw std::runtime_error("Key not found in table");
        }
    }
};
#endif //HASHTABLESC_H
