class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int res = 0;
        vector<bool> bools(letters.size(), false);
        vector<string> curr;
        check(words, letters, score, curr, 0, res, bools, 0);
        return res;
    }

    void check(vector<string>& words, vector<char>& letters, vector<int>& score, vector<string>& curr, int index, int& res, vector<bool>& bools, int sc){
        if(index == words.size()){
            res = max(res, sc);
            return;
        }
        check(words, letters, score, curr, index+1, res, bools, sc);

        string toBeAdded = words[index];
        int toBeAddedScore = 0;
        vector<int> indexes;
        int sizee = 0;
        vector<bool> tempUsed = bools;
        for(char ch : toBeAdded){
            bool bb = false;
            for(int i=0; i<letters.size(); i++){
                if(letters[i] == ch && !tempUsed[i]){
                    tempUsed[i] = true;
                    toBeAddedScore+=score[ch-'a'];
                    indexes.push_back(i);
                    bb = true;
                    sizee++;
                    break;
                }
            }
            if(!bb)break;
        }
        if(sizee == toBeAdded.length()){
            for(int n : indexes){
                bools[n] = true;
            }
            check(words, letters, score, curr, index+1, res, bools, sc+toBeAddedScore);
            for(int n : indexes){
                bools[n] = false;
            }
        }
    }
};