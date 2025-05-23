class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> map;
        string curr = "";
        return fill(s, wordDict, curr, map);
    }

    bool fill(string& s, vector<string>& wordDict, string& curr, unordered_map<string, bool>& map){
        if(s==curr){
            return true;
        }
        if(map.count(curr)){
            return map[curr];
        }
        for(string str : wordDict){
            if(curr.size() + str.size() <= s.size()){
                curr+=str;
                if(curr == s.substr(0, curr.size()) && fill(s, wordDict, curr, map)){
                    map[curr] = true;
                    return true;
                }
                map[curr] = false;
                curr = curr.substr(0, curr.size()-str.size());
            }
        }
        return false;
    }
};