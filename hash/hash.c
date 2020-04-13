#include <stdio.h>
#include "hash.h"

int find_cur(HashTable* ht, KeyType key, size_t* cur);

size_t hash_func_default(KeyType key) {
    return key % HashMaxSize;
}

/**
 *
 * @param ht
 * @param hashFunc
 */
void init(HashTable* ht, HashFunc hashFunc)
{
    if (ht == NULL) {
        return;
    }
    ht->size = 0;
    ht->hashFunc = hashFunc == NULL ? hash_func_default : hashFunc;

    for (size_t i = 0; i < HashMaxSize; ++i) {
        ht->data[i].key = 0;
        ht->data[i].stat = Empty;
        ht->data[i].value = 0;
    }

}

/**
 *
 * @param ht
 * @param key
 * @param value
 * @return
 */
int insert(HashTable* ht, KeyType key, ValueType value)
{

    if (ht == NULL)
        return 0;

    if (ht->size >= HashMaxSize * LoadFactor) {
        return 0;
    }
    size_t cur = ht->hashFunc(key);

    while (1) {
        if (ht->data[cur].key == key)
            return 0;

        if (ht->data[cur].stat != Valid) {
            ht->data[cur].key = key;
            ht->data[cur].stat = Valid;
            ht->data[cur].value = value;
            ht->size++;
            return 1;
        }
        cur++;
    }
}

/**
 *
 * @param ht
 * @param key
 * @param value
 * @param cur
 * @return
 */
int find(HashTable* ht, KeyType key, ValueType* value)
{
    if (ht == NULL)
        return 0;

    size_t offset = ht->hashFunc(key);
    if (ht->data[offset].key == key && ht->data[offset].stat == Valid) {
        *value = ht->data[offset].value;
        return 1;
    } else {
        while (ht->data[offset].stat != Empty) {
            if (ht->data[offset].key != key) {
                offset++;
                if (offset >= HashMaxSize)
                    offset = 0;
            } else {
                if (ht->data[offset].stat == Valid) {
                    *value = ht->data[offset].value;
                    return 1;
                } else
                    offset++;
            }
        }
        return 0;
    }
}

/**
 *
 * @param ht
 * @param key
 */
int find_cur(HashTable* ht, KeyType key, size_t* cur)
{

    if (ht == NULL)
        return 0;

    for (size_t i = 0; i < HashMaxSize; ++i) {
        if (ht->data[i].key == key && ht->data[i].stat == Valid) {
            *cur = i;
            return 1;
        }
    }
    return 0;
}


/**
 *
 * @param ht
 * @param key
 */
int remove_element(HashTable* ht, KeyType key)
{
    if (ht == NULL)
        return 0;

    size_t cur = 0;

    int ret = find_cur(ht, key, &cur);
    if (ret == 0)
        return 0;
    else {
        ht->data[cur].stat = Invalid;
        ht->size--;
        return 1;
    }
}

/**
 *
 * @param ht
 * @return
 */
int is_empty(HashTable* ht)
{
    if (ht == NULL)
        return 0;
    else
        return ht->size > 0 ? 1 : 0;
}

/**
 *
 * @param ht
 * @return
 */
int get_size(HashTable* ht)
{
    if (ht == NULL)
        return 0;

    int size = 0;
    int offset = 0;

    while (ht->data[offset].stat != Empty) {
        offset++;
        size++;
    }
    return size;
}

/**
 *
 * @param ht
 */
void print_hashtable(HashTable* ht)
{
    const char* msg = "当前hash表: ";
    if (ht == NULL || ht->size == 0) {
        return;
    }
    printf("%s\n", msg);
    for (int i = 0; i < HashMaxSize; i++)
    {
        if (ht->data[i].stat != Empty)
            printf("[%d]  key=%d  value=%d  stat=%d\n", i, ht->data[i].key,
                   ht->data[i].value, ht->data[i].stat);
    }
}