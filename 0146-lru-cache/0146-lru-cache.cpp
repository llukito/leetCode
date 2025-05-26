class LRUCache {
public:

    int size=0;
    list<pair<int, int>> lruList;
    unordered_map<int, list<pair<int, int>>::iterator> map;

    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(map.count(key)){
            auto t = map[key];
            int val = t->second;
            lruList.erase(t);
            lruList.push_front({key, val});
            map[key] = lruList.begin();
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(map.count(key)){
            auto t = map[key];
            int val = t->second;
            lruList.erase(t);
            lruList.push_front({key, value});
            map[key] = lruList.begin();
        } else {
            if(lruList.size() == size){
                map.erase(lruList.back().first);
                lruList.pop_back();
            }
            lruList.push_front({key, value});
            map[key] = lruList.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */