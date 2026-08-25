class Solution {
public:
    int numberOfSpecialChars(string word) {
        int array[26] = {0};
        unordered_set<char> distinctWord;
        for(char ch : word){
            distinctWord.insert(ch);
        }
        for(char ch : distinctWord){
            array[tolower(ch)-'a']++;
        }
        int res = 0;
        for(int n : array){
            res+=(n/2);
        }
        return res;
    }
};
