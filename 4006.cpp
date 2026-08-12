class Solution {
public:
    int countValidPrefixes(string s) {
        int zeros = 0;
        int ones = 0;
        int res = 0;
        for(char ch : s){
            if(ch == '0'){
                zeros++;
            } else {
                ones++;
            }

            if(abs(zeros-ones) <= 1){
                res++;
            }
        }
        return res;
    }
};
