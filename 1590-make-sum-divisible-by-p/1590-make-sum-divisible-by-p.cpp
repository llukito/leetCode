class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums) total += x;
        long long rem = total % p;
        if (rem == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;

        long long prefix = 0;
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            prefix = (prefix + nums[i]) % p;

            long long want = (prefix - rem + p) % p;
            if (mp.count(want))
                ans = min(ans, i - mp[want]);

            mp[prefix] = i;
        }

        return ans == nums.size() ? -1 : ans;
    }
};