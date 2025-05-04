class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>, int> mp;
        for(vector<int> vect : dominoes){
            sort(vect.begin(), vect.end());
            mp[vect]++;
        }
        int res = 0;
        for(auto& entry : mp){
            if(entry.second > 1){
                res+= nCm(entry.second);
            }
        }
        return res;
    }

    long long nCm(int total){
        long long r = total*(total-1);
        r/=2;
        return r;
    }
};