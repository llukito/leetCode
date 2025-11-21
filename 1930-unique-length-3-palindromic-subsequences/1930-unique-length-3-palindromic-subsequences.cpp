class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> st;
        vector<set<int>> indexes(26, set<int>{0});

        vector<pair<int,int>> chars(26, {INT_MAX, INT_MIN});

        for(int i = 0; i < s.size(); i++){
            indexes[s[i]-'a'].insert(i);

            chars[s[i]-'a'] =  {min(chars[s[i]-'a'].first, i), max(chars[s[i]-'a'].second, i)};
        }
        int res = 0;
        for(auto& entry : chars){
            if(entry.first != entry.second){
                for(int i = 0; i < 26; i++){
                    auto it = indexes[i].upper_bound(entry.first);
                    if(it  == indexes[i].end())continue;
                    if(*it >= entry.second)continue;
                    res++;
                }
            }
        }
        return res;
    }
};