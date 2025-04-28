class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        return possible(nums, 0, nums.size() - 1) >= 0;
    }

    int possible(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left]; 
        }

        int pickLeft = nums[left] - possible(nums, left + 1, right);
        int pickRight = nums[right] - possible(nums, left, right - 1);
        return max(pickLeft, pickRight);
    }
};
