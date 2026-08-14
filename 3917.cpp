class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        set<int> odd;
        set<int> even;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 0){
                even.insert(i);
            } else {
                odd.insert(i);
            }
        }

        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 0){
                res.push_back(distance(odd.upper_bound(i), odd.end()));
            } else {
                res.push_back(distance(even.upper_bound(i), even.end()));
            }
        }
        return res;
    }
};
