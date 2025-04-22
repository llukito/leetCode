class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max_ = 0;
        for(string sentence : sentences){
            max_ = max(max_, split(sentence, ' '));
        }
        return max_;
    }

    int split(const string& s, char delimiter) {
        int size = 1;
        for(char ch : s){
            if(ch==delimiter)size++;
        }
        return size;
    }   
};