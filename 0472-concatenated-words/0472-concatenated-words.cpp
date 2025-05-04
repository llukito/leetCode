class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
       vector<string> result;
       unordered_set<string> dict(words.begin(), words.end());
        unordered_map<string, bool> dp;
       for(int i=0; i<words.size(); i++){
            string str = words[i];
            dict.erase(str);
            if(possible(str, dict, dp)){
                result.push_back(str);
            }
            dict.insert(str);
       }
       return result;
    }

    bool possible(string& str, unordered_set<string>& dict, unordered_map<string, bool>& dp){
        if (str.empty()) return false;
        if(dp.count(str)){
            return dp[str];
        }
        for(int i=1; i<str.length(); i++){
            string left = str.substr(0,i);
            string right = str.substr(i);
            if(dict.count(left) && (dict.count(right) || possible(right, dict, dp))){
                return dp[str]=true;
            }
        }
        return dp[str]=false;
    }
};