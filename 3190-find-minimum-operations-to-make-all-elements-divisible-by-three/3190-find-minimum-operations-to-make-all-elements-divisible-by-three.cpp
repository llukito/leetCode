class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res = 0;
        for(int n : nums){
            if(n%3 != 0){
                res++;
            }
        }
        return res;
    }
};