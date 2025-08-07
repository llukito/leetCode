class Solution {
public:
    int minChanges(string s) {
        int res = 0;
        for(int i=0; i<s.length()-1; i+=2){
            int ones = 0; int zeros = 0;
            if(s[i]=='1'){
                ones++;
            } else {
                zeros++;
            }
            if(s[i+1]=='1'){
                ones++;
            } else {
                zeros++;
            }
            res+= 1 ? ones==1 : 0;
        }
        return res;
    }
};