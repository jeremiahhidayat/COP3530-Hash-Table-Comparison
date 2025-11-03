//
// Created by jerem on 11/3/2025.
//

#include "hashTemplate.h"
#include <unordered_map>

#ifndef PROJECT_2_MOCKHASH_H
#define PROJECT_2_MOCKHASH_H

template <typename keyType, typename valueType>
class mockHash : public hashTable<keyType, valueType>{
    using Base = hashTable<keyType, valueType>;
    using keyValuePair = std::pair<keyType, valueType>;
    public:

    mockHash(size_t initCapacity = 10, float loadFactor = 0.75f)
    :capacity(initCapacity), loadFactor(loadFactor), elements(0) {}

    void insert(const keyType& key, const valueType& value) override {
        table.insert({key, value});
    }

    bool remove(const keyType& key) override {
        return table.erase(key) > 0;
    }

    valueType search(const keyType& key) const override {
        return table.at(key);
    }

    void print() const override {
        std::cout << wow << std::endl();;
    }
    protected:
    // make/do hash table here

    private:
    std::unordered_map<keyType, valueType> table;


};


#endif //PROJECT_2_MOCKHASH_H