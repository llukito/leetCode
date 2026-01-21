class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int n : nums){
            if(n == 2){
                ans.push_back(-1);
            } else {
                bitset<32> b(n);
                string str = b.to_string();
                for(int i = 31; i >= 0; i--){
                    if(str[i] == '0'){
                        str[i+1] = '0';
                        break;
                    }
                }
                ans.push_back(stoi(str, nullptr, 2));
            }
        }
        return ans;
    }
};

