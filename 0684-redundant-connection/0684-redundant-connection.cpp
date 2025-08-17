class Solution {
public:
    unordered_map<int,int> parent;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res;
        for(vector<int> vect : edges){
            if(!unite(vect[0], vect[1])){
                res = vect;
            }
        }
        return res;
    }

    int find(int x){
        if(!parent.count(x))parent[x] = x;
        if(parent[x]!=x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y){
        int n1 = find(x);
        int n2 = find(y);
        if(n1 == n2){
            return false;
        }
        parent[n1] = n2;
        return true;
    }
};