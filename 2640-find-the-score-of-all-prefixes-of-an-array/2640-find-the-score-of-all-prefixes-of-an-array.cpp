class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<int> prefix(nums.size(), 0);
        prefix[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            prefix[i] = max(prefix[i-1], nums[i]);
        }
        vector<long long> vect;
        for(int i=0; i<nums.size(); i++){
            vect.push_back(nums[i]+prefix[i]);
        }
        vector<long long> res(vect.size(), 0);
        for(int i=0; i<nums.size(); i++){
            if(i>0){
                res[i] = res[i-1]; 
            }
            res[i]+=vect[i];
        }
        return res;
    }
};