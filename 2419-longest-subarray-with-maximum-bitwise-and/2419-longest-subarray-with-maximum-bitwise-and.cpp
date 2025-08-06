class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());
        int res = 1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == n){
                int curr = 0;
                while(i<nums.size() && nums[i]==n){
                    i++;
                    curr++;
                }
                res = max(res, curr);
            }
        }
        return res;
    }
};