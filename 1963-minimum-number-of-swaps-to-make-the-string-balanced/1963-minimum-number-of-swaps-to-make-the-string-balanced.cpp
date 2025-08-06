class Solution {
public:
    int minSwaps(string s) {
        int res = 0;
        int open = 0;
        int closed = 0;
        for(char ch : s){
            if(ch == '['){
                open++;
            } else {
                closed++;
            }
            if(closed>open){
                closed--;
                open++;
                for(int i=s.length(); i<=0; i--){
                    if(s[i] == ']'){
                        s[i] = '[';
                        break;
                    }
                }
                res++;
            }
        }
        return res;
    }
};