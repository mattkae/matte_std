#ifndef MAP_H
#define MAP_H
#include "../types.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

template <typename K, typename V>
struct HashedElement {
    K key;
    V element;
    i64 hashCode = 0;  
};

template <typename K, typename V>
struct HashBucket {
    HashedElement<K, V>* elements = NULL;
    i32 numElements = 0;
    i32 capacity = 0;

    void init(i32 defaultCapacity = 8) {
        elements = new HashedElement<K, V>[defaultCapacity];
        capacity = defaultCapacity;
        numElements = 0;
    }

    void grow() {
        if (numElements == capacity) {
            capacity = capacity * 2;
            HashedElement<K, V>* newElements = new HashedElement<K, V>[capacity];
            memcpy(newElements, elements, sizeof(V) * numElements);
            delete [] elements;
            elements = newElements;
        }
    }

    bool add(K key, V element, i64 hashCode) {
        for (i32 i = 0; i < numElements; i++) {
            if (elements[i].hashCode == hashCode) {
                return false;
            }
        }

        grow();
        HashedElement<K, V> v;
        v.key = key;
        memcpy(&v.element, &element, sizeof(V));
        v.hashCode = hashCode;
        elements[numElements] = v;
        numElements++;
        return true;
    }

    bool replace(V element, i64 hashCode) {
        for (i32 i = 0; i < numElements; i++) {
            if (elements[i].hashCode == hashCode) {
                memcpy(&elements[i].element, &element, sizeof(V));
                return true;
            }
        }
        
        return false;
    }

    bool find(i64 hashCode, V* out) {
        for (i32 i = 0; i < numElements; i++) {
            if (elements[i].hashCode == hashCode) {
                *out = elements[i].element;
                return true;
            }
        }

        return false;
    }

    bool remove(i64 hashCode) {
        for (i32 i = 0; i < numElements; i++) {
            if (elements[i].hashCode == hashCode) {
                for (i32 j = i + 1; j < numElements; j++) {
                    elements[j - 1] = elements[j];
                }
                numElements--;
                return true;
            }
        }

        return false;
    }

    void freeBucket() {
        delete[] elements;
        elements = NULL;
        numElements = 0;
        capacity = 0;
    }
};

// https://research.cs.vt.edu/AVresearch/hashing/strings.php
i64 strHashFunc(const char* str);

template <typename K, typename V, i64 HashFunc(K)>
struct HashMap {
    HashBucket<K, V>* buckets = NULL;
    i32 numBuckets = 0;

    HashMap(i32 bucketCount = 16) {
        buckets = new HashBucket<K, V>[bucketCount];
        numBuckets = bucketCount;

        for (i32 b = 0; b < numBuckets; b++) {
            buckets[b].init();
        }
    }

    i32 hash(K key, i64* outHashResult) {
        *outHashResult = HashFunc(key);
        return (*outHashResult) % numBuckets;
    }

    bool insert(K key, V element) {
        i64 hashResult;
        auto bucketIdx = hash(key, &hashResult);
        return buckets[bucketIdx].add(key, element, hashResult);
    }

    bool replace(K key, V element) {
        i64 hashResult;
        auto bucketIdx = hash(key, &hashResult);
        return buckets[bucketIdx].replace(element, hashResult);
    }

    bool lookup(K key, V* out) {
        i64 hashResult;

        auto bucketIdx = hash(key, &hashResult);
        return buckets[bucketIdx].find(hashResult, out);
    }

    bool remove(K key) {
        i64 hashResult;
        auto bucketIdx = hash(key, &hashResult);
        return buckets[bucketIdx].remove(hashResult);
    }

    void freeMap() {
        for (i32 b = 0; b < numBuckets; b++) {
            buckets[b].freeBucket();
        }

        delete[] buckets;
        buckets = NULL;
        numBuckets = 0;
    }

    void forEach(void(*op)(K, V)) {
        for (i32 b = 0; b < numBuckets; b++) {
            for (i32 i = 0; i < buckets[b].numElements; i++) {
                op(buckets[b].elements[i].key, buckets[b].elements[i].element);
            }
        }
    }
};

#endif