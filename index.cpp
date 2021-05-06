#include "index.h"

void KV_FTL::ReadKey(string key, bool &evict, string &coldKey) {
    keyInCache.Write(key, evict, coldKey);
}