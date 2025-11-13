class Solution {
public:
    int maxOperations(string s) {
        int res = 0;
        int ones = 0;
        int prev = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1'){
                ones++;
                i++;
                bool b = false;
                while(i < s.length() && s[i]=='0'){
                    i++;
                    b = true;
                }
                if(b){
                    res+=ones;
                }
                i--;
                prev = ones;
            }
        }
        return res;
    }
};