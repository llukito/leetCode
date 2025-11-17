class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int curr = 0; int first = -1;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 1){
                if(first != -1 && curr < k)return false;
                first = 0;
                curr = 0;
            } else {
                curr++;
            }
        }
        return true;
    }
};