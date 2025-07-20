class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int n : nums){
            map[n]++;
        }
        int res = 0;
        for(auto& entry : map){
            if(entry.second == 1){
                res+=entry.first;
            }
        }
        return res;
    }
};