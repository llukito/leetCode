class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        vector<bool> used(words.size(), false);
        int num = 0;
        for(int i=0; i<words.size(); i++){
            for(int j = i+1; j<words.size(); j++){
                if(!used[j]){
                    string str = words[i]; reverse(str.begin(), str.end());
                    if(str == words[j]){
                        used[i] = true; used[j] = true;
                        num++;
                    }
                }
            }
        }
        return num;
    }
};