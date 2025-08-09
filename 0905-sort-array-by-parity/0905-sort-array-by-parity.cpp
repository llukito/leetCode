class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> res;
        for(int n : nums){
            if(n%2==0){
                res.push_back(n);
            }
        }
        for(int n : nums){
            if(n%2==1){
                res.push_back(n);
            }
        }
        return res;
    }
};