class Solution {
public:
    int countBinarySubstrings(string s) {
        int ones = 0; int zeros = 0;
        int left = 0; int right = 0;
        char curr = s[0]; int change = 1;
        int res = 0;
        while(right < s.size()){
            if(s[right] == curr){
                if(curr == '1')ones++;
                else zeros++;
            } else {
                if(change == 1){
                    change--;
                    if(curr == '1'){
                        curr = '0';
                        zeros++;
                    } else{
                        curr = '1';
                        ones++;
                    }
                } else {
                    res+= min(ones, zeros);
                    if(s[right] == '1'){
                        left+=ones;
                        curr = '1';
                        ones = 1;
                    } else {
                        left+=zeros;
                        curr = '0';
                        zeros = 1;
                    }
                }
            }
            right++;
        }
        res+= min(ones, zeros);
        return res;
    }
};
