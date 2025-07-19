class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> set(nums.begin(), nums.end());
        string res;
        check(res, set, static_cast<int>(nums.size()), "");
        return res;
    }

    void check(string& res, unordered_set<string>& set, int n, string curr){
        if(!res.empty())return;
        if(curr.length() == n){
            if(!set.count(curr)){
                res = curr;
            }
            return;
        }
        check(res, set, n, curr+'0');
        check(res, set, n, curr+'1');
    }
};