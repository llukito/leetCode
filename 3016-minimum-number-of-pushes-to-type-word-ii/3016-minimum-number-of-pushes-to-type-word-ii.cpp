class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> temp;
        for(char ch : word){
            temp[ch]++;
        }
        vector<pair<int,int>> pr;
        for(auto& entry : temp){
            pr.push_back({entry.second, entry.first});
        }
        sort(pr.begin(), pr.end()); reverse(pr.begin(), pr.end());
        unordered_set<char> set; unordered_map<char,int> map;
        int res = 0;
        int add = 1;
        for(auto& p : pr){
            char ch = p.second;
            set.insert(ch);
            if(!map.count(ch)){
                map[ch] = add;
                if(set.size()%8==0){
                    add++;
                }
            }
            res+=map[ch]*p.first;
        }
        return res;
    }
};