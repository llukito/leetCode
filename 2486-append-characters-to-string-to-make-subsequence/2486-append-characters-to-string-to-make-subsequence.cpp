class Solution {
public:
    int appendCharacters(string s, string t) {
        int first = 0; int second = 0;
        while(first<s.length()){
            if(s[first] == t[second]){
                second++;
            }
            first++;
        }
        return t.length()-second;
    }
};