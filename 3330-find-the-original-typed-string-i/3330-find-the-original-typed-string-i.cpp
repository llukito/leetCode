class Solution {
public:
    int possibleStringCount(string word) {
        int res = 1;
        string curr = "";
        char c = word[0];
        for(char ch : word){
            if(ch == c){
                curr+=ch;
            } else {
                if(curr.length()>1){
                    res+=curr.length()-1;
                }
                c = ch;
                curr = ""; curr+=c;
            }
        }
        if(curr.length()>1){
            res+=curr.length()-1;
        }
        return res;
    }
};