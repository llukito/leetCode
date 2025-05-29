class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int s = 0;
        unordered_set<int> set(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            int num = nums[i];
            if(set.count(num+diff) && set.count(num+2*diff)){
                s++;
            }
        }
        return s;
    }
};