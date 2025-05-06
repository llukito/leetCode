class FrequencyTracker {
public:

    unordered_map<int,int> map;
    multiset<int> set;

    FrequencyTracker() {
        
    }
    
    void add(int number) {
        if (map.count(number)) {
            set.erase(set.find(map[number]));
        }
        map[number]++;
        set.insert(map[number]);
    }
    
    void deleteOne(int number) {
        if(map.count(number) && map[number]>0){
           set.erase(set.find(map[number]));
            map[number]--;
            if(map[number]>0){
                set.insert(map[number]);
            } else {
                map.erase(number);
            }
        }
    }
    
    bool hasFrequency(int frequency) {
        return set.count(frequency)>0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */