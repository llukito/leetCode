class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int res = 0;
        string curr;
        bool b = true;
        for(char ch : text){
            if(ch == ' '){
                if(b)res++;
                b = true;
            } else {
                if(brokenLetters.find(ch)!= string :: npos){
                    b = false;
                }
            }
        }
        if(b)res++;
        return res;
    }
};