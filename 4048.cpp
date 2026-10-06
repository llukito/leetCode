class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        int res = 0;
        for(auto& entry : mp){
            if(entry.second.size() == 3){
                if(entry.second[1]-entry.second[0] == entry.second[2]-entry.second[1])res++;
            }
        }
        return res;
    }
};
