class Solution {
public:
    int numDecodings(string s) {
        unordered_map<int, int> map;
        return dfs(0, map, s);
    }

    int dfs(int i, unordered_map<int, int>& map, string& s){
        if(i==s.length()){
            return 1;
        }
        if(s[i]=='0')return 0;
        if(map.count(i)){
            return map[i];
        }
        int ways = dfs(i+1, map, s);
        if(i+1 < s.length()){
            int num = stoi(s.substr(i,2));
            if(num>=1 && num<=26){
                ways+=dfs(i+2, map, s);
            }
        }
        return map[i] = ways;
    }
};