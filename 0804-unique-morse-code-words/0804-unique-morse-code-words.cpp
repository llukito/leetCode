class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> vect = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> set;
        for(string str : words){
            string morse;
            for(char ch : str){
                morse+=vect[ch-'a'];
            }
            set.insert(morse);
        }
        return set.size();
    }
};