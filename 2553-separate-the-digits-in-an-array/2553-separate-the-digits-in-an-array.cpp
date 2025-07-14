class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for(int n : nums){
            string str = to_string(n);
            while(!str.empty()){
                res.push_back(str[0]-'0');
                str = str.substr(1);
            }
        }
        return res;
    }
};