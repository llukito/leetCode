class Solution {
public:
    const int MAX_ELEM = 50000;
    int minimumPairRemoval(vector<int>& nums) {
        int steps = 0;
        while(!sorted(nums)){
            process(nums);
            steps++;
        }
        return steps;
    }

    bool sorted(auto& nums){
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i]>nums[i+1])return false;
        }
        return true;
    }

    void process(auto& nums){
        int currMin = MAX_ELEM;
        int idx = 0;
        for(int i = 0; i < nums.size()-1; i++){
            if(currMin > nums[i]+nums[i+1]){
                currMin = nums[i]+nums[i+1];
                idx = i;
            }
        }
        nums[idx] = currMin;
        nums.erase(nums.begin()+idx+1);
    }
};
