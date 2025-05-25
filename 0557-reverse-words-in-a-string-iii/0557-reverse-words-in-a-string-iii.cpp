class Solution {
public:
    string reverseWords(string s) {
        string curr = "";
        string res;
        for(int i=0; i<s.length(); i++){
            if(s[i]==' '){
                reverse(curr.begin(), curr.end());
                res+=curr;
                res+=" ";
                curr.clear();
            } else {
                curr+=s[i];
            }
        }
        reverse(curr.begin(), curr.end());
        res+=curr;
        return res;
    }
};