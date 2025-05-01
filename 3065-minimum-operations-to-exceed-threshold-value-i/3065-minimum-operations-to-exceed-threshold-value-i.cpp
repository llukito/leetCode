class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int num = 0;
        for(int n : nums){
            if(n<k)num++;
        }
        return num;
    }
};