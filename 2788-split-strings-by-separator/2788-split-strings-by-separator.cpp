class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> res;
        for(string s : words){
            string curr;
            for(char ch : s){
                if(ch == separator){
                    if(curr.empty())continue;
                    res.push_back(curr);
                    curr.clear();
                } else {
                    curr+=ch;
                }
            }
            if(!curr.empty())res.push_back(curr);
        }
        return res;
    }
};