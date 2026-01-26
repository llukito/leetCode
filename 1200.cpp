class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int min_ = minimumDifference(arr);
        vector<vector<int>> res;
        for(int i = 0; i < arr.size()-1; i++){
            if(arr[i+1]-arr[i] == min_){
                res.push_back({arr[i], arr[i+1]});
            }
        }
        return res;
    }

    int minimumDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        for(int i = 0; i < nums.size()-1; i++){
            res = min(res, nums[i+1]-nums[i]);
        }
        return res;
    }
};
