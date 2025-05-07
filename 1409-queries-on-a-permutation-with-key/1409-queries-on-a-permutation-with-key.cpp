class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> p;
        for(int i=1; i<=m; i++){
            p.push_back(i);
        }
        vector<int> res;
        for(int i=0; i<queries.size(); i++){
            int num = queries[i];
            int index = find(p.begin(), p.end(), num)-p.begin();
            p.erase(p.begin()+index);
            p.insert(p.begin(), num);
            res.push_back(index);
        }
        return res;
    }
};