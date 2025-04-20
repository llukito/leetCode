class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> map;
        int res = 0;
        for(int n : answers){
            map[n]++;
        }
        for(auto entry : map){
            int k = entry.first;
            int says = entry.second;
            int groups = (k+says)/(k+1);
            int groupSize = k+1;
            res+=groups*groupSize;
        }
        return res;
    }
};