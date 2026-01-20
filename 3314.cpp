class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            bool b = false;
            for(int j = 1; j <= 1000; j++){
                if((j | (j+1)) == nums[i]){
                    ans.push_back(j);
                    b =true;
                    break;
                }
            }
            if(!b)ans.push_back(-1);
        }
        return ans;
    }
};
