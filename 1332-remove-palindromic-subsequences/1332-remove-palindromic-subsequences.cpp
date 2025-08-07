class Solution {
public:
    int removePalindromeSub(string s) {
        if(palindrome(s)){
            return 1;
        } else {
            return 2;
        }
    }

    bool palindrome(string s){
        for(int i=0; i<s.length()/2; i++){
            if(s[i]!=s[s.length()-1-i])return false;
        }
        return true;
    }
};