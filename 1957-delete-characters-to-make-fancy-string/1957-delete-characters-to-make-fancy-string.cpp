class Solution {
public:
    string makeFancyString(string s) {
        string curr;
        char ch = '-';
        string res;
        for(int i=0; i<s.length(); i++){
            if(ch!='-' && s[i]!=ch){
                if(curr.size()<3){
                    res+=curr; 
                } else {
                    res+=curr.substr(0,2);
                }
                curr = s[i]; ch = s[i];
            } else {
                ch = s[i];
                curr+=ch;
            }
        }
        if(curr.size()<3){
            res+=curr; 
        } else {
            res+=curr.substr(0,2);
        }
        return res;
    }
};