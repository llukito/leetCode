class MyHashSet {
public:

    vector<int> set;

    MyHashSet() {
        
    }
    
    void add(int key) {
        if(find(set.begin(),set.end(),key)==set.end()){
            set.push_back(key);
        }
    }
    
    void remove(int key) {
        auto it = find(set.begin(),set.end(),key);
        if(it!=set.end()){
            int index = it-set.begin();
            set.erase(set.begin()+index);
        }
    }
    
    bool contains(int key) {
        return find(set.begin(),set.end(),key)!=set.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */