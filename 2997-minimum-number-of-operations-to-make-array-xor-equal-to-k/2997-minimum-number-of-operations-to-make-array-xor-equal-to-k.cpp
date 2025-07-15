class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x = nums[0];
        for(int i=1; i<nums.size(); i++){
            x^=nums[i];
        }
        int val = k^x;
        int count = 0;
        while(val){
            if(val & 1)count++;
            val=val>>1;
        }
        return count;
    }
};