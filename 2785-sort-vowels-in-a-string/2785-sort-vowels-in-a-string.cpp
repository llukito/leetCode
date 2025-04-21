class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        for(char c : s){
            char ch = c;
            ch = tolower(ch);
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                vowels.push_back(c);
            }
        }
        sort(vowels.begin(), vowels.end());
        int index = 0;
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            ch = tolower(ch);
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                s[i]=vowels[index++];
            }
        }
        return s;
    }
};