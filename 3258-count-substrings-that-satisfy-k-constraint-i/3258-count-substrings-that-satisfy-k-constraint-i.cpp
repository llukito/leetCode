class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int num = 0;
        for(int i=0; i<s.length(); i++){
            for(int j=i; j<s.length(); j++){
                string str = s.substr(i,j-i+1);
                if(valid(str,k))num++;
            }
        }
        return num;
    }

    bool valid(string str, int k){
        int ones = 0;
        int zeros = 0;
        for(char ch : str){
            if(ch=='1'){
                ones++;
            } else {
                zeros++;
            }
        }
        return ones<=k || zeros<=k;
    }
};