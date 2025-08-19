class Solution {
public:
    using ll = long long;
    long long zeroFilledSubarray(vector<int>& nums) {
        ll res = 0;
        ll curr = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                curr++;
            } else {
                res+= (1+curr)*curr/2;
                curr = 0;
            }
        }
        if(curr!=0){
            res+= (1+curr)*curr/2;
        }
        return res;
    }
};