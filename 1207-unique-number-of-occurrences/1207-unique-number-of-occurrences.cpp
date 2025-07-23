class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> map;
        for(int n : arr){
            map[n]++;
        }
        unordered_set<int> set;
        for(auto[n,m] : map){
            if(set.count(m))return false;
            set.insert(m);
        }
        return true;
    }
};