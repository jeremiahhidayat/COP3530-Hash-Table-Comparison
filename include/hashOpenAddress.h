//
// Created by kaide on 11/3/2025.
//

#include "hashTemplate.h"
#include <iostream>
#include <cmath>
#include <optional>

#ifndef COP3530_HASH_TABLE_COMPARISON_HASHTABLE_H
#define COP3530_HASH_TABLE_COMPARISON_HASHTABLE_H

template <typename keyType, typename valueType>
class hashOpenAddress : public hashTable<keyType, valueType>{
    using Base = hashTable<keyType, valueType>;
    using keyValuePair = std::pair<keyType, valueType>;

public:
    hashOpenAddress(size_t initCapacity = 10, float loadFactor = 0.75f)
    :Base(initCapacity, loadFactor), table(initCapacity, std::nullopt) {}

    void insert(const keyType& key, const valueType& value) override {
        if (this->getLoadFactor() >= this->loadFactor) {
            rehash(this->capacity * 2);
        }
        size_t index = this->hash(key);
        while (table[index].has_value() && table[index]->first != key) {
            index = (index+1) % this->capacity;
        }
        if (table[index].has_value()) {
            this->elements++;
        }
        table[index].keyValuePair(key, value);
    }

    valueType search(const keyType& key) const override {
        size_t index = this->hash(key);
        size_t start = index;

        while (table[index].has_value()) {
            if (table[index]->first == key) {
                return table[index]->second;
            }
        }
        throw std::runtime_error("Key not found in table");
    }

    float memoryUtilization() const {
        return static_cast<float>(this->elements) / static_cast<float>(this->capacity);
    }

protected:
    // make/do hash table here
    void rehash(size_t new_capacity) override {
        std::vector<std::optional<keyValuePair>> old = table;

        this->capacity = new_capacity;
        table = std::vector<std::optional<keyValuePair>>(new_capacity, std::nullopt);
        this->elements = 0;

        for (auto &slot : old) {
            if (slot.has_value() && slot != tombstone) {
                insert(slot->first, slot->second);
            }
        }
    }

private:
    std::vector<std::optional<keyValuePair>> table;
    const std::optional<keyValuePair> tombstone = std::make_optional(keyValuePair(keyType{}, valueType{}));
};

#endif //COP3530_HASH_TABLE_COMPARISON_HASHTABLE_H