#ifndef COP3530_HASH_TABLE_COMPARISON_HASHTABLE_H
#define COP3530_HASH_TABLE_COMPARISON_HASHTABLE_H

#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <stdexcept>

class hashOpenAddress {
public:
    using keyValuePair = std::pair<std::string, std::string>;

    hashOpenAddress(size_t initCapacity = 10, float loadFactor = 0.75f)
            : capacity(initCapacity), loadFactor(loadFactor),
              table(initCapacity, nullptr), elements(0) {}

    ~hashOpenAddress() {
        for (auto ptr : table) {
            delete ptr;
        }
    }

    void insert(const std::string& key, const std::string& value) {
        if (getLoadFactor() >= loadFactor) {
            rehash(capacity * 2);
        }

        size_t index = hash(key) % capacity;

        // Linear probing
        while (table[index] != nullptr && table[index]->first != key) {
            index = (index + 1) % capacity;
        }

        if (table[index] == nullptr) {
            elements++; // new element
            table[index] = new keyValuePair(key, value);
        } else {
            table[index]->second = value; // update existing
        }
    }

    std::string search(const std::string& key) const {
        size_t index = hash(key) % capacity;
        size_t start = index;

        while (table[index] != nullptr) {
            if (table[index]->first == key) {
                return table[index]->second;
            }
            index = (index + 1) % capacity;
            if (index == start) break; // searched whole table
        }

        throw std::runtime_error("Key not found in table");
    }

    float getLoadFactor() const {
        return static_cast<float>(elements) / static_cast<float>(capacity);
    }

    float memoryUtilization() const {
        return getLoadFactor();
    }

protected:
    size_t hash(const std::string& key) const {
        std::hash<std::string> hasher;
        return hasher(key);
    }

    void rehash(size_t new_capacity) {
        std::vector<keyValuePair*> oldTable = table;

        capacity = new_capacity;
        table = std::vector<keyValuePair*>(new_capacity, nullptr);
        elements = 0;

        for (auto ptr : oldTable) {
            if (ptr != nullptr) {
                insert(ptr->first, ptr->second);
                delete ptr; // delete old pointer
            }
        }
    }

private:
    std::vector<keyValuePair*> table;
    size_t capacity;
    size_t elements;
    float loadFactor;
};

#endif // COP3530_HASH_TABLE_COMPARISON_HASHTABLE_H
