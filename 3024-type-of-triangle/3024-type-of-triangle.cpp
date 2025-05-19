class Solution {
public:
    string triangleType(vector<int>& nums) {
        if(nums.size()!=3 || notValid(nums)){
            return "none";
        }
        set<int> s = {nums[0], nums[1], nums[2]};
        if(s.size() == 1){
            return "equilateral";
        } else if(s.size() == 2){
            return "isosceles";
        }
        return "scalene";
    }

    bool notValid(vector<int>& nums){
        sort(nums.begin(), nums.end());
        if(nums[0]+nums[1]<=nums[2]){
            return true;
        }
        return false;
    }
};