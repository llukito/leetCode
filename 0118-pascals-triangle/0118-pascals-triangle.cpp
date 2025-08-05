class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows == 0)return res;
        res.push_back({1});
        if(numRows == 1)return res;
        res.push_back({1,1});
        if(numRows == 2)return res;
        for(int i=3; i<=numRows; i++){
            vector<int> curr = res.back();
            vector<int> addable;
            addable.push_back(1);
            for(int i=0; i<curr.size()-1; i++){
                addable.push_back(curr[i]+curr[i+1]);
            }
            addable.push_back(1);
            res.push_back(addable);
        }
        return res;
    }
};