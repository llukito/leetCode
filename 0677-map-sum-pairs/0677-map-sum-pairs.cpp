class MapSum {
public:

    vector<string> keys;
    vector<int> vals;

    MapSum() {
        
    }
    
    void insert(string key, int val) {
        auto it = find(keys.begin(), keys.end(), key);
        if(it!=keys.end()){
            vals[it-keys.begin()]=val;
        } else {
            keys.push_back(key);
            vals.push_back(val);
        }
    }
    
    int sum(string prefix) {
        int sum = 0;
        for(int i=0; i<keys.size(); i++){
            string key = keys[i];
            if(key.size()<prefix.size())continue;
            string suff = key.substr(0, prefix.size());
            cout<<key<<endl;
            cout<<suff<<" "<<prefix.size()<<" "<<endl;
            if(suff==prefix){
                sum+=vals[i];
            }
        }
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */