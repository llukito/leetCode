class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> vect = nums;
        reverse(nums.begin(), nums.end());
        for(int n : nums){
            vect.push_back(n);
        }
        return vect;
    }
};
