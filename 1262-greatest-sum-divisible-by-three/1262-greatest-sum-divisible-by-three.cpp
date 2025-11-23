class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp {0, INT_MIN, INT_MIN};
        for(int i = 0; i < nums.size(); i++){
            vector<int> temp = dp;
            for(int j = 0; j < 3; j++){
                if(dp[j]!= INT_MIN){
                    int newSum = dp[j] + nums[i];
                    temp[newSum%3] = max(temp[newSum%3], newSum);
                }
            }
            dp = temp;
        }
        return dp[0];
    }
};   