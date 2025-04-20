class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> vec;
        int total = 0;
        for(int i=0; i<nums.size(); i++)total+=nums[i];
        for(int i=0; i<nums.size(); i++){
            int sum  =0;
            int right = 0;
            for(int j=i+1; j<nums.size(); j++){
                right+=nums[j];
            }
            int left = total-right-nums[i];
            vec.push_back(abs(left-right));
        }
        return vec;
    }
};