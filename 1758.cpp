class Solution {
public:
    int minOperations(string s) {
        string s1, s2;
        for(int i = 0; i < s.size(); i++){
            if(i%2 == 0){
                s1+='1';
                s2+='0';
            } else {
                s1+='0';
                s2+='1';
            }
        }
        int res1 = 0, res2 = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != s1[i]){
                res1++;
            }
            if(s[i] != s2[i]){
                res2++;
            }
        }
        return min(res1, res2);
    }
};
