class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> mp;
        int d = s.size()-k;
        for(int i = 0; i <= d; i++){
            mp.insert(s.substr(i, k));
        }
        return mp.size() == 1<<k;
    }
};
