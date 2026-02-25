class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> vect;
        for(int n : arr){
            bitset<32> b(n);
            int num = 0;
            for(char ch : b.to_string())if(ch == '1')num++;
            vect.push_back({num, n});
        }
        sort(vect.begin(), vect.end());
        vector<int> res;
        for(auto& en : vect){
            res.push_back(en.second);
        }
        return res;
    }
};
