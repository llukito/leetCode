class Solution {
public:
    const int MOD = 1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        int all = points.size();
        unordered_map<int, int> mp;
        for(auto& entry : points){
            mp[entry[1]]++;
        }
        int res = 0;
        int dep = 0;
        for(auto& entry : mp){
            if(entry.second < 2){
                dep++;
                continue;
            }
            int curr = 0;
            curr = (all-entry.second)*(all-entry.second-1)*(entry.second)*(entry.second-1)/4;
            res+=curr;
        }
        return max(0,(res-dep)/2);
    }
};