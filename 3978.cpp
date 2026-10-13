class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size()/2;
        int val = nums[n];
        for(int i = 0; i < nums.size(); i++){
            if(val == nums[i] && i!=n){
                return false;
            }
        }
        return true;
    }
};
