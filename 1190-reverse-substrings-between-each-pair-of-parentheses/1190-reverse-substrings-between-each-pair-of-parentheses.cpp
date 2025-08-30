class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> pran;
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            if(ch != ')'){
                pran.push(ch);
            } else {
                string curr = "";
                while(true){
                    if(pran.empty())break;
                    char c = pran.top(); pran.pop();
                    if(c == '(')break;
                    curr+=c;
                }
                for(char ch : curr){
                    pran.push(ch);
                }
            }
        }
        string res = "";
        while(!pran.empty()){
            res+=pran.top(); pran.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};