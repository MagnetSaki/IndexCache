#include "lru.h"

void LRUCache::SetSize(size_t _size) {
    cache_size_ = _size;
}
bool LRUCache::Full() {
    return lru.size() >= cache_size_;
}
bool LRUCache::Empty() {
    return lru.size() == 0;
}
LRU_status LRUCache::Read(string key) {
    auto it = mp.find(key);
    if (it == mp.end()) 
        return Not_Found;
    lru.splice(lru.begin(), lru, it->second);
    return Found;
}
LRU_status LRUCache::Write(string key, bool &evict, string &coldKey) {
    auto it = mp.find(key);
    if (it != mp.end()) {
        lru.splice(lru.begin(), lru, it->second);
    }
    else {
        if(Full()) {
            evict = true;
            DelBack(coldKey);
        }
        lru.push_front(key);
    }
    mp[key] = lru.begin();
}
LRU_status LRUCache::Erase(string key) {
    auto it = mp.find(key);
    if (it == mp.end()) {
        return Not_Found;
    }
    lru.erase(it->second);
    mp.erase(it);
    return Found;
}
LRU_status LRUCache::DelBack(string &key) {
    assert(!Empty());
    key = *lru.rbegin();
    mp.erase(key);
    lru.pop_back();
}
void LRUCache::Print() {
    auto it = lru.begin();
    if(it == lru.end())
        printf("LRUCache is empty.\n");
    while(it != lru.end()){
        cout<<"LRU key:"<<*it<<endl;
        it++;
    }
}