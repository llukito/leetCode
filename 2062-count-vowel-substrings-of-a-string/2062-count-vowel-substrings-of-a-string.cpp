class Solution {
public:
    int countVowelSubstrings(string word) {
        int res = 0;
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for(int i=0; i<word.length(); i++){
            bool b = false;
            set<char> curr;
            for(int k=i; k<=i+3; k++){
                if(!vowels.count(word[k])){
                    b = true;
                    break;
                } else{
                    curr.insert(word[k]);
                }
            }
            if(b)continue;
            for(int j=i+4; j<word.length(); j++){
                if(!vowels.count(word[j])){
                    break;
                }
                curr.insert(word[j]);
                if(curr.size()==5)res++;
            }
        }
        return res;
    }
};