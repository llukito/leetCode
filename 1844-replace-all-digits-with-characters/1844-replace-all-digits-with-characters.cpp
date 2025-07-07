class Solution {
public:
    string replaceDigits(string s) {
        char ch;
        for(int i=0; i<s.length(); i++){
            char c = s[i];
            if(c>='0' && c<='9'){
                s[i] = static_cast<char>(ch+c-'0');
                ch = '*';
            } else {
                ch = c;
            }
        }
        return s;
    }
};