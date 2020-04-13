#ifndef HASH_H
#define HASH_H

#define HashMaxSize 100
#define LoadFactor 0.8

typedef int KeyType;
typedef int ValueType;
typedef size_t (*HashFunc)(KeyType key);

typedef enum Stat {
    Empty,
    Valid,
    Invalid
} Stat;

typedef struct HashNode {
    KeyType key;
    ValueType value;
    Stat stat;
} HashNode;

typedef struct HashTable {
    HashNode data[HashMaxSize];
    size_t size;
    HashFunc hashFunc;
} HashTable;

size_t hash_func_default(KeyType key);

void init(HashTable* ht, HashFunc hashFunc);

int insert(HashTable* ht, KeyType key, ValueType value);

int find(HashTable* ht, KeyType key, ValueType* value);

int remove_element(HashTable* ht, KeyType key);

int is_empty(HashTable* ht);

int get_size(HashTable* ht);

void print_hashtable(HashTable* ht);


#endif
