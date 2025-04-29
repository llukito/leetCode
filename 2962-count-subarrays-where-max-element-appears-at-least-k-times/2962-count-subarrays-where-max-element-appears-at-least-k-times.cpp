class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        long long res = 0;
        int maxVal = *max_element(nums.begin(), nums.end());
        int count = 0;

        for (int right = 0; right < n; ++right) {
            if (nums[right] == maxVal) {
                count++;
            }
            while (count >= k) {
                res += (n - right);  
                if (nums[left] == maxVal) {
                    count--;
                }
                left++;
            }
        }

        return res;
    }
};
