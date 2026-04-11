class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        int res = INT_MAX;

        for(auto& entry : mp){
            auto& vect = entry.second;
            sort(vect.begin(), vect.end());
            for(int i = 0; i < max((int)vect.size()-2, 0); i++){
                res =  min(res, 2 * (vect[i+2]- vect[i]));
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
