class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> vector;
        for(int i=0; i<words.size(); i++){
            string s = words[i];
            if(s.find(x)!=string::npos){
                vector.push_back(i);
            }
        }
        return vector;
    }
};