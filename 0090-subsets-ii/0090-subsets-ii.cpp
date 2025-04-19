class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curr;
        set<vector<int>> s;
        fill(res, nums, curr, 0, s);
        return res;
    }

    void fill(vector<vector<int>>& res, vector<int>& nums, vector<int>& curr, int index, set<vector<int>>& s){
        if(index==nums.size()){
            if(!s.count(curr)){
                res.push_back(curr);
                s.insert(curr);
            }
            return;
        }
        fill(res, nums, curr, index+1, s);
        curr.push_back(nums[index]);
        fill(res, nums, curr, index+1, s);
        curr.pop_back();
    }
};