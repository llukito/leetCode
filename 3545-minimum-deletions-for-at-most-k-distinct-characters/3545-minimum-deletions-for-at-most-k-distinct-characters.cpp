class Solution {
public:
    int minDeletion(string s, int k) {
        map<char,int> m;
        for(char ch : s){
            m[ch]++;
        }
        vector<int> vect;
        for(auto& entry : m){
            vect.push_back(entry.second);
        }
        sort(vect.begin(), vect.end());
        int idx = 0;
        int res = 0;
        int size = m.size();
        while(size>k){
            res+=vect[idx++];
            size--;
        }
        return res;
    }
};