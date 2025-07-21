class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> map;
        for(char ch : s){
            map[ch]++;
        }
        int num = -1;
        for(auto& entry : map){
            if(num == -1){
                num = entry.second;
            } else {
                if(entry.second != num)return false;
            }
        }
        return true;
    }
};