class MyHashMap {
public:
    vector<int> keys;
    vector<int> values;

    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        auto it = find(keys.begin(),keys.end(),key);
        if(it!=keys.end()){
            int index = it-keys.begin();
            values[index]=value;
        } else {
            keys.push_back(key);
            values.push_back(value);
        }

    }
    
    int get(int key) {
        auto it = find(keys.begin(),keys.end(),key);
        if(it!=keys.end()){
            int index = it-keys.begin();
            return values[index];
        }
        return -1;
    }
    
    void remove(int key) {
        auto it = find(keys.begin(),keys.end(),key);
        if(it!=keys.end()){
            int index = it-keys.begin();
            keys.erase(keys.begin()+index);
            values.erase(values.begin()+index);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */