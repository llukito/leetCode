class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int res = 0;
        map<string,int> m1;
        map<string, int> m2;
        for(string s : words1){
            m1[s]++;
        }
        for(string s : words2){
            m2[s]++;
        }
        for(auto& entry : m1){
            if(m2[entry.first] == entry.second && entry.second ==1)res++;
        }
        return res;
    }
};