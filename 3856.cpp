class Solution {
public:
    string trimTrailingVowels(string s) {
        string res = "";
        for(int i = s.size()-1; i >=0; i--){
            if(!isVowel(s[i])){
                for(int k = 0; k <= i; k++){
                    res += s[k];
                }
                break;
            }
        }
        return res;
    }

    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};
