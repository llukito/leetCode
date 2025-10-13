class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        while(true){
            vector<string> next;
            bool b = true;
            for(int i=1; i<words.size(); i++){
                next.push_back(words[i-1]);
                string s1 = words[i]; sort(s1.begin(), s1.end());
                string s2 = words[i-1]; sort(s2.begin(), s2.end());
                if(s1 == s2){
                    b = false; i++;
                } else {
                    next.push_back(words[i]);
                }
            }
            if(b)break;
            words = next;
        }
        return words;
    }
};