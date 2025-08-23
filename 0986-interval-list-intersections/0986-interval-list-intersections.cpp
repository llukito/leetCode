class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        for(int i=0; i<firstList.size(); i++){
            for(int j=0; j<secondList.size(); j++){
                vector<int>& n = firstList[i];
                vector<int>& m = secondList[j];
                if( ((n[1] >= m[0] && n[1]<=m[1]) || (n[0] >= m[0] && n[0]<=m[1])) || ((m[1] >= n[0] && m[1]<=n[1]) || (m[0] >= n[0] && m[0]<=n[1]))){
                    int start = max(n[0], m[0]);
                    int end = min(n[1], m[1]);
                    res.push_back({start,end});
                }
            }
        }
        return res;
    }
};