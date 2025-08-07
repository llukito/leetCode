class RecentCounter {
public:
    vector<int> vect;

    RecentCounter() {
        
    }
    
    int ping(int t) {
        vect.push_back(t);
        int idx = lower_bound(vect.begin(), vect.end(), t-3000)-vect.begin();
        return vect.size()-idx;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */