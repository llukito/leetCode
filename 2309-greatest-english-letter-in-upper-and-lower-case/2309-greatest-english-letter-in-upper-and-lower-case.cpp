class Solution {
public:
    string greatestLetter(string s) {
        for(char ch='z'; ch>='a'; ch--){
            char c = ch;
            if(s.find(c)!=string::npos){
                c = toupper(c);
                if(s.find(c)!=string::npos){
                    string s; s+=c;
                    return s;
                }
            }
        }
        return "";
    }
};