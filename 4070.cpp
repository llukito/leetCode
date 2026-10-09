class Solution {
public:
    int minRotations(string s) {
        int res = min(abs(s[0]-'0'), '9'-s[0]+1);
        for(int i = 1; i < s.size(); i++){
            int v1 = s[i] > s[i-1] ? s[i]-s[i-1] : s[i-1]-s[i];
            int v2 = s[i] > s[i-1] ? '9'-s[i]+s[i-1]-'0' : '9'-s[i-1]+s[i]-'0';
            int currRes = min(v1, v2+1);
            res+=currRes;
        }
        return res;
    }
};
