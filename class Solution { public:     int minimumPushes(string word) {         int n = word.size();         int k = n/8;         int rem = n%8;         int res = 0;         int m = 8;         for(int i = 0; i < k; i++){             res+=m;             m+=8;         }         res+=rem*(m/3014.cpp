class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int k = n/8;
        int rem = n%8;
        int res = 0;
        int m = 8;
        for(int i = 0; i < k; i++){
            res+=m;
            m+=8;
        }
        res+=rem*(m/8);
        return res;
    }
};
