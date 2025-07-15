class Solution {
public:
    bool isValid(string word) {
        string vowels = "aeiou";
        if(word.length()<3)return false;
        bool vow = false; bool cons = false;
        for(char ch : word){
            ch = tolower(ch);
            if(!isalnum(ch))return false;
            if(isdigit(ch))continue;
            if(vowels.find(ch) != string::npos){
                vow = true;
            } else {
                cons = true;
            }
        }
        return vow && cons;
    }
};