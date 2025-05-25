class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> map;
        for(string s : words){
            map[s]++;
        }
        int num = 0;
        unordered_set<string> set;
        int m = 0;
        for(auto& entry : map){
            if(entry.first[0] == entry.first[1]){
                if(entry.second % 2 ==0){
                    num+=2*entry.second;
                } else {
                    m = max(m, 2*entry.second);
                }
            } else if(!set.count(entry.first)){
                string rev = entry.first;
                reverse(rev.begin(), rev.end());
                if(map.count(rev)){
                    set.insert(rev);
                    num+=4*min(entry.second, map[rev]);
                }
            }
        }
        num+=m;
        return num;
    }
};