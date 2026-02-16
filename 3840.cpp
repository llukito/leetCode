class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        vector<pair<long long, bool>> dp(nums.size()+1, {0, false});
        dp[0] = {nums[0], true};
        for(int i = 1; i < nums.size(); i++){
            if(!dp[i-1].second || (colors[i]!=colors[i-1])){
                dp[i] = {dp[i-1].first+nums[i], true};
            } else {
                if(dp[i-1].first >= dp[i-1].first-nums[i-1]+nums[i]){
                    dp[i] = {dp[i-1].first, false};
                } else {
                    dp[i] = {dp[i-1].first-nums[i-1]+nums[i], true};
                }
                if(i-2>=0 && dp[i].first < dp[i-2].first+nums[i]){
                    dp[i] = {dp[i-2].first+nums[i], true};
                }
            }
        }
        return dp[nums.size()-1].first;
    }
};
