class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        vector<string> fill;
        for(int n : nums){
            bitset<32> binary(n);
            fill.push_back(binary.to_string());
        }
        int res = 0;
        for(int i=0; i<32; i++){
            bool b = false;
            for(string s : fill){
                if(s[i] == '1'){
                    b = true;
                    break;
                }
            }
            if(b){
                res+=pow(2, 31-i);
            }
        }
        return res;
    }
};
