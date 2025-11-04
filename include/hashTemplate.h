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

    explicit hashTable(size_t initCapacity = 10, float loadFactor = 0.75f)
    :capacity(initCapacity), loadFactor(loadFactor), elements(0) {}

    virtual ~hashTable() = default;

    virtual void insert(const keyType& key, const valueType& value) = 0;
    virtual bool remove(const keyType& key) = 0;
    virtual valueType search(const keyType& key) const = 0;

    //getters
    [[nodiscard]] float getLoadFactor() const { return static_cast<float>(elements) / capacity; }
    [[nodiscard]] size_t getCapacity() const { return capacity; }
    [[nodiscard]] size_t getSize() const { return elements; }

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
template <typename keyType, typename valueType>
class hashTableSC : public hashTable<keyType, valueType> {
  private:
    std::list<valueType>* arr;
  public:
    using hashTable<keyType, valueType>::capacity;
    using hashTable<keyType, valueType>::keyValuePair;
    explicit hashTableSC()
       : hashTable<keyType, valueType>()  // ✅ initialize base class
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

#endif //PROJECT_2_HASHTEMPLATE_H