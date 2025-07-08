class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_set<string> seen;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            string curr;

            for (int j = i; j < n; ++j) {
                if (nums[j] % p == 0) cnt++;
                if (cnt > k) break;

                curr += to_string(nums[j]) + ",";
                seen.insert(curr);
            }
        }

        return seen.size();
    }
};