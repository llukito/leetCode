class Solution {
public:
    struct CustomCompare {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
            if (a.first != b.first)
                return a.first < b.first; // higher int = higher priority
            return a.second > b.second;   // reverse lex order: "apple" > "zebra" is false, so zebra comes first
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> map;
        for(string str : words){
            map[str]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, CustomCompare>  q;
        for(auto& entry : map){
            q.push({entry.second, entry.first});
        }
        vector<string> vect;
        for(int i=0; i<k; i++){
            vect.push_back(q.top().second);
            q.pop();
        }
        return vect;
    }
};