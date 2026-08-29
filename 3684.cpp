class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<>());
        vector<int> res;
        for(int n : nums){
            if(k != 0){
                if(find(res.begin(), res.end(), n) != res.end())continue;
                res.push_back(n);
                k--;
            } else if(k == 0){
                return res;
            }
        }
        return res;
    }
};
