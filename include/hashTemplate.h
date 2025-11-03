//
// Created by jerem on 11/3/2025.
//

#ifndef PROJECT_2_HASHTEMPLATE_H
#define PROJECT_2_HASHTEMPLATE_H

#include <vector>
#include <list>
#include <functional>
#include <optional>
#include <stdexcept>
#include <iostream>

template <typename keyType, typename valueType>
class hashTable {
public:
    using keyValuePair = std::pair<keyType, valueType>;

    hashTable(size_t initCapacity = 10, float loadFactor = 0.75f)
    :capacity(initCapacity), loadFactor(loadFactor), elements(0) {}

    virtual ~hashTable() = default;

    virtual void insert(const keyType& key, const valueType& value) = 0;
    virtual bool remove(const keyType& key) = 0;
    virtual valueType search(const keyType& key) const = 0;

    //getters
    float getLoadFactor() const { return static_cast<float>(elements) / capacity; }
    size_t getCapacity() const { return capacity; }
    size_t getSize() const { return elements; }

    //Print for Debugging
    virtual void print() const = 0;

protected:
    size_t capacity;
    float loadFactor;
    size_t elements;

    // change the hashing function here
    size_t hash(const keyType& key) const {
        return std::hash<keyType>{}(key) % capacity;
    }

    //needed for open addressing
    virtual void rehash(size_t new_capacity) = 0;

};

#endif //PROJECT_2_HASHTEMPLATE_H