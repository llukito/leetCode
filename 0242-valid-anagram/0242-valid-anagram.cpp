class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s == t;
        if(s.length()!=t.length())return false;
        map<char, int> mp1;
        for(char ch : s){
            mp1[ch]++;
        }
        map<char, int> mp2;
        for(char ch : t){
            mp2[ch]++;
        }
        for(auto& entry : mp1){
            if(!mp2.count(entry.first) || mp2[entry.first] != entry.second){
                return false;
            }
        }
        return true;
    }
};