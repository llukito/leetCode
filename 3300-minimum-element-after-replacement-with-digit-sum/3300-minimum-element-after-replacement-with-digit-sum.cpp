class Solution {
public:
    int minElement(vector<int>& nums) {
        int res = INT_MAX;
        for(int n : nums){
            int curr = transfer(n);
            res = min(res, curr);
        }
        return res;
    }

    int transfer(int n){
        int curr = 0;
        string str = to_string(n);
        for(char ch : str){
            curr+=ch-'0';
        }
        return curr;
    }
};