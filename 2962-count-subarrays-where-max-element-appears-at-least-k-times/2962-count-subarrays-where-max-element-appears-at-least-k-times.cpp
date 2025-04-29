class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int left = 0; int right = 0;
        long long res = 0;
        int maxValue = *max_element(nums.begin(), nums.end());
        int freq = 0;
        bool b = true;
        while(right<nums.size() && left<=right+1){
            if(nums[right]==maxValue && b){
                freq++;
            }
            if(freq>=k){
                res+=nums.size()-right;
                if(nums[left]==maxValue){
                    freq--;
                }
                left++;
                b = false;
            } else {
                b = true;
                right++;
            }
        }
        return res;
    }
};