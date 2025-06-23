class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        string curr;
        int l = 0; int r = 0;
        for(char ch : s){
            if(ch=='('){
                curr+='(';
                l++;
            } else {
                curr+=')';
                r++;
            }
            if(l == r){
                res+=curr.substr(1, curr.size()-2);
                curr = "";
                l = r = 0;
            }
        }
        return res;
    }
};