class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> res;
        for(int n : nums){
            res.insert(n);
            string str = to_string(n);
            reverse(str.begin(), str.end());
            res.insert(stoi(str));
        }
        return res.size();
    }
};