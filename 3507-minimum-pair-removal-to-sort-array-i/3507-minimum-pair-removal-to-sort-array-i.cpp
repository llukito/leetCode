class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int r = 0;
        while(!valid(nums)){
            pair<int, int> p;
            int min = INT_MAX;
            for(int i=0; i<nums.size()-1; i++){
                if(min > nums[i]+nums[i+1]){
                    min = nums[i]+nums[i+1];
                    p.first = i;
                    p.second = i+1;
                }
            }
            nums[p.first] = min;
            nums.erase(nums.begin()+p.second);
            r++;
        }
        return r;
    }

    bool valid(vector<int>& nums){
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] > nums[i+1]){
                return false;
            }
        }
        return true;
    }
};