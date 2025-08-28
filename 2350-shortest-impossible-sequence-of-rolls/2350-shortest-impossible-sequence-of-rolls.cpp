class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        unordered_set<int> set;
        int res = 1;
        for(int i=0; i<rolls.size(); i++){
            set.insert(rolls[i]);
            if(set.size()==k){
                res++;
                set.clear();
            }
        }
        return res;
    }
};