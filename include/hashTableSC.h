//
// Created by Test on 11/6/2025.
//
#ifndef HASHTABLESC_H
#define HASHTABLESC_H
#include <iostream>
#include <algorithm>
#include <utility>
#include <list>
#include <stdexcept>
#include <string>
using namespace std;
class hashTableSC {
    using keyValuePair = pair<string, string>;
private:
    std::list<keyValuePair>* arr;
    size_t capacity;
    size_t size;
    [[nodiscard]] size_t hash(const string& key) const {
        unsigned int sum = 0;
        for (int i = 0; i < 100; i++) {
            if (i == key.size() - 1) {
                break;
            }
            sum += key[i];
        }
        return sum % capacity;
    }
public:
    hashTableSC() {
        capacity = 10;
        size = 0;
        arr = new std::list<keyValuePair>[capacity];
    }
    ~hashTableSC() {
        delete[] arr;
    }
    void insert(const string& key, const string& value)  {
        arr[hash(key)].emplace_back(key, value);
        ++size;
        if(size / capacity >= 0.75) {
            capacity *= 2;
            auto* new_arr = new std::list<keyValuePair>[capacity];
            for (int i = 0; i < static_cast<int>(capacity / 2); i++) {
                auto it = arr[i].begin();
                while (it != arr[i].end()) {
                    new_arr[hash(it->first)].emplace_back(it->first, it->second);
                }
            }
            delete[] arr;
            arr = new_arr;
        }
    }
    bool remove(const string& key)  {
        const auto before = arr[hash(key)].size();
        arr[hash(key)].remove_if([key](const keyValuePair& p) {
        return p.first == key;
        });
        auto after = arr[hash(key)].size();
        if (after < before)
            return true;
        return false;
    }
    [[nodiscard]] string search(const string& key) const {
        auto& bucket = arr[hash(key)];
        const auto it = ranges::find_if(bucket,
                                        [key](const std::pair<string, std::string>& p) {
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
