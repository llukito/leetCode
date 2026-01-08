class Solution {
public:
    #define MAX(a,b)((a) > (b) ? (a) : (b))
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<long long>> dp(nums1.size(), vector<long long>(nums2.size(), INT_MIN));
        dp[nums1.size()-1][nums2.size()-1] = max(INT_MIN, nums1.back()*nums2.back());
        for(int i = nums1.size()-1; i>=0; i--){
            for(int j = nums2.size()-1; j>=0; j--){
                int n = nums1.size(); int m = nums2.size();
                int res = INT_MIN;
                res = MAX(res, nums1[i]*nums2[j]);
                if (i + 1 < n && j + 1 < m) {
                    res = MAX(res, nums1[i]*nums2[j] + dp[i + 1][j + 1]);
                }

                if (i + 1 < n) {
                    res = MAX(res, dp[i + 1][j]);
                }

                if (j + 1 < m) {
                    res = MAX(res, dp[i][j + 1]);
                }
                dp[i][j] = res;
            }
        }
        return dp[0][0];
    }
};
