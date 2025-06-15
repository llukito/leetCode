class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        check(res, temp, nums, 0);
        return res;
    }

    void check(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, int idx){
        if(idx == nums.size()){
            res.push_back(temp);
            return;
        }
        check(res, temp, nums, idx+1);
        temp.push_back(nums[idx]);
        check(res, temp, nums, idx+1);
        temp.pop_back();
    }
};