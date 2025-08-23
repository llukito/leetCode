class Solution {
public:
    bool checkString(string s) {
        if(s.find_first_of('b') == string::npos)return 1;
        for(int i=s.find_first_of('b')+1; i<s.length(); i++){
            if(s[i] == 'a')return 0;
        }
        return 1;
    }
};