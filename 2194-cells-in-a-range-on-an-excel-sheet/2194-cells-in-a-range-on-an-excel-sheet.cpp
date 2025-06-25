class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> res;
        char start = s[0];
        char end = s[3];
        for(char ch=start; ch<=end; ch++){
            for(int i=s[1]-'0'; i<=s[4]-'0'; i++){
                res.push_back(ch+to_string(i));
            }
        }
        return res;
    }
};