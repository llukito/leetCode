class Solution {
public:
    int countAsterisks(string s) {
        bool b = true;
        int num = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '|'){
                if(b){
                    b = false;
                } else {
                    b = true;
                }
            } else if(b && s[i]=='*'){
                num++;
            }
        }
        return num;
    }
};