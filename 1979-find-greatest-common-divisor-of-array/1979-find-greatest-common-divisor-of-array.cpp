class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min_ = *min_element(nums.begin(), nums.end());
        int max_ = *max_element(nums.begin(), nums.end());
        for(int i=min(min_, max_); i>=1; i--){
            if(min_ % i == 0 && max_ % i == 0)return i;
        }
        return -1;
    }
};