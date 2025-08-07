class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        map<char,int> m;
        for(char ch : pattern){
            m[ch]++;
        }
        vector<int> vect;
        for(char ch : pattern){
            vect.push_back(m[ch]);
        }
        for(string s : words){
            map<char,int> mp;
            for(char ch : s){
                mp[ch]++;
            }
            vector<int> ve;
            for(char ch : s){
                ve.push_back(mp[ch]);
            }
            if(ve == vect){
                if(valid(pattern, s)){
                    res.push_back(s);
                }
            }
        }
        return res;
    }

    bool valid(string p, string s){
        map<char,char> mp;
        for(int i=0; i<p.length(); i++){
            if(!mp.count(p[i])){
                mp[p[i]] = s[i]; 
            } else {
                if(mp[p[i]] != s[i])return false;
            }
        }
        return true;
    }
};