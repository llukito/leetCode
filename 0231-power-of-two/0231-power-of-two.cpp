class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;
        bitset<32> b(n);
        string s = b.to_string();
        int idx = 0;
        while(s[idx]=='0'){
            idx++;
        }
        int ones = 0;
        for(int i=idx; i<32; i++){
            if(s[i]=='1')ones++;
            if(ones>1)return false;
        }
        return true;
    }
};