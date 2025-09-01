class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, pair<int,int>> map;
        for(int i=0; i<s.length(); i++){
            if(!map.count(s[i])){
                map[s[i]].first = map[s[i]].second = i;
                continue;
            }
            map[s[i]].first = max(map[s[i]].first, i);
            map[s[i]].second = min(map[s[i]].second, i);
        }
        unordered_set<string> se;
        for(auto& entry : map){
            if(entry.second.first - entry.second.second >=2){
                for(int i=entry.second.second+1; i<entry.second.first; i++){
                    string str = "";
                    str+=entry.first; str+=s[i]; str+=entry.first;
                    se.insert(str);
                }
            }
        }
        return se.size();
    }
};