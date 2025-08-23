class Solution {
public:
    bool digitCount(string num) {
        map<char,int> m;
        for(char ch : num){
            m[ch]++;
        }
        for(int i=0; i<num.length(); i++){
            char ch = char('0'+i);
            if(m[ch]!=num[i]-'0')return false;
        }
        return true;
    }
};