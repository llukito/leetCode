class Solution {
public:
    string sortVowels(string s) {
        string res  ="";
        string vowels = "";
        for(char ch : s){
            if(isVowel(ch)){
                res+="-";
                vowels+=ch;
            } else {
                res+=ch;
            }
        }
        sort(vowels.begin(), vowels.end());
        int idx = 0;
        for(int i=0; i<res.length(); i++){
            char ch = res[i];
            if(ch == '-'){
                res[i] = vowels[idx++];
            }
        }
        return res;
    }

    bool isVowel(char c){
        char ch = tolower(c);
        unordered_set<char> s {'a', 'e', 'i', 'o', 'u'};
        return s.count(ch);
    }
};