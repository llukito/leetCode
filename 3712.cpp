class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> mp;
        for(int n : nums){
            mp[n]++;
        }
        for(int n : nums){
            if(mp[n] % k == 0){
                res += n;
            }
        }
        return res;
    }
};
