class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int num = 0;
        for(string s : words){
            if(s.length()>=pref.length() && pref == s.substr(0, pref.size())){
                num++;
            }
        }
        return num;
    }
};