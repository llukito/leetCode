class Solution {
public:
    int countGoodSubstrings(string s) {
        int left = 0;
        int res=0;
        while(left+2<s.length()){
            if(s[left]!=s[left+1] && s[left+1]!=s[left+2] && s[left]!=s[left+2]){
                res++;
            }
            left++;
        }
        return res;
    }
};