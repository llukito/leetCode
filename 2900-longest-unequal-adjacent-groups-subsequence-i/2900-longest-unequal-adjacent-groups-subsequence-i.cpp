class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result;
        // string binary;
        // vector<string> fina;
        // check(words, groups, 0, binary, result, fina);
        // return fina;

        for(int i=0; i<words.size(); i++){
            vector<string> vect;
            int indx = -1;
            for(int j=0; j<words.size(); j++){
                if(indx == -1 || groups[indx]!=groups[j]){
                    vect.push_back(words[j]);
                    indx = j;
                }
            }
            if(vect.size() > result.size()){
                result = vect;
            }
        }
        return result;
    }

    void check(vector<string>& words, vector<int>& groups, int index, string& binary, vector<string>& result, vector<string>& fina){
        if(index == words.size()){
            if(result.size()>fina.size()){
                fina = result;
            }
            return;
        }
        check(words, groups, index+1, binary, result, fina);
        if(binary.empty() || binary.back()!=groups[index]){
            result.push_back(words[index]);
            check(words, groups, index+1, binary, result, fina);
            result.pop_back();
        }
    }
};