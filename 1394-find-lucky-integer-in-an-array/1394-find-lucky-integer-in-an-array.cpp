class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> mp;
        for(int n : arr){
            mp[n]++;
        }
        int res = -1;
        for(auto& entry : mp){
            if(entry.first == entry.second){
                res = entry.first;
            }
        }
        return res;
    }
};