class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int add = 0;
        string res = "";
        unordered_set<int> set(spaces.begin(), spaces.end());
        for(int i=0; i<s.length(); i++){
            if(set.count(i)){
                res+=" ";
            }
            res+=s[i];
        }
        return res;
    }
};