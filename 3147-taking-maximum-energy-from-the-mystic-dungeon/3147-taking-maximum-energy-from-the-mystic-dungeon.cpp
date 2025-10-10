class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int res = INT_MIN;
        unordered_map<int,int> dp;
        for(int i=energy.size()-1; i>=0; i--){
            dp[i] = dp[i+k] + energy[i];
            res = max(res, dp[i]);
        }
        return res;
    }
};