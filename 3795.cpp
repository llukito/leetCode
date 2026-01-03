class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int left = 0;
        int right = 0;
        long long sum = 0;
        int res = INT_MAX;
        while(right < nums.size()){
            if(mp[nums[right]] == 0){
                sum += nums[right];
            }
            mp[nums[right]]++;
            while(sum >= k){
                res = min(res, right - left + 1);
                mp[nums[left]]--;
                if(mp[nums[left]] == 0){
                    sum -= nums[left];
                }
                left++;
            }
            right++;
        }
        return res != INT_MAX ? res : -1;
    }
};
