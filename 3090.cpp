class Solution {
public:
    int maximumLengthSubstring(string s) {
        int res = 0;
        vector<int> vect(26, 0);
        int j = 0;
        for(int i = 0; i < s.size(); i++){
            vect[s[i] - 'a']++;
            while(vect[s[i] - 'a'] > 2){
                vect[s[j] - 'a']--;
                j++;
            }
            res = max(res, i-j+1);
        }
        return res;
    }
};
