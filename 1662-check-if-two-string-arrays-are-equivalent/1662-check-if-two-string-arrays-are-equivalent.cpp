class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1, s2;
        for(string str : word1){
            s1+=str;
        }
        for(string str : word2){
            s2+=str;
        }
        return s1 == s2;
    }
};