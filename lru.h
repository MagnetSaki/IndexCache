#include <unordered_map>
#include <list>
#include <utility>
#include <assert.h>
#include <string>
#include <iostream>

using namespace std;
#define DEFAULT_LRU_SIZE 5242880

typedef enum LRU_status {
    Not_Found,
    Found
} LRU_status;

struct LRUCache {
public:
    LRUCache(size_t size = DEFAULT_LRU_SIZE) : cache_size_(size) {}
    ~LRUCache() {
        lru.clear();
        mp.clear();
    }

    void SetSize(size_t _size);
    bool Full();
    bool Empty();
    LRU_status Read(string key);
    LRU_status Write(string key, bool &evict, string &coldKey);
    LRU_status Erase(string key);
    LRU_status DelBack(string &key);
    void Print();
    
private:
    size_t cache_size_;
    std::list<string> lru;
    std::unordered_map<string, std::list<string>::iterator> mp;
};