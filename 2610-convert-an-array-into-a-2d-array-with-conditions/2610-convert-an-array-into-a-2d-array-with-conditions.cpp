class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<bool> bools(nums.size(), false);
        vector<vector<int>> result;
        while(find(bools.begin(), bools.end(), false) != bools.end()){
            vector<int> vect;
            for(int i=0; i<nums.size(); i++){
                if(!bools[i] && find(vect.begin(), vect.end(), nums[i])==vect.end()){
                    vect.push_back(nums[i]);
                    bools[i] = true;
                }
            }
            result.push_back(vect);
        }
        return result;
    }
};