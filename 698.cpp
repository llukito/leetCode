class Solution {
public:
    unordered_map<string, bool> dp;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int n : nums)sum+=n;
        if(sum % k != 0)return false;
        sort(nums.begin(), nums.end(), greater<>());
        vector<int> vect(k, 0);
        return rec(nums, vect, 0, k, sum);
    }

    bool rec(auto& nums, auto& vect, int idx, int& k, int& sum){
        if(idx == nums.size()){
            return true;
        }
        string key = getKey(vect);
        if(dp.count(key))return false;
        for(int i = 0; i < k; i++){
            if(vect[i] + nums[idx] > sum/k)continue;
            vect[i]+=nums[idx];
            if(rec(nums, vect, idx+1, k, sum)) return true;
            vect[i]-=nums[idx];
        }
        return dp[key] = false;
    }

    string getKey(auto& vect){
        string key = "";
        for(int n : vect){
            key+=n+'|';
        }
        return key;
    }
};
