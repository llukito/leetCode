class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        int left = 0; int right = 9;
        while(right < s.length()){
            string str = s.substr(left, right-left+1);
            mp[str]++;
            left++;
            right++;
        }
        vector<string> res;
        for(auto& entry : mp){
            if(entry.second >1){
                res.push_back(entry.first);
            }
        }
        return res;
    }
};