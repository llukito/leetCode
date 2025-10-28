class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int all = 0;
        int sums = 0;
        for(int i : nums)sums+=i;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                if(move(nums, i, sums, -1))all++;
                if(move(nums,i, sums, 1))all++;
            }
        }
        return all;
    }

    bool move(vector<int> nums, int i, int sums, int unit){
        while(true){
            if(sums == 0)return true;
            if(i<0 || i>=nums.size())return false;
            if(nums[i] == 0){
                i+=unit;
            } else if(nums[i]>0){
                nums[i]--;
                unit*=-1;
                sums-=1;
                i+=unit;
            }
        }
        return false;
    }
};