class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, map<string,int>> mp;
        set<string> st;
        for(vector<string> vect : orders){
            mp[stoi(vect[1])][vect[2]]++;
            st.insert(vect[2]);
        }
        vector<vector<string>> res;
        vector<string> first;
        first.push_back("Table");
        for(string s : st){
            first.push_back(s);
        }
        res.push_back(first);
        for(auto& entry : mp){
            vector<string> vect;
            vect.push_back(to_string(entry.first));
            for(int i=1; i<first.size(); i++){
                vect.push_back(to_string(entry.second[first[i]]));
            }
            res.push_back(vect);
        }
        return res;
    }
};