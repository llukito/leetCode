class Solution {
public:
    char findKthBit(int n, int k) {
        string s1 = "0";
        while(n--){
            string s2 = s1;
            s2+='1';
            string inverted = invert(s1);
            reverse(inverted.begin(), inverted.end());
            s2+=inverted;
            s1 = s2;
        }
        return s1[k-1];
    }

    string invert(string s){
        string res;
        for(char ch : s){
            if(ch == '0')res+='1';
            else res+='0';
        }
        return res;
    }
};
