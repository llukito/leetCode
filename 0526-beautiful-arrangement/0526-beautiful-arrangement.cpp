class Solution {
public:
    int countArrangement(int n) {
        int res = 0;
        vector<int> vect;
        for(int i=1; i<=n; i++)vect.push_back(i);
        vector<bool> b(n, false); vector<int> curr;
        backtrack(vect, b, curr, res);
        return res;
    }

    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current, int& res) {
        if (current.size() == nums.size()) {
            res++;
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            if(nums[i]%(current.size()+1)!=0 && (current.size()+1)%nums[i]!=0)continue;
            used[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, used, current, res);
            current.pop_back();
            used[i] = false;
        }
    }
};