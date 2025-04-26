class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long left = -1, right = -1, bad = -1;
        long long  res = 0;
        for(int i=0; i<nums.size(); i++){
            int n = nums[i];
            if(n<minK || n>maxK){
                bad = i;
            }
            if(n==minK){
                left = i;
            }
            if(n==maxK){
                right = i;
            } 
            if(left!=-1 && right!=-1 && min(left,right)>bad){
                res+=min(left, right)-bad;
            }
        }
        return res;
    }
};
