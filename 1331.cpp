class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> r = arr;
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        int rank = 1;
        for(int n : arr){
            if(!mp.count(n)){
                mp[n] = rank++;
            }
        }
        vector<int> res;
        for(int n : r){
            res.push_back(mp[n]);
        }
        return res;
    }
};
