class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int res = 0;
        for(string str : words){
            if(str.length()<=s.length() && s.substr(0, str.length())==str)res++;
        }
        return res;
    }
};