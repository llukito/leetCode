class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int n = INT_MIN;
        for(int i : nums){
            n = max(i, n);
        }
        int res = 0;
        for(int i=0; i<k; i++){
            res+=n++;
        }
        return res;
    }
};