class Solution {
public:
    int firstMatchingIndex(string s) {
        for(int i = 0; i <= s.size()/2; i++){
            if(s[i] == s[s.size()-1-i])return i;
        }
        return -1;
    }
};
