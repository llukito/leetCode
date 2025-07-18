class Solution {
public:
    int countKeyChanges(string s) {
        int res = 0;
        char ch = '*';
        for(char c : s){
            c = tolower(c);
            if(ch == '*'){
                ch = c;
            } else {
                if(c !=ch){
                    res++;
                    ch = c;
                }
            }
        }
        return res;
    }
};