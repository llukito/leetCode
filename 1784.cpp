class Solution {
public:
    bool checkOnesSegment(string s) {
        bool b = false;
        for(int i = 0; i < s.size(); i++){
           if(s[i] == '0'){
               b = true;
           } else if(b)return false;
        }
        return true;
    }
};