class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        map<int, int> parents;
        for(int i=0; i<n; i++){
            parents[i] = i;
        }
        for(vector<int> vect : edges){
            if(find(vect[0], parents)!=find(vect[1], parents)){
                unify(vect[0], vect[1], parents);
            }
        }
        return find(source, parents) == find(destination, parents);
    }

    int find(int n, map<int, int>& parents){
        if(parents[n]!=n){
            return find(parents[n], parents);
        }
        return parents[n];
    }

    void unify(int n, int m, map<int, int>& parents){
        int p1 = find(n, parents);
        int p2 = find(m, parents);
        parents[p1] = p2;
    }
};