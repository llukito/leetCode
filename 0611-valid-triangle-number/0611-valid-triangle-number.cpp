class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        // unordered_set<string> visited;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size()-1; j++){
                int sum = nums[i]+nums[j];
                int idx = lower_bound(nums.begin()+j+1, nums.end(), sum)-nums.begin();
                res+= idx-j-1;
            }
        }
        return res;
    }
}; 
//2 2 2 3 3 4
