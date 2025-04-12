class Solution {
public:
    string toLowerCase(string s) {
        string str;
        for(char ch : s){
            str+=tolower(ch);
        }
        return str;
    }
};