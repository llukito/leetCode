class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            int res = nums[i];
            bool b = true;
            for(int m=0; m<=1000; m++){
                if((m|(m+1)) == res){
                    ans.push_back(m);
                    b = false;
                    break;
                }
            }
            if(b)ans.push_back(-1);
        }
        return ans;
    }
};