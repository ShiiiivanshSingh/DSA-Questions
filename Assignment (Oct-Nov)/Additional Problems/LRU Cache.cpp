

// design the class in the most optimal way


class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cacheList; // front = most recent, back = least recent
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;
    
public:
   
    LRUCache(int cap) : capacity(cap) {}

    
    int get(int key) {
       
        if (cacheMap.find(key) == cacheMap.end())
            return -1;
        
       
        auto it = cacheMap[key];
        int value = it->second;
        cacheList.erase(it);
        cacheList.push_front({key, value});
        cacheMap[key] = cacheList.begin();
        
        return value;
    }

 
    void put(int key, int value) {
       
        if (cacheMap.find(key) != cacheMap.end()) {
            auto it = cacheMap[key];
            cacheList.erase(it);
            cacheList.push_front({key, value});
            cacheMap[key] = cacheList.begin();
        } else {
            
            if (cacheList.size() == capacity) {
               
                int lastKey = cacheList.back().first;
                cacheList.pop_back();
                cacheMap.erase(lastKey);
            }
           
            cacheList.push_front({key, value});
            cacheMap[key] = cacheList.begin();
        }
    }
};


