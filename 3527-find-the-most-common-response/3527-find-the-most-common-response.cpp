class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        map<string,int> mp;
        for(vector<string> vect : responses){
            set<string> st;
            for(string s : vect){
                if(!st.count(s)){
                    st.insert(s);
                    mp[s]++;
                }
            }
        }
        string res; int freq = 0;
        for(auto& entry : mp){
            if(entry.second > freq){
                freq = entry.second;
                res = entry.first;
            }
        }
        return res;
    }
};