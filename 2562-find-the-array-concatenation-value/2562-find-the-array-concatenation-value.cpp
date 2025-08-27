class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long res = 0;
        int left = 0; int right = nums.size()-1;
        while(left<right){
            res+=stoi((to_string(nums[left])+to_string(nums[right])));
            left++;
            right--;
        }
        if(left == right){
            res+=nums[left];
        }
        return res;
    }
};