#include <iostream>
#include <string.h>
#include <unordered_map>
#include <list>
#include "lru.h"

using namespace std;
#define DEFAULT_CACHE_SIZE 5242880

struct LRUCache;
typedef string Index_Key;
typedef struct Index_Value {
    int keyVal_Size; // size of key and value
    uint64_t slabNo; // slab number
    uint64_t dramPFN; // in dram
    uint64_t flashPPN; // in flash
    bool inDram;
} Index_Value;

typedef struct KV_FTL {
    uint64_t cacheSize;
    unordered_map<Index_Key, Index_Value> kvMap;
    LRUCache keyInCache;

    KV_FTL(size_t size = DEFAULT_CACHE_SIZE) : cacheSize(size), keyInCache(size) {}

    void ReadKey(string key, bool &evict, string &coldKey);
} KV_FTL;
